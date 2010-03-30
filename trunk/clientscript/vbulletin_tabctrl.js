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

var vB_TabCtrls = new Array();

// #############################################################################
// vB_TabCtrl 2007 Kier Darby
// call using:
// vBulletin.register_control("vB_TabCtrl", tab_container, initial_tab_id, overflow_tab_label, ajax_load_url)
// #############################################################################

vBulletin.events.systemInit.subscribe(function()
{
	if (vBulletin.elements["vB_TabCtrl"])
	{
		var i,
			element;

		for (i = 0; i < vBulletin.elements["vB_TabCtrl"].length; i++)
		{
			element = vBulletin.elements["vB_TabCtrl"][i];
			vB_TabCtrls[element[0]] = new vB_TabCtrl(element[0], element[1], element[2], element[3]);
		}
		vBulletin.elements["vB_TabCtrl"] = null;
	}
});

// =============================================================================

/**
* vBulletin tabbed content
*
* @package	vBulletin
* @version	$Revision: 24798 $
* @date		$Date: 2007-11-22 13:59:49 +0000 (Thu, 22 Nov 2007) $
* @author	Kier Darby
* @copyright	Jelsoft Enterprises Ltd.
*
* @param	string	HTML element containing tab divs - each tab must be a div.content_block with a child of h4... etc.
* @param	string	Identifier of initially-selected tab
* @param	string	Text to place onto the overflow tab - recommend &raquo;
* @param	string	URL from which to request new tab content via AJAX
*/
function vB_TabCtrl(tab_container, initial_tab_id, overflow_tab_string, ajax_load_url)
{
	var i,
		content_blocks,
		li,
		tab_id,
		selected_index,
		collapseobj,
		tab_banner;

	console.log("Init vB_TabCtrl for %s with initial tab id = %s", tab_container, initial_tab_id);
	this.tab_container = YAHOO.util.Dom.get(tab_container).parentNode;
	this.selected_tab_id = initial_tab_id;

	if (ajax_load_url)
	{
		this.ajax_load_url = ajax_load_url.split("?");
		this.ajax_load_url[1] = this.ajax_load_url[1].replace(/\{(\d+)(:\w+)?\}/gi, '%$1$s');
	}

	this.tab_count = 0;

	content_blocks = YAHOO.util.Dom.getElementsByClassName("content_block", "div", tab_container);
	if (content_blocks.length)
	{
		console.log("vB_TabCtrl :: Found %d tab content blocks", content_blocks.length);

		this.tab_element = document.createElement("ul");
		YAHOO.util.Dom.addClass(this.tab_element, "tab_list");

		selected_index = -1;

		for (i = 0; i < content_blocks.length; i++)
		{
			this.tab_count++;

			tab_id = content_blocks[i].getAttribute("id");

			// hide collapser
			collapseobj = YAHOO.util.Dom.get("collapseobj_" + tab_id);
			if (collapseobj)
			{
				YAHOO.util.Dom.setStyle(collapseobj, "display", "block");
			}

			// create tab element
			li = this.tab_element.appendChild(document.createElement("li"));
			li.id = tab_id + "_tab";
			li.innerHTML = YAHOO.util.Dom.getElementsByClassName("block_name", "span", content_blocks[i].getElementsByTagName("h4")[0])[0].innerHTML;

			// apply block_title to first block_row div
			YAHOO.util.Dom.addClass(YAHOO.util.Dom.getElementsByClassName("block_row", "div", content_blocks[i])[0], "block_title");

			li.setAttribute("tab_id", tab_id);
			YAHOO.util.Dom.addClass(li, "tborder tcat");

			if (tab_id == this.selected_tab_id)
			{
				selected_index = i;
			}
		}

		content_blocks[0].parentNode.insertBefore(this.tab_element, content_blocks[0]);

		tab_banner = content_blocks[0].parentNode.insertBefore(document.createElement("div"), content_blocks[0]);
		YAHOO.util.Dom.addClass(tab_banner, "tborder tcat tab_header");
	}

	this.tabs = this.tab_element.getElementsByTagName("li");

	// prevent wrapped tabs from showing by setting the height of the overflow-hidden tab container
	YAHOO.util.Dom.setStyle(this.tab_element, "height", this.tabs[0].offsetHeight + "px");

	for (i = 0; i < this.tab_count; i++)
	{
		this.init_tab(this.tabs[i], false);
		this.tabs[i].setAttribute("fixed_width", this.tabs[i].offsetWidth);
		YAHOO.util.Dom.setStyle(this.tabs[i], "width", this.tabs[i].getAttribute("fixed_width") + "px");
		YAHOO.util.Dom.setStyle(this.tabs[i], "display", "none");
	}

	// create the overflow tab
	this.overflow_tab = this.tab_element.appendChild(document.createElement("li"));
	this.overflow_tab.setAttribute("dir", "ltr");
	YAHOO.util.Dom.addClass(this.overflow_tab, "tborder thead overflow_tab");
	YAHOO.util.Event.on(this.overflow_tab, "click", this.show_menu, this, true);

	if (overflow_tab_string)
	{
		this.overflow_tab.innerHTML = overflow_tab_string;
	}
	else
	{
		this.overflow_tab.appendChild(document.createTextNode("»"));
	}

	// set a default tab
	if (selected_index == -1)
	{
		selected_index = 0;
		this.selected_tab_id = content_blocks[0].getAttribute("id");
	}

	this.switch_tab(this.selected_tab_id, true);

	// get heights for selected and normal tabs
	var selected_tab_height = YAHOO.util.Dom.get(this.selected_tab_id + "_tab").offsetHeight;
	var normal_tab_height = 0;

	for (i = 0; i < this.tabs.length; i++)
	{
		if (this.tabs[i].getAttribute("tab_id") != this.selected_tab_id)
		{
			normal_tab_height = this.tabs[i].offsetHeight;
			break;
		}
	}

	// apply those selected heights, and fix background position for selected tabs to be seamless
	var tab_css = document.createElement('style');
	tab_css.type = "text/css";

	if (tab_css.styleSheet && is_ie)
	{	// no, we don't know why either - IE is doing wierd things with the background position...
		tab_css.styleSheet.cssText = "ul.tab_list li.thead { top:" + (selected_tab_height - normal_tab_height) + "px; } div.tab_header { background-position:1px -" + (selected_tab_height - 2) + "px; }";
	}
	else
	{
		tab_css.appendChild(document.createTextNode("ul.tab_list li.thead { top:" + (selected_tab_height - normal_tab_height) + "px; } div.tab_header { background-position:0px -" + (selected_tab_height - 1) + "px; }"));
	}

	document.getElementsByTagName('head')[0].appendChild(tab_css);

	YAHOO.util.Event.on(window, "resize", this.resize, this, true);
	YAHOO.util.Event.on(document, "click", this.hide_menu, this, true);
};

/**
* Handles a click on a tab
*
* @param	event
*/
vB_TabCtrl.prototype.click_tab = function(e)
{
	var element = YAHOO.util.Event.getTarget(e);
	
	while (element.getAttribute("tab_id") == null && element.tagName.toUpperCase() != "HTML")
	{
		element = element.parentNode;
	}

	this.switch_tab(element.getAttribute("tab_id"));
	
	YAHOO.util.Event.stopEvent(e);
};

/**
* Switch to a different tab
*
* @param	string	ID of tab to be selected
* @param	boolean	Force tab switch
*/
vB_TabCtrl.prototype.switch_tab = function(selected_tab_id, force)
{
	if (this.selected_tab_id != selected_tab_id || force)
	{
		var i,
			tab_id,
			content_element;

		this.hide_menu();

		this.selected_tab_id = selected_tab_id;
		this.selected_tab = YAHOO.util.Dom.get(this.selected_tab_id + "_tab");

		for (i = 0; i < this.tab_count; i++)
		{
			tab_id = this.tabs[i].getAttribute("tab_id");

			YAHOO.util.Dom[(tab_id == this.selected_tab_id ? "addClass" : "removeClass")](this.tabs[i], "tcat");
			YAHOO.util.Dom[(tab_id != this.selected_tab_id ? "addClass" : "removeClass")](this.tabs[i], "thead");

			content_element = YAHOO.util.Dom.get(tab_id);
			YAHOO.util.Dom.setStyle(content_element, "display", (tab_id == this.selected_tab_id ? "block" : "none"));

			if (tab_id == this.selected_tab_id && YAHOO.util.Dom.get("collapseobj_" + tab_id).innerHTML == "")
			{
				this.load_tab_content(this.selected_tab_id);
			}
		}

		console.log("vB_TabCtrl :: Switched to '%s' tab", this.selected_tab_id);

		this.resize();
	}

	return false;
};

/**
* Recalculates which tabs should be displayed after a page resize
*
* @param	event
*/
vB_TabCtrl.prototype.resize = function(e)
{
	this.hide_menu();

	var total_width,
		i,
		j,
		display_tab_count,
		content_element_id,
		selected_tab,
		replace_tab,
		new_selected_tab,
		menu_element_names;

	YAHOO.util.Dom.setStyle(this.overflow_tab, "display", "block");
	total_width = this.overflow_tab.offsetWidth + 10;
	YAHOO.util.Dom.setStyle(this.overflow_tab, "display", "none");

	display_tab_count = 0;

	for (i = 0; i < this.tab_count; i++)
	{
		YAHOO.util.Dom.setStyle(this.tabs[i], "display", "block");
		total_width += Math.max(parseInt(this.tabs[i].getAttribute("fixed_width")), this.tabs[i].offsetWidth);

		if (this.tab_container.offsetWidth > total_width)
		{
			display_tab_count++;
		}
		else
		{
			YAHOO.util.Dom.setStyle(this.tabs[i], "display", "none");
		}

		content_element_id = this.tabs[i].getAttribute("tab_id");
		if (content_element_id == this.selected_tab_id && YAHOO.util.Dom.getStyle(this.tabs[i], "display") == "none")
		{
			console.info("vB_TabCtrl :: Moving selected tab... Found the selected tab: %d, %s", i, content_element_id);
			selected_tab = this.tabs[i];

			for (j = i; j >= 0; j--)
			{
				if (YAHOO.util.Dom.getStyle(this.tabs[j], "display") != "none")
				{
					console.log("vB_TabCtrl :: Replace tab %d (%s) with %d (%s)", j, this.tabs[j].getAttribute("tab_id"), i, content_element_id);

					// placeholder for new tab
					replace_tab = this.tabs[j];

					new_selected_tab = this.tab_element.insertBefore(selected_tab.cloneNode(true), replace_tab);

					// remove the selected tab
					YAHOO.util.Event.removeListener(selected_tab, "click", this.click_tab, this, true);
					YAHOO.util.Event.removeListener(selected_tab.firstChild, "click", this.click_tab, this, true);
					selected_tab.parentNode.removeChild(selected_tab);

					YAHOO.util.Dom.setStyle(new_selected_tab, "display", "block");
					this.init_tab(new_selected_tab, false);

					return this.resize();
				}
			}
		}
	}

	this.display_tab_count = display_tab_count;

	// show the overflow tab and set its title
	menu_element_names = new Array();
	for (i = this.display_tab_count; i < this.tabs.length; i++)
	{
		if (this.tabs[i] != this.overflow_tab)
		{
			menu_element_names.push(this.tabs[i].innerHTML);
		}
	}

	this.overflow_tab.setAttribute("title", menu_element_names.join(",\n"));
	YAHOO.util.Dom.setStyle(this.overflow_tab, "display", (this.tab_count > display_tab_count ? "block" : "none"));

	// update the background position
	for (i = 0; i < this.tabs.length; i++)
	{
		YAHOO.util.Dom.setStyle(this.tabs[i], "backgroundPosition", (this.tabs[i].getAttribute("tab_id") == this.selected_tab_id ? (this.tabs[i].offsetLeft * -1) + "px 0px" : "0px 0px"));
	}
};

/**
* Shows the popup menu containing overflowed tabs
*
* @param	event
*/
vB_TabCtrl.prototype.show_menu = function(e)
{
	YAHOO.util.Event.stopEvent(e);

	if (this.menu_open)
	{
		this.hide_menu();
		return;
	}

	var i,
		counter,
		current_menu_element,
		menupos,
		menupos_x;

	this.menu = document.createElement("ul");
	this.menu.setAttribute("id", this.tab_element.id + "menu");
	YAHOO.util.Dom.addClass(this.menu, "vbmenu_popup");
	YAHOO.util.Dom.addClass(this.menu, "tab_popup");

	menu_element_names = new Array();
	counter = 0;

	for (i = this.display_tab_count; i < this.tab_count; i++)
	{
		current_menu_element = this.menu.appendChild(this.tabs[i].cloneNode(true));
		YAHOO.util.Dom.setStyle(current_menu_element, "display", "block");
		YAHOO.util.Dom.setStyle(current_menu_element, "width", "auto");
		YAHOO.util.Dom.removeClass(current_menu_element, "tborder");
		YAHOO.util.Dom.removeClass(current_menu_element, "tcat");
		YAHOO.util.Dom.removeClass(current_menu_element, "thead");
		YAHOO.util.Dom.addClass(current_menu_element, "vbmenu_option");
		if (counter++ < 1)
		{
			YAHOO.util.Dom.addClass(current_menu_element, "first");
		}
		this.init_tab(current_menu_element, true);
	}

	this.tab_container.appendChild(this.menu);

	menupos = YAHOO.util.Dom.getXY(this.overflow_tab);

	// check that the menu has not opened hanging off the screen
	menupos_x = menupos[0] - current_menu_element.offsetWidth + this.overflow_tab.offsetWidth;
	menupos_x  = (menupos_x < fetch_viewport_info()["x"]) ? menupos[0] : menupos_x;

	YAHOO.util.Dom.setX(this.menu, menupos_x);
	YAHOO.util.Dom.setY(this.menu, menupos[1] + this.overflow_tab.offsetHeight - 1);

	this.menu_open = true;
};

/**
* Hides the popup menu containing overflowed tabs
*/
vB_TabCtrl.prototype.hide_menu = function()
{
	try { this.menu.parentNode.removeChild(this.menu); } catch(e) {}

	this.menu_open = false;
};

/**
* Initializes a tab with event listeners etc.
*
* @param	object	HTML tab (LI) element
* @param	boolean	Extract full title for tab
*/
vB_TabCtrl.prototype.init_tab = function(tab_element, full_title)
{
	YAHOO.util.Event.on(tab_element, "click", this.click_tab, this, true);

	content_element = YAHOO.util.Dom.get(tab_element.getAttribute("tab_id"));

	YAHOO.util.Dom.setStyle(YAHOO.util.Dom.getElementsByClassName("block_title", "h4", content_element)[0], "display", "none");
};

/**
* Checks to see if a node has rel="Block"
*
* @param	object	HTML element
*
* @return	boolean
*/
vB_TabCtrl.prototype.is_block_title = function(element)
{
	return (element.getAttribute("rel") == "Block");
}

/**
* Handles AJAX errors
*
* @param	object	YUI AJAX
*/
vB_TabCtrl.prototype.handle_ajax_error = function(ajax)
{
	//TODO: Something bad happened, try again
	vBulletin_AJAX_Error_Handler(ajax);
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 15951 $
|| ####################################################################
\*======================================================================*/