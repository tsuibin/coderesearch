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
// vB_AJAX_ImageReg
// call using:
// vBulletin.register_control("vB_AJAX_ImageReg")
// #############################################################################

/**
* vBulletin image verification reloader
*/
function vB_AJAX_ImageReg()
{
	this.init();
}

/**
* Adds events to the controls
*/
vB_AJAX_ImageReg.prototype.init = function()
{
	if (AJAX_Compatible && (typeof vb_disable_ajax == 'undefined' || vb_disable_ajax < 2) && YAHOO.util.Dom.get("refresh_imagereg"))
	{
		YAHOO.util.Event.on("refresh_imagereg", "click", this.fetch_image, this, true);
		YAHOO.util.Dom.setStyle("refresh_imagereg", "cursor", pointer_cursor);
		YAHOO.util.Dom.setStyle("refresh_imagereg", "display", "");

		YAHOO.util.Event.on("imagereg", "click", this.fetch_image, this, true);
		YAHOO.util.Dom.setStyle("imagereg", "cursor", pointer_cursor);
	}
}

/**
* Requests a new hash
*
* @param	event
*/
vB_AJAX_ImageReg.prototype.fetch_image = function(e)
{
	YAHOO.util.Event.stopEvent(e);

	YAHOO.util.Dom.setStyle("progress_imagereg", "display", "");

	YAHOO.util.Connect.asyncRequest("POST", "ajax.php?do=imagereg", {
		success: this.handle_ajax_response,
		failure: this.handle_ajax_error,
		timeout: vB_Default_Timeout,
		scope: this
	}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&do=imagereg&hash=" + YAHOO.util.Dom.get("hash").getAttribute("value"));

	return false;
};

/**
* Handles AJAX Errors
*
* @param	object	YUI AJAX
*/
vB_AJAX_ImageReg.prototype.handle_ajax_error = function(ajax)
{
	//TODO: Something bad happened, try again
	vBulletin_AJAX_Error_Handler(ajax);
};

/**
* Receives the AJAX responseXML and updates the page
*
* @param	object	AJAX object from YAHOO.util.Connect
*/
vB_AJAX_ImageReg.prototype.handle_ajax_response = function(ajax)
{
	YAHOO.util.Dom.setStyle("progress_imagereg", "display", "none");

	if (ajax.responseXML)
	{
		// check for error
		var error = ajax.responseXML.getElementsByTagName("error");
		if (error.length)
		{
			alert(error[0].firstChild.nodeValue);
		}
		else
		{
			var hash = ajax.responseXML.getElementsByTagName("hash")[0].firstChild.nodeValue;
			if (hash)
			{
				YAHOO.util.Dom.get("hash").setAttribute("value", hash);
				YAHOO.util.Dom.get("imagereg").setAttribute("src", "image.php?" + SESSIONURL + "type=hv&hash=" + hash);
			}
		}
	}
}

// #############################################################################

/**
* Legacy init for vB_AJAX_ImageReg
*/
function vB_AJAX_ImageReg_Init()
{
	new vB_AJAX_ImageReg();
}


/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 26385 $
|| ####################################################################
\*======================================================================*/