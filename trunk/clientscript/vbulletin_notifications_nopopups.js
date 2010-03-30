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
// vB_Notifications_NoPopups
// call using:
// vBulletin.register_control("vB_Notifications_NoPopups", notifications_text_element_id)
// #############################################################################

vBulletin.events.systemInit.subscribe(function()
{
	if (vBulletin.elements["vB_Notifications_NoPopups"])
	{
		vBulletin.vB_Notifications_NoPopups = new Object();
	
		for (var i = 0; i < vBulletin.elements["vB_Notifications_NoPopups"].length; i++)
		{
			var element = vBulletin.elements["vB_Notifications_NoPopups"][i][0];
			vBulletin.vB_Notifications_NoPopups[element] = new vB_Notifications_NoPopups(element);
		}
		vBulletin.elements["vB_Notifications_NoPopups"] = null;
	}
});

/**
* Does a text rotation showing notificatons in the navbar for those with popups disabled
*
* @param	string	ID of element to contain the text - navbar id="notification"
*/
function vB_Notifications_NoPopups(elementid)
{
	this.elementid = elementid;
	this.element = YAHOO.util.Dom.get(this.elementid);	
	this.notifications_text = new Array();
	this.counter = 0;
	this.timeout = null;
	this.timeout_time = 2000;
	
	this.fetch_text();
	
	this.timeout = setTimeout("vBulletin.vB_Notifications_NoPopups['" + this.elementid + "'].cycle()", this.timeout_time);
}

/**
* Reads the notifications text from the corresponding popup menu
*/
vB_Notifications_NoPopups.prototype.fetch_text = function()
{
	var tablerows, i, links;
	
	tablerows = YAHOO.util.Dom.get(this.element.id + "_menu").getElementsByTagName("tr");
	
	for (i = 0; i < tablerows.length; i++)
	{
		links = tablerows[i].getElementsByTagName("a");
		
		if (links.length)
		{			
			if (parseInt(links[1].firstChild.nodeValue) != 0)
			{
				this.notifications_text.push('<a href="' + links[0].getAttribute("href") + '">' + links[0].firstChild.nodeValue + '</a> ' + links[1].firstChild.nodeValue.bold());
			}
		}
	}
}

/**
* Updates the notifications text with the next in the list.
*/
vB_Notifications_NoPopups.prototype.cycle = function()
{
	if (this.counter >= this.notifications_text.length)
	{
		this.counter = 0;
	}
	
	this.element.innerHTML = this.notifications_text[this.counter];
	
	this.counter++;
	
	this.timeout = setTimeout("vBulletin.vB_Notifications_NoPopups['" + this.elementid + "'].cycle()", this.timeout_time);
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 24191 $
|| ####################################################################
\*======================================================================*/