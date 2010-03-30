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

/*
* IMPORTANT: This file is used by the blog and public messaing so be mindful!
*
* call like this:
*
* var quick_comment = new vB_BlogQuickComment("qcform", $vboptions[postminchars]);
*
* The variable name 'quick_comment' is important!
*/
/**
* Quick AJAX comment for blog and public messaging
*
* @package	vBulletin
* @version	$Revision: 24798 $
* @date		$Date: 2007-11-22 13:59:49 +0000 (Thu, 22 Nov 2007) $
* @author	Kier Darby, vBulletin Development Team
* @copyright	Jelsoft Enterprises Ltd.
*/
function vB_QuickComment(formid, minchars, returnorder)
{
	this.repost       = false;
	this.errors_shown = false;
	this.posting      = false;
	this.submit_str   = null;
	this.lastelement  = YAHOO.util.Dom.get("lastcommentdiv");
	this.returnorder  = 'ASC';
	this.basiceditor = YAHOO.util.Dom.get(formid + "_textarea");
	this.form = YAHOO.util.Dom.get(formid);
	if (typeof(this.form.allow_ajax_qc) != 'undefined' && this.form.allow_ajax_qc.value == 0)
	{
		this.allow_ajax_qc = false;
	}
	else	// Allow AJAX
	{
		this.allow_ajax_qc = true;
	}

	if (returnorder == 'DESC')
	{
		this.returnorder = 'DESC';
	}

	this.minchars = minchars;

	YAHOO.util.Event.on("qr_submit", "click", this.submit_comment, this, true);
	YAHOO.util.Event.on("qr_preview", "click", this.submit_comment, this, true);
	YAHOO.util.Event.on("qc_hide_errors", "click", this.hide_errors, this, true);
}

/**
* Works with form data to decide what to do
*
* @param	event	Javascript event object
*
* @return	boolean
*/
vB_QuickComment.prototype.check_data = function(e)
{
	if (typeof(this.form.preview) != 'undefined' && YAHOO.util.Event.getTarget(e) == this.form.preview)
	{
		minchars = 0;
	}
	else
	{
		minchars = this.minchars;
	}

	return this.prepare_submit(minchars);
}

/**
* Check if we need to refocus the editor window
*/
vB_QuickComment.prototype.write_editor_contents = function(contents)
{
	if (typeof(QR_EditorID) != 'undefined')
	{
		vB_Editor[QR_EditorID].write_editor_contents(contents);
	}
	else
	{
		this.basiceditor.value = contents;
	}
}

/**
* Check if we need to refocus the editor window
*/
vB_QuickComment.prototype.check_focus = function()
{
	if (typeof(QR_EditorID) != 'undefined')
	{
		vB_Editor[QR_EditorID].check_focus();
	}
	else
	{
		if (!this.basiceditor.hasfocus)
		{
			this.basiceditor.focus();
			if (is_opera)
			{
				// see http://www.vbulletin.com/forum/project.php?issueid=10687
				this.basiceditor.focus();
			}
		}
	}
}

/**
* Prepare Form For Submit
*
* @param	integer	minimum amount of characters to allow
*
* @return	boolean
*/
vB_QuickComment.prototype.prepare_submit = function(minchars)
{
	if (typeof(QR_EditorID) != 'undefined')
	{
		return vB_Editor[QR_EditorID].prepare_submit(0, minchars);
	}
	else
	{
		var returnvalue = validatemessage(stripcode(this.basiceditor.value, true), 0, minchars);

		if (returnvalue)
		{
			return returnvalue;
		}
		else
		{
			this.check_focus();
			return false;
		}
	}
}

/**
* Checks the contents of the new comment and decides whether or not to allow it through
*
* @param	event	Javascript event object
*
* @return	boolean
*/
vB_QuickComment.prototype.submit_comment = function(e)
{
	if (this.repost == true)
	{
		return true;
	}
	else if (!AJAX_Compatible || !this.allow_ajax_qc)
	{
		if (!this.check_data(e))
		{
			YAHOO.util.Event.stopEvent(e);
			return false;
		}
		return true;
	}
	else if (this.check_data(e))
	{
		if (is_ie && userAgent.indexOf("msie 5.") != -1)
		{
			// IE 5 has problems with non-ASCII characters being returned by
			// AJAX. Don't universally disable it, but if we're going to be sending
			// non-ASCII, let's not use AJAX.
			if (PHP.urlencode(this.form.message.value).indexOf('%u') != -1)
			{
				return true;
			}
		}

		if (this.posting == true)
		{
			YAHOO.util.Event.stopEvent(e);
			return false;
		}
		else
		{
			this.posting = true;
			setTimeout("quick_comment.posting = false", 1000); // ATTENTION
		}

		if (typeof(this.form.preview) != 'undefined' && YAHOO.util.Event.getTarget(e) == this.form.preview)
		{
			return true;
		}
		else
		{
			this.submit_str = this.build_submit_string();

			YAHOO.util.Dom.setStyle("qc_posting_msg", "display", "");
			YAHOO.util.Dom.setStyle(document.body, "cursor", "wait");

			this.save(this.form.action, this.submit_str);

			YAHOO.util.Event.stopEvent(e);
			return false;
		}
	}
	else
	{
		YAHOO.util.Event.stopEvent(e);
		return false;
	}
}

/**
* Builds the submit string for the AJAX request
*
* @return	string	Submit query URI string
*/
vB_QuickComment.prototype.build_submit_string = function()
{
	this.submit_str = 'ajax=1';

	var hiddenform = new vB_Hidden_Form(null);
	hiddenform.add_variables_from_object(this.form);

	return this.submit_str += "&" + hiddenform.build_query_string();
}

/**
* Sends quick comment data to php via AJAX
*
* @param	string	GET string for action
* @param	string	String representing form data ('x=1&y=2&z=3' etc.)
*/
vB_QuickComment.prototype.save = function()
{
	this.repost = false;

	YAHOO.util.Connect.asyncRequest("POST", this.form.action, {
		success: this.post_save,
		failure: this.handle_ajax_error,
		timeout: vB_Default_Timeout,
		scope: this
	}, this.submit_str);
}

/**
* Handle AJAX Error
*
* @param	object	YUI AJAX
*/
vB_QuickComment.prototype.handle_ajax_error = function(ajax)
{
	vBulletin_AJAX_Error_Handler(ajax);

	console.log("AJAX Timeout - Submitting form");
	this.repost = true;
	fetch_object('qcform').submit();
}

/**
* Handles quick comment data when AJAX says qc_ajax_post() is complete
* This function must be defined in your specific class extension
*/
vB_QuickComment.prototype.post_save = function(ajax)
{
	YAHOO.util.Dom.setStyle(document.body, "cursor", "auto");
	YAHOO.util.Dom.setStyle("qc_posting_msg", "display", "none");
	this.posting = false;

	var messages = ajax.responseXML.getElementsByTagName("message");
	if (messages.length)
	{
		this.write_editor_contents("");

		this.form.lastcomment.value = ajax.responseXML.getElementsByTagName("time")[0].firstChild.nodeValue;

		this.hide_errors();

		var total = 0;

		var messagelist = YAHOO.util.Dom.get("message_list");

		for (var i = 0; i < messages.length; i++)
		{
			if (this.returnorder == 'ASC')
			{
				Comment_Init(messagelist.insertBefore(string_to_node(messages[i].firstChild.nodeValue), messagelist.firstChild));
			}
			else
			{
				Comment_Init(messagelist.appendChild(string_to_node(messages[i].firstChild.nodeValue)));
			}
			
			if (messages[i].getAttribute("quickedit"))
			{
				// initialise the quick editor again
				vB_QuickEditor_Watcher.init();
			}
			
			total += parseInt(messages[i].getAttribute("visible"));
		}

		if (total > 0)
		{
			var page_total = YAHOO.util.Dom.get("page_message_count");
			if (page_total)
			{
				page_total.innerHTML = parseInt(page_total.innerHTML) + total;
			}

			var message_total = YAHOO.util.Dom.get("total_message_count");
			if (message_total)
			{
				message_total.innerHTML = parseInt(message_total.innerHTML) + total;
			}
		}

		// unfocus the qc_submit button to prevent a space from resubmitting
		var submit_btn = YAHOO.util.Dom.get("qr_submit")
		if (submit_btn)
		{
			submit_btn.blur();
		}
	}
	else // no comments found - handle the error
	{
		if (!is_saf)
		{
			this.show_errors(ajax);
			return false;
		}

		// this is the not so nice error handler, which is a fallback in case the previous one doesn't work
		this.repost = true;
		this.form.submit();
	}
}

/**
* Un-hides the quick comment errors element
*
* @param	object	YUI AJAX object
*
* @return	boolean	false
*/
vB_QuickComment.prototype.show_errors = function(ajax)
{
	this.errors_shown = true;

	var error_list = YAHOO.util.Dom.get("qc_error_list");
	while (error_list.hasChildNodes())
	{
		error_list.removeChild(error_list.firstChild);
	}

	// this is the nice error handler, of which Safari makes a mess
	var errors = ajax.responseXML.getElementsByTagName("error");

	var error_html = document.createElement("ol");
	for (var i = 0; i < errors.length; i++)
	{
		var current_error = document.createElement("li");
			current_error.className = "smallfont";
			//current_error.appendChild(document.createTextNode(errors[i].firstChild.nodeValue));
			// Our error phrases can contain html - createTextNode renders that HTML as text
			current_error.innerHTML = errors[i].firstChild.nodeValue;

		error_html.appendChild(current_error);

		console.warn(errors[i].firstChild.nodeValue);
	}

	error_list.appendChild(error_html);

	YAHOO.util.Dom.setStyle("qc_error_div", "display", "");

	this.check_focus();
	return false;
}

/**
* Hides the quick comment comment element
*
* @return	boolean	false
*/
vB_QuickComment.prototype.hide_errors = function()
{
	console.log("Hiding QC Errors");
	if (this.errors_shown)
	{
		this.errors_shown = true;

		YAHOO.util.Dom.setStyle("qc_error_div", "display", "none");

		return false;
	}
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 17991 $
|| ####################################################################
\*======================================================================*/