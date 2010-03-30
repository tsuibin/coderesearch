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

// ######################## SET PHP ENVIRONMENT ###########################
error_reporting(E_ALL & ~E_NOTICE & ~8192);

// ##################### DEFINE IMPORTANT CONSTANTS #######################
define('THIS_SCRIPT', 'install.php');
define('VERSION', '3.8.4'); // change this in class_core as well!

define('TIMENOW', time());

// ########################## REQUIRE BACK-END ############################

if ($_GET['step'] > 2 OR $_POST['step'] > 2)
{
	require_once('./installcore.php');
	// connected to the database now lets load schema
	require_once(DIR . '/install/mysql-schema.php');
}
else
{
	if ($_ENV['REQUEST_URI'] OR $_SERVER['REQUEST_URI'])
	{
		$scriptpath = $_SERVER['REQUEST_URI'] ? $_SERVER['REQUEST_URI'] : $_ENV['REQUEST_URI'];
	}
	else
	{
		if ($_ENV['PATH_INFO'] OR $_SERVER['PATH_INFO'])
		{
			$scriptpath = $_SERVER['PATH_INFO'] ? $_SERVER['PATH_INFO']: $_ENV['PATH_INFO'];
		}
		else if ($_ENV['REDIRECT_URL'] OR $_SERVER['REDIRECT_URL'])
		{
			$scriptpath = $_SERVER['REDIRECT_URL'] ? $_SERVER['REDIRECT_URL']: $_ENV['REDIRECT_URL'];
		}
		else
		{
			$scriptpath = $_SERVER['PHP_SELF'] ? $_SERVER['PHP_SELF'] : $_ENV['PHP_SELF'];
		}

		if ($_ENV['QUERY_STRING'] OR $_SERVER['QUERY_STRING'])
		{
			$scriptpath .= '?' . ($_SERVER['QUERY_STRING'] ? $_SERVER['QUERY_STRING'] : $_ENV['QUERY_STRING']);
		}
	}
	define('SCRIPTPATH', $scriptpath);
	define('SKIPDB', true);

	require_once('./installcore.php');
}

// ########################################################################
// ######################### START MAIN SCRIPT ############################
// ########################################################################

if ($vbulletin->GPC['step'] == 'welcome')
{
	echo "<blockquote>\n";
	echo $install_phrases['welcome'];
	if (function_exists('mmcache_get'))
	{
		echo $install_phrases['turck'];
	}
	echo "</blockquote>\n";
}

if ($vbulletin->GPC['step'] == 1)
{
	if (!file_exists(DIR . '/includes/config.php'))
	{
		$vbulletin->GPC['step']--;
		echo "<p>{$install_phrases['cant_find_config']}</p>";
	}
	else if (!is_readable(DIR . '/includes/config.php'))
	{
		$vbulletin->GPC['step']--;
		echo "<p>{$install_phrases['cant_read_config']}</p>";
	}
	else
	{
		echo "<p>{$install_phrases['config_exists']}</p>";
	}
}

if ($vbulletin->GPC['step'] == 2)
{
	// turn off errors
	$db->hide_errors();

	if (!function_exists($db->functions['connect']))
	{
		echo "<p>" . sprintf($install_phrases['database_functions_not_detected'], $vbulletin->config['Database']['dbtype']) . "</p>";
		define('HIDEPROCEED', true);
	}
	else
	{
		// make database connection
		$db->connect(
			$vbulletin->config['Database']['dbname'],
			$vbulletin->config['MasterServer']['servername'],
			$vbulletin->config['MasterServer']['port'],
			$vbulletin->config['MasterServer']['username'],
			$vbulletin->config['MasterServer']['password'],
			$vbulletin->config['MasterServer']['usepconnect'],
			$vbulletin->config['SlaveServer']['servername'],
			$vbulletin->config['SlaveServer']['port'],
			$vbulletin->config['SlaveServer']['username'],
			$vbulletin->config['SlaveServer']['password'],
			$vbulletin->config['SlaveServer']['usepconnect']
		);

		$connect_errno = $db->errno();
		$connect_error = ($db->error ? $db->error : $db->error());

		if (!empty($vbulletin->config['Database']['force_sql_mode']) AND $db->connection_master)
		{
			$db->force_sql_mode('');
			// small hack to prevent the above query from generating an error below
			$db->query_read('SELECT 1 + 1');
		}

		echo "<p>{$install_phrases['attach_to_db']}</p>";

		if ($db->connection_master)
		{
// vB 中文: 获得 MySQL 版本号
			$mysqlversion = $db->query_first("SELECT version() AS version");
			define('MYSQL_VERSION', $mysqlversion['version']);
// vB 中文
// vB 中文: 检查 $config['Mysqli']['charset']
			if (version_compare(MYSQL_VERSION, '4.1', '<') AND !empty($vbulletin->config['Mysqli']['charset']))
			{
				echo "<p>{$install_phrases['config_misc_charset_error']}</p>";
				define('HIDEPROCEED', true);
			}
			else
			{
				// 重新生成错误
				$db->select_db($vbulletin->config['Database']['dbname']);
// vB 中文
			if ($connect_errno)
			{ // error found
				if ($connect_errno == 1049)
				{
					echo "<p>{$install_phrases['no_db_found_will_create']}</p>";
					$db->query_write("CREATE DATABASE " . $vbulletin->config['Database']['dbname']);
					echo "<p>{$install_phrases['attempt_to_connect_again']}</p>";
					$db->select_db($vbulletin->config['Database']['dbname']);
					if ($db->errno() == 1049)
					{ // unable to create database
						echo "<p>{$install_phrases['unable_to_create_db']}</p>";
						define('HIDEPROCEED', true);
					}
					else
					{
						echo "<p>{$install_phrases['database_creation_successful']}</p>";
					}
				}
				else
				{ // Unknown Error
					echo "<p>{$install_phrases['connect_failed']}</p>";
					echo "<p>" . sprintf($install_phrases['db_error_num'], $connect_errno) . "</p>";
					echo "<p>" . sprintf($install_phrases['db_error_desc'], $connect_error) . "</p>";
					echo "<p>{$install_phrases['check_dbserver']}</p>";
					define('HIDEPROCEED', true);
				}
			}
			else
			{ // connection suceeded and database already exists
				echo "<p>{$install_phrases['connection_succeeded']}</p>";

				if (empty($vbulletin->config['Database']['force_sql_mode']))
				{
					// check to see if MySQL is running strict mode and recommend disabling it
					$strict_mode_check = $db->query_first("SHOW VARIABLES LIKE 'sql\\_mode'");
					if (strpos(strtolower($strict_mode_check['Value']), 'strict_') !== false)
					{
						echo "<p><strong>{$install_phrases['mysql_strict_mode']}</strong></p>";
					}
				}

				// see if there's a user table already
				$db->query_write("SHOW FIELDS FROM " . trim($vbulletin->config['Database']['tableprefix']) . "user");
				if ($db->errno() == 0)
				{ // echo vB already exists message
					define('HIDEPROCEED', true);
					echo "<p><font size=\"+1\"><b>{$install_phrases['vb_installed_maybe_upgrade']}</b></font></p>";
				}

				echo "<p><a href=\"install.php?step=3&emptydb=true\">{$install_phrases['wish_to_empty_db']}</a></p>";
			}
// vB 中文: 检查 $config['Mysqli']['charset']
			}
// vB 中文
		}
		else
		{ // Unable to connect to database
			echo "<p>" . sprintf($install_phrases['db_error_desc'], $db->error) . "</p>";
			echo "<p><font size=\"+1\" color=\"red\"><b>{$install_phrases['no_connect_permission']}</b></font></p>";
			define('HIDEPROCEED', true);
		}
	}
	// end init db
}

if ($vbulletin->GPC['step'] == 3)
{
	$vbulletin->input->clean_array_gpc('r', array(
		'emptydb' => TYPE_BOOL,
		'confirm' => TYPE_BOOL,
	));

	if ($vbulletin->GPC['emptydb'])
	{
		if (!$vbulletin->GPC['confirm'])
		{
			$skipstep = true;
			define('HIDEPROCEED', true);

			$tables = array();
			$tables_result = $db->query_read("SHOW TABLES");
			while ($table = $db->fetch_array($tables_result, DBARRAY_NUM))
			{
				$tables["$table[0]"] = $table[0];
			}

			$default_tables = array_keys($schema['CREATE']['query']);

			echo "<script type=\"text/javascript\" src=\"../clientscript/yui/yahoo-dom-event/yahoo-dom-event.js\"></script>";
			echo "<script type=\"text/javascript\" src=\"../clientscript/vbulletin_global.js\"></script>";
			print_form_header('install', '');
			construct_hidden_code('step', 3);
			construct_hidden_code('emptydb', 'true');
			construct_hidden_code('confirm', 'true');
			print_table_header($install_phrases['reset_database']);
			print_description_row($install_phrases['delete_tables_instructions']);
			print_description_row("<label><input type=\"checkbox\" id=\"allbox\" onclick=\"js_check_all(this.form)\" />$install_phrases[select_deselect_all_tables]</label>", false, 2, "thead");

			$options = '';
			foreach ($tables AS $table)
			{
				if (substr($table, 0, strlen(TABLE_PREFIX)) == TABLE_PREFIX)
				{
					$table_basename = substr($table, strlen(TABLE_PREFIX));

					if (in_array($table_basename, $default_tables))
					{
						$checked = ' checked="checked"';
						$class = 'alt2';
					}
					else
					{
						$checked = '';
						$class = 'alt1';
					}

					$options .= "<label class=\"$class\" style=\"float:$stylevar[left]; display:block; width:250px; margin:0px 6px 6px 0px\"><input type=\"checkbox\" name=\"drop[]\" value=\"$table\"$checked />" . TABLE_PREFIX . "<strong>$table_basename</strong></label>\n";
				}
				else
				{
					$options .= "<label class=\"alt1\" style=\"float:$stylevar[left]; display:block; width:250px; margin:0px 6px 6px 0px\"><input type=\"checkbox\" name=\"drop[]\" value=\"$table\" /><strong>$table</strong></label>\n";
				}
			}

			print_description_row($options);
			print_submit_row($install_phrases['delete_selected_tables']);

		}
		else
		{
			$vbulletin->input->clean_gpc('p', 'drop', TYPE_ARRAY_NOHTML);

			echo "<div><strong>{$install_phrases['resetting_db']}</strong></div><ul>";
			$result = $db->query_write("SHOW tables");
			while ($currow = $db->fetch_array($result, DBARRAY_NUM))
			{
				if (in_array($currow[0], $vbulletin->GPC['drop']))
				{
					$db->query_write("DROP TABLE IF EXISTS $currow[0]");
					echo "<li>" . sprintf($vbphrase['remove_table'], $currow[0]) . "</li>\n";
				}
			}
			echo '</ul><hr />';
		}
	}
	if (!$skipstep)
	{
// vB 中文: 根据 $config['Mysqli']['charset'] 修改数据库编码
		if (version_compare(MYSQL_VERSION, '4.1', '>='))
		{
			if (strtolower($vbulletin->config['Mysqli']['charset']) == 'utf8')
			{
				$charactersql = ' DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci';
			}
			elseif (strtolower($vbulletin->config['Mysqli']['charset']) == 'latin1')
			{
				$charactersql = ' DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci';
			}
			else
			{
				$charactersql = '';
			}
		}
		else
		{
			$charactersql = '';
		}
		if (!empty($charactersql))
		{
			$db->query_write("ALTER DATABASE `" . $vbulletin->config['Database']['dbname'] . "`" . $charactersql);
		}
// vB 中文
		$query =& $schema['CREATE']['query'];
		$explain =& $schema['CREATE']['explain'];
		exec_queries();
		if ($db->errno())
		{
			echo "<p>{$install_phrases['script_reported_errors']}</p>";
			echo "<p>{$install_phrases['errors_were']}</p>";
			echo "<p>" . sprintf($install_phrases['db_error_num'], $db->errno()) . "</p>";
			echo "<p>" . sprintf($install_phrases['db_error_desc'], $db->error()) . "</p>";
		}
		else
		{
			echo "<p>{$install_phrases['tables_setup']}</p>";
		}
	}
}

if ($vbulletin->GPC['step'] == 4)
{
	$query =& $schema['ALTER']['query'];
	$explain =& $schema['ALTER']['explain'];
	exec_queries();
}

if ($vbulletin->GPC['step'] == 5)
{
	$query =& $schema['INSERT']['query'];
	$explain =& $schema['INSERT']['explain'];
	exec_queries();
}

if ($vbulletin->GPC['step'] == 6)
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
	if (!($xml = file_read('./install/vbulletin-language-tc.xml')))
	{
		echo '<p>' . sprintf($vbphrase['file_not_found'], 'vbulletin-language-tc.xml') . '</p>';
		print_cp_footer();
	}

	echo '<p>' . sprintf($vbphrase['importing_file'], 'vbulletin-language-tc.xml (繁體中文)');

	xml_import_language($xml, NULL, NULL, 1);
	// vB 中文修改结束：导入繁体中文语言文件

	build_language();
	build_language_datastore();
	echo "<br /><span class=\"smallfont\"><b>$vbphrase[ok]</b></span></p>";
}

if ($vbulletin->GPC['step'] == 7)
{
	require_once(DIR . '/includes/adminfunctions_template.php');

	if (!($xml = file_read(DIR . '/install/vbulletin-style.xml')))
	{
		echo '<p>' . sprintf($vbphrase['file_not_found'], 'vbulletin-style.xml') . '</p>';
		print_cp_footer();
	}

	echo '<p>' . sprintf($vbphrase['importing_file'], 'vbulletin-style.xml');

	xml_import_style($xml);
	build_all_styles(0, 1);
	echo "<br /><span class=\"smallfont\"><b>$vbphrase[ok]</b></span></p>";
}

if ($vbulletin->GPC['step'] == 8)
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

if ($vbulletin->GPC['step'] == 9)
{
	require_once(DIR . '/includes/adminfunctions_options.php');

	define('HIDEPROCEED', true);
	$port = ((!empty($_SERVER['SERVER_PORT']) AND $_SERVER['SERVER_PORT'] != 80) ? ':' . intval($_SERVER['SERVER_PORT']) : '');
	$vboptions['bburl'] = 'http://' . $_SERVER['SERVER_NAME'] . $port . substr(SCRIPTPATH,0, strpos(SCRIPTPATH, '/install/'));
	$vboptions['homeurl'] = 'http://' . $_SERVER['SERVER_NAME'] . $port;
	$webmaster = 'webmaster@' . preg_replace('#^www\.#', '', $_SERVER['SERVER_NAME']);

	print_form_header(substr(THIS_SCRIPT, 0, -strlen('.php')), '');
	construct_hidden_code('step', ($vbulletin->GPC['step'] + 1));
	print_table_header($install_phrases['general_settings']);
	print_input_row($install_phrases['bbtitle'], 'vboptions[bbtitle]', 'Forums', 0, 40);
	print_input_row($install_phrases['hometitle'], 'vboptions[hometitle]', '', 0, 40);
	print_input_row($install_phrases['bburl'], 'vboptions[bburl]', $vboptions['bburl'], 0, 40);
	print_input_row($install_phrases['homeurl'], 'vboptions[homeurl]', $vboptions['homeurl'], 0, 40);
	print_input_row($install_phrases['webmasteremail'], 'vboptions[webmasteremail]', $webmaster, 0, 40);
	print_label_row($install_phrases['cookiepath'], '
		<fieldset>
			<legend>' . $install_phrases['suggested_settings'] . '</legend>
			<div style="padding:4px">
				<select name="vboptions[cookiepath]" tabindex="1" class="bginput">' .
					construct_select_options(fetch_valid_cookiepaths($vbulletin->script), '/') . '
				</select>
			</div>
		</fieldset>
		<br />
		<fieldset>
			<legend>' . $install_phrases['custom_setting'] . '</legend>
			<div style="padding:4px">
				<label for="cookiepatho"><input type="checkbox" id="cookiepatho" name="cookiepath_other" tabindex="1" value="1" />' . $install_phrases['use_custom_setting'] . '
				</label><br />
				<input type="text" class="bginput" size="25" name="cookiepath_value" value="" />
			</div>
		</fieldset>
	');
	print_label_row($install_phrases['cookiedomain'], '
		<fieldset>
			<legend>' . $install_phrases['suggested_settings'] . '</legend>
			<div style="padding:4px">
				<select name="vboptions[cookiedomain]" tabindex="1" class="bginput">' .
					construct_select_options(fetch_valid_cookiedomains($_SERVER['HTTP_HOST'], $install_phrases['blank']), '') . '
				</select>
			</div>
		</fieldset>
		<br />
		<fieldset>
			<legend>' . $install_phrases['custom_setting'] . '</legend>
			<div style="padding:4px">
				<label for="cookiedomaino"><input type="checkbox" id="cookiedomaino" name="cookiedomain_other" tabindex="1" value="1" />' . $install_phrases['use_custom_setting'] . '
				</label><br />
				<input type="text" class="bginput" size="25" name="cookiedomain_value" value="" />
			</div>
		</fieldset>
	');
	print_submit_row($vbphrase['proceed'], $vbphrase['reset']);

}

if ($vbulletin->GPC['step'] == 10)
{
	require_once(DIR . '/includes/adminfunctions_options.php');

	$vbulletin->input->clean_array_gpc('p', array(
		'vboptions'          => TYPE_ARRAY_NOHTML,
		'cookiepath_other'   => TYPE_BOOL,
		'cookiepath_value'   => TYPE_NOHTML,
		'cookiedomain_other' => TYPE_BOOL,
		'cookiedomain_value' => TYPE_NOHTML
	));

	$vbulletin->options =& $vbulletin->GPC['vboptions'];

	if (!($xml = file_read(DIR . '/install/vbulletin-settings.xml')))
	{
		echo '<p>' . sprintf($vbphrase['file_not_found'], 'vbulletin-settings.xml') . '</p>';
		print_cp_footer();
	}

	// vB 中文修改开始：默认不要启用全文搜索
	// Enable fulltext search for new installs
	$vbulletin->options['fulltextsearch'] = 0;
	// vB 中文修改结束

	if ($vbulletin->GPC['cookiepath_other'] AND $vbulletin->GPC['cookiepath_value'])
	{
		$vbulletin->options['cookiepath'] = $vbulletin->GPC['cookiepath_value'];
	}
	if ($vbulletin->GPC['cookiedomain_other'] AND $vbulletin->GPC['cookiedomain_value'])
	{
		$vbulletin->options['cookiedomain'] = $vbulletin->GPC['cookiedomain_value'];
	}

	$gdinfo = fetch_gdinfo();
	if ($gdinfo['version'] >= 2)
	{
		if ($gdinfo['freetype'] == 'freetype')
		{
			$vbulletin->options['regimagetype'] = 'GDttf';
		}
	}
	else
	{
		$vbulletin->options['hv_type'] = '0';
		$vbulletin->options['regimagetype'] = '';
	}

	// vB 中文修改开始：若浏览器使用繁体中文，那么设置繁体中文为默认
	if ($langfile == 'zh-tw')
	{
		$vbulletin->options['languageid'] = 2;
		require_once(DIR . '/includes/adminfunctions_language.php');
		build_language(2);
	}
	else
	{
	$languageinfo = $db->query_first("
		SELECT languageid
		FROM " . TABLE_PREFIX . "language
	");
	$vbulletin->options['languageid'] = $languageinfo['languageid'];
	}
	// vB 中文修改结束

	echo '<p>' . sprintf($vbphrase['importing_file'], 'vbulletin-settings.xml');

	xml_import_settings($xml);
	echo "<br /><span class=\"smallfont\"><b>$vbphrase[ok]</b></span></p>";
}

if ($vbulletin->GPC['step'] == 11)
{
	$vbulletin->input->clean_array_gpc('r', array(
		'username'        => TYPE_STR,
		'password'        => TYPE_STR,
		'confirmpassword' => TYPE_STR,
		'email'           => TYPE_STR,
	));
	define('HIDEPROCEED', true);

	print_form_header(substr(THIS_SCRIPT, 0, -strlen('.php')), '');
	construct_hidden_code('step', ($vbulletin->GPC['step'] + 1));
	print_table_header("{$install_phrases['fill_in_for_admin_account']}");
	print_input_row("<b>{$install_phrases['username']}</b>", 'username', $vbulletin->GPC['username']);
	print_password_row("<b>{$install_phrases['password']}</b>", 'password', $vbulletin->GPC['password']);
	print_password_row("<b>{$install_phrases['confirm_password']}</b>", 'confirmpassword', $vbulletin->GPC['confirmpassword']);
	print_input_row("<b>{$install_phrases['email_address']}</b>", 'email', $vbulletin->GPC['email']);
	print_submit_row($vbphrase['proceed'], $vbphrase['reset']);
}

if ($vbulletin->GPC['step'] == 12)
{
	$vbulletin->input->clean_array_gpc('p', array(
		'username'        => TYPE_STR,
		'password'        => TYPE_STR,
		'confirmpassword' => TYPE_STR,
		'email'           => TYPE_STR,
	));

	if (empty($vbulletin->GPC['username']) OR empty($vbulletin->GPC['password']) OR empty($vbulletin->GPC['confirmpassword']) OR empty($vbulletin->GPC['email']))
	{
		$vbulletin->GPC['step'] = $vbulletin->GPC['step'] - 2;
		echo "<p>{$install_phrases['complete_all_data']}</p>";

		$hiddenfields['username'] = $vbulletin->GPC['username'];
		$hiddenfields['password'] = $vbulletin->GPC['password'];
		$hiddenfields['confirmpassword'] = $vbulletin->GPC['confirmpassword'];
		$hiddenfields['email'] = $vbulletin->GPC['email'];
	}
	else if ($vbulletin->GPC['password'] != $vbulletin->GPC['confirmpassword'])
	{
		$vbulletin->GPC['step'] = $vbulletin->GPC['step'] - 2;
		echo "<p>{$install_phrases['password_not_match']}</p>";

		$hiddenfields['username'] = $vbulletin->GPC['username'];
		$hiddenfields['password'] = $vbulletin->GPC['password'];
		$hiddenfields['confirmpassword'] = $vbulletin->GPC['confirmpassword'];
		$hiddenfields['email'] = $vbulletin->GPC['email'];
	}
	else
	{
		$admin_defaults = array('showsignatures', 'showavatars', 'showimages', 'adminemail', 'dstauto' , 'receivepm', 'showusercss', 'receivefriendemailrequest', 'vm_enable');
		$admin_useroption = 0;
		foreach ($admin_defaults AS $bitfield)
		{
			$admin_useroption |= $vbulletin->bf_misc_useroptions["$bitfield"];
		}

		require_once(DIR . '/includes/functions_user.php');
		$salt = fetch_user_salt(3);
		/*insert query*/
// vB 中文修改开始: 管理员默认时区 GMT+8
		$db->query_write("
			INSERT INTO " . TABLE_PREFIX . "user
				(username, salt, password, email, usertitle, joindate, lastvisit, lastactivity, usergroupid, passworddate, options, showvbcode, timezoneoffset)
			VALUES (
				'" . $db->escape_string(htmlspecialchars_uni($vbulletin->GPC['username'])) . "',
				'" . $db->escape_string($salt) . "',
				'" . $db->escape_string(md5(md5($vbulletin->GPC['password']) . $salt)) . "',
				'" . $db->escape_string($vbulletin->GPC['email']) . "',
				'" . $db->escape_string($install_phrases['usergroup_admin_usertitle']) . "',
				" . TIMENOW . ",
				" . TIMENOW . ",
				" . TIMENOW . ",
				6,
				FROM_UNIXTIME(" . TIMENOW . "),
				$admin_useroption,
				2,
				8
			)
		");
// vB 中文修改结束
		$userid = $db->insert_id();
		/*insert query*/
		$db->query_write("
			INSERT INTO " . TABLE_PREFIX . "usertextfield
				(userid)
			VALUES
				($userid)
		");
		/*insert query*/
		$db->query_write("
			INSERT INTO " . TABLE_PREFIX . "userfield
				(userid)
			VALUES
				($userid)
		");
		/*insert query*/
		$db->query_write("INSERT INTO " . TABLE_PREFIX . "administrator
			(userid, adminpermissions)
		VALUES
			($userid, " . (array_sum($vbulletin->bf_ugp_adminpermissions)-3) . ")
		");
		/*insert query*/
		$db->query_write("INSERT INTO " . TABLE_PREFIX . "moderator
			(userid, forumid, permissions, permissions2)
		VALUES
			(
				$userid,
				-1,
				" . (array_sum($vbulletin->bf_misc_moderatorpermissions) - ($vbulletin->bf_misc_moderatorpermissions['newthreademail'] + $vbulletin->bf_misc_moderatorpermissions['newpostemail'])) . ",
				" . (array_sum($vbulletin->bf_misc_moderatorpermissions2)) . "
			)
		");

		echo "<p>{$install_phrases['admin_added']}</p>";
	}
}

if ($vbulletin->GPC['step'] == 13)
{
	build_image_cache('smilie');
	build_image_cache('avatar');
	build_image_cache('icon');
	build_bbcode_cache();
	require_once(DIR . '/includes/functions_databuild.php');
	build_user_statistics();
	build_forum_child_lists();
	build_forum_permissions();
	require_once(DIR . '/includes/functions_cron.php');
	build_cron_next_run();
	require_once(DIR . '/includes/adminfunctions_attachment.php');
	build_attachment_permissions();
	require_once(DIR . '/includes/class_bitfield_builder.php');
	vB_Bitfield_Builder::save($db);

	echo "<blockquote>\n";
	echo "<p>" . sprintf($install_phrases['install_complete'], $vbulletin->config['Misc']['admincpdir']) . "</p>\n";
	echo "</blockquote>\n";

	define('HIDEPROCEED', true);
}

print_next_step();
print_upgrade_footer();

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 31739 $
|| ####################################################################
\*======================================================================*/
?>