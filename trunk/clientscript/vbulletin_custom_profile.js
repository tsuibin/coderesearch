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

// CSS preview object - basically a singleton
var csspreview;

vBulletin.events.systemInit.subscribe(function()
{
	// setup the clear all button
	var clear = YAHOO.util.Dom.get("clear_all_button");
	if (clear)
	{
		YAHOO.util.Event.on(clear, "click",  clear_css_customizations);
	}

	// enable the preview button
	if (vBulletin.elements["vB_UserCSSPreview"])
	{
		var buttonid;
		for (var i = 0; i < vBulletin.elements["vB_UserCSSPreview"].length; i++)
		{
			buttonid = vBulletin.elements["vB_UserCSSPreview"][i][0];

			YAHOO.util.Dom.get(buttonid).style.display = '';
			YAHOO.util.Event.on(buttonid, "click", preview_css_customizations);
		}
		vBulletin.elements["vB_ProfilefieldEditor"] = null;
	}
});

/**
* Event to handle clicks of the "preview" button and setup the handler.
*/
function preview_css_customizations()
{
	if (!csspreview)
	{
		csspreview = new vB_AJAX_CSSPreview();
	}

	csspreview.move_preview(this.parentNode);
	csspreview.fetch_preview(this.form);
}

/**
* CSS Preview object.
*/
function vB_AJAX_CSSPreview()
{
	this.progress = 'preview_progress';
	this.preview_area = 'usercss_example';
}

/**
* Move the CSS preview to be a child of the specified node's parent.
*
* @param	Node to add along side
*/
vB_AJAX_CSSPreview.prototype.move_preview = function(previous_node)
{
	previous_node.parentNode.appendChild(YAHOO.util.Dom.get(this.preview_area));
}

/**
* Submit the preview and fetch the results via AJAX
*
* @param	The form to submit
*/
vB_AJAX_CSSPreview.prototype.fetch_preview = function(form)
{
	this.form = form;

	var psuedoform = new vB_Hidden_Form(this.form.action);
	psuedoform.add_variable('ajax', 1);
	psuedoform.add_variables_from_object(this.form);

	this.ajax_request = YAHOO.util.Connect.asyncRequest("POST", this.form.action, {
		success: this.handle_ajax_response,
		failure: this.handle_ajax_failure,
		timeout: vB_Default_Timeout,
		scope: this
	}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&" + psuedoform.build_query_string());

	YAHOO.util.Dom.get(this.progress).style.display = '';
}

/**
* Handle the AJAX response. Update the CSS to reflect the new values.
*/
vB_AJAX_CSSPreview.prototype.handle_ajax_response = function(ajax)
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
			var csstext = '';

			var cssnodes = ajax.responseXML.getElementsByTagName('css');
			if (cssnodes.length && cssnodes[0].firstChild)
			{
				csstext = cssnodes[0].firstChild.nodeValue;
			}

			var styletag = YAHOO.util.Dom.get("vbulletin_user_css");
			if (styletag)
			{
				styletag.parentNode.removeChild(styletag);
			}

			var style = document.createElement('style');
			style.type = "text/css";
			style.id = "vbulletin_user_css";

			if (style.styleSheet)
			{
				//alert(style.styleSheet);
				style.styleSheet.cssText = csstext;
			}
			else
			{
				var csstextnode = document.createTextNode(csstext);
				style.appendChild(csstextnode);
			}

			document.getElementsByTagName('head')[0].appendChild(style);
		}
	}

	YAHOO.util.Dom.get(this.progress).style.display = 'none';
}

/**
* Handle AJAX failure - as of now, do nothing.
*/
vB_AJAX_CSSPreview.prototype.handle_ajax_failure = function(ajax)
{
}

/**
* General function to clear all customizations.
*/
function clear_css_customizations()
{
	var i, f, elements;
	var fieldsets = YAHOO.util.Dom.get("usercss_editor").getElementsByTagName("fieldset");
	for (f = 0; f < fieldsets.length; f++)
	{
		elements = fieldsets[f].getElementsByTagName("input");
		for (i = 0; i < elements.length; i++)
		{
			if (elements[i].type == "text" && elements[i].value != "")
			{
				elements[i].focus();
				elements[i].value = "";
				if (YAHOO.util.Dom.hasClass(elements[i], "pickerinput"))
				{
					console.log("Updating preview for %s", elements[i].id);
					update_color_preview(elements[i].id);
				}
			}
		}

		elements = fieldsets[f].getElementsByTagName("select");
		for (i = 0; i < elements.length; i++)
		{
			if (elements[i].selectedIndex != 0)
			{
				elements[i].focus();
				elements[i].selectedIndex = 0;
			}
		}
	}

	YAHOO.util.Dom.get("usercss_editor").scrollIntoView();
}

/**
* Jump to the error of a specific selector and property
*/
function goto_css_error(selector, property)
{
	var element = YAHOO.util.Dom.get("usercss_" + selector + "_" + property);
	if (element)
	{
		element.scrollIntoView();
		element.focus();
		element.select();
		return false;
	}
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 15175 $
|| ####################################################################
\*======================================================================*/