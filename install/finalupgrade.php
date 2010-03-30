<?#shebang#?><?php
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

error_reporting(E_ALL & ~E_NOTICE & ~8192);

define('THIS_SCRIPT', 'finalupgrade.php');

// #############################################################################
// require the code that makes it all work...
require_once('./upgradecore.php');

// #############################################################################
// welcome step
if ($vbulletin->GPC['step'] == 'welcome')
{
	if ($vbulletin->options['templateversion'] == FILE_VERSION)
	{
		echo "<blockquote><p>&nbsp;</p>";
		echo $upgrade_phrases['finalupgrade.php']['upgrade_start_message'];
		echo "<p>&nbsp;</p></blockquote>";
	}
	else
	{
		echo "<blockquote><p>&nbsp;</p>";
		echo sprintf($upgrade_phrases['finalupgrade.php']['upgrade_version_mismatch'], $vbulletin->options['templateversion'], FILE_VERSION);
		echo "<p>&nbsp;</p></blockquote>";
		print_upgrade_footer();
	}
}

// #############################################################################
// import vbulletin options
if ($vbulletin->GPC['step'] == 1)
{
	// options might need this, so lets sneak it in
	require_once(DIR . '/includes/class_bitfield_builder.php');
	vB_Bitfield_Builder::save($db);
	build_forum_permissions();

	vBulletinHook::build_datastore($db);
	build_product_datastore();

	require_once(DIR . '/includes/adminfunctions_options.php');

	if (!($xml = file_read(DIR . '/install/vbulletin-settings.xml')))
	{
		echo '<p>' . sprintf($vbphrase['file_not_found'], 'vbulletin-settings.xml') . '</p>';
		print_cp_footer();
	}

	if (isset($vbulletin->options['showdeficon']))
	{
		if ($vbulletin->options['showdeficon'] == 1)
		{ // lets show that bug who's boss! (Scott)
			$vbulletin->options['showdeficon'] = "images/icons/icon1.gif";
		}
	}

	echo '<p>' . sprintf($vbphrase['importing_file'], 'vbulletin-settings.xml');

	xml_import_settings($xml);
	echo "<br /><span class=\"smallfont\"><b>$vbphrase[ok]</b></span></p>";
}

// #############################################################################
// import admin help
if ($vbulletin->GPC['step'] == 2)
{
	require_once(DIR . '/includes/adminfunctions_help.php');

	if (!($xml = file_read(DIR . '/install/vbulletin-adminhelp.xml')))
	{
		echo '<p>' . sprintf($vbphrase['file_not_found'], 'vbulletin-adminhelp.xml') . '</p>';
		print_cp_footer();
	}

	echo '<p>' . sprintf($vbphrase['importing_file'], 'vbulletin-adminhelp.xml');

	xml_import_help_topics($xml);
	echo "<br /><span class=\"smallfont\"><b>$vbphrase[ok]</b></span></p>";
}

// #############################################################################
// import language
if ($vbulletin->GPC['step'] == 3)
{
	require_once(DIR . '/includes/adminfunctions_language.php');

	if (!($xml = file_read(DIR . '/install/vbulletin-language.xml')))
	{
		echo '<p>' . sprintf($vbphrase['file_not_found'], 'vbulletin-language.xml') . '</p>';
		print_cp_footer();
	}

	echo '<p>' . sprintf($vbphrase['importing_file'], 'vbulletin-language.xml');

	xml_import_language($xml);

// vB 中文修改开始：导入繁体中文语言文件
	// 获取繁体中文语言的 ID
	$languageid = $db->query_first("SELECT languageid FROM " . TABLE_PREFIX . "language WHERE languagecode='zh-TW'");
	if (!empty($languageid['languageid']))
	{
		if (!($xml = file_read('./install/vbulletin-language-tc.xml')))
		{
			echo '<p>' . sprintf($vbphrase['file_not_found'], 'vbulletin-language-tc.xml') . '</p>';
			print_cp_footer();
		}

		echo '<p>' . sprintf($vbphrase['importing_file'], 'vbulletin-language-tc.xml (繁體中文)');

		xml_import_language($xml, $languageid['languageid'], NULL, 1);
	}
// vB 中文修改结束：导入繁体中文语言文件

	// Remove Extra Custom Pharse
	$db->query("DELETE FROM " . TABLE_PREFIX . "phrase WHERE languageid = 0 AND (username = '' OR username IN ('yoching', 'Mez', 'Jelsoft'))");

	build_language();
	build_language_datastore();
	echo "<br /><span class=\"smallfont\"><b>$vbphrase[ok]</b></span></p>";
}

// #############################################################################
// import style
if ($vbulletin->GPC['step'] == 4)
{
	require_once(DIR . '/includes/adminfunctions_template.php');

	if (!($xml = file_read(DIR . '/install/vbulletin-style.xml')))
	{
		echo '<p>' . sprintf($vbphrase['file_not_found'], 'vbulletin-style.xml') . '</p>';
		print_cp_footer();
	}

	echo '<p>' . sprintf($vbphrase['importing_file'], 'vbulletin-style.xml');

	xml_import_style($xml);
	build_all_styles();
	echo "<br /><span class=\"smallfont\"><b>$vbphrase[ok]</b></span></p>";
}

if ($vbulletin->GPC['step'] == 5)
{
	echo "<p>本步骤探测 word 表是否已经修改为正确的字段。</p>";

	$checkword = $db->query_first("DESCRIBE " . TABLE_PREFIX . "word title");

	if (substr($checkword['Type'], 0, 4) == 'char')
	{
		$query[] = "ALTER TABLE " . TABLE_PREFIX . "word CHANGE title title VARCHAR(50) NOT NULL";
		$explain[] = sprintf($vbphrase['alter_table'], TABLE_PREFIX . "word");
	}
	
	$db->hide_errors();
	$db->query_first("SELECT score FROM " . TABLE_PREFIX . "word LIMIT 1");
	if ($db->errno() != 0)
	{
		$query[] = "ALTER TABLE " . TABLE_PREFIX . "word ADD score INT(10) NOT NULL";
		$explain[] = sprintf($vbphrase['alter_table'], TABLE_PREFIX . "word");
	}
	$db->query_first("SELECT dateline FROM " . TABLE_PREFIX . "word LIMIT 1");
	if ($db->errno() != 0)
	{
		$query[] = "ALTER TABLE " . TABLE_PREFIX . "word ADD dateline INT(10) NOT NULL";
		$explain[] = sprintf($vbphrase['alter_table'], TABLE_PREFIX . "word");
	}
	$db->errno = 0;
	$db->show_errors();
	exec_queries();

	echo "<br /><span class=\"smallfont\"><b>$vbphrase[ok]</b></span></p>";
	
}

if ($vbulletin->GPC['step'] == 6)
{
	$gotopage = '../' . $vbulletin->config['Misc']['admincpdir'] . '/index.php';

	echo '<p align="center" class="smallfont"><a href="' . $gotopage . '">' . $vbphrase['proceed'] . '</a></p>';
	echo "\n<script type=\"text/javascript\">\n";
	echo "window.location=\"$gotopage\";";
	echo "\n</script>\n";

	print_upgrade_footer();
	exit;
}


// #############################################################################

print_next_step();
print_upgrade_footer();

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 31381 $
|| ####################################################################
\*======================================================================*/
?>