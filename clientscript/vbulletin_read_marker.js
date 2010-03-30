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

/**
* Array to store initialized vB_AJAX_ReadMarker objects
*
* @var	array
*/
var vB_ReadMarker = {
	'forum_statusicon_prefix'  : 'forum_statusicon_',
	'thread_statusicon_prefix' : 'thread_statusicon_',
	'thread_gotonew_prefix'    : 'thread_gotonew_',
	'thread_title_prefix'      : 'thread_title_'
};

// #############################################################################
// vB_AJAX_ReadMarker
// #############################################################################

/**
* vBulletin AJAX forum read marker class
*
* Allows a forum, its child forums and all contained threads to be marked as read
*
* @package	vBulletin
* @version	$Revision: 26385 $
* @date		$Date: 2008-04-22 05:40:28 -0500 (Tue, 22 Apr 2008) $
* @author	Kier Darby, vBulletin Development Team
*
* @param	integer	Forum ID to be marked as read
*/
function vB_AJAX_ReadMarker(forumid)
{
	this.forumid = forumid;
};

/**
* Initializes the AJAX request to mark the forum as read
*/
vB_AJAX_ReadMarker.prototype.mark_read = function()
{
	YAHOO.util.Connect.asyncRequest("POST", 'ajax.php?do=markread&f=' + this.forumid, {
		success: this.handle_ajax_request,
		failure: this.handle_ajax_error,
		timeout: vB_Default_Timeout,
		scope: this
	}, SESSIONURL + 'securitytoken=' + SECURITYTOKEN + '&do=markread&forumid=' + this.forumid);
};

/**
* Handles AJAX Errors
*
* @param	object	YUI AJAX
*/
vB_AJAX_ReadMarker.prototype.handle_ajax_error = function(ajax)
{
	//TODO: Something bad happened, try again
	vBulletin_AJAX_Error_Handler(ajax);
};

/**
* Handles the XML response from the AJAX response
*
* Passes forum IDs in XML to handler functions
*
* @param	object	YUI AJAX
*/
vB_AJAX_ReadMarker.prototype.handle_ajax_request = function(ajax)
{
	var forum_nodes = fetch_tags(ajax.responseXML, 'forum');
	for (var i = 0; i < forum_nodes.length; i++)
	{
		var forumid = forum_nodes[i].firstChild.nodeValue;
		this.update_forum_status(forumid);

		var threadbits_object = fetch_object('threadbits_forum_' + forumid);
		if (threadbits_object)
		{
			this.handle_threadbits(threadbits_object);
		}
	}
};

/**
* Updates the status of a 'forumbit*' template
*
* @param	integer	Forum ID
*/
vB_AJAX_ReadMarker.prototype.update_forum_status = function(forumid)
{
	var imageobj = fetch_object(vB_ReadMarker['forum_statusicon_prefix'] + forumid);
	if (imageobj)
	{
		imageobj.style.cursor = 'default';
		imageobj.title = imageobj.otitle;
		imageobj.src = this.fetch_old_src(imageobj.src, 'forum');
	}
};

/**
* Scans the provided object for gotonew links in threads
*
* @param	object	HTML object containing 'threadbit*' templates
*/
vB_AJAX_ReadMarker.prototype.handle_threadbits = function(threadbits_object)
{
	var links = fetch_tags(threadbits_object, 'a');
	for (var i = 0; i < links.length; i++)
	{
		if (links[i].id && links[i].id.substr(0, vB_ReadMarker['thread_gotonew_prefix'].length) == vB_ReadMarker['thread_gotonew_prefix'])
		{
			this.update_thread_status(links[i].id.substr(vB_ReadMarker['thread_gotonew_prefix'].length));
		}
	}
};

/**
* Updates the status of a 'threadbit*' template
*
* @param	integer	Thread ID
*/
vB_AJAX_ReadMarker.prototype.update_thread_status = function(threadid)
{
	var statusicon = fetch_object(vB_ReadMarker['thread_statusicon_prefix'] + threadid);
	if (statusicon)
	{
		statusicon.src = this.fetch_old_src(statusicon.src, 'thread');
	}

	var gotonew = fetch_object(vB_ReadMarker['thread_gotonew_prefix'] + threadid);
	if (gotonew)
	{
		gotonew.parentNode.removeChild(gotonew);
	}

	var threadtitle = fetch_object(vB_ReadMarker['thread_title_prefix'] + threadid);
	if (threadtitle)
	{
		threadtitle.style.fontWeight = 'normal';
	}
};

/**
* Converts an image source from x_new.y to the appropriate x_old.y format
*
* @param	string	Original image source
* @param	string	Type ('forum' or 'thread')
*
* @return	string	New image source
*/
vB_AJAX_ReadMarker.prototype.fetch_old_src = function(newsrc, type)
{
	var foo = newsrc.replace(/_(new)([\._])(.+)$/i, (type == 'thread' ? '$2$3' : '_old$2$3'));
	return foo;
};

// #############################################################################
// Ancilliary functions
// #############################################################################

/**
* Initializes a request to mark a forum and its children as read
*
* @param	integer	Forum ID to be marked as read
*
* @return	boolean	false
*/
function mark_forum_read(forumid)
{
	if (AJAX_Compatible)
	{
		vB_ReadMarker[forumid] = new vB_AJAX_ReadMarker(forumid);
		vB_ReadMarker[forumid].mark_read();
	}
	else
	{
		window.location = 'forumdisplay.php?' + SESSIONURL + 'do=markread&forumid=' + forumid;
	}

	return false;
};

/**
* Translates the ID of a scanned object into a forum ID and passes it to mark_forum_read()
*
* @param	event
*/
function init_forum_readmarker_icon(e)
{
	mark_forum_read(this.id.substr(vB_ReadMarker['forum_statusicon_prefix'].length));
};

/**
* Scans images on a page for forum status icons indicating that they contain new posts
* then initializes them to activate the read marking system on double-click
*/
function init_forum_readmarker_system()
{
	var images = fetch_tags(document, 'img');
	for (var i = 0; i < images.length; i++)
	{
		if (images[i].id && images[i].id.substr(0, vB_ReadMarker['forum_statusicon_prefix'].length) == vB_ReadMarker['forum_statusicon_prefix'])
		{
			if (images[i].src.search(/\/([^\/]+)(new)(_lock)?\.([a-z0-9]+)$/i) != -1)
			{
				img_alt_2_title(images[i]);
				images[i].otitle = images[i].title;
				images[i].title = vbphrase['doubleclick_forum_markread'];
				images[i].style.cursor = pointer_cursor;
				images[i].ondblclick = init_forum_readmarker_icon;
			}
		}
	}
};

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 26385 $
|| ####################################################################
\*======================================================================*/