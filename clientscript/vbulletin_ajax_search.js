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
* Adds onclick event to the save search prefs buttons
*
* @param	string	The ID of the button that fires the search prefs
*/
function vB_AJAX_SearchPrefs_Init(buttonid)
{
	if (AJAX_Compatible && (typeof vb_disable_ajax == 'undefined' || vb_disable_ajax < 2) && fetch_object(buttonid))
	{
		// prevent the form from submitting when clicking the submit button
		var sbutton = fetch_object(buttonid);
		sbutton.onclick = vB_AJAX_SearchPrefs.prototype.form_click;
	}
};

/**
* Class to handle saving search prefs
*
* @package	vBulletin
* @version	$Revision: 26385 $
* @date		$Date: 2008-04-22 05:40:28 -0500 (Tue, 22 Apr 2008) $
* @author	vBulletin Development Team
*
* @param	object	The form object containing the search options
*/
function vB_AJAX_SearchPrefs(formobj)
{
	// vB_Hidden_Form object to handle form variables
	this.pseudoform = new vB_Hidden_Form('search.php');
	this.pseudoform.add_variable('ajax', 1);
	this.pseudoform.add_variable('doprefs', 1);
	this.pseudoform.add_variables_from_object(formobj);
};

/**
* Handles AJAX request response
*
* @param	object	YUI AJAX
*/
vB_AJAX_SearchPrefs.prototype.handle_ajax_response = function(ajax)
{
	if (ajax.responseXML)
	{
		// check for error first
		var error = ajax.responseXML.getElementsByTagName('error');
		if (error.length)
		{
			alert(error[0].firstChild.nodeValue);
		}
		else
		{
			var message = ajax.responseXML.getElementsByTagName('message');
			if (message.length)
			{
				alert(message[0].firstChild.nodeValue);
			}
		}
	}
}

/**
* Submits the form via Ajax
*/
vB_AJAX_SearchPrefs.prototype.submit = function()
{
	YAHOO.util.Connect.asyncRequest("POST", "search.php", {
		success: this.handle_ajax_response,
		failure: this.handle_ajax_error,
		timeout: vB_Default_Timeout,
		scope: this
	}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&" + this.pseudoform.build_query_string());
};

/**
* Fallback - submits the form normally
*/
vB_AJAX_SearchPrefs.prototype.handle_ajax_error = function(ajax)
{
	vBulletin_AJAX_Error_Handler(ajax);

	this.pseudoform.submit_form();
}

/**
* Handles the form 'submit' action
*/
vB_AJAX_SearchPrefs.prototype.form_click = function()
{
	var AJAX_SearchPrefs = new vB_AJAX_SearchPrefs(this.form);
	AJAX_SearchPrefs.submit();
	return false;
};

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 26385 $
|| ####################################################################
\*======================================================================*/