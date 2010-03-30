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
* Initializes the link to fetch/deselect the additional MQ'd posts not in this thread.
*
* @package	vBulletin
* @version	$Revision: 26385 $
* @date		$Date: 2008-04-22 05:40:28 -0500 (Tue, 22 Apr 2008) $
* @author	Mike Sullivan, Kier Darby
*
* @param	string	ID of the editor to add the text to
* @param	integer	The ID of the current thread
*/
function vB_MultiQuote_Loader(editorid, threadid)
{
	this.editorid = editorid;
	this.threadid = threadid;

	YAHOO.util.Event.on("multiquote_more", "click", this.fetch, this, true);

	YAHOO.util.Event.on("multiquote_deselect", "click", this.deselect, this, true);
}

/**
* Init quotes fetch
*
* @param	event
*/
vB_MultiQuote_Loader.prototype.fetch = function(e)
{
	YAHOO.util.Event.stopEvent(e);

	this.handle_unquoted_posts('fetch');
};

/**
* Init posts deselect
*
* @param	event
*/
vB_MultiQuote_Loader.prototype.deselect = function(e)
{
	YAHOO.util.Event.stopEvent(e);

	this.handle_unquoted_posts('deselect');
};

/**
* Handles the unquoted posts for all other threads. Either fetches the contents of the posts, or deselects them
*
* @param	string	Type of data to retrieve: 'fetch' (returns post text) or 'deselect' (returns new value of cookie)
*/
vB_MultiQuote_Loader.prototype.handle_unquoted_posts = function(type)
{
	YAHOO.util.Connect.asyncRequest("POST", "newreply.php?do=unquotedposts&threadid=" + this.threadid, {
		success: this.handle_ajax_unquoted_response,
		failure: this.handle_ajax_error,
		timeout: vB_Default_Timeout,
		scope: this
	}, SESSIONURL
		+ 'securitytoken=' + SECURITYTOKEN
		+ '&do=unquotedposts&threadid=' + this.threadid
		+ '&wysiwyg=' + (vB_Editor[this.editorid].wysiwyg_mode ? 1 : 0)
		+ '&type=' + PHP.urlencode(type)
	);

	return false;
};

/**
* Handles unspecified AJAX errors
*
* @param	object	YUI AJAX
*/
vB_MultiQuote_Loader.prototype.handle_ajax_error = function(ajax)
{
	//TODO: Something bad happened, try again
	vBulletin_AJAX_Error_Handler(ajax);
}

/**
* Handles the returning AJAX request to fetch quotes or deselect posts
*
* @param	object	YUI AJAX
*/
vB_MultiQuote_Loader.prototype.handle_ajax_unquoted_response = function(ajax)
{
	if (ajax.responseXML)
	{
		var quotes = ajax.responseXML.getElementsByTagName('quotes');
		var mqpostids = ajax.responseXML.getElementsByTagName('mqpostids');

		if (quotes.length)
		{
			// insert the text into the editor
			vB_Editor[this.editorid].history.add_snapshot(vB_Editor[this.editorid].get_editor_contents());
			vB_Editor[this.editorid].insert_text(quotes[0].firstChild.nodeValue);
			vB_Editor[this.editorid].collapse_selection_end();
			vB_Editor[this.editorid].history.add_snapshot(vB_Editor[this.editorid].get_editor_contents());

			// change the multiquote empty input to empty the cookie completely
			var multiquote_empty_input = fetch_object('multiquote_empty_input');
			if (multiquote_empty_input)
			{
				multiquote_empty_input.value = 'all';
			}
		}
		else if (mqpostids.length)
		{
			var remaining_mq_posts = '';
			if (mqpostids[0].firstChild)
			{
				remaining_mq_posts = mqpostids[0].firstChild.nodeValue;
			}
			// this returns the new content of the cookie, so use it
			set_cookie('vbulletin_multiquote', remaining_mq_posts);
		}

		// remove the link to insert unquoted posts
		var unquoted_posts = fetch_object('unquoted_posts');
		if (unquoted_posts)
		{
			unquoted_posts.style.display = 'none';
		}
	}
}

// legacy loader
function init_unquoted_posts(editorid, threadid)
{
	// init multiquote manager class
	new vB_MultiQuote_Loader(editorid, threadid);
};

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 26385 $
|| ####################################################################
\*======================================================================*/