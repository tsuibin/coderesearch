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

vBulletin.events.systemInit.subscribe(function()
{
	if (AJAX_Compatible)
	{
		new vB_ProfilefieldEditor_Factory();
	}
});

/*
Elements to use this system should have the following class name format:
vB_ProfilefieldEditor[profilefieldid||pageuserid||bbuserid||element_to_contain_button_id]

In MEMBERINFO, include YUI framework (dom-event and connection), and include this file
In memberinfo_customfields, include this in class="..." for the field value element:
	vB_ProfilefieldEditor[$profilefield[profilefieldid]||$userinfo[userid]||$bbuserinfo[userid]||userfield_title_$profilefield[profilefieldid]]
*/


// =============================================================================

/**
* Factory to build userfield editor objects
*
* @package	vBulletin
* @version	$Revision: 24798 $
* @date		$Date: 2007-11-22 13:59:49 +0000 (Thu, 22 Nov 2007) $
* @author	Kier Darby, Mike Sullivan, vBulletin Development Team
* @copyright	Jelsoft Enterprises Ltd.
*/
function vB_ProfilefieldEditor_Factory()
{
	this.controls = new Array();
	this.open_fieldid = null;
	this.loading = false;

	this.init();
};

/**
* Initialises the system
*/
vB_ProfilefieldEditor_Factory.prototype.init = function()
{
	this.control_image = new Image();
	this.control_image.src = IMGDIR_MISC + "/userfield_edit.gif";

	var fieldid;

	if (vBulletin.elements["vB_ProfilefieldEditor"])
	{
		for (var i = 0; i < vBulletin.elements["vB_ProfilefieldEditor"].length; i++)
		{
			fieldid = vBulletin.elements["vB_ProfilefieldEditor"][i];

			this.controls[fieldid] = new vB_ProfilefieldEditor(fieldid, this);
		}
		vBulletin.elements["vB_ProfilefieldEditor"] = null;
	}

	this.progress_image = new Image();
	this.progress_image.src = IMGDIR_MISC + "/11x11progress.gif";
};

/**
* Deactivates all controls
*/
vB_ProfilefieldEditor_Factory.prototype.close_all = function()
{
	if (this.open_fieldid)
	{
		// close identified active menu
		this.controls[this.open_fieldid].deactivate();
	}
};

/**
* Records the name of the currently-active userfield
*/
vB_ProfilefieldEditor_Factory.prototype.set_open_fieldid = function(value)
{
	console.log("set_open_fieldid(%s)", value);
	this.open_fieldid = value;
};

// #############################################################################

/**
* Creates a single editable userfield value
*
* @package	vBulletin
* @version	$Revision: 24798 $
* @date		$Date: 2007-11-22 13:59:49 +0000 (Thu, 22 Nov 2007) $
* @author	Kier Darby, Mike Sullivan, vBulletin Development Team
*
* @param	string	Fieldid of the userfield to be edited
* @param	vB_ProfilefieldEditor_Factory	Controlling factory class
*/
function vB_ProfilefieldEditor(fieldid, factory)
{
	this.element = YAHOO.util.Dom.get("profilefield_value_" + fieldid);
	this.control_parent = YAHOO.util.Dom.get("profilefield_title_" + fieldid);
	this.fieldid = fieldid;
	this.factory = factory;

	this.value = this.element.innerHTML;

	// create button
	if (this.control_parent)
	{
		this.control = this.control_parent.appendChild(document.createElement("a"));
		this.control.href = "#";
		this.control_image = this.control.appendChild(document.createElement("img"));
		this.control_image.src = this.factory.control_image.src;
		this.control_image.border = 0;
		this.control_image.hspace = 6;
		this.control_image.alt = vbphrase["edit_value"];
		this.control_image.title = vbphrase["edit_value"];
		YAHOO.util.Event.on(this.control, "click", this.activate, this, true);
	}
}

/**
* Unregisters the editability of this entry.
*/
vB_ProfilefieldEditor.prototype.unregister = function()
{
	if (this.control)
	{
		this.control.parentNode.removeChild(this.control);
	}

	this.deactivate();
}

/**
* Activates the controls
*
* @param	event	Event object
*/
vB_ProfilefieldEditor.prototype.activate = function(e)
{
	YAHOO.util.Event.stopEvent(e);

	if (this.factory.open_fieldid == this.fieldid)
	{
		console.log("This field (%s) is already open", this.fieldid);
		return false;
	}
	else if (this.factory.loading)
	{
		console.log("Loading already in progress...");
		return false;
	}

	this.factory.close_all();

	if (this.control_parent)
	{
		this.control_image.src = this.factory.progress_image.src;
	}

	this.value = this.element.innerHTML;

	this.factory.loading = true;

	YAHOO.util.Connect.asyncRequest("POST", "ajax.php", {
		success: this.show_controls,
		failure: this.request_timeout,
		timeout: vB_Default_Timeout,
		scope: this
	}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&do=fetchuserfield&fieldid=" + PHP.urlencode(this.fieldid));

	return false;
}

/**
* Reads the editor template from AJAX request and shows the controls
*
* @param	AJAX	YUI AJAX object from activate()
*/
vB_ProfilefieldEditor.prototype.show_controls = function(ajax)
{
	this.factory.loading = false;

	var error = ajax.responseXML.getElementsByTagName("error");
	if (error[0])
	{
		alert(error[0].firstChild.nodeValue);
		this.deactivate();
	}
	else
	{
		this.factory.set_open_fieldid(this.fieldid);

		if (this.control_parent)
		{
			this.control_image.src = this.factory.control_image.src;
		}

		this.element.innerHTML = ajax.responseXML.getElementsByTagName("template")[0].firstChild.nodeValue;

		this.form = this.element.getElementsByTagName("form")[0];

		YAHOO.util.Event.on(this.form, "submit", this.save, this, true);
		YAHOO.util.Event.on(this.form, "reset", this.deactivate, this, true);

		for (var i = 0; i < this.form.elements.length; i++)
		{
			if (this.form.elements[i].tagName == "INPUT" || this.form.elements[i].tagName == "SELECT" || this.form.elements[i].tagName == "TEXTAREA")
			{
				this.form.elements[i].focus();
				break;
			}
		}
	}

	if (ajax.responseXML.getElementsByTagName("uneditable")[0])
	{
		this.unregister();
	}
}

/**
* Initializes the save mechanism
*
* @param	event	Event object
*/
vB_ProfilefieldEditor.prototype.save = function(e)
{
	YAHOO.util.Event.stopEvent(e);

	if (YAHOO.util.Dom.get('field_edit_progress'))
	{
		YAHOO.util.Dom.get('field_edit_progress').style.display = '';
	}
	else if (this.control_parent)
	{
		this.control_image.src = this.factory.progress_image.src;
	}

	var hidden_form = new vB_Hidden_Form(null);
	hidden_form.add_variables_from_object(this.element);

	YAHOO.util.Connect.asyncRequest("POST", "ajax.php", {
		success: this.post_save,
		failure: this.request_timeout,
		timeout: vB_Default_Timeout,
		scope: this
	}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&do=saveuserfield&fieldid=" + this.fieldid + "&" + hidden_form.build_query_string());
}

/**
* Handles the result of the AJAX save
*
* @param	AJAX	YUI AJAX object from save()
*/
vB_ProfilefieldEditor.prototype.post_save = function(ajax)
{
	var error = ajax.responseXML.getElementsByTagName("error");
	if (error[0])
	{
		this.reset_progress();

		if (YAHOO.util.Dom.get('field_edit_error_container'))
		{
			YAHOO.util.Dom.get('field_edit_error_container').style.display = '';
			YAHOO.util.Dom.get('field_edit_errors').innerHTML = error[0].firstChild.nodeValue;
		}
	}
	else
	{
		this.value = ajax.responseXML.getElementsByTagName("value")[0].firstChild.nodeValue;
		this.deactivate();
	}

	if (ajax.responseXML.getElementsByTagName("uneditable")[0])
	{
		this.unregister();
	}
}

/**
* Resets any progress indicators to their initial (no pending action) states.
*/
vB_ProfilefieldEditor.prototype.reset_progress = function()
{
	if (this.control_image)
	{
		this.control_image.src = this.factory.control_image.src;
	}

	if (YAHOO.util.Dom.get('field_edit_progress'))
	{
		YAHOO.util.Dom.get('field_edit_progress').style.display = 'none';
	}
}

/**
* Deactivates a control without saving
*/
vB_ProfilefieldEditor.prototype.deactivate = function()
{
	this.reset_progress();
	this.element.innerHTML = this.value;
	this.factory.set_open_fieldid(null);
}

/**
* Handles timeout errors
*/
vB_ProfilefieldEditor.prototype.request_timeout = function(ajax)
{
	vBulletin_AJAX_Error_Handler(ajax);
	alert(vbphrase['server_failed_respond_try_again']);
	this.deactivate();
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision$
|| ####################################################################
\*======================================================================*/