<?#shebang#?><?php
/*======================================================================*\
|| #################################################################### ||
|| # vBulletin [#]version[#] - Licence Number [#]license[#]
|| # ---------------------------------------------------------------- # ||
|| # Copyright �2000-[#]year[#] Jelsoft Enterprises Ltd. All Rights Reserved. ||
|| # This file may not be redistributed in whole or significant part. # ||
|| # ---------------- VBULLETIN IS NOT FREE SOFTWARE ---------------- # ||
|| # http://www.vbulletin.com | http://www.vbulletin.com/license.html # ||
|| #################################################################### ||
\*======================================================================*/

error_reporting(E_ALL & ~E_NOTICE & ~8192);

define('THIS_SCRIPT', 'upgrade_350b2.php');
define('VERSION', '3.5.0 Beta 2');
define('PREV_VERSION', '3.5.0 Beta 1');

$phrasegroups = array();
$specialtemplates = array();

// #############################################################################
// require the code that makes it all work...
require_once('./upgradecore.php');

// #############################################################################
// welcome step
if ($vbulletin->GPC['step'] == 'welcome')
{
	if ($vbulletin->options['templateversion'] == PREV_VERSION)
	{
		echo "<blockquote><p>&nbsp;</p>";
		echo "$vbphrase[upgrade_start_message]";
		echo "<p>&nbsp;</p></blockquote>";
	}
	else
	{
		echo "<blockquote><p>&nbsp;</p>";
		echo "$vbphrase[upgrade_wrong_version]";
		echo "<p>&nbsp;</p></blockquote>";
		print_upgrade_footer();
	}
}

// #############################################################################
if ($vbulletin->GPC['step'] == 1)
{
	$upgrade->add_field(
		sprintf($upgrade_phrases['upgrade_300b3.php']['altering_x_table'], 'forum', 1, 3),
		'forum',
		'title_clean',
		'varchar',
		array('length' => 100, 'attributes' => FIELD_DEFAULTS)
	);

	$upgrade->add_field(
		sprintf($upgrade_phrases['upgrade_300b3.php']['altering_x_table'], 'forum', 2, 3),
		'forum',
		'description_clean',
		'text',
		FIELD_DEFAULTS
	);

	$upgrade->run_query(
		sprintf($upgrade_phrases['upgrade_300b3.php']['altering_x_table'], 'forum', 3, 3),
		"ALTER TABLE " . TABLE_PREFIX . "forum CHANGE description description TEXT"
	);

	$upgrade->execute();
}

// #############################################################################
// FINAL step (notice the SCRIPTCOMPLETE define)
if ($vbulletin->GPC['step'] == 2)
{
	$forums = $db->query_read("
		SELECT title, description, forumid
		FROM " . TABLE_PREFIX . "forum
	");
	while ($forum = $db->fetch_array($forums))
	{
		$title_clean = htmlspecialchars_uni(str_replace('&amp;', '&', strip_tags($forum['title'])));
		$description_clean = htmlspecialchars_uni(str_replace('&amp;', '&', strip_tags($forum['description'])));
		$db->query_write("
			UPDATE " . TABLE_PREFIX . "forum
			SET title_clean = '" . $db->escape_string($title_clean) . "',
				description_clean = '" . $db->escape_string($description_clean) . "'
			WHERE forumid = $forum[forumid]
		");
	}

	// rebuild forum cache to refelct the queries we just performed
	build_forum_permissions();

	// tell log_upgrade_step() that the script is done
	define('SCRIPTCOMPLETE', true);
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
