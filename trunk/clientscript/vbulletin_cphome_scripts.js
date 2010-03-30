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

var announcement_url = 'http://forum.vbulletin-china.cn/';
var membersarea_url = 'http://members.vbulletin-china.cn/';

// #############################################################################
// newer version detector
if (typeof(vb_version) != "undefined" && isNewerVersion(current_version, vb_version))
{
	var t = fetch_object('news_table');
		var t_head_r = t.insertRow(0);
			t_head_c = t_head_r.insertCell(0);
			t_head_c.className = 'thead';
			t_head_c.innerHTML = newer_version_string.bold();
		var t_body_r = t.insertRow(1);
			var t_body_c = t_body_r.insertCell(0);
			t_body_c.className = 'alt1';
				t_body_p1 = document.createElement('p');
				t_body_p1.className = 'smallfont';
					t_body_a1 = document.createElement('a');
					t_body_a1.href = announcement_url + 'showthread.ph' + 'p?p=' + vb_announcementid;
					t_body_a1.target = '_blank';
					t_body_a1.innerHTML = construct_phrase(latest_string, vb_version).bold();
				t_body_p1.appendChild(t_body_a1);
				t_body_p1.innerHTML += '. ' + construct_phrase(current_string, current_version.bold()) + '.';
			t_body_c.appendChild(t_body_p1);
				t_body_p2 = document.createElement('p');
				t_body_p2.className = 'smallfont';
					t_body_a2 = document.createElement('a');
					t_body_a2.href = membersarea_url;
					t_body_a2.target = '_blank';
					t_body_a2.innerHTML = construct_phrase(download_string, vb_version.bold());
				t_body_p2.appendChild(t_body_a2);
			t_body_c.appendChild(t_body_p2);
}

// #############################################################################
function create_cp_table(tableid)
{
	var t = document.createElement('table');

	t.cellPadding = 4;
	t.cellSpacing = 0;
	t.border = 0;
	t.align = 'center';
	t.width = '90%';
	t.className = 'tborder';

	if (tableid)
	{
		t.id = tableid;
	}

	return t;
}

// #############################################################################
function news_loader(ajax)
{
	if (ajax.responseXML)
	{
		var visible_messages = done_table; // if there's a table, we're already displaying messages
		var table_visible = false;
		var news_id = '';
		var news_title = '';
		var news_body = '';
		var news_link = '';

		var news_items = ajax.responseXML.getElementsByTagName('item');

		if (done_table)
		{
			t = fetch_object('news_table');
			table_visible = true;
		}
		else
		{
			// table is there we've just hidden it
			var t = fetch_object('news_table');

			if (news_items.length)
			{
				// no point in displaying if there's nothing to add
				fetch_object('admin_news').style.display = '';

				var th = t.insertRow(0);
				cell = th.insertCell(0);
				cell.className = 'tcat';
				cell.align = 'center';
				cell.innerHTML = news_header_string.bold();

				table_visible = true;
			}
		}

		var i;
		for (i = 0; i < news_items.length; i++)
		{

			news_id = news_items[i].getElementsByTagName('guid')[0].firstChild.nodeValue;

			if (PHP.in_array(news_id, dismissed_news) == -1)
			{
				visible_messages = true;

				news_title = news_items[i].getElementsByTagName('title')[0].firstChild.nodeValue;
				news_body = news_items[i].getElementsByTagName('description')[0].firstChild.nodeValue;
				news_link = news_items[i].getElementsByTagName('link')[0].firstChild.nodeValue;

				var local_news_matches = news_body.match(/\[local\]((?!\[\/local\]).)*\[\/local\]/g);
				if (local_news_matches != null)
				{
					sessionurl = (SESSIONHASH == '' ? '' : 's=' + SESSIONHASH + '&');
					var local_match_number;
					for (local_match_number = 0; local_match_number < local_news_matches.length; local_match_number++)
					{
						news_body = news_body.replace(local_news_matches[local_match_number], local_news_matches[local_match_number].replace(/^\[local\](.*)\.php(\??)(.*)\[\/local\]$/, '$1' + local_extension + '?' + sessionurl + '$3'));
					}
				}

				var r1 = t.insertRow(t.rows.length);
				r1.id = 'r1_' + news_id;
					var c1 = r1.insertCell(0);
					c1.className = 'thead';
						var s = document.createElement('input');
						s.type = 'submit';
						s.name = 'acpnews[' + news_id + ']';
						s.className = 'button';
						if (is_ie)
						{
							s.style.styleFloat = stylevar_right;
						}
						else
						{
							s.style.cssFloat = stylevar_right;
						}
						s.title = "id=" + news_id;
						s.value = dismiss_string;
					c1.appendChild(s);
						var t1 = document.createTextNode(construct_phrase(vbulletin_news_string, news_title));
					c1.appendChild(t1);
				var r2 = t.insertRow(t.rows.length);
				r2.id = 'r2_' + news_id;
					var c2 = r2.insertCell(0);
					c2.className = 'alt2 smallfont';
					c2.innerHTML = news_body + ' ';
					if (news_link && news_link != 'http://')
					{
						link_elem = document.createElement('a');
						link_elem.href = news_link;
						link_elem.target = '_blank';
						link_elem.innerHTML = view_string.bold();
						c2.appendChild(link_elem);
					}
			}
		}

		if (table_visible)
		{
			if (news_items.length)
			{
				// row to display all (even dismissed news)
				var r3 = t.insertRow(t.rows.length);
				var c3 = r3.insertCell(0);
				c3.className = (visible_messages ? 'tfoot' : 'alt1');
				c3.align = 'center';
				var a = document.createElement('a');
				a.href = show_all_news_link;
				a.innerHTML = show_all_news_string;

				// workaround an issue where the link color isn't applied properly
				if (c3.currentStyle)
				{
					a.style.color = c3.currentStyle.color;
				}
				else if (window.getComputedStyle && window.getComputedStyle(c3, null))
				{
					a.style.color = window.getComputedStyle(c3, null).color;
				}

				c3.appendChild(a);
			}


			// little bit of code to redo all the inserted table rows
			var rows = fetch_tags(fetch_object('news_table'), 'td');
			var last_row = 'alt1';
			for (i = 0; i < rows.length; i++)
			{
				if (rows[i].className == 'alt1' || rows[i].className == 'alt2')
				{
					last_row = rows[i].className;
				}
				else if (rows[i].className == 'alt2 smallfont')
				{
					if (last_row == 'alt1')
					{
						last_row = 'alt2';
					}
					else
					{
						rows[i].className = 'alt1 smallfont';
						last_row = 'alt1';
					}
				}
			}
		}
	}
}

// #############################################################################
if (AJAX_Compatible)
{
	dismissed_news = dismissed_news.split(',');

	YAHOO.util.Connect.asyncRequest("POST", "newsproxy.php", {
		success: news_loader,
		//scope: this,
		timeout: vB_Default_Timeout
	}, SESSIONURL);
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 26290 $
|| ####################################################################
\*======================================================================*/