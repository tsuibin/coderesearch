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
// vB_AJAX_NameVerify
// #############################################################################

/**
* Class to read input and verify usernames from the typed fragment
*
* @package	vBulletin
* @version	$Revision: 29004 $
* @date		$Date: 2009-01-05 06:11:27 -0600 (Mon, 05 Jan 2009) $
* @author	Andy Huang
* @copyright	Jelsoft Enterprises Ltd.
*
* @param	string	Name of variable instantiating this class
* @param	string	ID of the text input element to monitor
*/
function vB_AJAX_NameVerify(varname, textobjid)
{
	var webkit_version = userAgent.match(/applewebkit\/([0-9]+)/);

	if (AJAX_Compatible && !(is_saf && !(webkit_version[1] >= 412)))
	{
		this.textobj = fetch_object(textobjid);
		this.textobj.setAttribute("autocomplete", "off");
		this.textobj.obj = this;

		/**
		* Varaiables used by this class
		*
		* @var	string	The name given to the instance of this class
		* @var	string	The current name fragment text
		* @var	object	A javascript timeout marker
		* @var	object	YUI AJAX Transaction
		*/
		this.varname = varname;
		this.fragment = '';
		this.timeout = null;
		this.ajax_req = null;

		// =============================================================================
		// vB_AJAX_NameVerify methods

		/**
		* Reads the contents of the text input box
		*/
		this.get_text = function()
		{
			this.fragment = new String(this.textobj.value);

			// trim away leading and trailing spaces from the fragment
			this.fragment = PHP.trim(this.fragment);
		}

		/**
		* Event handler for the text input box key-up event
		*
		* @param	event	The event object
		*/
		this.key_event_handler = function(evt)
		{
			// create the fragment
			this.get_text();

			clearTimeout(this.timeout);
			this.timeout = setTimeout(this.varname + '.name_verify();', 500);
		}

		/**
		* Sends the fragment to search the database
		*/
		this.name_verify = function()
		{
			if (YAHOO.util.Connect.isCallInProgress(this.ajax_req))
			{
				YAHOO.util.Connect.abort(this.ajax_req);
			}

			this.ajax_req = YAHOO.util.Connect.asyncRequest("POST", "ajax.php?do=verifyusername", {
				success: this.handle_ajax_request,
				failure: vBulletin_AJAX_Error_Handler,
				timeout: vB_Default_Timeout,
				scope: this
			}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&do=verifyusername&username=" + PHP.urlencode(this.fragment));
		}

		/**
		* Handles AJAX response
		*
		* @param	object	YUI AJAX
		*/
		this.handle_ajax_request = function(ajax)
		{
			if (ajax.responseXML && (ajax.responseXML.getElementsByTagName("status").length > 0))
			{
				// we have at least one status tag (hopefully proper xml) in our response
				var status	= ajax.responseXML.getElementsByTagName("status")[0].firstChild.nodeValue;
				var image	= ajax.responseXML.getElementsByTagName("image")[0].firstChild.nodeValue;
				var message	= ajax.responseXML.getElementsByTagName("message")[0].firstChild.nodeValue;

				var nodeDiv	= document.getElementById("reg_verif_div");
				var nodeImage = document.getElementById("reg_verif_image");

				nodeImage.src = image;
				nodeImage.style.display = "inline";
				if (status == "valid")
				{
					nodeDiv.style.display = "block";
					nodeDiv.className = "greenbox";
				}
				else
				{
					nodeDiv.style.display = "block";
					nodeDiv.className = "redbox";
				}
				nodeDiv.innerHTML = message;
			}
		}

		this.textobj.onkeyup = function(e) { return this.obj.key_event_handler(e); };
	}
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 29004 $
|| ####################################################################
\*======================================================================*/