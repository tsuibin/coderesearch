function vB_QuickEditor_PictureComment_Vars(args)
{
	this.init(args[0], args[1], args[2]);
}

vB_QuickEditor_PictureComment_Vars.prototype.init = function(pictureid, xid, group)
{
	this.peritemsettings = true;

	this.pictureid = pictureid;

	this.xid = xid;

	if (group)
	{
		this.type = 'group';
	}
	else
	{
		this.type = 'album';
	}

	this.target = "picturecomment.php";
	this.postaction = "message";

	this.objecttype = "commentid";
	this.getaction = "message";

	this.ajaxtarget = "picturecomment.php";
	this.ajaxaction = "quickedit";
	this.deleteaction = "deletepc";

	this.messagetype = "picturecomment_text_";
	this.containertype = "picturecomment";
	this.responsecontainer = "commentbits";
}




function vB_QuickEditor_PictureComment(objectid, watcher, vars, controlid)
{
	this.objectid = objectid;
	this.watcher = watcher;
	this.vars = vars;
	this.controlid = controlid;
	this.originalhtml = null;
	this.ajax_req = null;
	this.show_advanced = true;
	this.messageobj = null;
	this.node = null;
	this.progress_indicator = null;
	this.editbutton = null;
}

vBulletin.extend(vB_QuickEditor_PictureComment, vB_QuickEditor_Generic);

/**
 * Send AJAX request to fetch the editor HRML
 */
vB_QuickEditor_PictureComment.prototype.fetch_editor = function()
{
	if (this.progress_indicator)
	{
		this.progress_indicator.style.display = '';
	}
	document.body.style.cursor = 'wait';

	YAHOO.util.Connect.asyncRequest("POST", this.vars.ajaxtarget + "?do=" + this.vars.ajaxaction + "&" + this.vars.objecttype + "=" + this.objectid + "&pictureid=" + this.vars.pictureid + "&" + this.vars.type + "id=" + this.vars.xid, {
		success: this.display_editor,
		failure: this.error_opening_editor,
		timeout: vB_Default_Timeout,
		scope: this
	}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&do=" + this.vars.ajaxaction + "&" + this.vars.objecttype + "=" + this.objectid + "&pictureid=" + this.vars.pictureid + "&" + this.vars.type + "id=" + this.vars.xid + "&editorid=" + PHP.urlencode(this.editorid));
}


/**
 * Save the edited post via AJAX
 *
 * @param	event	Event Object
 *
 */
vB_QuickEditor_Generic.prototype.save = function(e)
{
	YAHOO.util.Event.stopEvent(e);

	var newtext = vB_Editor[this.editorid].get_editor_contents();
	var newreason = YAHOO.util.Dom.get(this.editorid + '_edit_reason');

	if (newtext == this.unchanged && newreason && newreason.value == this.unchanged_reason)
	{
		this.abort(e);
	}
	else
	{
		YAHOO.util.Dom.get(this.editorid + '_posting_msg').style.display = '';
		document.body.style.cursor = 'wait';

		this.ajax_req = YAHOO.util.Connect.asyncRequest("POST", this.vars.target + "?do" + this.vars.postaction + "&" + this.vars.objecttype + "=" + this.objectid + "&pictureid=" + this.vars.pictureid + "&" + this.vars.type + "id=" + this.vars.xid,{
			success: this.update,
			faulure: this.handle_save_error,
			timeout: vB_Default_Timeout,
			scope: this
		}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&do=" + this.vars.postaction + "&ajax=1&" + this.vars.objecttype + "="
			+ this.objectid
			+ "&pictureid=" + this.vars.pictureid + "&" + this.vars.type + "id=" + this.vars.xid
			+ "&wysiwyg=" + vB_Editor[this.editorid].wysiwyg_mode
			+ "&message=" + PHP.urlencode(newtext)
			+ "&reason=" + PHP.urlencode(YAHOO.util.Dom.get(this.editorid + '_edit_reason').value)
			+ "&parseurl=1"
		);

		this.pending = true;
	}
};

/**
 * Pass edits along to the full editor
 *
 * @param	event	Event object
 *
 */
vB_QuickEditor_PictureComment.prototype.full_edit = function(e)
{
	if (e)
	{
		YAHOO.util.Event.stopEvent(e);
	}

	var form = new vB_Hidden_Form(this.vars.target + "?do=" + this.vars.postaction + "&" + this.vars.objecttype + "=" + this.objectid + "&pictureid=" + this.vars.pictureid + "&" + this.vars.type + "id=" + this.vars.xid);

	form.add_variable('do', this.vars.postaction);
	form.add_variable('s', fetch_sessionhash());
	form.add_variable('securitytoken', SECURITYTOKEN);

	if (this.show_advanced)
	{
		form.add_variable('advanced', 1);
	}

	form.add_variable(this.vars.objecttype, this.objectid);
	form.add_variable(this.vars.type, this.vars.xid);
	form.add_variable('pictureid', this.vars.pictureid);
	form.add_variable('wysiwyg', vB_Editor[this.editorid].wysiwyg_mode);
	form.add_variable('message', vB_Editor[this.editorid].get_editor_contents());
	form.add_variable('reason', YAHOO.util.Dom.get(this.editorid + '_edit_reason').value);

	form.submit_form();
}


/**
 * Fetches URL for full editor
 *
 * @return	string
 *
 */

vB_QuickEditor_Generic.prototype.fail_url = function()
{
	return this.vars.target + "?" + SESSIONURL + "do=" + this.getaction + "&" + this.vars.objecttype + "=" + this.objectid+ "&pictureid=" + this.vars.pictureid + "&" + this.vars.type + "id=" + this.vars.xid;
}