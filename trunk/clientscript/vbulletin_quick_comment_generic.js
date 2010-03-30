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

// #############################################################################
// vB_QuickComment_GenericMessage - Demonstration class for class overriding
// #############################################################################

/**
* Quick Comment Class for Visitor Messaging, Picture Commenting - extension of vB_QuickComment
* Handles specifics of what to do with data returned from Ajax
*
* @package	vBulletin
* @version	$Revision: 24798 $
* @date		$Date: 2007-11-22 13:59:49 +0000 (Thu, 22 Nov 2007) $
* @author	Freddie Bingham, Kier Darby, vBulletin Development Team
* @copyright	Jelsoft Enterprises Ltd.
*
* @param	string	Form name that contains the controls
* @param	string	Minimum allowed characters
* @param	string	Are the returning posts ordered in asc or desc order?
*/
function vB_QuickComment_GenericMessage(formid, minchars, returnorder)
{
	vB_QuickComment_GenericMessage.baseConstructor.call(this, formid, minchars, returnorder);
	this.id = this;
}

vBulletin.extend(vB_QuickComment_GenericMessage, vB_QuickComment);

/**
* Handles quick comment data when AJAX says qc_ajax_post() is complete
*/
vB_QuickComment_GenericMessage.prototype.post_save = function(ajax)
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

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 17991 $
|| ####################################################################
\*======================================================================*/
