<?php
/*======================================================================*\
|| #################################################################### ||
|| # vBulletin [#]version[#] - Licence Number [#]license[#]
|| # ---------------------------------------------------------------- # ||
|| # Copyright 2000-[#]year[#] Jelsoft Enterprises Ltd. All Rights Reserved. ||
|| # This file may not be redistributed in whole or significant part. # ||
|| # ---------------- VBULLETIN IS NOT FREE SOFTWARE ---------------- # ||
|| # http://www.vbulletin.com | http://www.vbulletin.com/license.html # ||
|| #################################################################### ||
\*======================================================================*/

if (!isset($GLOBALS['vbulletin']->db))
{
	exit;
}

// display the credits table for use in admin/mod control panels

print_form_header('index', 'home');
print_table_header($vbphrase['vbulletin_developers_and_contributors']);
print_column_style_code(array('white-space: nowrap', ''));
print_label_row('<b>' . $vbphrase['software_developed_by'] . '</b>', '
	<a href="http://www.jelsoft.com/" target="vbulletin">Jelsoft Enterprises Limited</a>
', '', 'top', NULL, false);
print_label_row('<b>' . $vbphrase['product_manager'] . '</b>', '
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=1034" target="vbulletin">Kier Darby</a>
', '', 'top', NULL, false);
print_label_row('<b>' . $vbphrase['business_development'] . '</b>', '
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=2" target="vbulletin">James Limm</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=22709" target="vbulletin">Ashley Busby</a>
', '', 'top', NULL, false);
print_label_row('<b>' . $vbphrase['software_development'] . '</b>', '
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=1034" target="vbulletin">Kier Darby</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=224" target="vbulletin">Freddie Bingham</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=1814" target="vbulletin">Scott MacVicar</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=37" target="vbulletin">Mike Sullivan</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=24628" target="vbulletin">Jerry Hutchings</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=218637" target="vbulletin">Darren Gordon</a>
', '', 'top', NULL, false);
print_label_row('<b>' . $vbphrase['graphics_development'] . '</b>', '
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=1034" target="vbulletin">Kier Darby</a>,
	<a href="http://www.meshweaver.com" target="vbulletin">Fabio Passaro</a>
', '', 'top', NULL, false);
print_label_row('<b>' . $vbphrase['other_contributions_from'] . '</b>', '
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=2026" target="vbulletin">Jake Bunce</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=65" target="vbulletin">Doron Rosenberg</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=219" target="vbulletin">Overgrow</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=2751" target="vbulletin">Kevin Schumacher</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=5755" target="vbulletin">Chen Avinadav</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=11606" target="vbulletin">Floris Fiedeldij Dop</a>,
	<a href="http://www.vbulletin-germany.com/forum/member.ph' . 'p?u=2" target="vbulletin">Stephan \'pogo\' Pogodalla</a>,
	<a href="http://www.vbulletin-germany.com/forum/member.ph' . 'p?u=274" target="vbulletin">Michael \'Mystics\' K&ouml;nig</a>,
	<a href="http://www.vbulletin.com/forum/member.ph' . 'p?u=43043" target="vbulletin">Martin Meredith</a>,
	<a href="http://www.vikjavev.com/hovudsida/umtestside.ph' . 'p" target="vbulletin">Torstein H&oslash;nsi</a>,
	<a href="http://www.famfamfam.com/lab/icons/silk/" target="vbulletin">Mark James</a>
', '', 'top', NULL, false);
print_label_row('<b>' . $vbphrase['copyright_enforcement_by'] . '</b>', '
	<a href="http://www.piratereports.com/" target="vbulletin">Pirate Reports</a>
', '', 'top', NULL, false);
print_table_footer();

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 27843 $
|| ####################################################################
\*======================================================================*/
?>