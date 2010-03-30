<?php
/*======================================================================*\
|| #################################################################### ||
|| # vBulletin [#]version[#] - Licence Number [#]license[#]
|| # ---------------------------------------------------------------- # ||
|| # Copyright ?000-[#]year[#] Jelsoft Enterprises Ltd. All Rights Reserved. ||
|| # This file may not be redistributed in whole or significant part. # ||
|| # ---------------- VBULLETIN IS NOT FREE SOFTWARE ---------------- # ||
|| # http://www.vbulletin.com | http://www.vbulletin.com/license.html # ||
|| #################################################################### ||
\*======================================================================*/

error_reporting(E_ALL & ~E_NOTICE & ~8192);

// moved from upgradecore to here
$stylevar = array(
	'textdirection' => 'ltr',
	'left' => 'left',
	'right' => 'right',
	'languagecode' => 'zh_CN',
	'charset' => 'UTF-8'
);

$authenticate_phrases['upgrade_title'] = '简体中文版升级系统';
$authenticate_phrases['enter_system'] = '进入升级系统';
$authenticate_phrases['enter_cust_num'] = '请输入您的客户号';
$authenticate_phrases['customer_number'] = '客户号';
$authenticate_phrases['cust_num_explanation'] = '这是您登录 vBulletin 客户区使用的客户号';
$authenticate_phrases['cust_num_success'] = '客户号验证成功。';
$authenticate_phrases['redirecting'] = '正在重定向……';

#####################################
# upgradecore phrases
#####################################
$upgradecore_phrases['vb3_upgrade_system'] = 'vBulletin 3.8 中文版升级系统';
$upgradecore_phrases['please_login'] = '请登录:';
$upgradecore_phrases['username'] = '用户名';
$upgradecore_phrases['password'] = '密码';
$upgradecore_phrases['login'] = ' 登录 ';
$upgradecore_phrases['php_version_too_old'] = 'vBulletin 3.8 需要 PHP 版本 4.3.3 或更高版本。您的 PHP 版本是 ' . PHP_VERSION . '，请联系主机商升级。';
$upgradecore_phrases['mysql_version_too_old'] = 'vBulletin 3.8 需要 MySQL 版本 4.0.16 或更高版本。您的 MySQL 版本是 %1$s，请联系主机商升级。';
$upgradecore_phrases['ensure_config_exists'] = '请确认您已经创建了 vB3 的新目录结构';
$upgradecore_phrases['mysql_strict_mode'] = 'MySQL 正运行在 Strict 模式。您可以继续，但是 vBulletin 的某些功能会不正常。<strong>强烈建议</strong>您在 includes/config.php 文件中将 <code>$config[\'Database\'][\'force_sql_mode\']</code> 设置为 <code>true</code>!';
$upgradecore_phrases['step_x_of_y'] = ' (步骤 %1$d ，共 %2$d 步)';
$upgradecore_phrases['unknown'] = '未知';
$upgradecore_phrases['file_not_found'] = '文件未找到!';
$upgradecore_phrases['xml_file_versions'] = 'XML 文件版本:';
$upgradecore_phrases['may_take_some_time'] = '(请注意一些步骤会花去较长时间，请耐心等待)';
$upgradecore_phrases['update_v_number'] = '正在更新版本号到 ' . VERSION . '… ';
$upgradecore_phrases['skipping_v_number_update'] = '正在跳过版本号更新，因为您安装的版本版本号更新... ';
$upgradecore_phrases['done'] = '完成';
$upgradecore_phrases['step_title'] = '步骤 %1$d) %2$s';
$upgradecore_phrases['batch_complete'] = '批处理完成！如果您没有被自动重定向，请点击右边的按钮。';
$upgradecore_phrases['next_batch'] = ' 下一批';
$upgradecore_phrases['next_step'] = '下一步 (%1$d/%2$d)';
$upgradecore_phrases['click_button_to_proceed'] = '点击右边的按钮继续。';
$upgradecore_phrases['page_x_of_y'] = '第 %1$d 页，共 %2$d 页';
$upgradecore_phrases['semicolons_file_intro'] = "下面的用户名包含分号( ; )\r\n*必须*在控制面板中修改:";
$upgradecore_phrases['dump_data_to_sql'] = '导出数据到 SQL 文件';
$upgradecore_phrases['choose_table_to_dump'] = '选择要备份的数据表';
$upgradecore_phrases['dump_tables'] = '备份数据表';
$upgradecore_phrases['dump_data_to_csv'] = '导出数据到 CSV 文件';
$upgradecore_phrases['backup_individual_table'] = '备份<b>单个数据表</b>';
$upgradecore_phrases['field_seperator'] = '字段分隔符';
$upgradecore_phrases['quote_character'] = '引号字符';
$upgradecore_phrases['show_column_names'] = '显示列名';
$upgradecore_phrases['dump_table'] = '备份数据表';
$upgradecore_phrases['vb_db_dump_completed'] = 'vBulletin 数据库备份完成';
$upgradecore_phrases['dump_all_tables'] = '* 备份所有数据表 *';
$upgradecore_phrases['dump_database_desc'] = '<p class="smallfont">在这里，您可以备份您的 vBulletin 数据库。</p>
		<p class="smallfont">请注意如果您有一个特别大的数据库，
		此程序<i>可能</i>无法将它完全备份下来。</p>
		<p class="smallfont">如果您想要一个安全的备份，请通过 Telnet 或 SSH 登录到您的服务器并使用 <i>mysqldump</i> 命令。
		更多信息，请参考
		<a href="http://www.vbulletin.com/manual/html/manual_database_backup" target="_blank">这里</a>。</p>';
$upgradecore_phrases['backup_after_upgrade'] = '<p class="smallfont">在执行升级前必须进行备份，如果升级完成请使用管理面板。</p>
		<p class="smallfont">更安全的备份方式是，通过 Telnet 或 SSH 登录到您的服务器并在命令行使用 <i>mysqldump</i> 命令。
		要了解更多信息，请<a href="http://www.vbulletin.com/docs/html/maintenance_ssh_backup" target="_blank">阅读这里</a>。</p>';
$upgradecore_phrases['vb_database_backup_system'] = 'vBulletin 数据库备份系统';
$upgradecore_phrases['eaccelerator_too_old'] = 'eAccelerator for PHP 必须升级到 0.9.3 或更高版本。请浏览<a href="http://www.vbulletin.com/forum/showthread.php?p=979044#post979044">这个帖子</a>以了解更多信息。';
$upgradecore_phrases['apc_too_old'] = '您的服务器正在运行 <a href="http://pecl.p' . 'hp.net/package/APC/">Alternative PHP Cache</a> (APC) 的一个版本，而这个版本不兼容 vBulletin。请升级到 APC 3.0.0 或更高版本。';
$upgradecore_phrases['mmcache_not_supported'] = 'Turck MMCache 已经被 eAcclerator 取代，不能正确支持 vBulletin。请浏览<a href="http://www.vbulletin.com/forum/showthread.php?p=979044#post979044">这个帖子</a>以了解更多信息。';
$upgradecore_phrases['altering_x_table'] = '正在修改 %1$s 数据表 (第 %2$d 个，共计 %3$d 个)';
$upgradecore_phrases['wrong_bitfield_xml'] = 'includes/xml/bitfield_vbulletin.xml 文件已过期。请确认您上传了正确的文件。';

// this should contain only characters which will show on the file system
$upgradecore_phrases['illegal_user_names'] = 'Illegal User Names.txt';

$phrasetype['global'] = '全局 (GLOBAL)';
$phrasetype['cpglobal'] = '控制面板全局 (Control Panel Global)';
$phrasetype['cppermission'] = '权限 (Permissions)';
$phrasetype['forum'] = '版面相关 (Forum-Related)';
$phrasetype['calendar'] = '日历 (Calendar)';
$phrasetype['attachment_image'] = '附件/图像 (Attachment/Image)';
$phrasetype['style'] = '风格工具 (Style Tools)';
$phrasetype['logging'] = '日志工具 (Logging Tools)';
$phrasetype['cphome'] = '控制面板首页 (Control Panel Home Pages)';
$phrasetype['promotion'] = '提升工具 (Promotion Tools)';
$phrasetype['user'] = '用户工具(全局) (User Tools (global))';
$phrasetype['help_faq'] = '论坛帮助管理 (FAQ / Help Management)';
$phrasetype['sql'] = 'SQL 工具 (SQL Tools)';
$phrasetype['subscription'] = '订阅工具 (Subscription Tools)';
$phrasetype['language'] = '语言工具 (Language Tools)';
$phrasetype['bbcode'] = 'BB 代码工具 (BB Code Tools)';
$phrasetype['stats'] = '统计工具 (Statistics Tools)';
$phrasetype['diagnostics'] = '诊断工具 (Diagnostic Tools)';
$phrasetype['maintenance'] = '维护工具 (Maintenance Tools)';
$phrasetype['profile'] = '用户资料栏目工具 (Profile Field Tools)';
$phrasetype['cprofilefield'] = '自定义资料栏目 (Custom Profile Fields)';
$phrasetype['thread'] = '主题工具 (Thread Tools)';
$phrasetype['timezone'] = '时区 (Timezones)';
$phrasetype['banning'] = '封禁工具 (Banning Tools)';
$phrasetype['reputation'] = '声望 (Reputation)';
$phrasetype['wol'] = '在线信息 (Who\\\'s Online)';
$phrasetype['threadmanage'] = '主题管理 (Thread Management)';
$phrasetype['pm'] = '悄悄话 (Private Messaging)';
$phrasetype['cpuser'] = '控制面板用户管理 (Control Panel User Management)';
$phrasetype['register'] = '注册 (Register)';
$phrasetype['accessmask'] = '访问权限 (Access Masks)';
$phrasetype['cron'] = '计划任务 (Scheduled Tasks)';
$phrasetype['moderator'] = '版主 (Moderators)';
$phrasetype['cpoption'] = '控制面板选项 (Control Panel Options)';
$phrasetype['cprank'] = '控制面板用户等级 (Control Panel User Ranks)';
$phrasetype['cpusergroup'] = '控制面板用户组 (Control Panel User Groups)';
$phrasetype['holiday'] = '节假日 (Holidays)';
$phrasetype['posting'] = '发帖 (Posting)';
$phrasetype['poll'] = '投票 (Polls)';
$phrasetype['fronthelp'] = '前台论坛帮助 (Frontend FAQ/Help)';
$phrasetype['search'] = '搜索 (Searching)';
$phrasetype['showthread'] = '显示主题 (Show Thread)';
$phrasetype['postbit'] = '帖子块 (Postbit)';
$phrasetype['forumdisplay'] = '版面显示 (Forum Display)';
$phrasetype['messaging'] = '即时消息 (Messaging)';
$phrasetype['inlinemod'] = '快速管理 (Inline Moderation)';
$phrasetype['plugins'] = '插件系统 (Plugin System)';
$phrasetype['front_end_error'] = '错误信息 (Error Messages)';
$phrasetype['front_end_redirect'] = '前台重定向信息 (Front-End Redirect Messages)';
$phrasetype['email_body'] = '邮件内容文本 (Email Body Text)';
$phrasetype['email_subj'] = '邮件主题文本 (Email Subject Text)';
$phrasetype['vbulletin_settings'] = '论坛设置 (vBulletin Settings)';
$phrasetype['cp_help'] = '控制面板帮助内容 (Control Panel Help Text)';
$phrasetype['faq_title'] = '论坛帮助标题 (FAQ Title)';
$phrasetype['faq_text'] = '论坛帮助内容 (FAQ Text)';
$phrasetype['stop_message'] = '控制面板停止信息 (Control Panel Stop Message)';
$phrasetype['reputationlevel'] = '声望级别 (Reputation Levels)';
$phrasetype['infraction'] = '用户违规 (User Infractions)';
$phrasetype['infractionlevel'] = '用户违规级别 (User Infraction Levels)';
$phrasetype['notice'] = '通知 (Notices)';
$phrasetype['prefix'] = '主题前缀 (Thread Prefixes)';
$phrasetype['prefixadmin'] = '主题前缀 (管理) (Thread Prefixes (Admin))';
$phrasetype['album'] = '相册 (Albums)';
$phrasetype['hvquestion'] = '真人验证问题 (Human Verification Questions)';
$phrasetype['socialgroups'] = '社会兴趣讨论组 (Social Groups)';

#####################################
# phrases for import systems
#####################################
$vbphrase['please_wait'] = '请等待';
$vbphrase['language'] = '语言';
$vbphrase['master_language'] = '主语言';
$vbphrase['admin_help'] = '管理员帮助';
$vbphrase['style'] = '风格';
$vbphrase['styles'] = '风格';
$vbphrase['settings'] = '设置';
$vbphrase['master_style'] = '主风格';
$vbphrase['templates'] = '模板';
$vbphrase['css'] = 'CSS';
$vbphrase['stylevars'] = '风格变量';
$vbphrase['replacement_variables'] = '替换变量';
$vbphrase['controls'] = '控制';
$vbphrase['rebuild_style_information'] = '重建风格信息';
$vbphrase['updating_style_information_for_each_style'] = '正在为每个风格更新风格信息';
$vbphrase['updating_styles_with_no_parents'] = '正在更新无父风格的风格集';
$vbphrase['updated_x_styles'] = '已更新 %1$s 个风格';
$vbphrase['no_styles_needed_updating'] = '没有风格需要更新';
$vbphrase['yes'] = '是';
$vbphrase['no'] = '否';


#####################################
# global upgrade phrases
#####################################
$vbphrase['vbulletin_message'] = 'vBulletin 信息';
$vbphrase['create_table'] = '正在创建 %1$s 数据表';
$vbphrase['remove_table'] = '正在删除 %1$s 数据表';
$vbphrase['alter_table'] = '正在修改 %1$s 数据表';
$vbphrase['update_table'] = '正在更新 %1$s 数据表';
$vbphrase['upgrade_start_message'] = "<p>此程序将把您的 vBulletin 升级到 <b>" . VERSION . "</b>。</p>\n<p>点击“下一步”按钮继续。</p>";
$vbphrase['upgrade_wrong_version'] = "<p>您的 vBulletin 版本不符合此程序的运行条件 (需要在版本 <b>" . PREV_VERSION . "</b> 的基础上运行)。</p>\n<p>请确认您运行的脚本是否正确。</p>\n<p>如果您确信正确，<a href=\"" . THIS_SCRIPT . "?step=1\">请点击这里继续运行</a>。</p>";
$vbphrase['file_not_found'] = '嗯？./install/%1$s 好像不存在！';
$vbphrase['importing_file'] = '正在导入 %1$s';
$vbphrase['ok'] = '完成';
$vbphrase['query_took'] = '查询花去 %1$s 秒执行。';
$vbphrase['done'] = '完成';
$vbphrase['proceed'] = '继续';
$vbphrase['reset'] = '重置';
$vbphrase['alter_table_step_x'] = '正在修改 %1$s 数据表 (步骤 %2$d ，共 %3$d 步)';
$vbphrase['vbulletin_copyright'] = 'vBulletin v' . VERSION . ', 版权所有 &copy;2000 - ' . date('Y') . ', Jelsoft Enterprises Ltd.';
$vbphrase['vbulletin_copyright_orig'] = $vbphrase['vbulletin_copyright'];
$vbphrase['processing_complete_proceed'] = '处理完成 - 继续';
$vbphrase['xml_error_x_at_line_y'] = 'XML 错误: %1$s 在行 %2$s';
$vbphrase['apply_critical_template_change_to_x'] = '正在为风格 ID %2$s 的模板 %1$s 进行安全修正';
#####################################
# upgrade_300b3.php phrases
#####################################

$upgrade_phrases['upgrade_300b3.php']['steps'] = array(
	1  => '创建新的 vBulletin 3 数据表',
	2  => '升级模板并进行修改查询',
	3  => '升级日历',
	4  => '修改论坛数据表',
	5  => '升级论坛最新贴信息',
	6  => '升级悄悄话信息',
	7  => '升级用户',
	8  => '修改用户数据表 (第一部分)',
	9  => '修改用户数据表 (第二部分)',
	10 => '升级公告数据表',
	11 => '修改头像/表情符号/信息图标数据表',
	12 => '修改附件数据表',
	13 => '升级附件 (第一部分)',
	14 => '升级附件 (第二部分)',
	15 => '升级编辑帖子记录',
	16 => '升级主题和帖子数据表',
	17 => '升级帖子以支持树型查看模式',
	18 => '修改其它数据表 (第一部分)',
	19 => '修改其它数据表 (第二部分)',
	20 => '升级 BB 代码系统',
	21 => '修改用户组数据表',
	22 => '升级论坛权限',
	23 => '升级版主权限',
	24 => '插入短语组',
	25 => '插入计划任务',
	26 => '更新设置 (第一部分)',
	27 => '更新设置 (第二部分)',
	28 => '导入 vbulletin-language.xml',
	29 => '导入 vbulletin-adminhelp.xml',
	30 => '修改风格数据表并删除替换集数据表',
	31 => '修改模板数据表',
	32 => '生成用户声望',
	33 => '基于存在的 vB2 风格创建 vB3 风格',
	34 => '翻译 vB2 替换变量为 vB3 风格/CSS/替换模板变量',
	35 => '移动原有自定义模板到它们相应的风格中',
	36 => '删除多余的样式数据表并清理翻译过程',
	37 => '导入 vbulletin-style.xml',
	38 => '建立风格信息',
	39 => '导入常见问题解答项目',
	40 => '检查不合法的用户名',
	41 => '导入设置并清理',
	42 => '成功升级到vBulletin ' . VERSION . '！'
);
$upgrade_phrases['upgrade_300b3.php']['tableprefix_not_empty'] = '$config[\'Database\'][\'tableprefix\'] 不是空的！';
$upgrade_phrases['upgrade_300b3.php']['tableprefix_not_empty_fix'] = "在安装进程中 config.php 的 \$config['Database']['tableprefix'] 参数必须为空。";
$upgrade_phrases['upgrade_300b3.php']['welcome'] = '<p style="font-size:14px;"><b>欢迎使用 vBulletin 3.8 中文版</b></p>
	<p>您即将升级您的论坛，因此它被自动关闭。</p>
	<p>点击<b>[下一步]</b>按钮将会在您的数据库“<i>%1$s</i>”上开始升级进程。</p>
	<p>为了避免安装时浏览器崩溃，我们强烈建议您关闭浏览器上的第三方工具栏，例如 <b>Google、MSN、Alexa</b> 工具栏等。</p>
	<p>建议您升级前备份您的整个数据库。<br /><a href="upgrade_300b3.php?step=backup"><b>如果您要备份数据库，请点击这里</b></a>。</p>';
$upgrade_phrases['upgrade_300b3.php']['safe_mode_warning'] = '您的 PHP 当前运行在安全模式。当运行在安全模式时我们无法设置程序超时限制。因此，备份您的数据库以便出错后恢复显得更加重要。';
$upgrade_phrases['upgrade_300b3.php']['upgrade_already_run'] = '我们侦测到您曾经尝试运行过此升级程序。您必须将现在的数据库恢复成 vB 2.2.x 的结构此升级程序才能继续运行。';
$upgrade_phrases['upgrade_300b3.php']['moving_maxloggedin_datastore'] = '正在移动 maxloggedin 模板到新数据表';
$upgrade_phrases['upgrade_300b3.php']['new_datastore_values'] = '正在创建新的 Datastore 值';
$upgrade_phrases['upgrade_300b3.php']['removing_special_templates'] = '正在从模板数据表中移动特定的模板';
$upgrade_phrases['upgrade_300b3.php']['removing_orphan_pms'] = '正在删除重复的悄悄话';
$upgrade_phrases['upgrade_300b3.php']['rename_calendar_events'] = '正在重命名 calendar_events 为 event';
$upgrade_phrases['upgrade_300b3.php']['altering_x_table'] = '正在修改 %1$s 数据表 (步骤 %2$d ，共 %3$d 步)';
$upgrade_phrases['upgrade_300b3.php']['droping_event_date'] = '从 event 数据表中删除事件日期';
$upgrade_phrases['upgrade_300b3.php']['changing_subject_to_title'] = '正在更改“subject”为“title”';
$upgrade_phrases['upgrade_300b3.php']['creating_pub_calendar'] = '正在创建公共日历';
$upgrade_phrases['upgrade_300b3.php']['creating_priv_calendar'] = '正在创建私有日历';
$upgrade_phrases['upgrade_300b3.php']['moving_pub_events'] = '正在移动公共事件到公共日历';
$upgrade_phrases['upgrade_300b3.php']['moving_priv_events'] = '正在移动私有事件到私有日历';
$upgrade_phrases['upgrade_300b3.php']['drop_public_field'] = '正在从事件表中删除 public 列';
$upgrade_phrases['upgrade_300b3.php']['convert_forum_options'] = '正在转换论坛选项储存方式';
$upgrade_phrases['upgrade_300b3.php']['dropping_option_fields'] = '正在删除选项 (步骤 %1$d ，共 %2$d 步)';
$upgrade_phrases['upgrade_300b3.php']['resetting_styleids'] = '正在重置 styleid 为默认论坛风格';
$upgrade_phrases['upgrade_300b3.php']['updating_forum_child_lists'] = '正在更新子论坛列表';
$upgrade_phrases['upgrade_300b3.php']['updating_counters_for_x'] = '正在更新论坛 <i>%1$s</i> 的计数器';
$upgrade_phrases['upgrade_300b3.php']['updating_lastpost_info_for_x'] = '正在更新论坛 <i>%1$s</i> 的最新帖信息';
$upgrade_phrases['upgrade_300b3.php']['converting_priv_msg_x'] = '正在转换悄悄话，%1$s';
$upgrade_phrases['upgrade_300b3.php']['insert_priv_msg_txt_from_x'] = '正在插入来自 <i>%1$s</i> 的悄悄话文本';
$upgrade_phrases['upgrade_300b3.php']['insert_priv_msg_from_x_to_x'] = '正在插入从 <i>%1$s</i> 发往 <i>%2$s</i> 的悄悄话';
$upgrade_phrases['upgrade_300b3.php']['update_priv_msg_multiple_recip'] = '正在更新悄悄话文本以显示多回执';
$upgrade_phrases['upgrade_300b3.php']['insert_priv_msg_receipts'] = '正在插入悄悄话回执';
$upgrade_phrases['upgrade_300b3.php']['dropping_vb2_pm_table'] = '正在删除 vBulletin 2 悄悄话数据表';
$upgrade_phrases['upgrade_300b3.php']['alter_user_table_for_vb3_pm'] = '正在修改用户数据表以支持 vB3 悄悄话系统';
$upgrade_phrases['upgrade_300b3.php']['alter_user_table_vb3_password'] = '正在修改用户数据表以支持 vB3 密码系统';
$upgrade_phrases['upgrade_300b3.php']['priv_msg_import_complete'] = '悄悄话导入完成';
$upgrade_phrases['upgrade_300b3.php']['upgrading_users_x'] = '正在升级用户，%1$s';
$upgrade_phrases['upgrade_300b3.php']['found_x_users'] = '此批找到 %1$d 位用户…';
$upgrade_phrases['upgrade_300b3.php']['updating_priv_messages_for_x'] = '正在更新用户 <i>%1$s</i> 的悄悄话总数';
$upgrade_phrases['upgrade_300b3.php']['inserting_user_details_usertextfield'] = '正在插入用户细节到 <i>usertextfield</i> 数据表';
$upgrade_phrases['upgrade_300b3.php']['user_upgrades_complete'] = '用户升级完成';
$upgrade_phrases['upgrade_300b3.php']['updating_user_table_options'] = '正在更新 user 数据表选项';
$upgrade_phrases['upgrade_300b3.php']['drop_user_option_fields'] = '正在删除用户选项 (步骤 %1$d ，共 3 步)';
$upgrade_phrases['upgrade_300b3.php']['update_access_masks'] = '正在更新用户权限';
$upgrade_phrases['upgrade_300b3.php']['convert_new_birthday_format'] = '正在转换生日到新格式';
$upgrade_phrases['upgrade_300b3.php']['insert_admin_perms_admin_table'] = '正在插入管理员权限到 administrator 数据表';
$upgrade_phrases['upgrade_300b3.php']['updating_announcements'] = '正在更新公告';
$upgrade_phrases['upgrade_300b3.php']['announcement_x'] = '公告: %1$s';
$upgrade_phrases['upgrade_300b3.php']['add_index_avatar_table'] = '正在添加索引到 avatar 数据表';
$upgrade_phrases['upgrade_300b3.php']['move_avatars_to_category'] = '正在移动头像到“标准头像”分类';
$upgrade_phrases['upgrade_300b3.php']['move_icons_to_category'] = '正在移动信息图标到“标准信息图标”分类';
$upgrade_phrases['upgrade_300b3.php']['move_smilies_to_category'] = '正在移动表情符号到“标准表情符号”分类';
$upgrade_phrases['upgrade_300b3.php']['update_avatars_per_page'] = '正在更新每页的头像';
$upgrade_phrases['upgrade_300b3.php']['updating_attachments'] = '正在更新附件…';
$upgrade_phrases['upgrade_300b3.php']['attachment_x'] = '附件: %1$d';
$upgrade_phrases['upgrade_300b3.php']['remove_orphan_attachments'] = '正在删除重复的附件';
$upgrade_phrases['upgrade_300b3.php']['populating_attachmenttype_table'] = '正在生成附件类型数据表';
$upgrade_phrases['upgrade_300b3.php']['updating_editpost_log'] = '正在升级编辑帖子记录，%1$s';
$upgrade_phrases['upgrade_300b3.php']['found_x_posts'] = '此批找到 %1$d 个帖子…';
$upgrade_phrases['upgrade_300b3.php']['post_x'] = '帖子: %1$d';
$upgrade_phrases['upgrade_300b3.php']['post_editlog_complete'] = '帖子编辑记录升级完成';
$upgrade_phrases['upgrade_300b3.php']['steps_may_take_several_minutes'] = '请注意，如果您数据库中有大量帖子，此步骤会花去<b>几分钟</b>的时间。';
$upgrade_phrases['upgrade_300b3.php']['altering_post_table'] = '正在修改 post 数据表…';
$upgrade_phrases['upgrade_300b3.php']['altering_thread_table'] = '正在修改 thread 数据表…';
$upgrade_phrases['upgrade_300b3.php']['inserting_moderated_threads'] = '正在插入等待验证的主题';
$upgrade_phrases['upgrade_300b3.php']['inserting_moderated_posts'] = '正在插入等待验证的帖子';
$upgrade_phrases['upgrade_300b3.php']['update_posts_support_threaded'] = '正在更新帖子以支持树型模式，%1$s';
$upgrade_phrases['upgrade_300b3.php']['found_x_threads'] = '此批找到 %1$d 个主题…';
$upgrade_phrases['upgrade_300b3.php']['threaded_update_complete'] = '主题查看模式升级完成';
$upgrade_phrases['upgrade_300b3.php']['emptying_search'] = '正在清空搜索索引';
$upgrade_phrases['upgrade_300b3.php']['emptying_wordlist'] = '正在清空词语列表';
$upgrade_phrases['upgrade_300b3.php']['remove_bbcodes_hardcoded_now'] = '正在删除内部定义的 BB 代码 ([B], [I], [U], [FONT={option}], [SIZE={option}], [COLOR={option}])';
$upgrade_phrases['upgrade_300b3.php']['inserting_quote_bbcode'] = '正在插入 [QUOTE=<i>用户名</i>]----[/QUOTE] BB 代码标签';
$upgrade_phrases['upgrade_300b3.php']['select_banned_groups'] = '请选择所有包含“封禁用户”的用户组';
$upgrade_phrases['upgrade_300b3.php']['explain_banned_groups'] = "在 vBulletin 3 中，“被封禁用户”的用户组需要明确指定。<br /><br />\n如果您有任何“被封禁用户”的用户组，请在这里选中那些组。";
$upgrade_phrases['upgrade_300b3.php']['user_groups'] = '用户组:';
$upgrade_phrases['upgrade_300b3.php']['update_some_usergroup_titles'] = '正在更新一些用户组的标题';
$upgrade_phrases['upgrade_300b3.php']['updating_usergroup_permissions'] = '正在更新用户组权限';
$upgrade_phrases['upgrade_300b3.php']['usergroup_x'] = '用户组: <i>%1$s</i>';
$upgrade_phrases['upgrade_300b3.php']['updating_usergroups'] = '正在更新用户组';
$upgrade_phrases['upgrade_300b3.php']['updating_generic_options'] = '正在更新用户组常规选项';
$upgrade_phrases['upgrade_300b3.php']['updating_usergroup_calendar'] = '正在更新用户组日历权限';
$upgrade_phrases['upgrade_300b3.php']['creating_priv_calendar_perms'] = '正在创建私人日历权限';
$upgrade_phrases['upgrade_300b3.php']['removing_orhpan_forum_perms'] = '正在删除重复的论坛权限';
$upgrade_phrases['upgrade_300b3.php']['backup_forum_perms'] = '正在备份论坛权限';
$upgrade_phrases['upgrade_300b3.php']['drop_old_forumperms'] = '正在删除原论坛权限数据表';
$upgrade_phrases['upgrade_300b3.php']['usergroup_x_forum_y'] = '用户组: <i>%1$s</i> 在论坛 <i>%2$s</i>';
$upgrade_phrases['upgrade_300b3.php']['reinsert_forum_perms'] = '正在以新格式重新插入论坛权限';
$upgrade_phrases['upgrade_300b3.php']['remove_forum_perms_backup'] = '正在删除论坛权限备份';
$upgrade_phrases['upgrade_300b3.php']['updating_moderator_perms'] = '正在更新版主权限';
$upgrade_phrases['upgrade_300b3.php']['moderator_x_forum_y'] = '论坛 <u>%2$s</u> 的版主 <i>%1$s</i> ';
$upgrade_phrases['upgrade_300b3.php']['deleted_not_needed'] = '已删除 - 不再相关。';
$upgrade_phrases['upgrade_300b3.php']['insert_phrase_groups'] = '正在插入短语组';
$upgrade_phrases['upgrade_300b3.php']['inserting_task_x'] = '正在插入任务 %1$d';
$upgrade_phrases['upgrade_300b3.php']['scheduling_x'] = '正在安排 %1$s';
$upgrade_phrases['upgrade_300b3.php']['update_setting_group_x'] = '正在更新设置组: <i>%1$s</i>';
$upgrade_phrases['upgrade_300b3.php']['update_settings_within_x'] = '正在更新设置位于组: <i>%1$s</i>';
$upgrade_phrases['upgrade_300b3.php']['insert_phrases_nonstandard_groups'] = '正在为非标准设置组插入短语';
$upgrade_phrases['upgrade_300b3.php']['insert_phrases_nonstandard_settings'] = '正在插入非标准设置的短语';
$upgrade_phrases['upgrade_300b3.php']['saving_your_settings'] = '正在保存您的设置为以后使用…';
$upgrade_phrases['upgrade_300b3.php']['building_lang_x'] = '正在建立语言: %1$s';
$upgrade_phrases['upgrade_300b3.php']['language_imported_sucessfully'] = '语言导入成功！';
$upgrade_phrases['upgrade_300b3.php']['ahelp_imported_sucessfully'] = '管理员帮助导入成功！';
$upgrade_phrases['upgrade_300b3.php']['renaming_style_table'] = '正在重命名 <b>style</b> 数据表';
$upgrade_phrases['upgrade_300b3.php']['removing_default_templates'] = '正在删除默认模板 (它们将稍后被替换)';
$upgrade_phrases['upgrade_300b3.php']['updating_template_format'] = '正在更新模板为新格式…';
$upgrade_phrases['upgrade_300b3.php']['updating_template_x'] = '正在更新模板: <i>%1$s</i>';
$upgrade_phrases['upgrade_300b3.php']['populating_reputation_levels'] = '正在生成用户声望级别数据表';
$upgrade_phrases['upgrade_300b3.php']['set_reputation_to_neutral'] = '设置所有用户为中立的声望';
$upgrade_phrases['upgrade_300b3.php']['bbtitle_vb3_style'] = '%1$s vBulletin 3 风格';
$upgrade_phrases['upgrade_300b3.php']['please_read_txt'] = '请仔细阅读下面的文本！';
$upgrade_phrases['upgrade_300b3.php']['replacement_upgrade_desc'] = '<p><b>注意:</b></p>
		<p>此系统将尝试翻译 vBulletin 2 的替换变量 (例如: <b>{firstaltcolor}</b>) 使其能够正常工作在
		vBulletin 3 中。这将把您默认的替换变量翻译成 vBulletin 3 的风格变量和 CSS 设置。</p>
		<p>此程序现在将扫描您的 vBulletin 2 风格并创建一个相应的 vBulletin 3 新风格。</p>
		<p>下面列出的风格包含您 vBulletin 2 变量的风格设置，并且可以直接在 vBulletin 3 中使用。</p>';
$upgrade_phrases['upgrade_300b3.php']['create_vb3_style_x'] = "正在创建 vBulletin 3 风格: <b>'%1\$s'</b>";
$upgrade_phrases['upgrade_300b3.php']['template_upgrade_desc'] = '<p><b>注意:</b></p>
		<p>vBulletin 3 的模板与 vBulletin 2 显著不同。因此，任何自定义模板实质上在 vBulletin 3
		中是无用的。</p>
		<p>但是，当您想修改 vBulletin 3 的模板时，您或许要参考以前在 vBulletin 2 中修改的模板。
		所以，此系统将创建包含您自定义模板的新风格。</p>
		<p>这些风格将<i>无法</i>在 vBulletin 3 中使用，创建它们只是为了方便您修改和参照。</p>';
$upgrade_phrases['upgrade_300b3.php']['create_vb2_refernce_style'] = "正在为您的模板集“<b>%1\$s</b>”创建一个引用风格";
$upgrade_phrases['upgrade_300b3.php']['x_old_custom_templates'] = '%1$s - 旧自定义模板';
$upgrade_phrases['upgrade_300b3.php']['insert_styles_vb3_table'] = '正在插入风格到 vB3 style 数据表';
$upgrade_phrases['upgrade_300b3.php']['updating_style_parent_list'] = '正在更新父风格列表';
$upgrade_phrases['upgrade_300b3.php']['updating_user_to_new_style'] = '正在更新用户使用此新风格';
$upgrade_phrases['upgrade_300b3.php']['settings_imported_sucessfully'] = '设置导入成功！';
$upgrade_phrases['upgrade_300b3.php']['translate_replacement_to_stylevars'] = '正在翻译替换变量到风格变量';
$upgrade_phrases['upgrade_300b3.php']['no_value_to_translate'] = '此风格中没有变量需要翻译';
$upgrade_phrases['upgrade_300b3.php']['translating_replacement_to_css'] = '正在翻译替换变量到 CSS';
$upgrade_phrases['upgrade_300b3.php']['body_bg_color_x'] = 'body 背景颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['body_text_color_x'] = 'body 文本颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['margin_width_x'] = 'margin 宽度: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['link_color_x'] = '链接颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['hover_link_color_x'] = 'hover 链接颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['page_bg_color_x'] = '页面背景颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['page_text_color_x'] = '页面文本颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['table_border_color_x'] = '表格边界颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['category_strip_bg_color'] = '分类条背景颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['category_strip_text_color'] = '分类条文本颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['tbl_head_bg_color_x'] = '表格头部背景颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['tbl_head_text_color_x'] = '表格头部文本颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['first_alt_color_x'] = '第一交换颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['second_alt_color_x'] = '第二交换颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['normal_font_size'] = '正常字体大小: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['normal_font_family'] = '正常字体名称: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['normal_font_color'] = '正常字体颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['small_font_size'] = '小字体大小: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['small_font_family'] = '小字体名称: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['small_font_color'] = '小字体颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['highlight_font_size'] = '高亮字体大小: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['highlight_font_family'] = '高亮字体名称: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['highlight_font_color'] = '高亮字体颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['time_color_x'] = '时间颜色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['no_replacements_to_translate'] = '此风格中没有变量需要翻译成 CSS';
$upgrade_phrases['upgrade_300b3.php']['translating_remaining_replacements'] = '正在转换剩余的替换变量为 vB3 替换变量';
$upgrade_phrases['upgrade_300b3.php']['no_remaining_replacement_vars'] = '此风格中没有其它变量需要翻译';
$upgrade_phrases['upgrade_300b3.php']['translate_vb2_style_settings'] = '正在翻译 vB2 风格设置';
$upgrade_phrases['upgrade_300b3.php']['add_css_headinclude_to_extra'] = '正在从 headinclude 模板添加 CSS 数据到此风格的“额外”CSS 中';
$upgrade_phrases['upgrade_300b3.php']['found_css_data'] = '从 headinclude 模板找到并成功添加 CSS 数据';
$upgrade_phrases['upgrade_300b3.php']['no_css_data_found'] = 'headinclude 模板中没有找到 CSS 数据';
$upgrade_phrases['upgrade_300b3.php']['no_headinclude_found'] = '此风格中没有 headinclude 模板';
$upgrade_phrases['upgrade_300b3.php']['insert_style_settings'] = '正在插入风格设置到数据库';
$upgrade_phrases['upgrade_300b3.php']['moving_template_x_to_style_x'] = "正在移动模板从模板集“%1\$s”到引用风格“%2\$s”";
$upgrade_phrases['upgrade_300b3.php']['importing_faq_entries'] = '正在导入常见问题解答项目';
$upgrade_phrases['upgrade_300b3.php']['follow_users_contain_semicolons'] = '以下用户名包含分号，当您进入控制面板时<b>必须</b>修改:';
$upgrade_phrases['upgrade_300b3.php']['download_semicolon_users'] = '我们建议您使用<a href=\"upgrade_300b3.php?step=$step&amp;do=downloadillegalusers\"><b>这个链接</b></a>下载不合法的用户名列表为以后参考。';
$upgrade_phrases['upgrade_300b3.php']['no_illegal_users_found'] = '没有找到不合法的用户名';
$upgrade_phrases['upgrade_300b3.php']['remove_old_settings_storage'] = '正在删除旧风格选项';
$upgrade_phrases['upgrade_300b3.php']['salt_admin_x'] = '正在混淆管理员密码: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['build_forum_and_usergroup_cache'] = '正在建立论坛和用户缓存… ';
$upgrade_phrases['upgrade_300b3.php']['upgrade_complete'] = "您已经成功升级到 vBulletin 3。<br />
<br />
	<font size=\"+1\"><b>您运行此论坛前还必须删除如下文件:</b><br />
	install/install.php</font><br />
	<br />
	当您删除它后，点击“继续”按钮继续。<br />
	<br />
	请注意当前您的论坛为<b>关闭</b>状态<br />
	<br />
	<b>当您返回控制面板时需要重建搜索索引和统计。</b><br />
	<br />
	<b注意: 您的升级并没有完成。您当前运行的版本是 " . VERSION . ".
	点击 “<i>继续</i>”继续升级到更新版本。</b>";

$upgrade_phrases['upgrade_300b3.php']['public'] = '公共';
$upgrade_phrases['upgrade_300b3.php']['public_calendar'] = '公共日历';
$upgrade_phrases['upgrade_300b3.php']['private'] = '私有';
$upgrade_phrases['upgrade_300b3.php']['private_calendar'] = '私人日历';
$upgrade_phrases['upgrade_300b3.php']['deleted_user'] = '已删除用户';
$upgrade_phrases['upgrade_300b3.php']['standard_avatars'] = '标准头像';
$upgrade_phrases['upgrade_300b3.php']['standard_icons'] = '标准信息图标';
$upgrade_phrases['upgrade_300b3.php']['standard_smilies'] = '标准表情符号';
$upgrade_phrases['upgrade_300b3.php']['avatar_setting_title'] = '每页显示头像';
$upgrade_phrases['upgrade_300b3.php']['avatar_setting_desc'] = '在“编辑个人资料”的“编辑头像”中每页显示多少头像?';
$upgrade_phrases['upgrade_300b3.php']['registered_user'] = '注册用户';
// should be the values that vbulletin-language.xml contains
$upgrade_phrases['upgrade_300b3.php']['master_language_title'] = '简体中文';
$upgrade_phrases['upgrade_300b3.php']['master_language_langcode'] = 'zh-CN';
$upgrade_phrases['upgrade_300b3.php']['master_language_charset'] = 'UTF-8';
$upgrade_phrases['upgrade_300b3.php']['master_language_decimalsep'] = '.';
$upgrade_phrases['upgrade_300b3.php']['master_language_thousandsep'] = ',';
$upgrade_phrases['upgrade_300b3.php']['master_language_just_created'] = '正在创建简体中文语言';
$upgrade_phrases['upgrade_300b3.php']['settinggroups'] = array(
		'打开或者关闭论坛' => 'onoff',
		'常规设置' => 'general',
		'联系细节' => 'contact',
		'发帖允许的代码 (vB代码/HTML代码/等)' => 'postingallow',
		'论坛首页选项' => 'forumhome',
		'用户与注册选项' => 'user',
		'会员列表选项' => 'memberlist',
		'帖子显示选项' => 'showthread',
		'论坛显示选项' => 'forumdisplay',
		'搜索选项' => 'search',
		'Email选项' => 'email',
		'日期/时间选项' => 'datetime',
		'屏蔽选项' => 'editpost',
		'IP地址记录选项' => 'ip',
		'灌水检查选项' => 'floodcheck',
		'禁止选项' => 'banning',
		'悄悄话选项' => 'pm',
		'屏蔽选项' => 'censor',
		'HTTP头与输出' => 'http',
		'版本信息' => 'version',
		'模板' => 'templates',
		'上传限制选项' => 'loadlimit',
		'投票' => 'poll',
		'头像' => 'avatar',
		'附件' => 'attachment',
		'用户自定义头衔' => 'usertitle',
		'上传选项' => 'upload',
		'会员在线状态' => 'online',
		'语言选项' => 'OLDlanguage',
		'拼写检查' => 'OLDspellcheck',
		'日历' => 'OLDcalendar'
	);
$upgrade_phrases['upgrade_300b3.php']['vb2_default_style_title'] = '默认';
$upgrade_phrases['upgrade_300b3.php']['new_vb2_default_style_title'] = 'vBulletin 2 默认';
$upgrade_phrases['upgrade_300b3.php']['cron_birthday'] = '生日 Email 发送';
$upgrade_phrases['upgrade_300b3.php']['cron_thread_views'] = '主题人气更新';
$upgrade_phrases['upgrade_300b3.php']['cron_user_promo'] = '用户提升';
$upgrade_phrases['upgrade_300b3.php']['cron_daily_digest'] = '每日订阅发送';
$upgrade_phrases['upgrade_300b3.php']['cron_weekly_digest'] = '每周订阅发送';
$upgrade_phrases['upgrade_300b3.php']['cron_activation'] = '激活提醒 Email 发送';
$upgrade_phrases['upgrade_300b3.php']['cron_subscriptions'] = '即时订阅发送';
$upgrade_phrases['upgrade_300b3.php']['cron_hourly_cleanup'] = '每小时清理 #1';
$upgrade_phrases['upgrade_300b3.php']['cron_hourly_cleaup2'] = '每小时清理 #2';
$upgrade_phrases['upgrade_300b3.php']['cron_attachment_views'] = '附件人气更新';
$upgrade_phrases['upgrade_300b3.php']['cron_unban_users'] = '恢复临时封禁用户';
$upgrade_phrases['upgrade_300b3.php']['cron_stats_log'] = '每日统计日志';
$upgrade_phrases['upgrade_300b3.php']['reputation_-999999'] = '声名狼藉';
$upgrade_phrases['upgrade_300b3.php']['reputation_-50'] = '只能期待他慢慢抹去身上的污点';
$upgrade_phrases['upgrade_300b3.php']['reputation_-10'] = '在过去有过一些不好的行为';
$upgrade_phrases['upgrade_300b3.php']['reputation_0'] = '普普通通';
$upgrade_phrases['upgrade_300b3.php']['reputation_10'] = '向着好的方向发展';
$upgrade_phrases['upgrade_300b3.php']['reputation_50'] = '是将要出名的人啊';
$upgrade_phrases['upgrade_300b3.php']['reputation_150'] = '身上有一圈迷人的光环哦';
$upgrade_phrases['upgrade_300b3.php']['reputation_250'] = '即将成功的新星';
$upgrade_phrases['upgrade_300b3.php']['reputation_350'] = '即将成功的新星';
$upgrade_phrases['upgrade_300b3.php']['reputation_450'] = '星途闪耀';
$upgrade_phrases['upgrade_300b3.php']['reputation_550'] = '已经是明星了';
$upgrade_phrases['upgrade_300b3.php']['reputation_650'] = '有着人尽皆知的贡献和荣耀';
$upgrade_phrases['upgrade_300b3.php']['reputation_1000'] = '绝对是天王巨星';
$upgrade_phrases['upgrade_300b3.php']['reputation_1500'] = '有着超越历史的辉煌成就';
$upgrade_phrases['upgrade_300b3.php']['reputation_2000'] = '有着超越历史的辉煌成就';
$upgrade_phrases['upgrade_300b3.php']['upgrade_from_vb2_not_supported'] = '
	<p>由于数据结构的不兼容，无法从 vBulletin 2 直接升级到 vBulletin versions 3.8.x 或更新版本。</p>
	<p>如果您当前运行着 vBulletin 2，想要升级到最新版本的 vBulletin，请先从客户区下载 vBulletin 3.6。</p>
	<p>上传您从压缩包中解压缩得到的文件，并运行升级脚本直至完成。</p>
	<p>在升级完成后，从客户区下载最新版本的 vBulletin，并上传解压缩的文件，然后继续运行升级脚本直至完成。</p>
';

#####################################
# upgrade_300b4.php phrases
#####################################

$upgrade_phrases['upgrade_300b4.php']['steps'] = array(
	1 => '修改数据库结构',
	2 => '正在添加和删除数据',
	3 => '更新附件类型缓存',
	4 => '成功升级到 vBulletin ' . VERSION . '！'
);
$upgrade_phrases['upgrade_300b4.php']['default_avatar_category'] = '正在插入默认头像分类';
$upgrade_phrases['upgrade_300b4.php']['insert_into_whosonline'] = "正在插入当前在线蜘蛛缓存到 %1$sdatastore";
$upgrade_phrases['upgrade_300b4.php']['delete_redundant_cron'] = '正在删除多余的计划任务';
$upgrade_phrases['upgrade_300b4.php']['attachment_cache_rebuilt'] = '附件缓存已重建';
$upgrade_phrases['upgrade_300b4.php']['generic_avatars'] = '标准头像';

#####################################
# upgrade_300b5.php phrases
#####################################

$upgrade_phrases['upgrade_300b5.php']['steps'] = array(
	1 => '修改数据库结构',
	2 => '修改主题/帖子数据表',
	3 => '更改设置',
	4 => '成功升级到 vBulletin ' . VERSION . '！'
);
$upgrade_phrases['upgrade_300b5.php']['alter_post_title'] = '正在修改 " . TABLE_PREFIX ."post 数据表的 title 列为 VARCHAR(250)<br /><i>(这在较大的论坛中可能花去一些时间)';
$upgrade_phrases['upgrade_300b5.php']['alter_thread_title'] = '正在修改 " . TABLE_PREFIX ."thread 数据表的 title 列为 VARCHAR(250)<br /><i>(这在较大的论坛中可能花去一些时间)';
$upgrade_phrases['upgrade_300b5.php']['disabled_timeout_admin'] = '成功禁用“管理员登录超时”。';
$upgrade_phrases['upgrade_300b5.php']['timeout_admin_not_changed'] = '“管理员登录超时”设置没有更改。';
$upgrade_phrases['upgrade_300b5.php']['change_setting_value'] = '更改设置值？';
$upgrade_phrases['upgrade_300b5.php']['proceed'] = ' 继续 ';
$upgrade_phrases['upgrade_300b5.php']['setting_info'] = '<b>禁用“管理员登录超时”设置？</b> ' .
					'<dfn>“管理员登录超时”增加了安全性，但是可能导致登录管理面板出现困难。<br />' .
					'如果您登录管理面板时曾经出现过问题，或是需要穿过一个代理服务器登录管理面板' .
					'(例如美国在线的代理服务器)，您就需要禁用此设置。 (选择“是”)。</dfn>';
$upgrade_phrases['upgrade_300b5.php']['no_change_needed'] = '正在判断是否需要修改设置值… 无需修改。';

#####################################
# upgrade_300b6.php phrases
#####################################

$upgrade_phrases['upgrade_300b6.php']['steps'] = array(
	1 => '正在为主题数据表添加索引',
	2 => '修改数据库结构',
	3 => '更改订阅数据',
	4 => '正在重命名一些模板和表情符号以适应新的所见即所得编辑器',
	5 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300b6.php']['alter_thread_table'] = '正在修改 %1$sthread 数据表…<br /><i>(这在较大的论坛中可能花去一些时间)';
$upgrade_phrases['upgrade_300b6.php']['remove_avatar_cache'] = '正在删除头像缓存';
$upgrade_phrases['upgrade_300b6.php']['update_userban'] = '正在修改临时封禁用户自动解封计划任务运行在每小时的第十五分钟';
$upgrade_phrases['upgrade_300b6.php']['subscription_active'] = '正在激活订阅选项';
$upgrade_phrases['upgrade_300b6.php']['rename_old_template'] = '正在重命名 <i>%1$s</i> 模板为 <i>%2$s</i>';
$upgrade_phrases['upgrade_300b6.php']['delete_vbcode_color'] = '正在删除 <i>vbcode_color_options</i> 模板 (颜色现在在 clientscript/vbulletin_editor.js 文件中定义)';
$upgrade_phrases['upgrade_300b6.php']['smilie_fixes'] = "正在把表情符号的名称修改得更加漂亮 (并修复“embarra<b>s</b>ment”打字错误！)";

#####################################
# upgrade_300b7.php phrases
#####################################

$upgrade_phrases['upgrade_300b7.php']['steps'] = array(
	1 => '杂项升级 #1',
	2 => '正在修改用户数据表',
	3 => '正在导入关于 BB 代码修改的注意事项',
	4 => '正在修改 BB 代码系统',
	5 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300b7.php']['redundant_stylevars'] = "正在从 " . TABLE_PREFIX . "template 数据表删除重复的风格变量";
$upgrade_phrases['upgrade_300b7.php']['renaming_some_templates'] = '正在重命名一些模板';
$upgrade_phrases['upgrade_300b7.php']['ban_removal_fix'] = '正在修改临时封禁用户自动解封计划任务运行在每小时的第十五分钟 (修正上一个升级程序的错误)';
$upgrade_phrases['upgrade_300b7.php']['promotion_lastrun_fix'] = '正在重置上次用户提升操作运行时间到9月8日以进入修复进程';
$upgrade_phrases['upgrade_300b7.php']['default_charset'] = '设置默认语言字符集为 <i>UTF-8</i>。';
$upgrade_phrases['upgrade_300b7.php']['comma_var_names'] = '处理短语变量名中的逗号';
$upgrade_phrases['upgrade_300b7.php']['delete_quote_email_bbcode'] = '正在删除 [quote] 和 [email] BB 代码标签 - 它们在内核中定义';
$upgrade_phrases['upgrade_300b7.php']['bbcode_update'] = "<h3>重要注意事项…</h3>" .
	 "<p>下面的步骤是<b>删除</b> <i>[quote]</i>，<i>[quote=username]</i>，<i>[email]</i>，和 <i>[email=address]</i> BB 代码定义，因为它们现在是在 vBulletin 程序内部定义的，并且被一个模板控制。</p>" .
	 "<p>如果您曾经对这些代码进行过自定义，我们建议您现在访问<a href=\"../{$vbulletin->config[Misc][admincpdir]}/bbcode.php?$session[sessionurl]\" target=\"_blank\" title=\"在新窗口打开 BB 代码管理器\">BB 代码管理器</a>并对您自定义的 HTML 做记录。</p>" .
	 "<p>当本升级程序完成后，您便可以自定义 <b>bbcode_quote</b> 模板以达到您以前自定义它们的效果。</p>" .
	 "<p>点击“下一步”按钮继续升级程序。</p>";

#####################################
# upgrade_300g.php phrases
#####################################

$upgrade_phrases['upgrade_300g.php']['steps'] = array(
	1 => '杂项升级 #1',
	2 => '语言和短语改变',
	3 => '付费订阅',
	4 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300g.php']['remove_duplicate_templates'] = '正在删除风格内重复的模板...';
$upgrade_phrases['upgrade_300g.php']['done'] = '完成!';
$upgrade_phrases['upgrade_300g.php']['rename_searchindex_postindex'] = "正在重命名 " . TABLE_PREFIX . "searchindex 数据表为 " . TABLE_PREFIX . "postindex";
$upgrade_phrases['upgrade_300g.php']['removing_redundant_index_phrase'] = "正在删除 " . TABLE_PREFIX . "phrase 数据表中重复的索引";
$upgrade_phrases['upgrade_300g.php']['holiday_to_phrasetype'] = "正在添加节假日到 " . TABLE_PREFIX . "phrasetype 数据表";
$upgrade_phrases['upgrade_300g.php']['moving_holiday_type'] = "正在移动存在的节假日到新的短语类型";
$upgrade_phrases['upgrade_300g.php']['adding_x_to_phrasetype'] = '正在添加 %1$s 到 ' . TABLE_PREFIX . 'phrasetype 数据表';
$upgrade_phrases['upgrade_300g.php']['update_invalid_birthdays'] = "正在更新无效的生日";
$upgrade_phrases['upgrade_300g.php']['step_already_run'] = '此步骤无需运行';
$upgrade_phrases['upgrade_300g.php']['updating_subscription_expiry_times'] = '更新订阅过期时间完成';

#####################################
# upgrade_300rc1.php phrases
#####################################

$upgrade_phrases['upgrade_300rc1.php']['steps'] = array(
	1 => '杂项升级 #1',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300rc1.php']['alter_reputation_negative'] = "正在修改声望提升允许负值";
$upgrade_phrases['upgrade_300rc1.php']['phrase_varname_case_sens'] = "使短语变量名大小写敏感";
$upgrade_phrases['upgrade_300rc1.php']['add_faq_entry'] = '正在添加常见问题解答项目';

#####################################
# upgrade_300rc2.php phrases
#####################################

$upgrade_phrases['upgrade_300rc2.php']['steps'] = array(
	1 => '成功升级到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_300rc3.php phrases
#####################################

$upgrade_phrases['upgrade_300rc3.php']['steps'] = array(
	1 => '修复一些数据表错误',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300rc3.php']['click_here_auto_redirect'] = '如果没有自动重定向，请点击这里。';
$upgrade_phrases['upgrade_300rc3.php']['not_latest_files'] = '您没有上传所有最新的文件！<br /><br /><b>请上传最新的版本的 adminfunctions_profilefield.php 到 includes 目录，然后刷新此页。</b>';
$upgrade_phrases['upgrade_300rc3.php']['fix_sortorder'] = "正在修正 " . TABLE_PREFIX . "search 数据表中的 sortorder 字段";
$upgrade_phrases['upgrade_300rc3.php']['fix_logdateoverride'] = "正在修正 " . TABLE_PREFIX . "language 数据表中的 logdateoverride 字段";
$upgrade_phrases['upgrade_300rc3.php']['fix_filesize_customavatar'] = "正在为 " . TABLE_PREFIX . "customavatar 数据表添加 filesize 字段";
$upgrade_phrases['upgrade_300rc3.php']['fix_filesize_customprofile'] = "正在为 " . TABLE_PREFIX . "customprofilepic 数据表添加 filesize 字段";
$upgrade_phrases['upgrade_300rc3.php']['populate_avatar_filesize'] = '正在计算头像文件大小';
$upgrade_phrases['upgrade_300rc3.php']['populate_profile_filesize'] = '正在计算资料图片文件大小';

#####################################
# upgrade_300rc4.php phrases
#####################################

$upgrade_phrases['upgrade_300rc4.php']['steps'] = array(
	1 => '修复一些数据表错误',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300rc4.php']['increase_storage_dateoverride'] = "正在为 " . TABLE_PREFIX . "language 数据表的 dateoverride 字段增容";
$upgrade_phrases['upgrade_300rc4.php']['increase_storage_timeoverride'] = "正在为 " . TABLE_PREFIX . "language 数据表的 timeoverride 字段增容";
$upgrade_phrases['upgrade_300rc4.php']['increase_storage_registereddateoverride'] = "正在为 " . TABLE_PREFIX . "language 数据表的 registereddateoverride 字段增容";
$upgrade_phrases['upgrade_300rc4.php']['increase_storage_calformat1override'] = "正在为 " . TABLE_PREFIX . "language 数据表的 calformat1override 字段增容";
$upgrade_phrases['upgrade_300rc4.php']['increase_storage_calformat2override'] = "正在为 " . TABLE_PREFIX . "language 数据表的 calformat2override 字段增容";
$upgrade_phrases['upgrade_300rc4.php']['increase_storage_logdateoverride'] = "正在为 " . TABLE_PREFIX . "language 数据表的 logdateoverride 字段增容";
$upgrade_phrases['upgrade_300rc4.php']['adding_calendar_mardi_gras'] = "正在修改数据表 " . TABLE_PREFIX . "calendar 以支持新的预定义节日: 忏悔星期二和圣体节。您需要在日历管理器中启用这些节日";

#####################################
# upgrade_300.php phrases
#####################################

$upgrade_phrases['upgrade_300.php']['steps'] = array(
	1 => '修复一些数据表错误',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300.php']['make_reputation_signed'] = '正在修改声望为有符号整型';
$upgrade_phrases['upgrade_300.php']['add_birthday_search'] = '正在添加生日搜索字段';
$upgrade_phrases['upgrade_300.php']['add_index_birthday_search'] = '正在添加生日搜索字段索引';
$upgrade_phrases['upgrade_300.php']['populate_birhtday_search'] = '正在生成生日搜索字段';

#####################################
# upgrade_301.php phrases
#####################################

$upgrade_phrases['upgrade_301.php']['steps'] = array(
	1 => '成功升级到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_302.php phrases
#####################################

$upgrade_phrases['upgrade_302.php']['steps'] = array(
	1 => '数据表结构修改 1/4',
	2 => '数据表结构修改 2/4',
	3 => '数据表结构修改 3/4',
	4 => '数据表结构修改 4/4',
	5 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_302.php']['drop_pmpermissions'] = '正在删除多余的字段';
$upgrade_phrases['upgrade_302.php']['add_thumbnail_filesize'] = '正在为 attachment 数据表添加缩略图大小字段';
$upgrade_phrases['upgrade_302.php']['change_profilefield'] = '正在增加自定义字段的储存空间';
$upgrade_phrases['upgrade_302.php']['update_genericpermissions'] = '正在添加权限';
$upgrade_phrases['upgrade_302.php']['alter_poll_table'] = '正在添加 lastvote 字段到 ' . TABLE_PREFIX . 'poll 数据表';
$upgrade_phrases['upgrade_302.php']['alter_user_table'] = '正在添加长 Email 支持到 ' . TABLE_PREFIX . 'user 数据表';
$upgrade_phrases['upgrade_302.php']['add_rss_faq'] = '正在添加 RSS 条目到 ' . TABLE_PREFIX . 'faq 数据表';
$upgrade_phrases['upgrade_302.php']['add_notes'] = '正在添加 notes 字段到 ' . TABLE_PREFIX . 'administrator 数据表';
$upgrade_phrases['upgrade_302.php']['add_cpsession_table'] = '正在添加 cpsession 数据表';
$upgrade_phrases['upgrade_302.php']['fix_blank_charset'] = '正在添加默认的字符集';

#####################################
# upgrade_303.php phrases
#####################################

$upgrade_phrases['upgrade_303.php']['steps'] = array(
	1 => '数据表结构修改 1/1',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_303.php']['note'] = '<p>如果您启用了缩略图功能，并将附件存储为文件，并且在升级到 3.0.2 之后没有重建缩略图，那么请在升级完毕后请重建缩略图。，否则您的缩略图将不能正常工作。</p>';
$upgrade_phrases['upgrade_303.php']['rebuild_usergroupcache'] = '正在重建用户组缓存';

#####################################
# upgrade_303 - 309.php phrases
#####################################

$upgrade_phrases['upgrade_304.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_305.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_306.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];

$upgrade_phrases['upgrade_307.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_307.php']['update_calendarpermissions'] = '正在修改日历权限';
$upgrade_phrases['upgrade_307.php']['import_birthdaydatecut_option'] = '正在导入旧生日日期选项';

$upgrade_phrases['upgrade_308.php']['steps'] =& $upgrade_phrases['upgrade_303.php']['steps'];
$upgrade_phrases['upgrade_309.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_3010.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_3011.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_3012.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_3013.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_3014.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_3015.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];

#####################################
# upgrade_350b1.php phrases
#####################################

$upgrade_phrases['upgrade_350b1.php']['steps'] = array(
	1 => '数据表结构修改 1/6',
	2 => '数据表结构修改 2/6',
	3 => '数据表结构修改 3/6',
	4 => '数据表结构修改 4/6',
	5 => '数据表结构修改 5/6',
	5 => '数据表结构修改 6/6',
	7 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_350b1.php']['update_forumpermissions'] = '正在修改版面权限';
$upgrade_phrases['upgrade_350b1.php']['support_multiple_products'] = '增加多产品的支持';
$upgrade_phrases['upgrade_350b1.php']['update_adminpermissions'] = '正在修改管理权限';
$upgrade_phrases['upgrade_350b1.php']['cron_event_reminder'] = '事件提醒';

#####################################
# upgrade_350b2.php phrases
#####################################

$upgrade_phrases['upgrade_350b2.php']['steps'] = array(
	1 => '数据表结构修改 1/1',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_350b3.php phrases
#####################################

$upgrade_phrases['upgrade_350b3.php']['steps'] = array(
	1 => '正在转换多种设置',
	2 => '正在升级支付系统',
	3 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_350b3.php']['translating_allowvbcodebuttons'] = '正在转换 $vbulletin->options[\'allowvbcodebuttons\'] 和 $vbulletin->options[\'quickreply\'] 到新的 $vbulletin->options[\'editormodes\'] 整合设置';
$upgrade_phrases['upgrade_350b3.php']['translating_quickreply'] = '正在转换 $vbulletin->options[\'quickreply\'] 和 $vbulletin->options[\'quickreplyclick\'] 到新的 $vbulletin->options[\'quickreply\'] 整合设置';
$upgrade_phrases['upgrade_350b3.php']['converting_phrases_x_of_y'] = '正在转换短语 (第 %1$d 步 共 %2$d 步)';
$upgrade_phrases['upgrade_350b3.php']['paymentapi_data'] = '正在插入默认支付网关 API 数据';
$upgrade_phrases['upgrade_350b1.php']['note'] = '<p><h3>您即将储存头像到文件系统。vB 3.5.0 现在有个选项还可以储存用户照片到文件系统。在您升级完成后，进入管理面板并将所有头像通过 <em>头像->用户照片储存类型</em> 移动到数据库中。在这一过程完成后，返回到相同的地方，将照片移动到文件系统中。现在您的头像和用户照片都将储存在文件系统中。如果您没有按照上述方式做，您的用户照片将无法显示。</h3></p>';

#####################################
# upgrade_350b4.php phrases
#####################################

$upgrade_phrases['upgrade_350b4.php']['steps'] = array(
	1 => '数据表结构修改 1/1',
	2 => '正在升级支付系统',
	3 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_350b4.php']['adding_payment_api_x_settings'] = '正在添加支付网关 API %1$s 设置';
$upgrade_phrases['upgrade_350b4.php']['invert_moderate_permission'] = '正在反转“总是验证此用户组的帖子”权限';

#####################################
# upgrade_350rc1.php phrases
#####################################

$upgrade_phrases['upgrade_350rc1.php']['steps'] = array(
	1 => '设置产品管理系统',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_350rc1.php']['control_panel_hook_support'] = '正在添加控制面板钩子支持';

#####################################
# upgrade_350rc2.php phrases
#####################################

$upgrade_phrases['upgrade_350rc2.php']['steps'] = array(
	1 => '更新产品字段',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_350rc3.php phrases
#####################################

$upgrade_phrases['upgrade_350rc3.php']['steps'] = array(
	1 => '数据表结构修改',
	2 => '主题数据表修改',
	3 => '帖子数据表修改',
	4 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_350rc3.php']['please_wait_message'] = '下一步可能会花去一些时间，请耐心等待。';
$upgrade_phrases['upgrade_350rc3.php']['updating_payment_api_x_settings'] = '正在更新支付网关 API %1$s 设置';

#####################################
# upgrade_350.php phrases
#####################################

$upgrade_phrases['upgrade_350.php']['steps'] = array(
	1 => '数据表结构修改',
	2 => '主题数据表修改',
	3 => '成功升级到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_351.php phrases
#####################################

$upgrade_phrases['upgrade_351.php']['steps'] = array(
	1 => '数据表结构修改',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_351.php']['delete_vb_product'] = '从产品表中删除 vBulletin。';

#####################################
# upgrade_352.php phrases
#####################################

$upgrade_phrases['upgrade_352.php']['steps'] =& $upgrade_phrases['upgrade_351.php']['steps'];

$upgrade_phrases['upgrade_352.php']['adding_skype_field'] = '正在为 user 数据表添加 Skype 字段';

#####################################
# upgrade_353.php phrases
#####################################

$upgrade_phrases['upgrade_353.php']['steps'] =& $upgrade_phrases['upgrade_351.php']['steps'];

$upgrade_phrases['upgrade_353.php']['remove_352_xss_plugin'] = '如果安装，则从 3.5.2 移除 XSS 修正插件';

#####################################
# upgrade_354.php phrases
#####################################

$upgrade_phrases['upgrade_354.php']['steps'] =& $upgrade_phrases['upgrade_351.php']['steps'];

$upgrade_phrases['upgrade_355.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];

#####################################
# upgrade_360b1.php phrases
#####################################

$upgrade_phrases['upgrade_360b1.php']['steps'] = array(
	1 => '大数据表修改 (1/2)',
	2 => '大数据表修改 (2/2)',
	3 => '数据表结构修改',
	4 => '数据表结构修改',
	5 => '数据表结构修改',
	6 => '数据表结构修改',
	7 => '签名权限',
	8 => '违规',
	9 => '付费订阅更新',
	10 => '超级版主权限更新',
	11 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_360b1.php']['please_wait_message'] = '下一步可能需要一些时间，请耐心等待。如果页面停止装载，您可以刷新页面。';

$upgrade_phrases['upgrade_360b1.php']['updating_cron'] = '正在更新计划任务';
$upgrade_phrases['upgrade_360b1.php']['updating_subscriptions'] = '正在更新付费订阅';
$upgrade_phrases['upgrade_360b1.php']['updating_holidays'] = '正在更新节日';
$upgrade_phrases['upgrade_360b1.php']['updating_profilefields'] = '正在更新自定义资料栏目';
$upgrade_phrases['upgrade_360b1.php']['updating_reputationlevels'] = '正在更新声望级别';
$upgrade_phrases['upgrade_360b1.php']['invert_banned_flag'] = "正在反转“该用户组是一个‘封禁’用户组”选项";
$upgrade_phrases['upgrade_360b1.php']['install_canignorequota_permission'] = "正在设置“可以忽略限额”权限";
$upgrade_phrases['upgrade_360b1.php']['infractionlevel1_title'] = '垃圾广告';
$upgrade_phrases['upgrade_360b1.php']['infractionlevel2_title'] = '侮辱其他会员';
$upgrade_phrases['upgrade_360b1.php']['infractionlevel3_title'] = '签名违反规则';
$upgrade_phrases['upgrade_360b1.php']['infractionlevel4_title'] = '不适当的语言';
$upgrade_phrases['upgrade_360b1.php']['rssposter_title'] = 'RSS 发帖者';
$upgrade_phrases['upgrade_360b1.php']['infractions_title'] = '违规清理';
$upgrade_phrases['upgrade_360b1.php']['ccbill_title'] = 'CCBill 逆向检查';

$upgrade_phrases['upgrade_360b1.php']['rename_post_parsed'] = "正在重命名 " . TABLE_PREFIX . "post_parsed 数据表为 " . TABLE_PREFIX . "postparsed";

$upgrade_phrases['upgrade_360b1.php']['updating_thread_redirects'] = '正在更新主题重定向';

$upgrade_phrases['upgrade_360b1.php']['super_moderator_x_updated'] = '超级版主“%1$s”已更新';

$upgrade_phrases['upgrade_360b1.php']['lastpostid_notice'] = '<strong>为了完成升级，主题信息和版面信息<em>必须</em>在管理面板的更新计数器部分重建。</strong>';

#####################################
# upgrade_360b2.php phrases
#####################################

$upgrade_phrases['upgrade_360b2.php']['steps'] = array(
	1 => '数据表结构修改',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_360b3.php phrases
#####################################

$upgrade_phrases['upgrade_360b3.php']['steps'] = array(
	1 => '成功升级到 vBulletin ' . VERSION . '！'
);


$upgrade_phrases['upgrade_360b4.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_360rc1.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_360rc2.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_360rc3.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_360.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_361.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];

$upgrade_phrases['upgrade_361.php']['rename_podcasturl'] = "正在重命名 " . TABLE_PREFIX . "podcasturl 数据表为 " . TABLE_PREFIX . "podcastitem";

$upgrade_phrases['upgrade_362.php']['steps'] =& $upgrade_phrases['upgrade_360b3.php']['steps'];
$upgrade_phrases['upgrade_363.php']['steps'] =& $upgrade_phrases['upgrade_360b3.php']['steps'];

$upgrade_phrases['upgrade_364.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_365.php']['steps'] =& $upgrade_phrases['upgrade_360b3.php']['steps'];
$upgrade_phrases['upgrade_366.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_367.php']['steps'] =& $upgrade_phrases['upgrade_360b3.php']['steps'];
$upgrade_phrases['upgrade_368.php']['steps'] =& $upgrade_phrases['upgrade_360b3.php']['steps'];

$upgrade_phrases['upgrade_370b2.php']['steps'] = array(
	1 => '数据表创建',
	2 => '大数据表结构修改',
	3 => '杂项数据表结构修改',
	4 => '默认数据插入',
	5 => '用户列表重建',
	6 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370b2.php']['build_userlist'] = '<p>正在为 %1$s 重建用户列表</p>';
$upgrade_phrases['upgrade_370b2.php']['build_userlist_complete'] = '<p>用户列表重建完成</p>';

$upgrade_phrases['upgrade_370b3.php']['steps'] = array(
	1 => '数据表结构修改',
	2 => '修改数据表默认值',
	3 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370b4.php']['steps'] = array(
	1 => '杂项数据表结构修改',
	2 => '数据表数据更新',
	3 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370b5.php']['steps'] = array(
	1 => '杂项数据表结构修改',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370b6.php']['steps'] = array(
	1 => '杂项数据表结构修改',
	2 => '插入全新论坛帮助',
	3 => '是否删除旧论坛帮助?',
	4 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370b6']['inserting_vb37_faq_structure'] = '正在插入 vBulletin 3.8.0 论坛帮助结构';
$upgrade_phrases['upgrade_370b6']['delete_selected_faq_items'] = '删除选中的论坛帮助项目';
$upgrade_phrases['upgrade_370b6']['delete_faq_description'] = '
	在上一步中，我们插入了全新的 vBulletin 论坛帮助到您的论坛。
	这意味着您的论坛现在同时包含了新的论坛帮助和旧的论坛帮助。<br />
	<br />
	下面列出了所有旧论坛帮助项目。
	如果您没有修改过旧的论坛帮助，那么保持全选它们并删除。
	如果您自己添加过论坛帮助，或者修改过存在的项目，那么您需要取消选择那些您需要保留的项目。<br />
	<br />
	在您完成选择后，点击列表底部的<strong>' . $upgrade_phrases['upgrade_370b6']['delete_selected_faq_items'] . '</strong>按钮继续。
	如果没有选择任何条目，它们将都不会被删除，升级程序会继续下一步操作。
';
$upgrade_phrases['upgrade_370b6']['reset_selection'] = '重置选择';
$upgrade_phrases['upgrade_370b6']['selected_faq_items_deleted'] = '您选择的帮助项目已经被删除。';

$upgrade_phrases['upgrade_370rc1.php']['steps'] = $upgrade_phrases['upgrade_370b5.php']['steps'];

$upgrade_phrases['upgrade_370rc2.php']['steps'] = array(
	1 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370rc3.php']['dropping_old_table_x'] = '正在删除旧数据表 %1$s';
$upgrade_phrases['upgrade_370rc3.php']['steps'] = array(
	1 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370rc4.php']['steps'] = array(
	1 => '正在进行模板安全修正',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370rc4.php']['token_added_x_templates'] = '正在添加必要的安全标记到 %1$s 个自定义模板';

$upgrade_phrases['upgrade_370.php']['steps'] = array(
	1 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_371.php']['steps'] = array(
	1 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_380a2.php']['steps'] = array(
	1 => '数据表创建',
	2 => '杂项数据表结构修改',
	3 => '讨论组讨论转换',
	4 => '权限更新',
	5 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_380a2.php']['alter_index_on_x'] = '正在修改 %1$s 的索引';
$upgrade_phrases['upgrade_380a2.php']['create_index_on_x'] = '正在为 %1$s 创建索引';
$upgrade_phrases['upgrade_380a2.php']['creating_default_group_category'] = '正在创建默认社会兴趣讨论组分类';
$upgrade_phrases['upgrade_380a2.php']['fulltext_index_on_x'] = '正在为 %1$s 创建全文索引';
$upgrade_phrases['upgrade_380a2.php']['convert_messages_to_discussion'] = '正在转换社会兴趣讨论组到讨论';
$upgrade_phrases['upgrade_380a2.php']['set_discussion_titles'] = '正在设置初始讨论组标题';
$upgrade_phrases['upgrade_380a2.php']['update_last_post'] = '正在初始化讨论最后回复信息';
$upgrade_phrases['upgrade_380a2.php']['update_discussion_counters'] = '正在更新讨论计数器';
$upgrade_phrases['upgrade_380a2.php']['update_group_message_counters'] = '正在更新社会兴趣讨论组消息计数器';
$upgrade_phrases['upgrade_380a2.php']['update_group_discussion_counters'] = '正在更新社会兴趣讨论组讨论计数器';
$upgrade_phrases['upgrade_380a2.php']['uncategorized'] = '未分类';
$upgrade_phrases['upgrade_380a2.php']['uncategorized_description'] = '未分类的社会兴趣讨论组';
$upgrade_phrases['upgrade_380a2.php']['move_groups_to_default_category'] = '正在移动社会兴趣讨论组到“未分类”分类';
$upgrade_phrases['upgrade_380a2.php']['updating_profile_categories'] = '正在为个人资料栏目分类添加隐私设置';
$upgrade_phrases['upgrade_380a2.php']['update_hv_options'] = '正在更新真人验证选项';
$upgrade_phrases['upgrade_380a2.php']['update_album_update_counters'] = '正在更新“相册更新”计数器';
$upgrade_phrases['upgrade_380a2.php']['granting_permissions'] = '正在为新功能赋予权限';

$upgrade_phrases['upgrade_380b1.php']['steps'] = array(
	1 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_380b2.php']['steps'] = array(
	1 => '杂项数据表结构修改',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_380b3.php']['steps'] = array(
	1 => '杂项数据表结构修改',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_380b4.php']['steps'] = array(
	1 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_380rc1.php']['rebuild_event_cache'] = '正在重建事件缓存';

$upgrade_phrases['upgrade_380rc1.php']['steps'] = array(
	1 => '缓存重建',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_380rc2.php']['updating_mail_ssl_setting'] = '更新 SSL 邮件设置';
$upgrade_phrases['upgrade_380rc2.php']['steps'] = array(
	1 => '设置更新',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_380.php']['steps'] = array(
	1 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_381.php']['steps'] = array(
	1 => '杂项数据表结构修改',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_382.php']['steps'] = array(
	1 => '杂项数据表结构修改',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_383.php']['steps'] = array(
	1 => '成功升级到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_384.php']['steps'] = array(
	1 => '杂项数据表结构修改',
	2 => '成功升级到 vBulletin ' . VERSION . '！'
);

#####################################
# finalupgrade.php phrases
#####################################

$upgrade_phrases['finalupgrade.php']['steps'] = array(
	1 => '导入最新的选项',
	2 => '导入最新的管理员帮助',
	3 => '导入最新的语言',
	4 => '导入最新的风格',
	5 => '本步骤探测 word 表是否已经修改为正确的字段',
	6 => '全部完成',
);

$upgrade_phrases['finalupgrade.php']['upgrade_start_message'] = "<p>本程序将升级您的模版、设置、语言和管理帮助到最新版本。</p>\n<p>点击“下一步”按钮继续。";
$upgrade_phrases['finalupgrade.php']['upgrade_version_mismatch'] = '<p>您当前运行的 vBulletin (%1$s) 好像不是下载的版本 (%2$s)。</p>
		<p>这通常意味着您的升级没有成功。请确保您上传了所有最新的文件，然后<a href="upgrade.php">点击这里</a>重试。</p>
		<p>如果您确认要继续本部分的升级工作，<a href="finalupgrade.php?step=1">请点击这里</a>。</p>';

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 31742 $
|| ####################################################################
\*======================================================================*/
?>