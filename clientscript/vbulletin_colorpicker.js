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
	init_color_picker_page('profileform');
});

var color_picker;

/**
* Generic color picker object
*
* @package	vBulletin
* @version	$Revision: 24798 $
* @date		$Date: 2007-11-22 13:59:49 +0000 (Thu, 22 Nov 2007) $
* @author	Kier Darby, Mike Sullivan, vBulletin Development Team
* @copyright	Jelsoft Enterprises Ltd.
*/
function vB_ColorPicker()
{
	this.cpid = 'colorpicker';

	this.previewid = '';
	this.inputid = '';

	this.init();
}

/**
* Creates the table rows and initializes the system.
*/
vB_ColorPicker.prototype.init = function()
{
	// setup swatch colors and events
	var green = new Array(5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5);
	var blue = new Array(0, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 0);

	var color_lookup = new Array("00", "33", "66", "99", "CC", "FF");
	var special = new Array('#000000', '#333333', '#666666', '#999999', '#CCCCCC', '#FFFFFF', '#FF0000', '#00FF00', '#0000FF', '#FFFF00', '#00FFFF', '#FF00FF');

	var x, y, cell, row;
	var swatch_table_container = fetch_object(this.cpid + "_swatches_container");
		swatch_table_container.innerHTML = "";
	var swatch_table = swatch_table_container.appendChild(document.createElement("table"));
		swatch_table.cellPadding = 0;
		swatch_table.cellSpacing = 1;
		swatch_table.border = 0;
		swatch_table.width = "100%";
		swatch_table.id = "colorpicker_swatches";
	var swatch_tbody = document.createElement('tbody');
	swatch_table.appendChild(swatch_tbody);

	for (y = 0; y < 12; y++)
	{
		row = document.createElement('tr');
		swatch_tbody.appendChild(row);

		for (x = 0; x < 19; x++)
		{
			cell = document.createElement('td');
			cell.id = "sw" + x + "-" + y;
			cell.className = 'pickerswatch';
			cell.innerHTML = '<img src="' + cleargifurl + '" width="11" height="11" />';
			row.appendChild(cell);

			if (x == 0)
			{
				cell.style.background = special[y];
			}
			else
			{
				var r = Math.min(5, Math.floor((18 - x) / 6) * 2 + Math.floor(y / 6));
				var g = green[y];
				var b = blue[x];

				cell.style.background = "#" + color_lookup[r] + color_lookup[g] + color_lookup[b];
			}
		}

	}

	this.select_handler = new vB_Select_Overlay_Handler(this.cpid);

	// setup other events
	YAHOO.util.Event.on(swatch_table, 'click', this.swatch_click, this, true);
	YAHOO.util.Event.on(swatch_table, 'mouseover', this.swatch_hover, this, true);

	YAHOO.util.Event.on(this.cpid + '_transparent', 'click', this.transparent_click, this, true);
	YAHOO.util.Event.on(this.cpid + '_close', 'click', this.close_click, this, true);
}

/**
* Updates the "new" swatche's color.
*
* @param	string	Swatch ID
*/
vB_ColorPicker.prototype.update_new_color = function(swatchid)
{
	fetch_object(this.cpid + '_surround_new').style.background = fetch_object(swatchid).style.backgroundColor;
}

/**
* Open's the color picker.
*
* @param	string	The ID that was clicked -- must have an input named when "_preview" is stripped
*/
vB_ColorPicker.prototype.open = function(clickid)
{
	if (clickid)
	{
		this.previewid = clickid;
		this.inputid = clickid.replace(/_preview/, '');
	}

	if (is_color(fetch_object(this.inputid).value, fetch_object(this.cpid + '_surround_old')))
	{
		fetch_object(this.cpid + '_surround_old').style.background = fetch_object(this.inputid).value;
		fetch_object(this.cpid + '_surround_new').style.background = fetch_object(this.inputid).value;
	}

	var previewobj = fetch_object(this.previewid);
	var left_pos = YAHOO.util.Dom.getX(previewobj);
	var top_pos = YAHOO.util.Dom.getY(previewobj) + previewobj.offsetHeight;

	// set the colorPicker's position
	var cpobj = fetch_object(this.cpid);
	cpobj.style.left = left_pos + "px";
	cpobj.style.top = top_pos + "px";
	cpobj.style.display = '';

	// we're off the page, move us back enough to be on the page
	if (left_pos + cpobj.offsetWidth > document.body.clientWidth)
	{
		left_pos -= left_pos + cpobj.offsetWidth - document.body.clientWidth;
		cpobj.style.left = left_pos + "px";
	}

	this.select_handler.hide();
}

/**
* Closes the color picker
*/
vB_ColorPicker.prototype.close = function()
{
	fetch_object(this.cpid).style.display = 'none';
	this.select_handler.show();
}

/**
* Event that fires when a swatch is hovered.
*/
vB_ColorPicker.prototype.swatch_hover = function(e)
{
	var el = this.getAncestorOrThisByClassName(YAHOO.util.Event.getTarget(e), 'pickerswatch');
	if (!el)
	{
		return;
	}

	this.update_new_color(el.id);
}

/**
* Event that fires when a swatch is clicked.
*/
vB_ColorPicker.prototype.swatch_click = function(e)
{
	var el = this.getAncestorOrThisByClassName(YAHOO.util.Event.getTarget(e), 'pickerswatch');
	if (!el)
	{
		return;
	}

	fetch_object(this.inputid).value = this.fetch_hex_color(el.style.backgroundColor);
	update_color_preview(this.inputid);

	this.close();
}

/**
* Event that fires when the close button is clecked.
*/
vB_ColorPicker.prototype.close_click = function(e)
{
	this.close();
}

/**
* Event that fires when the transparent button is clicked.
*/
vB_ColorPicker.prototype.transparent_click = function(e)
{
	fetch_object(this.inputid).value = '';
	update_color_preview(this.inputid);
	this.close();
}

/**
* Helper function to fetch this object or an ancestor by its classname
*/
vB_ColorPicker.prototype.getAncestorOrThisByClassName = function(node, className)
{
	if (node.className && node.className == className)
	{
		return node;
	}
	else
	{
		return YAHOO.util.Dom.getAncestorByClassName(node, className);
	}
}

/**
* Helper function to ensure we are not returned an rgb(1,2,3) value
*/
vB_ColorPicker.prototype.fetch_hex_color = function(color)
{
	if (color.substr(0, 1) == "r")
	{
		colorMatch = color.match(/rgb\((\d+),\s*(\d+),\s*(\d+)\)/i);
		for (var i = 1; i < 4; i++)
		{
			colorMatch[i] = parseInt(colorMatch[i]).toString(16);
			if (colorMatch[i].length < 2)
			{
				colorMatch[i] = "0" + colorMatch[i];
			}
		}
		color = "#" + (colorMatch[1] + colorMatch[2] + colorMatch[3]).toUpperCase();
	}

	return color.toUpperCase();
}

// #############################################################################
/**
* Updates the color preview of an object based on the input object's ID and value
*
* @param	string	Input obj ID
*/
function update_color_preview(input_objid)
{
	var previewobj = fetch_object(input_objid + '_preview');
	var inputobj = fetch_object(input_objid);
	inputobj.value = PHP.trim(inputobj.value);

	if (is_transparent(inputobj.value))
	{
		previewobj.style.background = "none";
		previewobj.style.borderStyle = "dashed";
		previewobj.style.borderWidth = '1px';
	}
	else
	{
		// only update the preview if it's using something we like (a color or hexcode)
		if (is_color(inputobj.value, previewobj))
		{
			previewobj.style.background = inputobj.value;
			previewobj.style.borderStyle = "inset";
			previewobj.style.borderWidth = '1px';
		}
		else
		{
			previewobj.style.background = "";
			previewobj.style.borderStyle = "dashed";
			previewobj.style.borderWidth = '1px';
		}
	}
}

// #############################################################################
/**
* Determine if a value is a valid color. We don't want to allow for images to come through here.
*
* @param	string	Value to test
* @param	object	An object whose background can be set to do a better test
*/
function is_color(value, obj)
{
	var valid_colors = new RegExp("^(#?([a-f0-9]{3}){1,2}|\d{1,3}\s*,\s*\d{1,3}\s*,\s*\d{1,3}|[a-z0-9]+)$", 'gi');
	if (!value.match(valid_colors))
	{
		return false;
	}

	if (obj)
	{
		var reset = true;
		var origbackground = obj.style.background;
		try
		{
			obj.style.background = value;
			reset = false;
		}
		catch (error) {}

		if (reset)
		{
			obj.style.background = origbackground;
			return false;
		}
	}

	return true;
}

// #############################################################################
/**
* Determine if the value means transparent.
*
* @param	string
*/
function is_transparent(value)
{
	return (value == "" || value == "none" || value == "transparent")
}

// #############################################################################
/**
* Inits the color picker and preview stuff for any inputs in the specified parentid
*
* @param	string	ID of element to search within
*/
function init_color_picker_page(parentid)
{
	var previewobj;

	var inputs = fetch_tags(fetch_object(parentid), 'input');
	for (var i = 0; i < inputs.length; i++)
	{
		if (inputs[i].id && inputs[i].id.substr(0, 8) == 'usercss_')
		{
			previewobj = fetch_object(inputs[i].id + '_preview');
			if (previewobj)
			{
				YAHOO.util.Event.on(previewobj, 'click', display_color_picker);
				YAHOO.util.Event.on(inputs[i], 'change', input_color_change);

				update_color_preview(inputs[i].id);
			}
		}
	}
}

// #############################################################################
/**
* Display's the color picker when clicked
*/
function display_color_picker()
{
	if (!color_picker)
	{
		color_picker = new vB_ColorPicker();
	}

	if (typeof(background_picker) != 'undefined')
	{
		background_picker.close();
	}
	color_picker.open(this.id);
}

// #############################################################################
/**
* Handles when an input's value changes and updates the color preview
*/
function input_color_change()
{
	// try to catch people who just entered "abcdef" without the hash
	var valid_colors = new RegExp("^[a-f0-9]{3}([a-f0-9]{3})?$", 'gi');
	if (this.value.match(valid_colors))
	{
		this.value = '#' + this.value;
	}

	update_color_preview(this.id);
}


/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 15777 $
|| ####################################################################
\*======================================================================*/