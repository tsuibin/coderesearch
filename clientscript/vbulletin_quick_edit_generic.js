/*!======================================================================*\
|| #################################################################### ||
|| # vBulletin [#]version[#]
|| # ---------------------------------------------------------------- # ||
|| # Copyright ©2000-[#]year[#] Jelsoft Enterprises Ltd. All Rights Reserved. ||
|| # This file may not be redistributed in whole or significant part. # ||
|| # ---------------- VBULLETIN IS NOT FREE SOFTWARE ---------------- # ||
|| # http://www.vbulletin.com | http://www.vbulletin.com/license.html # ||
|| #################################################################### ||
\*======================================================================*/

vBulletin.events.systemInit.subscribe(function()
{
	if (AJAX_Compatible)
	{
		vB_QuickEditor_Watcher = new vB_QuickEditor_Watcher();
	}
});

/**
* Class to create Quick Edit controls.
*
* @package	vBulletin
* @version	$Revision: 25662 $
* @date		$Date: 2008-02-04 14:33:20 -0800 (Mon, 04 Feb 2008) $
* @author	Martin Meredith, vBulletin Development Team
*/
function vB_QuickEditor_Watcher()
{
	this.editorcounter = 0;
	this.controls = new Object();
	this.open_objectid = null;
	this.vars = new Object();

	this.init();
}


/**
 * Initialisation & Creation of objects
 */
vB_QuickEditor_Watcher.prototype.init = function()
{
	if (vBulletin.elements["vB_QuickEdit"])
	{

		for (var i = 0; i < vBulletin.elements["vB_QuickEdit"].length; i++)
		{
			var objectid = vBulletin.elements["vB_QuickEdit"][i].splice(0, 1)[0];

			var objecttype = vBulletin.elements["vB_QuickEdit"][i].splice(0, 1)[0];

			var args = vBulletin.elements["vB_QuickEdit"][i];

			var vartype = '';

			eval("vartype = typeof(vB_QuickEditor_" + objecttype + "_Vars);");

			if (vartype == 'undefined')
			{
				console.log('not found: ' + 'vB_QuickEditor_' + objecttype + '_Vars');
				continue;
			}

			var vars = null;

			if (typeof(this.vars[objecttype]) == 'undefined')
			{
				var obj = null;

				eval("obj = new vB_QuickEditor_" + objecttype + "_Vars(args);");

				this.vars[objecttype] = obj;

				vars = this.vars[objecttype];
			}
			else if (this.vars[objecttype].peritemsettings == true)
			{
				eval ("vars = new vB_QuickEditor_" + objecttype + "_Vars(args);");
			}
			else
			{
				vars = this.vars[objecttype];
			}

			var editbutton = YAHOO.util.Dom.get(this.vars[objecttype].containertype + "_edit_" + objectid);

			if (editbutton)
			{
				this.controls[objecttype + '_' + objectid] = this.fetch_editor_class(objectid, objecttype, vars, objecttype + '_' + objectid);
				this.controls[objecttype + '_' + objectid].init();
			}
			else
			{
				console.log(vars.containertype + "_edit_" + objectid + " not found");
			}
		}
		vBulletin.elements["vB_QuickEdit"] = null;
	}
}

/**
 * Function to fetch the correct editor class
 * (Fetches generic class if no specific class found)
 *
 * @param	string	The Object Id
 * @param	string	The Object Type
 * @param	object	The Variables for the Class
 * @param	object	The Edit Button
 *
 * @returns	object
 *
 */
vB_QuickEditor_Watcher.prototype.fetch_editor_class = function(objectid, objecttype, vars, controlid)
{
	var vartype = '';
	var obj = null;

	eval("vartype = typeof(vB_QuickEditor_" + objecttype + ");");

	if (vartype == 'undefined')
	{
		obj = new vB_QuickEditor_Generic(objectid, this, vars, controlid);
	}
	else
	{
		eval("obj = new vB_QuickEditor_" + objecttype + "(objectid, this, vars, controlid);");
	}

	return obj;
}

/**
 * Closes the Quick Editor
 *
 */
vB_QuickEditor_Watcher.prototype.close_all = function()
{
	if (this.open_objectid)
	{
		this.controls[this.open_objectid].abort();
	}
}

/**
 * Hides the error prompt
 *
 */
vB_QuickEditor_Watcher.prototype.hide_errors = function()
{
	if (this.open_objectid)
	{
		this.controls[this.open_objectid].hide_errors();
	}
}

/**
 * Generic Class for Quick Editor
 *
 * @param	string	The Object Id
 * @param	object	The Watcher Class
 * @param	object	The Variables
 * @param	object	The Edit Button
 *
 */
function vB_QuickEditor_Generic(objectid, watcher, vars, controlid)
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


/**
 * Initialise/Re-initialise the object
 *
 */
vB_QuickEditor_Generic.prototype.init = function()
{
	this.originalhtml = null;
	this.ajax_req = null;
	this.show_advanced = true;

	this.messageobj = YAHOO.util.Dom.get(this.vars.messagetype + this.objectid);
	this.node = YAHOO.util.Dom.get(this.vars.containertype + this.objectid);
	this.progress_indicator = YAHOO.util.Dom.get(this.vars.containertype + "_progress_" + this.objectid);

	var obj = YAHOO.util.Dom.get(this.vars.containertype + "_edit_" + this.objectid);
	this.editbutton = obj;

	YAHOO.util.Event.on(this.editbutton, "click", this.edit, this, true);
}

/**
 * Removes click handler, and prevents memory leakage
 *
 */
vB_QuickEditor_Generic.prototype.remove_clickhandler = function()
{
	YAHOO.util.Event.purgeElement(this.editbutton);
}

/**
 * Check if the AJAX System is ready for us to proceed
 *
 * @returns	boolean
 *
 */
vB_QuickEditor_Generic.prototype.ready = function()
{
	if (this.watcher.open_objectid != null || YAHOO.util.Connect.isCallInProgress(this.ajax_req))
	{
		return false;
	}
	else
	{
		return true;
	}
};

/**
 * Prepare to edit a single post
 *
 * @returns	boolean
 *
 */
vB_QuickEditor_Generic.prototype.edit = function(e)
{

	if (typeof(vb_disable_ajax) != 'undefined' && vb_disable_ajax > 0)
	{
		return true;
	}

	if (e)
	{
		YAHOO.util.Event.stopEvent(e);
	}

	if (YAHOO.util.Connect.isCallInProgress(this.ajax_req))
	{
		return false;
	}
	else if (!this.ready())
	{
		if (this.objectid == this.watcher.open_objectid)
		{
			this.full_edit();
			return false;
		}
		this.watcher.close_all();
	}

	this.watcher.open_objectid = this.controlid;
	this.watcher.editorcounter++;
	this.editorid = 'vB_Editor_QE_' + this.vars.containertype + this.watcher.editorcounter;

	this.originalhtml = this.messageobj.innerHTML;
	this.unchanged = null;
	this.unchanged_reason = null;

	this.fetch_editor();

	return false;
}

/**
 * Send AJAX request to fetch the editor HRML
 */
vB_QuickEditor_Generic.prototype.fetch_editor = function()
{
	if (this.progress_indicator)
	{
		this.progress_indicator.style.display = '';
	}
	document.body.style.cursor = 'wait';

	YAHOO.util.Connect.asyncRequest("POST", this.vars.ajaxtarget + "?do=" + this.vars.ajaxaction + "&" + this.vars.objecttype + "=" + this.objectid, {
		success: this.display_editor,
		failure: this.error_opening_editor,
		timeout: vB_Default_Timeout,
		scope: this
	}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&do=" + this.vars.ajaxaction + "&" + this.vars.objecttype + "=" + this.objectid + "&editorid=" + PHP.urlencode(this.editorid));
}

/**
 * Handle unspecified AJAX server error when opening (goto full editor)
 *
 * @param	object	YUI AJAX
 *
 */
vB_QuickEditor_Generic.prototype.handle_save_error = function(ajax)
{
	vBulletin_AJAX_Error_Handler(ajax);
	window.location = this.fail_url();
}

/**
 * Fetches URL for full editor
 *
 * @return	string
 *
 */

vB_QuickEditor_Generic.prototype.fail_url = function()
{
	return this.vars.target + "?" + SESSIONURL + "do=" + this.getaction + "&" + this.vars.objecttype + "=" + this.objectid;
}
/**
 * Handles unspecified AJAX error when saving
 *
 * @param	object	YUI AJAX
 *
 */
vB_QuickEditor_Generic.prototype.handle_save_error = function(ajax)
{
	vBulletin_AJAX_Error_Handler(ajax);

	this.show_advanced = false;
	this.full_edit();
}

/**
 * Display the editor HTML when AJAX says fetch_editor() is ready
 *
 * @param	object	YUI AJAX
 *
 */
vB_QuickEditor_Generic.prototype.display_editor = function(ajax)
{
	if (ajax.responseXML)
	{
		if (this.progress_indicator)
		{
			this.progress_indicator.style.display = 'none';
		}

		document.body.style.cursor = 'auto';

		if (fetch_tag_count(ajax.responseXML, 'disabled'))
		{
			// Quick Edit is disabled... goto Full edit
			window.location = this.fail_url();
		}
		else if (fetch_tag_count(ajax.responseXML, 'error'))
		{
			// Do Nothing
		}
		else
		{
			var editor = fetch_tags(ajax.responseXML, 'editor')[0];
			var reason = editor.getAttribute('reason');

			// display the editor
			this.messageobj.innerHTML = editor.firstChild.nodeValue;

			// display the reason

			var editreason = YAHOO.util.Dom.get(this.editorid + '_edit_reason');

			if (editreason)
			{
				this.unchanged_reason = PHP.unhtmlspecialchars(reason);
				editreason.value = this.unchanged_reason;
				editreason.onkeypress = vB_QuickEditor_Delete_Events.prototype.reason_key_trap;
			}

			// initialize the editor
			vB_Editor[this.editorid] = new vB_Text_Editor(
				this.editorid,
				editor.getAttribute('mode'),
				editor.getAttribute('parsetype'),
				editor.getAttribute('parsesmilies')
			);

			vB_Editor[this.editorid].set_editor_width('100%', true);
			vB_Editor[this.editorid].check_focus();

			this.unchanged = vB_Editor[this.editorid].get_editor_contents();

			YAHOO.util.Event.on(YAHOO.util.Dom.get(this.editorid + '_save'), "click", this.save, this, true);
			YAHOO.util.Event.on(YAHOO.util.Dom.get(this.editorid + '_abort'), "click", this.abort, this, true);
			YAHOO.util.Event.on(YAHOO.util.Dom.get(this.editorid + '_adv'), "click", this.full_edit, this, true);
			YAHOO.util.Event.on("quick_edit_errors_hide", "click", this.hide_errors, this, true);
			YAHOO.util.Event.on("quick_edit_errors_cancel", "click", this.abort, this, true);

			var delbutton = YAHOO.util.Dom.get(this.editorid + '_delete');

			if (delbutton)
			{
				YAHOO.util.Event.on(this.editorid + '_delete', "click", this.show_delete, this, true);
			}
		}
	}
};


/**
 * Destroy the Editor, and use the specified text as the post contents
 *
 * @param	string	Text of post
 *
 */
vB_QuickEditor_Generic.prototype.restore = function(post_html, type)
{
	this.hide_errors(true);

	if (this.editorid && vB_Editor[this.editorid] && vB_Editor[this.editorid].initialized)
	{
		vB_Editor[this.editorid].destroy();
	}

	if (type == 'node')
	{
		// Usually called when message is saved
		var newnode = string_to_node(post_html);
		this.node.parentNode.replaceChild(newnode, this.node);
	}
	else
	{
		// Usually called when message edit is cancelled
		this.messageobj.innerHTML = post_html;
	}

	this.watcher.open_objectid = null;
};

/**
 * Cancel the post edit and restore everything to how it started
 *
 * @param	event	Event Object
 *
 */
vB_QuickEditor_Generic.prototype.abort = function(e)
{
	if (e)
	{
		YAHOO.util.Event.stopEvent(e);
	}

	if (this.progress_indicator)
	{
		this.progress_indicator.style.display = 'none';
	}
	document.body.style.cursor = 'auto';
	this.restore(this.originalhtml, 'messageobj');
};

/**
 * Pass edits along to the full editor
 *
 * @param	event	Event object
 *
 */
vB_QuickEditor_Generic.prototype.full_edit = function(e)
{
	if (e)
	{
		YAHOO.util.Event.stopEvent(e);
	}

	var form = new vB_Hidden_Form(this.vars.target + "?do=" + this.vars.postaction + "&" + this.vars.objecttype + "=" + this.objectid);

	form.add_variable('do', this.vars.postaction);
	form.add_variable('s', fetch_sessionhash());
	form.add_variable('securitytoken', SECURITYTOKEN);

	if (this.show_advanced)
	{
		form.add_variable('advanced', 1);
	}

	form.add_variable(this.vars.objecttype, this.objectid);
	form.add_variable('wysiwyg', vB_Editor[this.editorid].wysiwyg_mode);
	form.add_variable('message', vB_Editor[this.editorid].get_editor_contents());
	form.add_variable('reason', YAHOO.util.Dom.get(this.editorid + '_edit_reason').value);

	form.submit_form();
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

		this.ajax_req = YAHOO.util.Connect.asyncRequest("POST", this.vars.target + "?do" + this.vars.postaction + "&" + this.vars.objecttype + "=" + this.objectid,{
			success: this.update,
			faulure: this.handle_save_error,
			timeout: vB_Default_Timeout,
			scope: this
		}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&do=" + this.vars.postaction + "&ajax=1&" + this.vars.objecttype + "="
			+ this.objectid
			+ "&wysiwyg=" + vB_Editor[this.editorid].wysiwyg_mode
			+ "&message=" + PHP.urlencode(newtext)
			+ "&reason=" + PHP.urlencode(YAHOO.util.Dom.get(this.editorid + '_edit_reason').value)
			+ "&parseurl=1"
		);

		this.pending = true;
	}
};

/**
 * Shows the delete dialog
 *
 */
vB_QuickEditor_Generic.prototype.show_delete = function()
{
	this.deletedialog = YAHOO.util.Dom.get('quickedit_delete');
	if (this.deleteddialog && this.deleteddialog.style.display != '')
	{
		this.deletedialog.style.display = '';

		this.deletebutton = YAHOO.util.Dom.get('quickedit_dodelete');
		YAHOO.util.Event.on(this.deletebutton, "click", this.delete_post, this, true);

		var del_reason = YAHOO.util.Dom.get("del_reason");

		if (del_reason)
		{
			del_reason.onkeypress = vB_QuickEditor_Delete_Events.prototype.delete_items_key_trap;
		}

		// don't do this stuff for browsers that don't have any defined events
		// to detect changed radio buttons with keyboard navigation
		if (!is_opera && !is_saf)
		{
			this.deletebutton.disabled = true;
			this.deleteoptions = new Array();

			this.deleteoptions['leave'] = YAHOO.util.Dom.get('rb_del_leave');
			this.deleteoptions['soft'] = YAHOO.util.Dom.get('rb_del_soft');
			this.deleteoptions['hard'] = YAHOO.util.Dom.get('rb_del_hard');

			for (var i in this.deleteoptions)
			{
				if (YAHOO.lang.hasOwnProperty(this.deleteoptions, i) && this.deleteoptions[i])
				{
					this.deleteoptions[i].onclick = this.deleteoptions[i].onchange = vB_QuickEditor_Delete_Events.prototype.delete_button_handler;
					this.deleteoptions[i].onkeypress = vB_QuickEditor_Delete_Events.prototype.delete_items_key_trap;
				}
			}
		}
	}
}

/**
 * Run the delete system
 */
vB_QuickEditor_Generic.prototype.delete_post = function()
{
	var dontdelete = YAHOO.util.Dom.get('rb_del_leave');
	if (dontdelete && dontdelete.checked)
	{
		this.abort();
		return;
	}

	var form = new vB_Hidden_Forum(this.vars.target);

	form.add_variable('do', this.vars.deleteaction);
	form.add_variable('s', fetch_sessionhash());
	form.add_variable('securitytoken', SECURITYTOKEN);
	form.add_variabl(this.vars.objecttype, this.objectid);
	form.add_variables_from_object(this.deletedialog);

	form.submit_form();
}

/**
 * Check for errors etc. and initialize restore when AJAX says save() is complete
 *
 * @param	object	YUI AJAX
 *
 * @return	boolean	false
 *
 */
vB_QuickEditor_Generic.prototype.update = function(ajax)
{
	if (ajax.responseXML)
	{
		this.pending = false;
		document.body.style.cursor = 'auto';
		YAHOO.util.Dom.get(this.editorid + '_posting_msg').style.display = 'none';

		// this is the nice error handler, of which Safari makes a mess
		if (fetch_tag_count(ajax.responseXML, 'error'))
		{
			var errors = fetch_tags(ajax.responseXML, 'error');

			var error_html = '<ol>';

			for (var i = 0; i < errors.length; i++)
			{
				error_html += '<li>' + errors[i].firstChild.nodeValue + '</li>';
			}
			error_html += '</ol>';

			this.show_errors('<ol>' + error_html + '</ol>');
		}
		else
		{
			var message = ajax.responseXML.getElementsByTagName("message");
			this.restore(message[0].firstChild.nodeValue, 'node');
			this.remove_clickhandler(); // To stop memory leaks
			this.init(); // To be able to use the editor again

		}
	}
	return false;
}

/**
 * Pop up a window showing errors
 *
 * @param	string	Error HTML
 *
 */
vB_QuickEditor_Generic.prototype.show_errors = function(errortext)
{
	YAHOO.util.Dom.get('ajax_post_errors_message').innerHTML = errortext;
	var errortable = YAHOO.util.Dom.get('ajax_post_errors');
	errortable.style.width = '400px';
	errortable.style.zIndex = 500;
	var measurer = (is_saf ? 'body' : 'documentElement');
	errortable.style.left = (is_ie ? document.documentElement.clientWidth : self.innerWidth) / 2 - 200 + document[measurer].scrollLeft + 'px';
	errortable.style.top = (is_ie ? document.documentElement.clientHeight : self.innerHeight) / 2 - 150 + document[measurer].scrollTop + 'px';
	errortable.style.display = '';
}

/**
 * Hide the error Window
 *
 */
vB_QuickEditor_Generic.prototype.hide_errors = function(skip_focus_check)
{
	this.errors = false;
	var errors = YAHOO.util.Dom.get("ajax_post_errors")
	if (errors)
	{
		errors.style.display = 'none';
	}
	if (skip_focus_check != true)
	{
		vB_Editor[this.editorid].check_focus();
	}
}

// =============================================================================
// vB_AJAX_QuickEditor Event Handlers


/**
* Class to handle quick editor events
*/
function vB_QuickEditor_Delete_Events()
{
}

/**
* Handles manipulation of form elements in the delete section
*/
vB_QuickEditor_Delete_Events.prototype.delete_button_handler = function(e)
{
	var open_objectid = vB_QuickEditor_Watcher.open_objectid;
	var openobj = vB_QuickEditor_Watcher.controls[open_objectid];

	if (this.id == 'rb_del_leave' && this.checked)
	{
		openobj.deletebutton.disabled = true;
	}
	else
	{
		openobj.deletebutton.disabled = false;
	}
}

/**
* Key trapper for reason box
*/
vB_QuickEditor_Delete_Events.prototype.reason_key_trap = function(e)
{
	var open_objectid = vB_QuickEditor_Watcher.open_objectid;
	var openobj = vB_QuickEditor_Watcher.controls[open_objectid];
	e = e ? e : window.event;

	switch (e.keyCode)
	{
		case 9: // tab
		{
			YAHOO.util.Dom.get(openobj.editorid + '_save').focus();
			return false;
		}
		break;

		case 13: // enter
		{
			openobj.save();
			return false;
		}
		break;

		default:
		{
			return true;
		}
	}
}

/**
* Key trapper for reason box
*/
vB_QuickEditor_Delete_Events.prototype.delete_items_key_trap = function(e)
{
	var open_objectid = vB_QuickEditor_Watcher.open_objectid;
	var openobj = vB_QuickEditor_Watcher.controls[open_objectid];
	e = e ? e : window.event;

	if (e.keyCode == 13) // enter
	{
		if (open_obj.deletebutton.disabled == false)
		{
			open_obj.delete_post();
		}
		return false;
	}

	return true;
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 25662 $
|| ####################################################################
\*======================================================================*/
