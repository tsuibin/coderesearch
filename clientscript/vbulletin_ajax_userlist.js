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

var vB_UserList_Highlighters = new Object();
var vB_UserList_Filters = new Object();

// #############################################################################

vBulletin.events.systemInit.subscribe(function()
{
	var i, elementid = null, element = null;

	// activate highlighters
	if (vBulletin.elements["vB_UserList_Highlighter"])
	{
		for (i = 0; i < vBulletin.elements["vB_UserList_Highlighter"].length; i++)
		{
			elementid = vBulletin.elements["vB_UserList_Highlighter"][i][0]
			vB_UserList_Highlighters[elementid] = new vB_UserList_Highlighter(elementid);
		}
		vBulletin.elements["vB_UserList_Highlighter"] = null;
	}

	// activate savers
	if (vBulletin.elements["vB_UserList_Saver"])
	{
		for (i = 0; i < vBulletin.elements["vB_UserList_Saver"].length; i++)
		{
			new vB_UserList_Saver(vBulletin.elements["vB_UserList_Saver"][i][0]);
		}
		vBulletin.elements["vB_UserList_Saver"] = null;
	}

	// activate filter objects
	if (vBulletin.elements["vB_UserList_Filter"])
	{
		for (i = 0; i < vBulletin.elements["vB_UserList_Filter"].length; i++)
		{
			element = vBulletin.elements["vB_UserList_Filter"][i];
			vB_UserList_Filters[i] = new vB_UserList_Filter(element[0], element[1], element[2]);
		}

		vBulletin.elements["vB_UserList_Filter"] = null;
	}
});

// #############################################################################

/**
* Class to save the userlist (friends/buddies/ignore) via AJAX
*
* @package	vBulletin
* @version	$Revision: 28428 $
* @date		$Date: 2008-11-17 07:46:28 -0600 (Mon, 17 Nov 2008) $
* @author	Kier Darby
*
* @param	string	Shared prefix of HTML elements relating to the system
*/
function vB_UserList_Saver(prefix)
{
	this.ajax_request = null;

	this.prefix = prefix;

	this.change_form = YAHOO.util.Dom.get(this.prefix + "_change_form");
	YAHOO.util.Event.on(this.change_form, "submit", this.handle_form_submit, this, true);

	this.add_form = YAHOO.util.Dom.get(this.prefix + "_add_form");
	YAHOO.util.Event.on(this.add_form, "submit", this.handle_form_submit, this, true);
}

/**
* Intercepts the submit event of the containing form and redirects using AJAX
*
* @param	event
*/
vB_UserList_Saver.prototype.handle_form_submit = function(e)
{
	YAHOO.util.Event.stopEvent(e);

	var form = YAHOO.util.Event.getTarget(e);
	if (form.tagName != "FORM")
	{
		form = form.form;
	}

	var targetlist = null;
	var prompttype = null;
	var radiobutton = YAHOO.util.Dom.get("incomingaction_reject");
	if (form.userlist.value == "buddy")
	{
		targetlist = "buddylist";
		prompttype = false;
	}
	else if (form.userlist.value == "incoming" && radiobutton.checked == true)
	{
		targetlist = "incomingreqs";
		prompttype = true;
	}

	if (targetlist && form.id.match(/_change_form$/))
	{
		for (var i = 0; i < vB_UserList_Highlighters[targetlist].items.length; i++)
		{

			if (targetlist == "buddylist")
			{
				if (vB_UserList_Highlighters[targetlist].items[i].origfriend == true && vB_UserList_Highlighters[targetlist].items[i].friendcheck.checked == false)
				{
					if (!confirm(vbphrase["remove_from_userlist_confirm"]))
					{
						return false;
					}
					break;
				}
			}

			if (vB_UserList_Highlighters[targetlist].items[i].usercheck.checked == prompttype)
			{
				if (!confirm(vbphrase["remove_from_userlist_confirm"]))
				{
					return false;
				}
				break;
			}
		}
	}

	var progress_image_id = form.id.replace(/_form$/, "_progress");
	YAHOO.util.Dom.setStyle(progress_image_id, "display", "");

	var psuedoform = new vB_Hidden_Form(form.action);

	if (YAHOO.util.Connect._submitElementValue && YAHOO.util.Connect._submitElementValue.match(/^makefriends=/))
	{
		psuedoform.add_variable('makefriends', 1);
	}
	psuedoform.add_variable('ajax', 1);
	psuedoform.add_variables_from_object(form);

	this.ajax_request = YAHOO.util.Connect.asyncRequest("POST", form.action, {
		success: this.handle_ajax_response,
		failure: this.handle_ajax_failure,
		timeout: vB_Default_Timeout,
		scope: this,
		argument: [progress_image_id, form.id]
	}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&" + psuedoform.build_query_string());
}

/**
* Handle AJAX going pear-shaped by doing a regular form submission
*
* @param	object	YUI AJAX
*/
vB_UserList_Saver.prototype.handle_ajax_failure = function(ajax)
{
	vBulletin_AJAX_Error_Handler(ajax);

	// remove the form listeners
	YAHOO.util.Event.removeListener(this.change_form, "submit", this.handle_form_submit);
	YAHOO.util.Event.removeListener(this.add_form, "submit", this.handle_form_submit);

	// and now submit the form via a regular POST
	YAHOO.util.Dom.get(ajax.argument[1]).submit();
}

/**
* Deals with the XML returned by AJAX and updates the page accordingly
*
* @param	object	YUI AJAX
*/
vB_UserList_Saver.prototype.handle_ajax_response = function(ajax)
{
	if (ajax.responseXML)
	{
		var errors, userlists, i, listid, listelement = null;

		YAHOO.util.Dom.setStyle(ajax.argument[0], "display", "none");

		errors = ajax.responseXML.getElementsByTagName("error");
		if (errors.length)
		{
			YAHOO.util.Dom.get(this.prefix + "_error_message").innerHTML = errors[0].firstChild.nodeValue;
			YAHOO.util.Dom.setStyle(this.prefix + "_error", "display", "block");
			return;
		}
		else
		{
			YAHOO.util.Dom.setStyle(this.prefix + "_error", "display", "none");
		}

		if (this.add_form && this.add_form.username)
		{
			this.add_form.username.value = "";
		}


		buddycountobj = YAHOO.util.Dom.get("buddycount");
		if (buddycountobj)
		{
			buddycountobj.innerHTML = ajax.responseXML.getElementsByTagName('buddycount')[0].firstChild.nodeValue;
		}

		userlists = ajax.responseXML.getElementsByTagName("userlist");
		if (userlists.length)
		{
			for (i = 0; i < userlists.length; i++)
			{
				listid = userlists[i].getAttribute("type");

				if (vB_UserList_Highlighters[listid])
				{
					vB_UserList_Highlighters[listid].deactivate();
				}

				listelement = YAHOO.util.Dom.get(listid);
				if (listelement && userlists[i].firstChild)
				{
					YAHOO.util.Dom.setStyle(listid + "_container", "display", "block");
					YAHOO.util.Dom.setStyle(listid + "_change_form", "display", "block");

					listelement.innerHTML = userlists[i].firstChild.nodeValue;
				}
				else if (listelement && userlists[i])
				{
					YAHOO.util.Dom.setStyle(listid + "_container", "display", "none");
					YAHOO.util.Dom.setStyle(listid + "_change_form", "display", "none");

					listelement.innerHTML = "";
				}

				vB_UserList_Highlighters[listid] = new vB_UserList_Highlighter(listid);
			}
		}
		
		users = ajax.responseXML.getElementsByTagName("user");
		if (users.length)
		{
			var userlist = {};
			for (i = 0; i < users.length; i++)
			{
				userlist[users[i].getAttribute("username")] = users[i].getAttribute("userid");
			}

			for (filter in vB_UserList_Filters)
			{	
				vB_UserList_Filters[filter].update_userlist(userlist);
			}
		}
	}
}

// #############################################################################

/**
* Allows images to act as <label> tags in the buddy/friends list, plus other userlist actions
*
* @package	vBulletin
* @version	$Revision: 28428 $
* @date		$Date: 2008-11-17 07:46:28 -0600 (Mon, 17 Nov 2008) $
* @author	Kier Darby
*
* @param	string	ID of HTML element containing all user items
*/
function vB_UserList_Highlighter(parentid)
{
	var i, j, labels, images, element;

	this.parentid = parentid;
	this.parent = YAHOO.util.Dom.get(parentid);
	this.items = new Array();

	labels = this.parent.getElementsByTagName("label");
	if (labels.length)
	{
		for (i = 0; i < labels.length; i++)
		{
			if (YAHOO.util.Dom.hasClass(labels[i], "avatar_label"))
			{
				images = labels[i].getElementsByTagName("img");
				if (images.length)
				{
					for (j = 0; j < images.length; j++)
					{
						if (images[j].id && images[j].id.substr(0, 8 + this.parentid.length) == (this.parentid + "_avatar_"))
						{
							element = new vB_UserList_UserObject(images[j].id.substr(8 + this.parentid.length), this.parentid);
							this.items.push(element);
						}
					}
				}
			}
		}
	}

	this.check_all_checkbox = YAHOO.util.Dom.get(this.parentid + "_checkall");
	YAHOO.util.Event.on(this.check_all_checkbox, "click", this.check_all, this, true);

	this.show_avatars_checkbox = YAHOO.util.Dom.get(this.parentid + "_showavatars");
	YAHOO.util.Event.on(this.show_avatars_checkbox, "click", this.show_avatars, this, true);

	this.show_avatars_checkbox.checked = (parseInt(fetch_cookie("vbulletin_userlist_hide_avatars_" + this.parentid)) ? false : true);

	this.show_avatars();
}

/**
* Deactivates all highlighters registered to this object
*/
vB_UserList_Highlighter.prototype.deactivate = function()
{
	for (var i = 0; i < this.items.length; i++)
	{
		this.items[i].deactivate();
	}
}

/**
* Checks / Unchecks all highlighters
*/
vB_UserList_Highlighter.prototype.check_all = function()
{
	var i, inputs;

	if (this.items.length)
	{
		for (i = 0; i < this.items.length; i++)
		{
			this.items[i].usercheck.checked = this.check_all_checkbox.checked;
			this.items[i].shade_avatar();
		}
	}
	else
	{
		var inputs = this.parent.getElementsByTagName("input");
		for (i = 0; i < inputs.length; i++)
		{
			if (inputs[i].type == "checkbox")
			{
				inputs[i].checked = this.check_all_checkbox.checked;
			}
		}
	}
}

/**
* Toggles avatar visibility
*/
vB_UserList_Highlighter.prototype.show_avatars = function()
{
	if (this.items.length && this.show_avatars_checkbox)
	{
		if (this.show_avatars_checkbox.checked)
		{
			YAHOO.util.Dom.replaceClass(this.parent, "userlist_hideavatars", "userlist_showavatars");
			console.info("checked");
		}
		else
		{
			YAHOO.util.Dom.replaceClass(this.parent, "userlist_showavatars", "userlist_hideavatars");
			console.info("not checked");
		}

		var expires = new Date();
		expires.setTime(expires.getTime() + (1000 * 86400 * 365));
		set_cookie("vbulletin_userlist_hide_avatars_" + this.parentid, (this.show_avatars_checkbox.checked ? 0 : 1), expires);
	}
}

// #############################################################################

/**
* Allows individual images to act as <label> tags in the buddy/friends list, plus more stuff
*
* @package	vBulletin
* @version	$Revision: 28428 $
* @date		$Date: 2008-11-17 07:46:28 -0600 (Mon, 17 Nov 2008) $
* @author	Kier Darby
*
* @param	integer	UserID of user item
* @param	string	ID of HTML element containing all user items
*/
function vB_UserList_UserObject(userid, prefix)
{
	this.avatar = YAHOO.util.Dom.get(prefix + "_avatar_" + userid);
	YAHOO.util.Event.on(this.avatar, "click", this.avatar_click, this, true);

	this.usercheck = YAHOO.util.Dom.get(prefix + "_usercheck_" + userid);
	if (this.usercheck.tagName == "INPUT" && this.usercheck.getAttribute("type") == "checkbox")
	{
		YAHOO.util.Event.on(this.usercheck, "click", this.usercheck_click, this, true);
		this.shade_avatar();
	}

	this.friendcheck = YAHOO.util.Dom.get(prefix + "_friendcheck_" + userid);
	if (this.friendcheck)
	{
		YAHOO.util.Event.on(this.friendcheck, "click", this.set_friend, this, true);
		this.friend = this.friendcheck.checked;
		this.origfriend = this.friendcheck.checked;
	}
}

/**
* Sets the opacity of the avatar to transparent if the user checkbox is un-checked
*/
vB_UserList_UserObject.prototype.shade_avatar = function()
{
	YAHOO.util.Dom.setStyle(this.avatar, "opacity", (this.usercheck.checked ? 1 : 0.25));

	if (this.friendcheck)
	{
		this.friendcheck.checked = (this.usercheck.checked ? this.friend : false);
	}
}

/**
* Handles a click on an avatar image
*
* @param	event
*/
vB_UserList_UserObject.prototype.avatar_click = function(e)
{
	YAHOO.util.Event.stopEvent(e);

	if (this.usercheck.tagName == "SELECT")
	{
		this.usercheck.focus();
	}
	else
	{
		this.usercheck.checked = !this.usercheck.checked;
		this.shade_avatar();
	}
}

/**
* Handles a click on a user checkbox
*
* @param	event
*/
vB_UserList_UserObject.prototype.usercheck_click = function(e)
{
	this.shade_avatar();
}

/**
* Handles a click on a friend checkbox
*
* @param	event
*/
vB_UserList_UserObject.prototype.set_friend = function(e)
{
	this.friend = this.friendcheck.checked;

	if (this.friend)
	{
		this.usercheck.checked = true;
		this.shade_avatar();
	}
}

/**
* Unregisters all event listeners attached to this object
*/
vB_UserList_UserObject.prototype.deactivate = function()
{
	YAHOO.util.Event.removeListener(this.avatar, "click", this.avatar_click);
	YAHOO.util.Event.removeListener(this.usercheck, "click", this.usercheck_click);
	YAHOO.util.Event.removeListener(this.friendcheck, "click", this.set_friend);
}

// #############################################################################

/**
* Allows a text input box to be used to filter the results of userlist by username contains {searchstring}
*
* @package	vBulletin
* @version	$Revision: 28428 $
* @date		$Date: 2008-11-17 07:46:28 -0600 (Mon, 17 Nov 2008) $
* @author	Kier Darby
*
* @param	mixed	Filter box element
* @param	array	Array of container IDs
* @param	array	Array of users in { "username" : userid } format
*/
function vB_UserList_Filter(filterbox, containers, userlist)
{
	this.filterbox = YAHOO.util.Dom.get(filterbox);
	this.containers = containers;
	this.userlist = userlist;

	// activate textbox events
	YAHOO.util.Event.on(this.filterbox, "keydown", this.ignore_submit, this, true);
	YAHOO.util.Event.on(this.filterbox, "keyup", this.perform_filter, this, true);
	YAHOO.util.Event.on(this.filterbox, "focus", this.handle_focus, this, true);
	YAHOO.util.Event.on(this.filterbox, "blur", this.handle_blur, this, true);

	// show the textbox
	this.labeltext = new String(this.filterbox.value);
	YAHOO.util.Dom.setStyle(this.filterbox, "display", "inline");
}

/**
* Ignores submission of the form when return is pressed in the filter box
*/
vB_UserList_Filter.prototype.ignore_submit = function(e)
{
	if (e.keyCode == 13)
	{
		YAHOO.util.Event.stopEvent(e);
	}
}

vB_UserList_Filter.prototype.update_userlist = function(userlist)
{
	this.userlist = userlist; 
}

/**
* Performs the filter, showing or hiding user elements as necessary
*/
vB_UserList_Filter.prototype.perform_filter = function(e)
{
	var inputvalue, filtertext, username, item, display, i;

	inputvalue = this.filterbox.value;

	if (inputvalue == this.labeltext)
	{
		return;
	}

	filtertext = PHP.trim(inputvalue.toLowerCase());

	console.log("vB_UserList_Filter :: Filtering results to users containing '%s'.", filtertext);

	for (username in this.userlist)
	{
		if (this.filterbox.value == inputvalue)
		{
			display = (username.toLowerCase().indexOf(filtertext) != -1 ? "block" : "none");

			for (i = 0; i < this.containers.length; i++)
			{
				item = YAHOO.util.Dom.get(this.containers[i] + "_user" + this.userlist[username]);
				if (item != null)
				{
					item.style.display = display;
				}
			}
		}
		else
		{
			console.warn("vB_UserList_Filter :: Filter race condition; search string '%s' does not match input value '%s'. Aborting.", inputvalue, this.filterbox.value);
			return;
		}
	}
}

/**
* Handles focus events - prepares the text input box for entry
*/
vB_UserList_Filter.prototype.handle_focus = function(e)
{
	YAHOO.util.Dom.removeClass(this.filterbox, "filterbox_inactive");

	if (this.filterbox.value == this.labeltext)
	{
		this.filterbox.value = "";
	}
}

/**
* Handles blur events - resets the text input box if necessary
*/
vB_UserList_Filter.prototype.handle_blur = function(e)
{
	if (PHP.trim(this.filterbox.value) == "")
	{
		YAHOO.util.Dom.addClass(this.filterbox, "filterbox_inactive");
		this.filterbox.value = this.labeltext;
	}
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 28428 $
|| ####################################################################
\*======================================================================*/
