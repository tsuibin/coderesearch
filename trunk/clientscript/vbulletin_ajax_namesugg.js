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
// vB_AJAX_NameSuggest
// #############################################################################

/**
* Class to read input and suggest usernames from the typed fragment
*
* @package	vBulletin
* @version	$Revision: 28688 $
* @date		$Date: 2008-12-04 06:17:26 -0600 (Thu, 04 Dec 2008) $
* @author	Mike Sullivan
* @copyright	Jelsoft Enterprises Ltd.
*
* @param	string	Name of variable instantiating this class
* @param	string	ID of the text input element to monitor
* @param	string	Unique key of the popup menu in which to show suggestions
*/
function vB_AJAX_NameSuggest(varname, textobjid, menukey)
{
	var webkit_version = userAgent.match(/applewebkit\/([0-9]+)/);

	if (AJAX_Compatible && !(is_saf && !(webkit_version[1] >= 412)))
	{
		this.menuobj = fetch_object(menukey + '_menu');
		this.textobj = fetch_object(textobjid);
		this.textobj.setAttribute("autocomplete", "off");
		this.textobj.onfocus = function(e) { this.obj.active = true; };
		this.textobj.onblur  = function(e) { this.obj.active = false; };
		this.textobj.obj = this;

		/**
		* Varaiables used by this class
		*
		* @var	string	The name given to the instance of this class
		* @var	string	The menu key for the vbmenu name suggestion popup
		* @var	string	The current name fragment text
		* @var	string	The current string of completed names (Foo ; Bar etc.)
		* @var	integer	The currently selected name index in the menu
		* @var	boolean	Is the suggestion menu open or not
		* @var	object	A javascript timeout marker
		* @var	array	The list of suggested names
		* @var	object	The XML sender object
		* @var	boolean	True when text box is focussed - only show menu when true
		* @var	object	YUI AJAX Transaction
		*/
		this.varname = varname;
		this.menukey = menukey;
		this.fragment = '';
		this.donenames = '';
		this.selected = 0;
		this.menuopen = false;
		this.timeout = null;
		this.names = new Array();
		this.active = false;
		this.ajax_req = null;

		/**
		* Options used by this class
		*
		* @var	boolean	Allow multiple names (Foo ; Bar etc.) or just single (Foo)
		* @var	integer	The minimum length of the text fragment before requesting a search
		*/
		this.allow_multiple = false;
		this.min_chars = 3;

		// =============================================================================
		// vB_AJAX_NameSuggest methods

		/**
		* Reads the contents of the text input box
		*/
		this.get_text = function()
		{
			if (this.allow_multiple)
			{
				// search for a semi-colon (meaning we have more than one name in the box)
				var semicolon = this.textobj.value.lastIndexOf(';');

				if (semicolon == -1)
				{
					// the current name is the only one in the text box
					this.donenames = new String('');
					this.fragment = new String(this.textobj.value);
				}
				else
				{
					// also need to store completed names in the text box
					this.donenames = new String(this.textobj.value.substring(0, semicolon + 1));
					this.fragment = new String(this.textobj.value.substring(semicolon + 1));
				}
			}
			else
			{
				this.fragment = new String(this.textobj.value);
			}

			// trim away leading and trailing spaces from the fragment
			this.fragment = PHP.trim(this.fragment);
		}

		/**
		* Sets the contents of the text input box
		*
		* @param	integer	The index of the desired name in this.names to insert
		*/
		this.set_text = function(i)
		{
			if (this.allow_multiple)
			{
				this.textobj.value = PHP.ltrim(this.donenames + " " + PHP.unhtmlspecialchars(this.names[i]) + " ; ");
			}
			else
			{
				this.textobj.value = PHP.unhtmlspecialchars(this.names[i]);
			}

			this.textobj.focus();

			this.menu_hide();

			return false;
		}

		/**
		* Moves the 'selected' row in the menu
		*
		* @param	integer	Increment (1, -1 etc.)
		*/
		this.move_row_selection = function(increment)
		{
			var newval = parseInt(this.selected, 10) + parseInt(increment, 10);

			if (newval < 0)
			{
				newval = this.names.length - 1;
			}
			else if (newval >= this.names.length)
			{
				newval = 0;
			}

			this.set_row_selection(newval);

			return false;
		}

		/**
		* Sets the 'selected' row in the menu
		*
		* @param	integer	The index of the desired selection (0 - n)
		*/
		this.set_row_selection = function(i)
		{
			var tds = fetch_tags(this.menuobj, 'td');
			tds[this.selected].className = 'vbmenu_option';
			this.selected = i;
			tds[this.selected].className = 'vbmenu_hilite';
		}

		/**
		* Event handler for the text input box key-up event
		*
		* @param	event	The event object
		*/
		this.key_event_handler = function(evt)
		{
			evt = evt ? evt : window.event;

			if (this.menuopen)
			{
				// 38 = up
				// 40 = down
				// 13 = return
				// 27 = escape

				switch (evt.keyCode)
				{
					case 38: // arrow up
					{
						this.move_row_selection(-1);
						return false;
					}
					case 40: // arrow down
					{
						this.move_row_selection(1);
						return false;
					}
					case 27: // escape
					{
						this.menu_hide();
						return false;
					}
					case 13: // return / enter
					{
						this.set_text(this.selected);
						return false;
					}
				}
			}

			// create the fragment
			this.get_text();

			if (this.fragment.length >= this.min_chars)
			{
				clearTimeout(this.timeout);
				this.timeout = setTimeout(this.varname + '.name_search();', 500);
			}
			else
			{
				this.menu_hide();
			}
		}

		/**
		* Sends the fragment to search the database
		*/
		this.name_search = function()
		{
			if (this.active)
			{
				this.names = new Array();

				if (YAHOO.util.Connect.isCallInProgress(this.ajax_req))
				{
					YAHOO.util.Connect.abort(this.ajax_req);
				}

				this.ajax_req = YAHOO.util.Connect.asyncRequest("POST", "ajax.php?do=usersearch", {
					success: this.handle_ajax_request,
					failure: vBulletin_AJAX_Error_Handler,
					timeout: vB_Default_Timeout,
					scope: this
				}, SESSIONURL + "securitytoken=" + SECURITYTOKEN + "&do=usersearch&fragment=" + PHP.urlencode(this.fragment));
			}
		}

		/**
		* Handles AJAX response
		*
		* @param	object	YUI AJAX
		*/
		this.handle_ajax_request = function(ajax)
		{
			if (ajax.responseXML)
			{
				var users = ajax.responseXML.getElementsByTagName("user");
				for (var i = 0; i < users.length; i++)
				{
					this.names[i] = users[i].firstChild.nodeValue;
				}

				if (this.names.length > 0)
				{
					this.menu_build();
					this.menu_show();
				}
				else
				{
					this.menu_hide();
				}
			}
		}

		/**
		* Builds the menu html from the list of found names
		*/
		this.menu_build = function()
		{
			this.menu_empty();
			var re = new RegExp('^(' + PHP.preg_quote(this.fragment) + ')', "i");

			var table = document.createElement('table');
			table.cellPadding = 4;
			table.cellSpacing = 1;
			table.border = 0;
			for (var i in this.names)
			{
				if (YAHOO.lang.hasOwnProperty(this.names, i))
				{
					var td = table.insertRow(-1).insertCell(-1);
					td.className = (i == this.selected ? 'vbmenu_hilite' : 'vbmenu_option');
					td.title = 'nohilite';
					td.innerHTML = '<a onclick="return ' + this.varname + '.set_text(' + i + ')">' + this.names[i].replace(re, '<strong>$1</strong>') + '</a>';
				}
			}
			this.menuobj.appendChild(table);

			if (this.vbmenu == null)
			{
				if (typeof(vBmenu.menus[this.menukey]) != 'undefined')
				{
					this.vbmenu = vBmenu.menus[this.menukey];
				}
				else
				{
					this.vbmenu = vBmenu.register(this.menukey, true);
				}
			}
			else
			{
				this.vbmenu.init_menu_contents();
			}
		}

		/**
		* Empties the menu of all names
		*/
		this.menu_empty = function()
		{
			this.selected = 0;

			while (this.menuobj.firstChild)
			{
				this.menuobj.removeChild(this.menuobj.firstChild);
			}
		}

		/**
		* Shows the menu
		*/
		this.menu_show = function()
		{
			if (this.active)
			{
				this.vbmenu.show(fetch_object(this.menukey), this.menuopen);
				this.menuopen = true;
			}
		}

		/**
		* Hides the menu
		*/
		this.menu_hide = function()
		{
			try
			{
				this.vbmenu.hide();
			}
			catch(e) {}
			this.menuopen = false;
		}

		this.textobj.onkeyup = function(e) { return this.obj.key_event_handler(e); };
		this.textobj.onkeypress = function(e)
		{
			e = e ? e : window.event;
			if (e.keyCode == 13)
			{
				return (this.obj.menuopen ? false : true);
			}
		};
	}
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 28688 $
|| ####################################################################
\*======================================================================*/