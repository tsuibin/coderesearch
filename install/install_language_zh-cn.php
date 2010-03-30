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

// moved from installcore to here
$stylevar = array(
	'textdirection' => 'ltr',
	'left' => 'left',
	'right' => 'right',
	'languagecode' => 'zh_CN',
	'charset' => 'UTF-8'
);

$authenticate_phrases['install_title'] = '中文安装程序';
$authenticate_phrases['new_installation'] = '全新安装';
$authenticate_phrases['enter_system'] = '进入安装系统';
$authenticate_phrases['enter_cust_num'] = '请输入您的客户号';
$authenticate_phrases['customer_number'] = '客户号';
$authenticate_phrases['cust_num_explanation'] = '这是您登录 vBulletin 客户区使用的客户号';
$authenticate_phrases['cust_num_success'] = '客户号验证成功。';
$authenticate_phrases['redirecting'] = '正在重定向...';

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
$phrasetype['cprofilefield'] = '自定义用户资料栏目 (Custom Profile Fields)';
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
# custom phrases
#####################################

$customphrases['cprofilefield']['field1_title'] = '个人描述';
$customphrases['cprofilefield']['field1_desc']  = '您的个人描述';
$customphrases['cprofilefield']['field2_title'] = '住址';
$customphrases['cprofilefield']['field2_desc']  = '您的居住地';
$customphrases['cprofilefield']['field3_title'] = '兴趣';
$customphrases['cprofilefield']['field3_desc']  = '您的爱好, 等等';
$customphrases['cprofilefield']['field4_title'] = '职业';
$customphrases['cprofilefield']['field4_desc']  = '您的工作';

$customphrases['reputationlevel']['reputation1']  = '现在声名狼藉';
$customphrases['reputationlevel']['reputation2']  = '只能期待他慢慢抹去身上的污点';
$customphrases['reputationlevel']['reputation3']  = '在过去有过一些不好的行为';
$customphrases['reputationlevel']['reputation4']  = '是普普通通的会员';
$customphrases['reputationlevel']['reputation5']  = '正向着好的方向发展';
$customphrases['reputationlevel']['reputation6']  = '是一个将要出名的人';
$customphrases['reputationlevel']['reputation7']  = '身上有一圈迷人的光环哦';
$customphrases['reputationlevel']['reputation8']  = '即将成为的新星';
$customphrases['reputationlevel']['reputation9']  = '是一位成功的新星';
$customphrases['reputationlevel']['reputation10'] = '的星途闪耀';
$customphrases['reputationlevel']['reputation11'] = '已经是超级明星了';
$customphrases['reputationlevel']['reputation12'] = '有着人尽皆知的贡献和荣耀';
$customphrases['reputationlevel']['reputation13'] = '已经是前无古人后无来者';
$customphrases['reputationlevel']['reputation14'] = '有着超越历史的辉煌成就';
$customphrases['reputationlevel']['reputation15'] = '绝对是天王巨星';

$customphrases['infractionlevel']['infractionlevel1_title'] = '垃圾广告';
$customphrases['infractionlevel']['infractionlevel2_title'] = '侮辱其他会员';
$customphrases['infractionlevel']['infractionlevel3_title'] = '签名违反规则';
$customphrases['infractionlevel']['infractionlevel4_title'] = '不适当的语言';

#####################################
# phrases for import systems
#####################################
$vbphrase['importing_language'] = '正在导入语言';
$vbphrase['importing_style'] = '正在导入风格';
$vbphrase['importing_admin_help'] = '正在导入管理员帮助';
$vbphrase['importing_settings'] = '正在导入设置选项';
$vbphrase['please_wait'] = '请稍候';
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
$vbphrase['updating_style_information_for_each_style'] = '正在更新每个风格信息';
$vbphrase['updating_styles_with_no_parents'] = '正在更新无父风格的风格集';
$vbphrase['updated_x_styles'] = '已更新 %1$s 个风格';
$vbphrase['no_styles_needed_updating'] = '没有风格需要更新';
$vbphrase['yes'] = '是';
$vbphrase['no'] = '否';

#####################################
# global upgrade phrases
#####################################
$vbphrase['refresh'] = '刷新';
$vbphrase['vbulletin_message'] = 'vBulletin 信息';
$vbphrase['create_table'] = '正在创建 %1$s 数据表';
$vbphrase['remove_table'] = '正在删除 %1$s 数据表';
$vbphrase['alter_table'] = '正在修改 %1$s 数据表';
$vbphrase['update_table'] = '正在更新 %1$s 数据表';
$vbphrase['upgrade_start_message'] = "<p>此程序将把您的 vBulletin 升级到版本 <b>" . VERSION . "</b>。</p>\n<p>点击“下一步”按钮继续。</p>";
$vbphrase['upgrade_wrong_version'] = "<p>您的 vBulletin 版本不符合此程序的运行条件 (需要在版本 <b>" . PREV_VERSION . "</b> 的基础上运行)。</p>\n<p>请确认您运行的脚本是否正确。</p>\n<p>如果您确信正确，<a href=\"" . THIS_SCRIPT . "?step=1\">请点击这里继续运行</a>。</p>";
$vbphrase['file_not_found'] = '啊哦, ./install/%1$s 好像不存在！';
$vbphrase['importing_file'] = '正在导入 %1$s';
$vbphrase['ok'] = '完成';
$vbphrase['query_took'] = '执行查询花去 %1$s 秒。';
$vbphrase['done'] = '完成';
$vbphrase['proceed'] = '继续';
$vbphrase['reset'] = '重置';
$vbphrase['vbulletin_copyright'] = 'vBulletin v' . VERSION . ', 版权所有 &copy;2000 - [#]year[#], Jelsoft Enterprises Ltd.';
$vbphrase['vbulletin_copyright_orig'] = $vbphrase['vbulletin_copyright'];
$vbphrase['xml_error_x_at_line_y'] = 'XML 错误: %1$s 在第 %2$s 行';
$vbphrase['default_data_type'] = '正在插入默认数据到 %1$s';
$vbphrase['processing_complete_proceed'] = '处理完成 - 继续';
#####################################
# upgradecore phrases
#####################################

$installcore_phrases['php_version_too_old'] = 'vBulletin ' . VERSION . ' 需要 PHP 版本在 4.3.3 以上。您当前的 PHP 版本是 ' . PHP_VERSION . '。请联系主机商升级。';
$installcore_phrases['mysql_version_too_old'] = 'vBulletin ' . VERSION . ' 需要 MySQL 版本在 4.0.16 以上。您当前的 MySQL 版本是 %1$s。请联系主机商升级。';
$installcore_phrases['need_xml'] = 'vBulletin ' . VERSION . ' 需要 PHP 支持 XML 函数。请联系主机商启用这些函数。';
$installcore_phrases['need_mysql'] = 'vBulletin ' . VERSION . ' 需要 PHP 支持 MySQL 函数。请联系主机商启用这些函数。';
$installcore_phrases['need_config_file'] = '请确认您已经修改了 config.php.new 的设置值并将其重命名为 config.php.';
$installcore_phrases['step_x_of_y'] = ' (第 %1$d 步，共 %2$d 步)';
$installcore_phrases['vb3_install_script'] = 'vBulletin ' . VERSION . ' 中文版安装程序';
$installcore_phrases['may_take_some_time'] = '(有些步骤需要一定的时间，请耐心等待)';
$installcore_phrases['step_title'] = '第 %1$d 步) %2$s';
$installcore_phrases['batch_complete'] = '批处理完成！如果您没有被自动重定向，请点击右边的按钮。';
$installcore_phrases['next_batch'] = ' 下一批';
$installcore_phrases['next_step'] = '下一步 (%1$d/%2$d)';
$installcore_phrases['click_button_to_proceed'] = '点击右边的按钮继续。';
$installcore_phrases['page_x_of_y'] = '第 %1$d 页，共 %2$d 页';
$installcore_phrases['eaccelerator_too_old'] = 'eAccelerator for PHP 必须升级到 0.9.3 或更高版本。请浏览<a href="http://www.vbulletin.com/forum/showthread.p' . 'hp?p=979044#post979044">这个帖子</a>以了解更多信息。';
$upgradecore_phrases['apc_too_old'] = '您的服务器正在运行 <a href="http://pecl.p' . 'hp.net/package/APC/">Alternative PHP Cache</a> (APC) 的一个版本，而这个版本不兼容 vBulletin。请升级到 APC 3.0.0 或更高版本。';
$installcore_phrases['mmcache_not_supported'] = 'Turck MMCache 已经被 eAcclerator 取代，不能正确支持 vBulletin。请浏览<a href="http://www.vbulletin.com/forum/showthread.p' . 'hp?p=979044#post979044">这个帖子</a>以了解更多信息。';
$installcore_phrases['dbname_is_mysql'] = '在 <em>includes/config.php</em> 中的 <code>$config[\'Database\'][\'dbname\']</code> 指定的数据库名不能为 <strong>mysql</strong>，因为这是一个保留的数据库名。<br />执行被终止以避免可能发生的损害。';

#####################################
# install.php phrases
#####################################
$install_phrases['steps'] = array(
	1  => '确认配置',
	2  => '连接到数据库',
	3  => '创建数据表',
	4  => '修改数据表',
	5  => '正在插入默认数据',
	6  => '正在导入语言',
	7  => '正在导入风格信息',
	8  => '正在导入管理员帮助',
	9  => '获取默认设置',
	10 => '导入默认设置',
	11 => '获取用户数据',
	12 => '设置默认数据',
	13 => '安装完成'
);
$install_phrases['welcome'] = '<p style="font-size:10pt"><b>欢迎使用 vBulletin 3.8 中文版</b></p>
	<p>您即将开始安装本程序。</p>
	<p>点击 <b>[下一步]</b> 按钮将开始安装进程。</p>
	<p>为了避免安装时浏览器崩溃，我们强烈建议您关闭浏览器上的第三方工具栏，例如 <b>Google、MSN、Alexa</b> 工具栏等。</p>';
$install_phrases['turck'] = '<p>您的服务器安装了 <strong>Turck MMCache</strong>。<strong>Turck MMCache</strong> 不支持新版本的 PHP，可能会导致 vBulletin 出现问题。我们建议您将其禁用，或升级到 eAccelerator 的新版本。</p>';
$install_phrases['cant_find_config'] = '我们无法定位“includes/config.php”文件，请确认此文件存在。';
$install_phrases['cant_read_config'] = '我们无法读取“includes/config.php”文件，请确保此文件可读。';
$install_phrases['config_exists'] = '配置文件存在并可读。';
$install_phrases['config_misc_charset_error'] = '您的 MySQL 版本低于 4.1，不支持多编码数据库。请您修改 config.php，将 $config[\'Mysqli\'][\'charset\'] 设置为空 (\'\')。修改完成后，请您刷新本页面以继续安装。';
$install_phrases['attach_to_db'] = '正在尝试连接到数据库';
$install_phrases['no_db_found_will_create'] = '没有找到数据库，正在尝试创建。';
$install_phrases['attempt_to_connect_again'] = '正在尝试重新连接。';
$install_phrases['database_functions_not_detected'] = '选择的数据库类型 \'%1$s\' 并没有编译在您的 PHP 中。';
$install_phrases['unable_to_create_db'] = '无法创建数据库。请确认在“inculdes/config.php”中定义的数据库名存在，或者要求您的主机提供商帮您创建一个数据库。';
$install_phrases['database_creation_successful'] = '数据库成功创建！';
$install_phrases['connect_failed'] = '连接失败: 数据库异常错误。';
$install_phrases['db_error_num'] = '错误号: %1$s';
$install_phrases['db_error_desc'] = '错误描述: %1$s';
$install_phrases['check_dbserver'] = '请确保数据库和服务器正确配置并重试。';
$install_phrases['connection_succeeded'] = '连接成功！数据库已经存在。';
$install_phrases['vb_installed_maybe_upgrade'] = '您已经安装了 vBulletin。您是否想<a href="upgrade.php">升级</a>？';
$install_phrases['wish_to_empty_db'] = '如果您想查看清空现有数据库中数据的选项，请点击这里。';
$install_phrases['no_connect_permission'] = '数据库连接失败，因为您没有足够的权限。请检查在“includes/config.php”输入的数据库用户名密码是否正确。';
$install_phrases['empty_db'] = '<p align="center"><font color="Red">危险，老兄! 危险啊!<br /><h1 align="center">清空数据库?</h1></font></p>
<p align="center">点击“是”，您的整个数据库将被清空。</p>
<p align="center">如果您的数据库中存在除了 vBulletin 以外的其它数据，<b>不要</b>选择“是”，<br />否则这些数据将<br><b>不可挽回的被删除</b>。</p>
<p align="center">这是您最后一次机会阻止您的数据被删除！</p>
<p align="center"><a href="install.php?step=3&emptydb=true&confirm=true">[ <b>是</b>，清空该数据库的<b>所有</b>数据 ]</a></p>
<p align="center"><a href="install.php?step=2">[ <b>否</b>，不要清空该数据库 ]</a></p>
<p align="center" class="smallfont">vBulletin、Jelsoft Enterprises Ltd. 及 vBulletin 中文不承担任何<br />由于进行此操作数据丢失而带来的损失。</p>';
$install_phrases['reset_database'] = '重置数据库';
$install_phrases['delete_tables_instructions'] = '<p>下面列出了您数据库中所有的数据表。被识别为属于 vBulletin 的数据表已经自动为您选中。可能有另外一些列出数据表无法识别 - 它们会高亮显示在列表中。</p>
<p style="font-size:12pt">在点击<em>删除选中的数据表</em>按钮后，所有选中的数据表和它们的数据将会<strong>永久不可逆的从数据库中删除</strong>。</p>
<p><a href="install.php?step=2">如果您不想删除任何数据表并继续安装进程，请点击这里。</a></p>
<p>vBulletin 和 Jelsoft Enterprises Ltd. 不承担任何由于进行此操作数据丢失而带来的损失。</p>';
$install_phrases['select_deselect_all_tables'] = '选择/取消选择所有数据表';
$install_phrases['delete_selected_tables'] = '删除选中的数据表';
$install_phrases['mysql_strict_mode'] = 'MySQL 正运行在 Strict 模式。您可以继续，但是 vBulletin 的某些功能会不正常。<strong>强烈建议</strong>您在 includes/config.php 文件中将 <code>$config[\'Database\'][\'force_sql_mode\']</code> 设置为 <code>true</code>!';
$install_phrases['resetting_db'] = '正在清空数据库...';
$install_phrases['succeeded'] = '成功';
$install_phrases['script_reported_errors'] = '安装程序在创建数据表的时候出现错误。仅当您觉得此错误不严重的情况下才可以继续安装。';
$install_phrases['errors_were'] = '错误是:';
$install_phrases['tables_setup'] = '数据表成功创建。';
$install_phrases['general_settings'] = '常规设置';
$install_phrases['bbtitle'] = '<b>论坛标题</b> <dfn>论坛的标题，显示在论坛的每一页。</dfn>';
$install_phrases['hometitle'] = '<b>主页标题</b> <dfn>您的主页名称，显示在论坛每一页底部。例如，<em>http://www.example.com/forums</em></dfn>';
$install_phrases['bburl'] = '<b>论坛网址</b> <dfn>论坛的网址 (不包括最后的“/”)。</dfn>';
$install_phrases['homeurl'] = '<b>主页网址</b> <dfn>您主页的网址，显示在论坛每一页底部。</dfn>';
$install_phrases['webmasteremail'] = '<b>网站管理员电子邮件地址</b> <dfn>网站管理员的电子邮件地址。</dfn>';
$install_phrases['cookiepath'] = '<b>Cookie 保存路径</b> <dfn>Cookie 保存的路径。如果您在同一个域名下运行了多个论坛，便需要将它设置为每个论坛所在的目录名。否则，填写 / 便可以了。<br /><br />Cookie 路径建议的有效值已在旁边的下拉框中列出。如果您认为还有更加合适的不同的设置，选中复选框并在下面的输入框中输入合适的值。<br /><br />请注意路径<b>总是</b>应当以正斜杠结尾，例如 \'/forums/\'、\'/vbulletin/\' 等。<br /><br /><span class="modlasttendays">输入错误的路径，会导致您无法登录论坛。</span></dfn>';
$install_phrases['cookiedomain'] = '<b>Cookie 作用域名</b> <dfn>Cookie 所影响的域名。修改此选项默认值最常见的原因是，您的论坛有两个不同的网址，例如 example.com 和 forums.example.com。要使用户在以两个不同的域名访问论坛时，都能保持登录状态，您需要将此选项设置为 <b>.example.com</b> (注意域名需要以<b>点</b>开头)。<br /><br />Cookie 域名建议的有效值已在旁边的下拉框中列出。如果您认为还有更加合适的不同的设置，选中复选框并在下面的输入框中输入合适的值。<br /><br /><span class="modlasttendays">若您没有把握，最好在这里什么也不填写，因为错误的设置会导致您无法登录论坛。</span></dfn>';
$install_phrases['suggested_settings'] = '建议的设置';
$install_phrases['custom_setting'] = '自定义设置';
$install_phrases['use_custom_setting'] = '使用自定义设置 (在下面指定)';
$install_phrases['blank'] = '(空)';
$install_phrases['fill_in_for_admin_account'] = '请填写下面的表单，把自己设置成管理员';
$install_phrases['username'] = '用户名';
$install_phrases['password'] = '密码';
$install_phrases['confirm_password'] = '确认密码';
$install_phrases['email_address'] = '电子邮件';
$install_phrases['complete_all_data'] = '您没有填写全部数据。<br /><br />请点击“下一步”按钮返回重填。';
$install_phrases['password_not_match'] = '“密码”和“确认密码”两处填写的密码不一致！<br /><br />请点击“下一步”按钮返回并修正。';
$install_phrases['admin_added'] = '管理员已添加';
$install_phrases['install_complete'] = '<p>您已经成功的安装了 vBulletin 3。<br />
	<br />
	<font size="+1"><b>您运行此论坛前还必须删除如下文件:</b><br />
	install/install.php</font><br />
	<br />
	当您删除它后，您可以进入您的控制面板。
	<br />
	进入控制面板可以<b><a href="../%1$s/index.php">点击这里</a>。</b>';

$install_phrases['alter_table_type_x'] = '正在改变数据表 ' . TABLE_PREFIX . '%1$s 为 %2$s 类型';
$install_phrases['default_calendar'] = '默认日历';
$install_phrases['category_title'] = '主分类';
$install_phrases['category_desc'] = '主分类描述';
$install_phrases['forum_title'] = '主版面';
$install_phrases['forum_desc'] = '主版面描述';
$install_phrases['posticon_1'] = '帖子';
$install_phrases['posticon_2'] = '箭头';
$install_phrases['posticon_3'] = '灯泡';
$install_phrases['posticon_4'] = '警告';
$install_phrases['posticon_5'] = '问题';
$install_phrases['posticon_6'] = '酷';
$install_phrases['posticon_7'] = '微笑';
$install_phrases['posticon_8'] = '生气';
$install_phrases['posticon_9'] = '难过';
$install_phrases['posticon_10'] = '呲牙';
$install_phrases['posticon_11'] = '尴尬';
$install_phrases['posticon_12'] = '眨眼';
$install_phrases['posticon_13'] = '很差';
$install_phrases['posticon_14'] = '不错';
$install_phrases['generic_avatars'] = '标准头像';
$install_phrases['generic_smilies'] = '标准表情图标';
$install_phrases['generic_icons'] = '标准信息图标';
// should be the values that vbulletin-language.xml contains
$install_phrases['master_language_title'] = '简体中文';
$install_phrases['master_language_langcode'] = 'zh-CN';
$install_phrases['master_language_charset'] = 'UTF-8';
$install_phrases['master_language_decimalsep'] = '.';
$install_phrases['master_language_thousandsep'] = ',';
$install_phrases['default_style'] = '默认风格';
$install_phrases['smilie_smile'] = '微笑';
$install_phrases['smilie_embarrass'] = '困窘';
$install_phrases['smilie_grin'] = '尴尬';
$install_phrases['smilie_wink'] = '眨眼';
$install_phrases['smilie_tongue'] = '吐舌';
$install_phrases['smilie_cool'] = '酷';
$install_phrases['smilie_roll'] = '讽刺';
$install_phrases['smilie_mad'] = '疯狂';
$install_phrases['smilie_eek'] = '惊讶';
$install_phrases['smilie_confused'] = '困惑';
$install_phrases['smilie_frown'] = '难过';
$install_phrases['socialgroups_uncategorized'] = '未分类';
$install_phrases['socialgroups_uncategorized_description'] = '未分类的社会兴趣讨论组';
$install_phrases['usergroup_guest_title'] = '游客/未登录用户';
$install_phrases['usergroup_guest_usertitle'] = '游客';
$install_phrases['usergroup_registered_title'] = '注册会员';
$install_phrases['usergroup_activation_title'] = '等待邮件验证会员';
$install_phrases['usergroup_coppa_title'] = '等待管理员 (或 COPPA) 验证会员';
$install_phrases['usergroup_super_title'] = '超级版主';
$install_phrases['usergroup_super_usertitle'] = '超级版主';
$install_phrases['usergroup_admin_title'] = '管理员';
$install_phrases['usergroup_admin_usertitle'] = '论坛管理员';
$install_phrases['usergroup_mod_title'] = '版主';
$install_phrases['usergroup_mod_usertitle'] = '版主';
$install_phrases['usergroup_banned_title'] = '封禁用户';
$install_phrases['usergroup_banned_usertitle'] = '封禁用户';
$install_phrases['usertitle_jnr'] = '初级会员';
$install_phrases['usertitle_mbr'] = '普通会员';
$install_phrases['usertitle_snr'] = '高级会员';

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 31381 $
|| ####################################################################
\*======================================================================*/
?>