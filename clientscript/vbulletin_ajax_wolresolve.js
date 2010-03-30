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
* Adds onclick events to appropriate elements for AJAX IP resolving
*
* @param	string	The ID of the table that contains WOL entries with IPs to resolve
*/
function vB_AJAX_WolResolve_Init(woltableid)
{
	if (AJAX_Compatible && (typeof vb_disable_ajax == 'undefined' || vb_disable_ajax < 2))
	{
		var link_list = fetch_tags(fetch_object(woltableid), 'a');
		for (var i = 0; i < link_list.length; i++)
		{
			if (link_list[i].id && link_list[i].id.substr(0, 10) == 'resolveip_' && link_list[i].innerHTML.match(/^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$/))
			{
				// innerHTML is the ip address
				link_list[i].onclick = resolve_ip_click;
			}
		}
	}
}

/**
* Class to handle resolving IP addresses to host names with AJAX
*
* @param	string	The IP to resolve
* @param	string	The ID of the object that the resolved IP will replace
*/
function vB_AJAX_WolResolve(ip, objid)
{
	this.ip = ip;
	this.objid = objid;
}

/**
* Resolves the IP using AJAX
*
* @package	vBulletin
* @version	$Revision: 26385 $
* @date		$Date: 2008-04-22 05:40:28 -0500 (Tue, 22 Apr 2008) $
* @author	Freddie Bingham, vBulletin Development Team
*/
vB_AJAX_WolResolve.prototype.resolve = function()
{
	YAHOO.util.Connect.asyncRequest("POST", 'online.php?do=resolveip&ipaddress=' + PHP.urlencode(this.ip), {
		success: this.handle_ajax_response,
		failure: this.handle_ajax_error,
		timeout: vB_Default_Timeout,
		scope: this
	}, SESSIONURL + 'securitytoken=' + SECURITYTOKEN + '&do=resolveip&ajax=1&ipaddress=' + PHP.urlencode(this.ip));
}

/**
* Handle AJAX Error
*
* @param	object	YUI AJAX
*/
vB_AJAX_WolResolve.prototype.handle_ajax_error = function(ajax)
{
	//TODO: Something bad happened, try again
	vBulletin_AJAX_Error_Handler(ajax);
}

/**
* Handle AJAX request response
*
* @param	object	YUI AJAX
*/
vB_AJAX_WolResolve.prototype.handle_ajax_response = function(ajax)
{
	if (ajax.responseXML)
	{
		var obj = fetch_object(this.objid);
		obj.parentNode.insertBefore(document.createTextNode(ajax.responseXML.getElementsByTagName('ipaddress')[0].firstChild.nodeValue), obj);

		// might need to display the IP still instead of removing it... we'll wait and see.
		obj.parentNode.removeChild(obj);
	}
}

/**
* Handles click events on resolve IP links
*/
function resolve_ip_click(e)
{
	var resolver = new vB_AJAX_WolResolve(this.innerHTML, this.id);
	resolver.resolve();
	return false;
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 26385 $
|| ####################################################################
\*======================================================================*/