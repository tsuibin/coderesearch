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
	init_background_picker_page('profileform');
});

var background_picker;

/**
* Generic background picker object
*
* @package	vBulletin
* @version	$Revision: 24798 $
* @date		$Date: 2007-11-22 13:59:49 +0000 (Thu, 22 Nov 2007) $
* @author	vBulletin Development Team
* @copyright	Jelsoft Enterprises Ltd.
*/
function vB_BackgroundPicker()
{
	this.bgid = 'backgroundpicker';

	this.previewid = '';
	this.inputid = '';
	this.selectobj = null;
	this.activealbum = null;
	this.highlightobj = null;
	this.albumid = 0;

	this.init();
}

/**
* Initializes the system.
*/
vB_BackgroundPicker.prototype.init = function()
{
	this.select_handler = new vB_Select_Overlay_Handler(this.bgid);

	// setup other events
	YAHOO.util.Event.on(this.bgid + '_close', 'click', this.close_click, this, true);

	this.selectobj = fetch_object("backgroundpicker_select");
	if (this.selectobj)
	{
		this.albumid = this.selectobj.options[this.selectobj.selectedIndex].value;
		this.activealbum = fetch_object("usercss_background_container_" + this.albumid);
		YAHOO.util.Event.on(this.selectobj, 'change', this.switch_backgrounds, this, true);
	}

	var items = fetch_tags(fetch_object(this.bgid), 'li');
	for (var i = 0; i < items.length; i++)
	{
		if (items[i].id && items[i].id.substr(0, 8) == 'usercss_')
		{
			YAHOO.util.Event.on(items[i].id, 'click', this.insert_image);
			items[i].pictureid = items[i].id.replace(/usercss_background_image_/, '');
		}
	}
}

/**
* Insert the selected images info!
*
*/
vB_BackgroundPicker.prototype.insert_image = function(e)
{
	var inputobj = fetch_object(background_picker.inputid);
	inputobj.value = "albumid=" + background_picker.albumid + "&pictureid=" + this.pictureid;

	background_picker.close();
}

/**
* Switch the displayed background div
*
*/
vB_BackgroundPicker.prototype.switch_backgrounds = function(clickid)
{
	this.activealbum.style.display = "none";

	this.albumid = this.selectobj.options[this.selectobj.selectedIndex].value;
	this.activealbum = fetch_object("usercss_background_container_" + this.albumid);
	this.activealbum.style.display = "";
}

/**
* Open's the background picker.
*
* @param	string	The ID that was clicked -- must have an input named when "_preview" is stripped
*/
vB_BackgroundPicker.prototype.open = function(clickid)
{
	this.toggle_highlight("off");
	if (clickid)
	{
		this.clickid = clickid;
		this.inputid = clickid.replace(/_chooser/, '');
	}

	var clickobj = fetch_object(this.clickid);
	var left_pos = YAHOO.util.Dom.getX(clickobj);
	var top_pos = YAHOO.util.Dom.getY(clickobj) + clickobj.offsetHeight;

	var inputobj = fetch_object(this.inputid);

	var pictureid = null;
	var albumid = null;
	var albummatch = inputobj.value.match(/albumid=(\d+)/);
	if (albummatch)
	{
		albumid = albummatch[1];
	}

	var picturematch = inputobj.value.match(/pictureid=(\d+)/);
	if (picturematch)
	{
		pictureid = picturematch[1];
	}

	if (albumid && pictureid)
	{
		var album = fetch_object("usercss_background_container_" + albumid);
		if (album)
		{
			var items = fetch_tags(album, 'li');
			for (var i = 0; i < items.length; i++)
			{
				if (items[i].id && items[i].id.substr(0, 8) == 'usercss_')
				{
					if (items[i].pictureid == pictureid)
					{
						this.highlightobj = fetch_object("usercss_background_item_" + pictureid);
						this.toggle_highlight("on");

						if (this.albumid != albumid)
						{
							for (i = 0; i < this.selectobj.options.length; i++)
							{
								if (this.selectobj.options[i].value == albumid)
								{
									this.selectobj.selectedIndex = i;
									break;
								}
							}
							this.activealbum.style.display = "none";
							this.albumid = albumid;
							this.activealbum = fetch_object("usercss_background_container_" + this.albumid);
							this.activealbum.style.display = "";
						}
						break;
					}
				}
			}
		}
	}

	fetch_object("usercss_background_container_" + this.albumid);

	// set the backgroundPicker's position
	var bgobj = fetch_object(this.bgid);
	bgobj.style.left = left_pos + "px";
	bgobj.style.top = top_pos + "px";
	bgobj.style.display = '';

/*
	if (this.highlightobj)
	{
		this.highlightobj.scrollIntoView(false);
	}
*/

	// we're off the page, move us back enough to be on the page
	if (left_pos + bgobj.offsetWidth > document.body.clientWidth)
	{
		left_pos -= left_pos + bgobj.offsetWidth - document.body.clientWidth;
		bgobj.style.left = left_pos + "px";
	}

	this.select_handler.hide();
}

vB_BackgroundPicker.prototype.toggle_highlight = function(state)
{
	if (this.highlightobj)
	{
		if (state == "on")
		{
			YAHOO.util.Dom.addClass(this.highlightobj, "box_selected");
			YAHOO.util.Dom.removeClass(this.highlightobh, "box");
		}
		else if (state == "off")
		{
			YAHOO.util.Dom.addClass(this.highlightobj, "box");
			YAHOO.util.Dom.removeClass(this.highlightobj, "box_selected");
		}
	}
}

/**
* Closes the background picker
*/
vB_BackgroundPicker.prototype.close = function()
{
	fetch_object(this.bgid).style.display = 'none';
	background_picker.toggle_highlight("off");
	this.select_handler.show();
}

/**
* Event that fires when the close button is clecked.
*/
vB_BackgroundPicker.prototype.close_click = function(e)
{
	this.close();
}

/**
* Helper function to fetch this object or an ancestor by its classname
*/
vB_BackgroundPicker.prototype.getAncestorOrThisByClassName = function(node, className)
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

// #############################################################################
/**
* Inits the background picker and preview stuff for any inputs in the specified parentid
*
* @param	string	ID of element to search within
*/
function init_background_picker_page(parentid)
{
	var previewobj;

	var inputs  = fetch_tags(fetch_object(parentid), 'input');
	for (var i = 0; i < inputs.length; i++)
	{
		if (inputs[i].id && inputs[i].id.substr(0, 8) == 'usercss_')
		{
			previewobj = fetch_object(inputs[i].id + '_chooser');
			if (previewobj)
			{
				previewobj.style.display = '';
				YAHOO.util.Event.on(previewobj, 'click', display_background_picker);
			}
		}
	}
}

// #############################################################################
/**
* Display's the background picker when clicked
*/
function display_background_picker()
{
	if (!background_picker)
	{
		background_picker = new vB_BackgroundPicker();
	}

	if (typeof(color_picker) != 'undefined')
	{
		color_picker.close();
	}

	background_picker.open(this.id);
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 15777 $
|| ####################################################################
\*======================================================================*/