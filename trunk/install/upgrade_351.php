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

define('THIS_SCRIPT', 'upgrade_351.php');
define('VERSION', '3.5.1');
define('PREV_VERSION', '3.5.0');

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
// Post Alter
if ($vbulletin->GPC['step'] == 1)
{
	// vBulletin says no, <cough>
	$upgrade->run_query(
		$upgrade_phrases['upgrade_351.php']['delete_vb_product'],
		"DELETE FROM " . TABLE_PREFIX . "product WHERE title = 'vbulletin'"
	);

	if (!$db->query_first("SELECT title FROM " . TABLE_PREFIX . "paymentapi WHERE title = 'Moneybookers'"))
	{
		$upgrade->run_query(
			$upgrade_phrases['upgrade_350b3.php']['paymentapi_data'],
			"INSERT INTO " . TABLE_PREFIX . "paymentapi
				(title, currency, recurring, classname, active, settings)
			VALUES
				('Moneybookers', 'usd,gbp', 0, 'moneybookers', 0, '')"
		);
	}

	$mb_settings =  array(
		'mbemail' => array(
			'type' => 'text',
			'value' => '',
			'validate' => 'string'
		),
		'mbsecret' => array(
			'type' => 'text',
			'value' => '',
			'validate' => 'string'
		)
	);

	$upgrade->run_query(
		sprintf($upgrade_phrases['upgrade_350b4.php']['adding_payment_api_x_settings'], 'moneybookers'),
		"UPDATE " . TABLE_PREFIX . "paymentapi
			SET settings = '" . $db->escape_string(serialize($mb_settings)) . "'
		WHERE classname = 'moneybookers'"
	);

	$upgrade->execute();
}

// #############################################################################
// FINAL step (notice the SCRIPTCOMPLETE define)
if ($vbulletin->GPC['step'] == 2)
{
	build_product_datastore();

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
