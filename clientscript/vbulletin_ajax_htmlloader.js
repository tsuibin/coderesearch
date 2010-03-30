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
* Replaces the innerHTML of the element having the given containerid with a html ajax response.
* An optional id can be specified for an element to be display during the request, ie for
* progress indication.
*
* @param string containerid						- The id of the container to update
* @param string getrequest						- The URL to post the request to
* @param string postrequest						- Additional post data in GET form
* @param string progresselementid				- Id of an optional progress indicator
*
* @return	boolean	False
*/
function load_html(containerid, getrequest, postrequest, progresselementid, triggerevent)
{
	if (AJAX_Compatible)
	{
		vB_HtmlLoader = new vB_AJAX_HtmlLoader(containerid, getrequest, postrequest, progresselementid, triggerevent);
		vB_HtmlLoader.load();
	}

	return false;
};

// #############################################################################
// vB_AJAX_HtmlLoader
// #############################################################################

var vB_HtmlLoader = false;

/**
* Basic AJAX html response handler
*
* @package	vBulletin
* @version	$Revision: 24798 $
* @date		$Date: 2008-11-10 15:36:49 +0000 (Mon, 10 Nov 2008) $
* @author	Darren Gordon, vBulletin Development Team
* @copyright	Jelsoft Enterprises Ltd.
*/
function vB_AJAX_HtmlLoader(containerid, getrequest, postrequest, progresselementid, triggerevent)
{
	this.getrequest = getrequest;
	this.container = fetch_object(containerid);
	this.postrequest = postrequest;
	this.progresselement = fetch_object(progresselementid);
	this.triggerevent = triggerevent;
};

/**
* Initiates the AJAX request
*/
vB_AJAX_HtmlLoader.prototype.load = function()
{
	if (this.progresselement)
	{
		this.progresselement.style.display = '';
	}

	if (this.container)
	{
		YAHOO.util.Connect.asyncRequest("POST", this.getrequest, {
			success: this.display,
			failure: this.handle_ajax_error,
			timeout: vB_Default_Timeout,
			scope: this
		}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&ajax=1");
	}

	return false;
};

/**
* Handles AJAX Errors
*
* @param	object	YUI AJAX
*/
vB_AJAX_HtmlLoader.prototype.handle_ajax_error = function(ajax)
{
	if(this.progresselement)
	{
		this.progresselement.style.display = 'none';
	}

	//TODO: Something bad happened, try again
	vBulletin_AJAX_Error_Handler(ajax);
};

/**
* Takes the AJAX HTML output and replaces the existing container with the new HTML
*
* @param	object	YUI AJAX
*/
vB_AJAX_HtmlLoader.prototype.display = function(ajax)
{
	if(this.progresselement)
	{
		this.progresselement.style.display = 'none';
	}

	if (ajax.responseXML)
	{
		var html = ajax.responseXML.getElementsByTagName("html");
		var error = ajax.responseXML.getElementsByTagName("error");

		if (html.length)
		{
			this.container.innerHTML = html[0].firstChild.nodeValue;
		}
	}

	// Trigger any attached event functions
	if (this.triggerevent)
	{
		this.triggerevent();
	}
};

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 26385 $
|| ####################################################################
\*======================================================================*/