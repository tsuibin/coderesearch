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

vBulletin.events.systemInit.subscribe(function ()
{
	// only IE falls over on imgs for labels
	if (is_ie)
	{
		var picturebits = YAHOO.util.Dom.get('picturebits');
		if (picturebits)
		{
			// find all images in labels, ensure the label has a unique id
			// and tell the image about that id. Then register a click event
			// that can fire the label's click event.
			var labels = picturebits.getElementsByTagName('label');
			var images, imageindex, labelindex, labelid;

			for (labelindex = 0; labelindex < labels.length; labelindex++)
			{
				labelid = YAHOO.util.Dom.generateId(labels[labelindex]);

				images = labels[labelindex].getElementsByTagName('img');
				for (imageindex = 0; imageindex < images.length; imageindex++)
				{
					images[imageindex].labelid = labelid;
					YAHOO.util.Event.on(images[imageindex], "click",  image_label_click, images[imageindex]);
				}
			}
		}
	}
});

function image_label_click(e, img)
{
	YAHOO.util.Dom.get(img.labelid).click();
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 15175 $
|| ####################################################################
\*======================================================================*/