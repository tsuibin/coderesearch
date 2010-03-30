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
// vB_AJAX_GroupReadMarker
// #############################################################################

/**
* vBulletin AJAX group read marker class
*
* Allows a group to be marked as read.  Child discussions are considered read by 
* the backend if it's parent group readtime is greater than it's own.
*
* @package	vBulletin
* @version	$Revision: 26385 $
* @date		$Date: 2008-04-22 11:40:28 +0100 (Tue, 22 Apr 2008) $
* @author	Darren Gordon, vBulletin Development Team
*
* @param	integer	Group ID to be marked as read
*/
function vB_AJAX_GroupReadMarker(groupid)
{
	this.groupid = groupid;
};

/**
* Initializes the AJAX request to mark the group as read
*/
vB_AJAX_GroupReadMarker.prototype.mark_read = function()
{
	YAHOO.util.Connect.asyncRequest("POST", 'group.php?do=markread&groupid=' + this.groupid, {
		success: this.handle_ajax_request,
		failure: this.handle_ajax_error,
		timeout: vB_Default_Timeout,
		scope: this
	}, SESSIONURL + 'securitytoken=' + SECURITYTOKEN + '&do=markread&groupid=' + this.groupid);
};

/**
* Handles AJAX Errors
*
* @param	object	YUI AJAX
*/
vB_AJAX_GroupReadMarker.prototype.handle_ajax_error = function(ajax)
{
	// TODO: Something bad happened, try again
	vBulletin_AJAX_Error_Handler(ajax);
};

/**
* Handles the XML response from the AJAX response
*
* Pushes all discussion bits to be displayed as read.
*
* @param	object	YUI AJAX
*/
vB_AJAX_GroupReadMarker.prototype.handle_ajax_request = function(ajax)
{
	if (ajax.responseXML && ajax.responseXML.firstChild)
	{
		// check for error first
		var error = fetch_tags(ajax.responseXML, 'error');
		
		if (error.length)
		{
			alert(error[0].firstChild.nodeValue);
			return;
		}
	}

	var discussion_node = document.getElementById('discussion_list');
	var read_nodes = YAHOO.util.Dom.getElementsByClassName('unread', false, discussion_node);
		
	for (var i = 0; i < read_nodes.length; i++)
	{
		YAHOO.util.Dom.removeClass(read_nodes[i], 'unread');
		
		var goto_unread_nodes = YAHOO.util.Dom.getElementsByClassName('id_goto_unread', 'a', read_nodes[i]);
		
		for (var n = 0; n < goto_unread_nodes.length; n++)
		{
			YAHOO.util.Dom.addClass(goto_unread_nodes[n], 'hidden');
		}
	}
};

// #############################################################################
// Ancilliary functions
// #############################################################################

/**
* Initializes a request to mark a group as read
*
* @param	integer	Group ID to be marked as read
*
* @return	boolean	false
*/
function mark_group_read(groupid)
{
	if (AJAX_Compatible)
	{
		vB_GroupReadMarker = new vB_AJAX_GroupReadMarker(groupid);
		vB_GroupReadMarker.mark_read();
	}
	else
	{
		window.location = 'group.php?' + SESSIONURL + 'do=markread&groupid=' + groupid;
	}

	return false;
};

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 26385 $
|| ####################################################################
\*======================================================================*/