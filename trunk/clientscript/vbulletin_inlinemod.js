/*!======================================================================*\
|| #################################################################### ||
|| # vBulletin [#]version[#]
|| # ---------------------------------------------------------------- # ||
|| # Copyright �2000-[#]year[#] Jelsoft Enterprises Ltd. All Rights Reserved. ||
|| # This file may not be redistributed in whole or significant part. # ||
|| # ---------------- VBULLETIN IS NOT FREE SOFTWARE ---------------- # ||
|| # http://www.vbulletin.com | http://www.vbulletin.com/license.html # ||
|| #################################################################### ||
\*======================================================================*/

// #############################################################################
// vB_Inline_Mod
// #############################################################################

/**
* Inline Moderation Class
*
* @package	vBulletin
* @version	$Revision: 27441 $
* @date		$Date: 2008-08-14 09:33:40 -0500 (Thu, 14 Aug 2008) $
* @author	Freddie Bingham, Kier Darby, vBulletin Development Team
*
* @param	string	Name of the instance of this class
* @param	string	Type of system (thread/post)
* @param	string	ID of the form containing all checkboxes
* @param	string	Phrase for use on Go button
* @param	string	Name of cookie
* @param string   Type of highilght to use if it doesn't jive with the specified type
*/
function vB_Inline_Mod(varname, type, formobjid, go_phrase, cookieprefix, highlighttype)
{
	/**
	* Variables created from arguments
	*
	* @var	string
	* @var	string
	* @var	object
	* @var	string
	*/
	this.varname = varname;
	this.type = type.toLowerCase();
	this.formobj = fetch_object(formobjid);
	this.go_phrase = go_phrase;
	if (typeof cookieprefix != 'undefined')
	{
		this.cookieprefix = cookieprefix;
	}
	else
	{
		this.cookieprefix = 'vbulletin_inline';
	}
	/**
	* Other variables
	*
	* @var	string	Prefix for all checkbox IDs
	* @var	integer	Number of items checked on this page
	* @var	array	Array of IDs fetched from the cookie
	* @var	array	Array of IDs ready to be saved into the cookie
	*/

	// Change tlist_/plist_ in the templates to threadlist_/postlist_ in the next major version
	if (this.type == 'thread')
	{
		this.list = 'tlist_';
	}
	else if (this.type == 'post')
	{
		this.list = 'plist_';
	}
	else
	{
		this.list = this.type + 'list_';
	}

	if (typeof highlighttype != 'undefined')
	{
		this.highlighttype = highlighttype;
	}
	else
	{
		this.highlighttype = this.type;
	}

	this.cookie_ids = null;
	this.cookie_array = new Array();

	// =============================================================================
	// vB_Inline_Mod methods

	/**
	* Initialization action to run on page load
	*/
	this.init = function(elements)
	{
		var i;
		// attach clickfunc to all checkboxes
		for (i = 0; i < elements.length; i++)
		{
			if (this.is_in_list(elements[i]))
			{
				elements[i].inlineModID = this.varname;
				elements[i].onclick = inlinemod_checkbox_onclick;
			}
		}

		this.cookie_array = new Array();
		if (this.fetch_ids())
		{
			for (i in this.cookie_ids)
			{
				if (YAHOO.lang.hasOwnProperty(this.cookie_ids, i) && this.cookie_ids[i] != '')
				{
					if (checkbox = fetch_object(this.list + this.cookie_ids[i]))
					{
						checkbox.checked = true;

						if (typeof (this["highlight_" + this.highlighttype]) != 'undefined')
						{
							this["highlight_" + this.highlighttype](checkbox);
						}
					}
					this.cookie_array[this.cookie_array.length] = this.cookie_ids[i];
				}
			}
		}

		this.set_output_counters();
	}

	/**
	* Returns an array of IDs from the inlinemod cookie
	*
	* @return	boolean	True if array created
	*/
	this.fetch_ids = function()
	{
		this.cookie_ids = fetch_cookie(this.cookieprefix + this.type);

		if (this.cookie_ids != null && this.cookie_ids != '')
		{
			this.cookie_ids = this.cookie_ids.split('-');
			if (this.cookie_ids.length > 0)
			{
				return true;
			}
		}

		return false;
	}

	/**
	* Toggles the selected state of an inline moderation item, updates the cookie
	*
	* @param	string	ID of the checkbox
	*
	* @return	boolean
	*/
	this.toggle = function(checkbox)
	{
		if (typeof (this["highlight_" + this.highlighttype]) != 'undefined')
		{
			this["highlight_" + this.highlighttype](checkbox);
		}

		this.save(checkbox.id.substring(this.list.length), checkbox.checked);
	}

	/**
	* Saves the inline moderation cookie
	*
	* @param	string	Item ID
	* @param	boolean	Add id to array?
	*
	* @return	boolean
	*/
	this.save = function(checkboxid, checked)
	{
		this.cookie_array = new Array();

		if (this.fetch_ids())
		{
			for (var i in this.cookie_ids)
			{
				if (YAHOO.lang.hasOwnProperty(this.cookie_ids, i) && this.cookie_ids[i] != checkboxid && this.cookie_ids[i] != '')
				{
					this.cookie_array[this.cookie_array.length] = this.cookie_ids[i];
				}
			}
		}

		if (checked)
		{
			this.cookie_array[this.cookie_array.length] = checkboxid;
		}

		this.set_output_counters();

		this.set_cookie();

		return true;
	}

	/**
	* Saves the inline moderation cookie
	*/
	this.set_cookie = function()
	{
		expires = new Date();
		expires.setTime(expires.getTime() + 3600000);
		set_cookie(this.cookieprefix + this.type, this.cookie_array.join('-'), expires);
	}

	/**
	* Check / Uncheck All Inline Moderation Checkboxes
	*/
	this.check_all = function(checked, itemtype, caller)
	{
		if (typeof checked == 'undefined')
		{
			checked = this.formobj.allbox.checked;
		}

		this.cookie_array = new Array();

		// Remove all items on this page from the cookie list
		if (this.fetch_ids())
		{
			for (i in this.cookie_ids)
			{
				if (YAHOO.lang.hasOwnProperty(this.cookie_ids, i) && !fetch_object(this.list + this.cookie_ids[i]))
				{
					// this item is not on this page so put back in the cookie
					this.cookie_array[this.cookie_array.length] = this.cookie_ids[i]
				}
			}
		}

		counter = 0;

		// check/uncheck all boxes
		for (var i = 0; i < this.formobj.elements.length; i++)
		{
			if (this.is_in_list(this.formobj.elements[i]))
			{
				var elm = this.formobj.elements[i];

				if (typeof itemtype != 'undefined')
				{
					if (isNaN(itemtype))
					{
						if (elm.value == itemtype)
						{
							elm.checked = checked;
						}
					}
					else
					{
						if (elm.value & itemtype)
						{
							elm.checked = checked;
						}
						else
						{
							elm.checked = !checked;
						}
					}
				}
				else if (checked == 'invert')
				{
					elm.checked = !elm.checked;
				}
				else
				{
					elm.checked = checked;
				}

				if (typeof (this["highlight_" + this.highlighttype]) != 'undefined')
				{
					this["highlight_" + this.highlighttype](elm);
				}

				if (elm.checked)
				{
					// add item to cookie if we are 'checking' it
					this.cookie_array[this.cookie_array.length] = elm.id.substring(this.list.length)
				}
			}
		}

		this.set_output_counters();

		this.set_cookie();

		return true;
	}

	this.is_in_list = function(obj)
	{
		return (obj.type == 'checkbox' && obj.id.indexOf(this.list) == 0 && (obj.disabled == false || obj.disabled == 'undefined'));
	}

	/**
	* Sets the value of the inline go button and the menu feedback
	*/
	this.set_output_counters = function()
	{
		// change inlinego in the templates to thread_inlinego and post_inlinego in the next major version and just use var gobutton = this.type + '_inlinego';
		var gobutton;
		if (this.type == 'thread' || this.type == 'post')
		{
			gobutton = 'inlinego';
		}
		else
		{
			gobutton = this.type + '_inlinego';
		}

		var obj;
		if (obj = fetch_object(gobutton))
		{
			obj.value = construct_phrase(this.go_phrase, this.cookie_array.length);
		}
	}

	/**
	* Toggles an element's classname between original and 'inlinemod'
	*
	* @param	object	The element on which to work
	* @param	object	The checkbox corresponding to the cell element
	*/
	this.toggle_highlight = function(element, checkbox, force)
	{
		if (element.tagName)
		{
			if (force || YAHOO.util.Dom.hasClass(element, "alt1") || YAHOO.util.Dom.hasClass(element, "alt2") || YAHOO.util.Dom.hasClass(element, "inlinemod"))
			{
				if (checkbox.checked)
				{
					YAHOO.util.Dom.addClass(element, "inlinemod");
				}
				else
				{
					YAHOO.util.Dom.removeClass(element, "inlinemod");
				}
			}
		}
	}

	/**
	* Highlights a thread <tr> in a thread listing
	*
	* @param	object	The checkbox for the thread
	*/
	this.highlight_thread = function(checkbox)
	{
		var tobj = checkbox;
		while (tobj.tagName != 'TR')
		{
			if (tobj.parentNode.tagName == 'HTML')
			{
				break;
			}
			else
			{
				tobj = tobj.parentNode;
			}
		}
		if (tobj.tagName == 'TR')
		{
			var tds = tobj.childNodes;
			for (var i = 0; i < tds.length; i++)
			{
				this.toggle_highlight(tds[i], checkbox);
			}
		}
	}

	/**
	* Highlights a post <table> on showthread
	*
	* @param	object	The checkbox for the post
	*/
	this.highlight_post = function(checkbox)
	{
		if (table = fetch_object(this.type + checkbox.id.substr(this.list.length)))
		{
			var tds = fetch_tags(table, 'td');
			for (var i = 0; i < tds.length; i++)
			{
				this.toggle_highlight(tds[i], checkbox);
			}
		}
	}

	/**
	* Highlights a visitor message on memberinfo
	*
	* @param	object	The checkbox for the message
	*/
	this.highlight_message = function(checkbox)
	{
		var i = 0;
		var messageid = checkbox.id.substr(this.list.length);

		var container = YAHOO.util.Dom.get(this.type + messageid);
		if (container)
		{
			this.toggle_highlight(container, checkbox, true);

			var inner_divs = YAHOO.util.Dom.getElementsByClassName("alt2", "div", container);
			if (inner_divs.length)
			{
				this.toggle_highlight(inner_divs[0], checkbox);
			}
		}
	}

	/**
	* Highlights a div
	*
	* @param	object	Associated checkbox
	*/
	this.highlight_div = function(checkbox)
	{
		var div;
		if (div = fetch_object(this.type + checkbox.id.substr(this.list.length)))
		{
			console.log("Highlight %s", this.type + checkbox.id.substr(this.list.length));
			this.toggle_highlight(div, checkbox);
			var divs = fetch_tags(div, 'div');
			for (var i = 0; i < divs.length; i++)
			{
				this.toggle_highlight(divs[i], checkbox);
			}
		}
	}

	// get everything running
	this.init(this.formobj.elements);
}

/**
* Function to handle checkboxes being clicked
*
* @param	event	Event object
*/
function inlinemod_checkbox_onclick(e)
{
	var inlineModObj = eval(this.inlineModID);
	inlineModObj.toggle(this);
};

/**
* Function to init a single post
*
* @param	event	Event object
*/
function im_init(obj, inlineobj)
{
	var inputs = fetch_tags(obj, 'input');

	if (typeof inlineobj == 'object' && typeof inlineobj.init == 'function')
	{
		inlineobj.init(inputs);
	}
	else
	{
		inlineMod.init(inputs);
	}
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 27441 $
|| ####################################################################
\*======================================================================*/