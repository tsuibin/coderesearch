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

// set up some variables for the search functions
var win = window;
var n = 0;

// ***************************************************************************************
// functions for use on the template listing page
// ***************************************************************************************

// #############################################################################
// function to jump to various style-related pages
function Sdo(phpdo, styleid)
{
	// get the variables we need
	phpdo = phpdo.split("_");

	if (phpdo[0] == "template")
	{
		switch (phpdo[1])
		{
			case "templates": // expand templates list
			{
				goURL = "modify&expandset=";
			}
			break;

			case "addtemplate": // add template
			{
				goURL = "add&dostyleid=";
			}
			break;

			case "editstyle": // edit style
			{
				goURL = "editstyle&dostyleid=";
			}
			break;

			case "addstyle": // add child style
			{
				goURL = "addstyle&parentid=";
			}
			break;

			case "delete": // delete style
			{
				goURL = "deletestyle&dostyleid=";
			}
			break;

			case "download": // go to style file manager
			{
				goURL = "files&dostyleid=";
			}
			break;

			case "revertall": // revert all templates
			{
				goURL = "revertall&dostyleid=";
			}
			break;
		}
		if (goURL)
		{
			window.location = "template.php?s=" + SESSIONHASH + "&group=" + document.forms.tform.group.value + "&do=" + goURL + styleid;
		}
	}
	else if (phpdo[0] == "css")
	{
		window.location = "css.php?s=" + SESSIONHASH + "&do=edit&dowhat=" + phpdo[1] + "&group=" + document.forms.tform.group.value + "&dostyleid=" + styleid;
	}
}

// #############################################################################
// function to jump to a url within template.php
function Tjump(gourl)
{
	var gotourl = "template.php?s=" + SESSIONHASH + "&do=" + gourl + "&searchstring=" + SEARCHSTRING + "&expandset=" + EXPANDSET;

	if (is_ie && event.shiftKey)
	{
		window.open(gotourl)
	}
	else
	{
		window.location = gotourl;
	}
}

// #############################################################################
// function to expand a template group
function Texpand(dogroup,doexpandset)
{
	window.location="template.php?s=" + SESSIONHASH + "&do=modify&expandset=" + doexpandset + "&group=" + dogroup + "#" + dogroup;
}

// ***************************************************************************************
// these functions are used only by the STANDARD editor (not IE)
// ***************************************************************************************

// #############################################################################
// function to edit a template
function Tedit(templateid)
{
	Tjump("edit&templateid=" + templateid + "&dostyleid=" + EXPANDSET + "&group=" + GROUP);
}

// #############################################################################
// function to customize a default template
function Tcustom1(styleid,title)
{
	Tjump("add&dostyleid=" + styleid + "&title=" + title + "&group=" + GROUP);
}

// #############################################################################
// function to further customize a customized template
function Tcustom2(styleid,templateid)
{
	Tjump("add&dostyleid=" + styleid + "&templateid=" + templateid + "&group=" + GROUP);
}

// #############################################################################
// function to delete a template
function Tdelete(styleid,templateid)
{
	Tjump("delete&dostyleid=" + styleid + "&templateid=" + templateid + "&group=" + GROUP);
}

// #############################################################################
// function to view an original template
function Toriginal(title)
{
	window.open("template.php?s=" + SESSIONHASH + "&do=view&title=" + title);
}

// ***************************************************************************************
// these functions are used by the ENHANCED editor (IE only)
// ***************************************************************************************

// #############################################################################
// function to display help info etc in the FORMTYPE enhanced editor
function Tprep(elm, styleid, echo)
{
	// get string value
	var str = elm.value;

	if (echo)
	{
		button = new Array();
		button['edit'] = eval("document.forms.tform.edit" + styleid);
		button['edit'].disabled = "disabled";
		button['cust'] = eval("document.forms.tform.cust" + styleid);
		button['cust'].disabled = "disabled";
		button['kill'] = eval("document.forms.tform.kill" + styleid);
		button['kill'].disabled = "disabled";
		button['expa'] = eval("document.forms.tform.expa" + styleid);
		button['expa'].disabled = "disabled";
		button['orig'] = eval("document.forms.tform.orig" + styleid);
		button['orig'].disabled = "disabled";
		textbox = document.getElementById('helparea' + styleid);
	}

	if (str != '')
	{
		selitem = eval("document.forms.tform.tl" + styleid);
		var out = new Array();
		out['selectedtext'] = selitem.options[selitem.selectedIndex].text.replace(/^-- /,'');
		if (str == "~")
		{
			str = out['selectedtext'];
		}
		out['styleid'] = styleid;
		out['original'] = str;
		if (str.search(/^\[(\w*)\]$/) != -1)
		{
			out['value'] = str.replace(/^\[(\w*)\]$/,'$1');
			if (isNaN(out['value']) || out['value']=="")
			{
				out['action'] = "expand";
				//out['text'] = "Click the 'Expand/Collapse' button or double-click the group name to expand or collapse the " + out['selectedtext'].replace(/ Templates/,'').bold() + " group of templates.";
				out['text'] = construct_phrase(vbphrase['click_the_expand_collapse_button'], out['selectedtext'].replace(/Templates/, '').bold());
				button['expa'].disabled = "";
			}
			else
			{
				out['action'] = "editinherited";
				selecteditem = eval('document.forms.tform.tl'+styleid);
				tsid = selecteditem.options[selecteditem.selectedIndex].getAttribute('tsid');
				out['text'] = construct_phrase(vbphrase['this_template_has_been_customized_in_a_parent_style'], STYLETITLE[tsid].bold(), STYLETITLE[styleid].bold(), out['selectedtext'].bold(), "template.php?s=" + SESSIONHASH + "&amp;do=edit&amp;templateid=" + out['value'] + "&amp;group=" + GROUP);
				button['orig'].disabled = "";
				button['cust'].disabled = "";
			}
		}
		else
		{
			out['value'] = str;
			if (isNaN(out['value']))
			{
				out['action'] = "customize";
				out['text'] = vbphrase['this_template_has_not_been_customized'];
				button['cust'].disabled = "";
			}
			else
			{
				out['action'] = "edit";
				out['text'] = vbphrase['this_template_has_been_customized_in_this_style'];
				button['edit'].disabled = "";
				button['orig'].disabled = "";
				button['kill'].disabled = "";
			}
		}
		if (echo)
		{
			textbox.innerHTML = out['selectedtext'].bold() + ":<br /><br />" + out['text'];
			if (elm.getAttribute('i'))
			{
				var editinfo = elm.getAttribute('i').split(";");
				editinfo[1] = new Date(editinfo[1] * 1000);
				var day = editinfo[1].getDate();
				var month = editinfo[1].getMonth();
				var year = editinfo[1].getFullYear();
				var hours = editinfo[1].getHours();
				if (hours < 10)
				{
					hours = '0' + hours;
				}
				var mins = editinfo[1].getMinutes();
				if (mins < 10)
				{
					mins = '0' + mins;
				}
				textbox.innerHTML += construct_phrase("<br /><br />" + vbphrase['template_last_edited_js'], MONTH[month], day, year, hours, mins, editinfo[0].bold());
			}
		}
		else
		{
			return out;
		}
	}
	else
	{
		textbox.innerHTML = construct_phrase("<center>" + vbphrase['x_templates'] + "</center>", STYLETITLE[styleid].bold());
	}
}

// #############################################################################
// function to jump to the correct template.php page
function Tdo(arry, request)
{
	if (arry == null)
	{
		return false;
	}
	switch(arry['action'])
	{
		case "expand":
			Tjump("modify&expandset=" + EXPANDSET + "&group=" + arry['value']);
			break;
		case "customize":
			Tjump("add&dostyleid=" + arry['styleid'] + "&title=" + arry['value'] + "&group=" + GROUP);
			break;
		case "edit":
			switch(request)
			{
				case "vieworiginal":
					window.open("template.php?s=" + SESSIONHASH + "&do=view&title=" + arry['selectedtext']);
					break;
				case "killtemplate":
					Tjump("delete&templateid=" + arry['value'] + "&dostyleid=" + arry['styleid'] + "&group=" + GROUP);
					break;
				default:
					Tjump("edit&templateid=" + arry['value'] + "&group=" + GROUP);
					break;
			}
			break;
		case "editinherited":
			if (request == "vieworiginal")
			{
				window.open("template.php?s=" + SESSIONHASH + "&do=view&title=" + arry['selectedtext']);
			}
			else
			{
				Tjump("add&dostyleid=" + arry['styleid'] + "&templateid=" + arry['value'] + "&group=" + GROUP);
			}
			break;
	}
}

// ***************************************************************************************
// functions for manipulating template text - formerly in PHP function print_template_javascript()
// ***************************************************************************************

// #############################################################################
// function to do a preview of a template in a new window
var popup = '';
function displayHTML()
{
	var inf = document.cpform.template.value;

	if (popup && !popup.closed)
	{
		popup.document.close();
	}
	else
	{
		popup = window.open(", ", 'popup', 'toolbar = no, status = no, scrollbars=yes');
	}
	popup.document.open();
	popup.document.write('' + inf + '');
}

// #############################################################################
// function to copy text into the clipboard
function HighlightAll()
{
	document.cpform.template.focus();
	document.cpform.template.select();
	if (document.all)
	{
		var therange = document.cpform.template.createTextRange();
		therange.execCommand('Copy');
	}
}

// #############################################################################
// keypress handler for the "find in page" text box
function findInPageKeyPress(e)
{
	e = e ? e : window.event;

	if (e.keyCode == 13)
	{
		findInPage(this.value);
		return false;
	}
	else
	{
		return true;
	}
}

// #############################################################################
// function to find text on a page
var startpos = 0;
function findInPage(str)
{
	var txt, i, found;
	if (str == '')
	{
		return false;
	}
	if (is_moz)
	{
		txt = fetch_object(textarea_id).value;
		if (!startpos || startpos + str.length >= txt.length)
		{
			startpos = 0;
		}
		var x = 0;
		var matchfound = false;
		for (i = startpos; i < txt.length; i++)
		{
			if (txt.charAt(i).toLowerCase() == str.charAt(x).toLowerCase())
			{
				x++;
			}
			else
			{
				x = 0;
			}
			if (x == str.length)
			{
				i++;
				startpos = i;
				fetch_object(textarea_id).focus();
				fetch_object(textarea_id).setSelectionRange(i - str.length, i);
				// really dirty nasty thing, hide from Kier
				moz_txtarea_scroll(fetch_object(textarea_id), i);
				matchfound = true;
				break;
			}
			if (i == txt.length - 1 && startpos > 0)
			{ // argh at end
				i = 0;
				startpos = 0;
			}
		}
		if (!matchfound)
		{
			alert(vbphrase['not_found']);
		}
	}
	if (is_ie)
	{
		txt = win.fetch_object(textarea_id).createTextRange();
		for (i = 0; i <= n && (found = txt.findText(str)) != false; i++)
		{
			txt.moveStart('character', 1);
			txt.moveEnd('textedit');
		}
		if (found)
		{
			txt.moveStart('character', -1);
			txt.findText(str);
			txt.select();
			txt.scrollIntoView(true);
			n++;
		}
		else
		{
			if (n > 0)
			{
				n = 0;
				findInPage(str);
			}
			else { alert(vbphrase['not_found']); }
		}
	}
	return false;
}

// well the lame we're going to do here is create a textarea dynamically
// once we've done that we can just substring it to the length of the where the match is
// from there we can just grab the actual height of the new textarea and whats where the offset should be
function moz_txtarea_scroll(input, txtpos)
{
	// handle vertical scrolling
	var newarea = input.cloneNode(true);
	newarea.setAttribute('id', 'moo');
	newarea.style.width = input.offsetWidth + 'px';
	newarea.value = input.value.substr(0, txtpos) + "\n"; // new line avoids issues with horizontal scrollbars
	document.body.appendChild(newarea);

	if (newarea.scrollHeight <= input.scrollTop || newarea.scrollHeight >= input.scrollTop + input.offsetHeight)
	{
		if (newarea.scrollHeight == newarea.clientHeight)
		{
			input.scrollTop = 0;
		}
		else
		{
			input.scrollTop = newarea.scrollHeight - 40;
		}
	}

	document.body.removeChild(document.getElementById('moo'));

	// handle horizontal scrolling
	newarea = input.cloneNode(true);
	newarea.setAttribute('id', 'moo');
	newarea.style.width = input.offsetWidth + 'px';

	var last_break = input.value.substr(0, txtpos).lastIndexOf("\n");
	if (!last_break)
	{
		last_break = 0;
	}

	newarea.value = input.value.substring(last_break, txtpos);
	document.body.appendChild(newarea);

	if (newarea.scrollWidth == input.offsetWidth)
	{
		// no horiz scrolling needed
		input.scrollLeft = 0;
	}
	else
	{
		input.scrollLeft = newarea.scrollWidth - 40;
	}

	document.body.removeChild(document.getElementById('moo'));
}

// #############################################################################
// function to change the text-wrap style of an element
function set_wordwrap(idname, yesno)
{
	element = fetch_object(idname);

	if (yesno)
	{
		element.wrap = "soft";
	}
	else
	{
		element.wrap = "off";
	}
}

// #############################################################################
// function to check/uncheck userselectability boxes for child styles
function check_children(styleid, value)
{
	// check this box
	fetch_object("userselect_" + styleid).checked = value;

	// check check children
	for (var i in STYLEPARENTS)
	{
		if (YAHOO.lang.hasOwnProperty(STYLEPARENTS, i) && STYLEPARENTS[i] == styleid)
		{
			check_children(i, value);
		}
	}

	return false;
}

// #############################################################################
// function to calculate the crc32 of a string, in this case a template
function crc32(str)
{
	var table = "00000000 77073096 EE0E612C 990951BA 076DC419 706AF48F E963A535 9E6495A3 0EDB8832 79DCB8A4 E0D5E91E 97D2D988 09B64C2B 7EB17CBD E7B82D07 90BF1D91 1DB71064 6AB020F2 F3B97148 84BE41DE 1ADAD47D 6DDDE4EB F4D4B551 83D385C7 136C9856 646BA8C0 FD62F97A 8A65C9EC 14015C4F 63066CD9 FA0F3D63 8D080DF5 3B6E20C8 4C69105E D56041E4 A2677172 3C03E4D1 4B04D447 D20D85FD A50AB56B 35B5A8FA 42B2986C DBBBC9D6 ACBCF940 32D86CE3 45DF5C75 DCD60DCF ABD13D59 26D930AC 51DE003A C8D75180 BFD06116 21B4F4B5 56B3C423 CFBA9599 B8BDA50F 2802B89E 5F058808 C60CD9B2 B10BE924 2F6F7C87 58684C11 C1611DAB B6662D3D 76DC4190 01DB7106 98D220BC EFD5102A 71B18589 06B6B51F 9FBFE4A5 E8B8D433 7807C9A2 0F00F934 9609A88E E10E9818 7F6A0DBB 086D3D2D 91646C97 E6635C01 6B6B51F4 1C6C6162 856530D8 F262004E 6C0695ED 1B01A57B 8208F4C1 F50FC457 65B0D9C6 12B7E950 8BBEB8EA FCB9887C 62DD1DDF 15DA2D49 8CD37CF3 FBD44C65 4DB26158 3AB551CE A3BC0074 D4BB30E2 4ADFA541 3DD895D7 A4D1C46D D3D6F4FB 4369E96A 346ED9FC AD678846 DA60B8D0 44042D73 33031DE5 AA0A4C5F DD0D7CC9 5005713C 270241AA BE0B1010 C90C2086 5768B525 206F85B3 B966D409 CE61E49F 5EDEF90E 29D9C998 B0D09822 C7D7A8B4 59B33D17 2EB40D81 B7BD5C3B C0BA6CAD EDB88320 9ABFB3B6 03B6E20C 74B1D29A EAD54739 9DD277AF 04DB2615 73DC1683 E3630B12 94643B84 0D6D6A3E 7A6A5AA8 E40ECF0B 9309FF9D 0A00AE27 7D079EB1 F00F9344 8708A3D2 1E01F268 6906C2FE F762575D 806567CB 196C3671 6E6B06E7 FED41B76 89D32BE0 10DA7A5A 67DD4ACC F9B9DF6F 8EBEEFF9 17B7BE43 60B08ED5 D6D6A3E8 A1D1937E 38D8C2C4 4FDFF252 D1BB67F1 A6BC5767 3FB506DD 48B2364B D80D2BDA AF0A1B4C 36034AF6 41047A60 DF60EFC3 A867DF55 316E8EEF 4669BE79 CB61B38C BC66831A 256FD2A0 5268E236 CC0C7795 BB0B4703 220216B9 5505262F C5BA3BBE B2BD0B28 2BB45A92 5CB36A04 C2D7FFA7 B5D0CF31 2CD99E8B 5BDEAE1D 9B64C2B0 EC63F226 756AA39C 026D930A 9C0906A9 EB0E363F 72076785 05005713 95BF4A82 E2B87A14 7BB12BAE 0CB61B38 92D28E9B E5D5BE0D 7CDCEFB7 0BDBDF21 86D3D2D4 F1D4E242 68DDB3F8 1FDA836E 81BE16CD F6B9265B 6FB077E1 18B74777 88085AE6 FF0F6A70 66063BCA 11010B5C 8F659EFF F862AE69 616BFFD3 166CCF45 A00AE278 D70DD2EE 4E048354 3903B3C2 A7672661 D06016F7 4969474D 3E6E77DB AED16A4A D9D65ADC 40DF0B66 37D83BF0 A9BCAE53 DEBB9EC5 47B2CF7F 30B5FFE9 BDBDF21C CABAC28A 53B39330 24B4A3A6 BAD03605 CDD70693 54DE5729 23D967BF B3667A2E C4614AB8 5D681B02 2A6F2B94 B40BBE37 C30C8EA1 5A05DF1B 2D02EF8D";
	var crc = -1;
	var x = 0, y = 0;

	for (var char_count = 0; char_count < str.length; char_count++)
	{
		y = (crc ^ str.charCodeAt(char_count)) & 0xFF;
		x = "0x" + table.substr(y * 9, 8);
		crc = (crc >>> 8) ^ x;
    }

	return crc ^ (-1);
}
/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 29488 $
|| ####################################################################
\*======================================================================*/