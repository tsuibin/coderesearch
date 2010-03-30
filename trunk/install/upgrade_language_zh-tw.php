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

$authenticate_phrases['upgrade_title'] = '繁體中文版升級系統';
$authenticate_phrases['enter_system'] = '進入升級系統';
$authenticate_phrases['enter_cust_num'] = '請輸入您的客戶號';
$authenticate_phrases['customer_number'] = '客戶號';
$authenticate_phrases['cust_num_explanation'] = '這是您登入 vBulletin 客戶區使用的客戶號';
$authenticate_phrases['cust_num_success'] = '客戶號驗證成功。';
$authenticate_phrases['redirecting'] = '正在重導向……';

#####################################
# upgradecore phrases
#####################################
$upgradecore_phrases['vb3_upgrade_system'] = 'vBulletin 3.8 中文版升級系統';
$upgradecore_phrases['please_login'] = '請登入:';
$upgradecore_phrases['username'] = '用戶名稱';
$upgradecore_phrases['password'] = '密碼';
$upgradecore_phrases['login'] = ' 登入 ';
$upgradecore_phrases['php_version_too_old'] = 'vBulletin 3.8 需要 PHP 版本 4.3.3 或更高版本。您的 PHP 版本是 ' . PHP_VERSION . '，請聯繫主機商升級。';
$upgradecore_phrases['mysql_version_too_old'] = 'vBulletin 3.8 需要 MySQL 版本 4.0.16 或更高版本。您的 MySQL 版本是 %1$s，請聯繫主機商升級。';
$upgradecore_phrases['ensure_config_exists'] = '請確認您已經建立了 vB3 的新目錄結構';
$upgradecore_phrases['mysql_strict_mode'] = 'MySQL 正運行在 Strict 模式。您可以繼續，但是 vBulletin 的某些功能會不正常。<strong>強烈建議</strong>您在 includes/config.php 檔案中將 <code>$config[\'Database\'][\'force_sql_mode\']</code> 發文為 <code>true</code>!';
$upgradecore_phrases['step_x_of_y'] = ' (步驟 %1$d ，共 %2$d 步)';
$upgradecore_phrases['unknown'] = '未知';
$upgradecore_phrases['file_not_found'] = '檔案未找到!';
$upgradecore_phrases['xml_file_versions'] = 'XML 檔案版本:';
$upgradecore_phrases['may_take_some_time'] = '(請注意一些步驟會花去較長時間，請耐心等待)';
$upgradecore_phrases['update_v_number'] = '正在更新版本號到 ' . VERSION . '… ';
$upgradecore_phrases['skipping_v_number_update'] = '正在跳過版本號更新，因為您安裝的版本版本號更新... ';
$upgradecore_phrases['done'] = '完成';
$upgradecore_phrases['step_title'] = '步驟 %1$d) %2$s';
$upgradecore_phrases['batch_complete'] = '批處理完成！如果您沒有被自動重導向，請按右邊的按鈕。';
$upgradecore_phrases['next_batch'] = ' 下一批';
$upgradecore_phrases['next_step'] = '下一步 (%1$d/%2$d)';
$upgradecore_phrases['click_button_to_proceed'] = '按右邊的按鈕繼續。';
$upgradecore_phrases['page_x_of_y'] = '第 %1$d 頁，共 %2$d 頁';
$upgradecore_phrases['semicolons_file_intro'] = "下面的用戶名稱包含分號( ; )\r\n*必須*在控制面版中修改:";
$upgradecore_phrases['dump_data_to_sql'] = '導出資料到 SQL 檔案';
$upgradecore_phrases['choose_table_to_dump'] = '選擇要備份的資料表';
$upgradecore_phrases['dump_tables'] = '備份資料表';
$upgradecore_phrases['dump_data_to_csv'] = '導出資料到 CSV 檔案';
$upgradecore_phrases['backup_individual_table'] = '備份<b>單個資料表</b>';
$upgradecore_phrases['field_seperator'] = '欄位分隔符';
$upgradecore_phrases['quote_character'] = '引號字元';
$upgradecore_phrases['show_column_names'] = '顯示列名';
$upgradecore_phrases['dump_table'] = '備份資料表';
$upgradecore_phrases['vb_db_dump_completed'] = 'vBulletin 資料庫備份完成';
$upgradecore_phrases['dump_all_tables'] = '* 備份所有資料表 *';
$upgradecore_phrases['dump_database_desc'] = '<p class="smallfont">在這裏，您可以備份您的 vBulletin 資料庫。</p>
		<p class="smallfont">請注意如果您有一個特別大的資料庫，
		此程式<i>可能</i>無法將它完全備份下來。</p>
		<p class="smallfont">如果您想要一個安全的備份，請通過 Telnet 或 SSH 登入到您的伺服器並使用 <i>mysqldump</i> 命令。
		更多訊息，請參考
		<a href="http://www.vbulletin.com/manual/html/manual_database_backup" target="_blank">這裏</a>。</p>';
$upgradecore_phrases['backup_after_upgrade'] = '<p class="smallfont">在執行升級前必須進行備份，如果升級完成請使用管理面版。</p>
		<p class="smallfont">更安全的備份方式是，通過 Telnet 或 SSH 登入到您的伺服器並在命令行使用 <i>mysqldump</i> 命令。
		要了解更多訊息，請<a href="http://www.vbulletin.com/docs/html/maintenance_ssh_backup" target="_blank">閱讀這裏</a>。</p>';
$upgradecore_phrases['vb_database_backup_system'] = 'vBulletin 資料庫備份系統';
$upgradecore_phrases['eaccelerator_too_old'] = 'eAccelerator for PHP 必須升級到 0.9.3 或更高版本。請瀏覽<a href="http://www.vbulletin.com/forum/showthread.php?p=979044#post979044">這個文章</a>以了解更多訊息。';
$upgradecore_phrases['apc_too_old'] = '您的伺服器正在運行 <a href="http://pecl.p' . 'hp.net/package/APC/">Alternative PHP Cache</a> (APC) 的一個版本，而這個版本不相容 vBulletin。請升級到 APC 3.0.0 或更高版本。';
$upgradecore_phrases['mmcache_not_supported'] = 'Turck MMCache 已經被 eAcclerator 取代，不能正確支援 vBulletin。請瀏覽<a href="http://www.vbulletin.com/forum/showthread.php?p=979044#post979044">這個文章</a>以了解更多訊息。';
$upgradecore_phrases['altering_x_table'] = '正在修改 %1$s 資料表 (第 %2$d 個，共計 %3$d 個)';
$upgradecore_phrases['wrong_bitfield_xml'] = 'includes/xml/bitfield_vbulletin.xml 檔案已過期。請確認您上傳了正確的檔案。';

// this should contain only characters which will show on the file system
$upgradecore_phrases['illegal_user_names'] = 'Illegal User Names.txt';

$phrasetype['global'] = '全局 (GLOBAL)';
$phrasetype['cpglobal'] = '控制面版全局 (Control Panel Global)';
$phrasetype['cppermission'] = '權限 (Permissions)';
$phrasetype['forum'] = '版面相關 (Forum-Related)';
$phrasetype['calendar'] = '日曆 (Calendar)';
$phrasetype['attachment_image'] = '附件/圖像 (Attachment/Image)';
$phrasetype['style'] = '風格工具 (Style Tools)';
$phrasetype['logging'] = '日誌工具 (Logging Tools)';
$phrasetype['cphome'] = '控制面版首頁 (Control Panel Home Pages)';
$phrasetype['promotion'] = '提升工具 (Promotion Tools)';
$phrasetype['user'] = '用戶工具(全局) (User Tools (global))';
$phrasetype['help_faq'] = '論壇幫助管理 (FAQ / Help Management)';
$phrasetype['sql'] = 'SQL 工具 (SQL Tools)';
$phrasetype['subscription'] = '訂閱工具 (Subscription Tools)';
$phrasetype['language'] = '語言工具 (Language Tools)';
$phrasetype['bbcode'] = 'BB 代碼工具 (BB Code Tools)';
$phrasetype['stats'] = '統計工具 (Statistics Tools)';
$phrasetype['diagnostics'] = '診斷工具 (Diagnostic Tools)';
$phrasetype['maintenance'] = '維護工具 (Maintenance Tools)';
$phrasetype['profile'] = '用戶資料欄目工具 (Profile Field Tools)';
$phrasetype['cprofilefield'] = '自訂資料欄目 (Custom Profile Fields)';
$phrasetype['thread'] = '主題工具 (Thread Tools)';
$phrasetype['timezone'] = '時區 (Timezones)';
$phrasetype['banning'] = '封禁工具 (Banning Tools)';
$phrasetype['reputation'] = '聲望 (Reputation)';
$phrasetype['wol'] = '線上訊息 (Who\\\'s Online)';
$phrasetype['threadmanage'] = '主題管理 (Thread Management)';
$phrasetype['pm'] = '悄悄話 (Private Messaging)';
$phrasetype['cpuser'] = '控制面版用戶管理 (Control Panel User Management)';
$phrasetype['register'] = '註冊 (Register)';
$phrasetype['accessmask'] = '存取權限 (Access Masks)';
$phrasetype['cron'] = '計劃任務 (Scheduled Tasks)';
$phrasetype['moderator'] = '版主 (Moderators)';
$phrasetype['cpoption'] = '控制面版選項 (Control Panel Options)';
$phrasetype['cprank'] = '控制面版用戶等級 (Control Panel User Ranks)';
$phrasetype['cpusergroup'] = '控制面版用戶群組 (Control Panel User Groups)';
$phrasetype['holiday'] = '節假日 (Holidays)';
$phrasetype['posting'] = '發文 (Posting)';
$phrasetype['poll'] = '投票 (Polls)';
$phrasetype['fronthelp'] = '前臺論壇幫助 (Frontend FAQ/Help)';
$phrasetype['search'] = '搜尋 (Searching)';
$phrasetype['showthread'] = '顯示主題 (Show Thread)';
$phrasetype['postbit'] = '文章塊 (Postbit)';
$phrasetype['forumdisplay'] = '版面顯示 (Forum Display)';
$phrasetype['messaging'] = '即時訊息 (Messaging)';
$phrasetype['inlinemod'] = '快速管理 (Inline Moderation)';
$phrasetype['plugins'] = '外掛程式系統 (Plugin System)';
$phrasetype['front_end_error'] = '錯誤訊息 (Error Messages)';
$phrasetype['front_end_redirect'] = '前臺重導向訊息 (Front-End Redirect Messages)';
$phrasetype['email_body'] = '郵件內容內容 (Email Body Text)';
$phrasetype['email_subj'] = '郵件主題內容 (Email Subject Text)';
$phrasetype['vbulletin_settings'] = '論壇發文 (vBulletin Settings)';
$phrasetype['cp_help'] = '控制面版幫助內容 (Control Panel Help Text)';
$phrasetype['faq_title'] = '論壇幫助標題 (FAQ Title)';
$phrasetype['faq_text'] = '論壇幫助內容 (FAQ Text)';
$phrasetype['stop_message'] = '控制面版停止訊息 (Control Panel Stop Message)';
$phrasetype['reputationlevel'] = '聲望級別 (Reputation Levels)';
$phrasetype['infraction'] = '用戶違規 (User Infractions)';
$phrasetype['infractionlevel'] = '用戶違規級別 (User Infraction Levels)';
$phrasetype['notice'] = '通知 (Notices)';
$phrasetype['prefix'] = '主題首碼 (Thread Prefixes)';
$phrasetype['prefixadmin'] = '主題首碼 (管理) (Thread Prefixes (Admin))';
$phrasetype['album'] = '相簿 (Albums)';
$phrasetype['hvquestion'] = '真人驗證問題 (Human Verification Questions)';
$phrasetype['socialgroups'] = '社會興趣討論群組 (Social Groups)';

#####################################
# phrases for import systems
#####################################
$vbphrase['please_wait'] = '請等待';
$vbphrase['language'] = '語言';
$vbphrase['master_language'] = '主語言';
$vbphrase['admin_help'] = '管理員幫助';
$vbphrase['style'] = '風格';
$vbphrase['styles'] = '風格';
$vbphrase['settings'] = '發文';
$vbphrase['master_style'] = '主風格';
$vbphrase['templates'] = '範本';
$vbphrase['css'] = 'CSS';
$vbphrase['stylevars'] = '風格變數';
$vbphrase['replacement_variables'] = '替換變數';
$vbphrase['controls'] = '控制';
$vbphrase['rebuild_style_information'] = '重建風格訊息';
$vbphrase['updating_style_information_for_each_style'] = '正在為每個風格更新風格訊息';
$vbphrase['updating_styles_with_no_parents'] = '正在更新無主風格的風格集';
$vbphrase['updated_x_styles'] = '已更新 %1$s 個風格';
$vbphrase['no_styles_needed_updating'] = '沒有風格需要更新';
$vbphrase['yes'] = '是';
$vbphrase['no'] = '否';


#####################################
# global upgrade phrases
#####################################
$vbphrase['vbulletin_message'] = 'vBulletin 訊息';
$vbphrase['create_table'] = '正在建立 %1$s 資料表';
$vbphrase['remove_table'] = '正在刪除 %1$s 資料表';
$vbphrase['alter_table'] = '正在修改 %1$s 資料表';
$vbphrase['update_table'] = '正在更新 %1$s 資料表';
$vbphrase['upgrade_start_message'] = "<p>此程式將把您的 vBulletin 升級到 <b>" . VERSION . "</b>。</p>\n<p>按“下一步”按鈕繼續。</p>";
$vbphrase['upgrade_wrong_version'] = "<p>您的 vBulletin 版本不符合此程式的運行條件 (需要在版本 <b>" . PREV_VERSION . "</b> 的基礎上運行)。</p>\n<p>請確認您運行的腳本是否正確。</p>\n<p>如果您確定正確，<a href=\"" . THIS_SCRIPT . "?step=1\">請按這裏繼續運行</a>。</p>";
$vbphrase['file_not_found'] = '嗯？./install/%1$s 好像不存在！';
$vbphrase['importing_file'] = '正在導入 %1$s';
$vbphrase['ok'] = '完成';
$vbphrase['query_took'] = '查詢花去 %1$s 秒執行。';
$vbphrase['done'] = '完成';
$vbphrase['proceed'] = '繼續';
$vbphrase['reset'] = '重置';
$vbphrase['alter_table_step_x'] = '正在修改 %1$s 資料表 (步驟 %2$d ，共 %3$d 步)';
$vbphrase['vbulletin_copyright'] = 'vBulletin v' . VERSION . ', 版權所有 &copy;2000 - ' . date('Y') . ', Jelsoft Enterprises Ltd.';
$vbphrase['vbulletin_copyright_orig'] = $vbphrase['vbulletin_copyright'];
$vbphrase['processing_complete_proceed'] = '處理完成 - 繼續';
$vbphrase['xml_error_x_at_line_y'] = 'XML 錯誤: %1$s 在行 %2$s';
$vbphrase['apply_critical_template_change_to_x'] = '正在為風格 ID %2$s 的範本 %1$s 進行安全修正';
#####################################
# upgrade_300b3.php phrases
#####################################

$upgrade_phrases['upgrade_300b3.php']['steps'] = array(
	1  => '建立新的 vBulletin 3 資料表',
	2  => '升級範本並進行修改查詢',
	3  => '升級日曆',
	4  => '修改論壇資料表',
	5  => '升級論壇最新貼訊息',
	6  => '升級悄悄話訊息',
	7  => '升級用戶',
	8  => '修改用戶資料表 (第一部分)',
	9  => '修改用戶資料表 (第二部分)',
	10 => '升級公告資料表',
	11 => '修改頭像/表情符號/訊息圖示資料表',
	12 => '修改附件資料表',
	13 => '升級附件 (第一部分)',
	14 => '升級附件 (第二部分)',
	15 => '升級編輯文章記錄',
	16 => '升級主題和文章資料表',
	17 => '升級文章以支援樹型查看模式',
	18 => '修改其它資料表 (第一部分)',
	19 => '修改其它資料表 (第二部分)',
	20 => '升級 BB 代碼系統',
	21 => '修改用戶群組資料表',
	22 => '升級論壇權限',
	23 => '升級版主權限',
	24 => '插入短語組',
	25 => '插入計劃任務',
	26 => '更新發文 (第一部分)',
	27 => '更新發文 (第二部分)',
	28 => '導入 vbulletin-language.xml',
	29 => '導入 vbulletin-adminhelp.xml',
	30 => '修改風格資料表並刪除替換集資料表',
	31 => '修改範本資料表',
	32 => '生成用戶聲望',
	33 => '基於存在的 vB2 風格建立 vB3 風格',
	34 => '翻譯 vB2 替換變數為 vB3 風格/CSS/替換範本變數',
	35 => '移動原有自訂範本到它們相應的風格中',
	36 => '刪除多餘的樣式資料表並清理翻譯過程',
	37 => '導入 vbulletin-style.xml',
	38 => '建立風格訊息',
	39 => '導入常見問題解答專案',
	40 => '檢查不合法的用戶名稱',
	41 => '導入發文並清理',
	42 => '成功升級到vBulletin ' . VERSION . '！'
);
$upgrade_phrases['upgrade_300b3.php']['tableprefix_not_empty'] = '$config[\'Database\'][\'tableprefix\'] 不是空的！';
$upgrade_phrases['upgrade_300b3.php']['tableprefix_not_empty_fix'] = "在安裝進程中 config.php 的 \$config['Database']['tableprefix'] 參數必須為空。";
$upgrade_phrases['upgrade_300b3.php']['welcome'] = '<p style="font-size:14px;"><b>歡迎使用 vBulletin 3.8 中文版</b></p>
	<p>您即將升級您的論壇，因此它被自動關閉。</p>
	<p>按<b>[下一步]</b>按鈕將會在您的資料庫“<i>%1$s</i>”上開始升級進程。</p>
	<p>為了避免安裝時瀏覽器崩潰，我們強烈建議您關閉瀏覽器上的第三方工具欄，例如 <b>Google、MSN、Alexa</b> 工具欄等。</p>
	<p>建議您升級前備份您的整個資料庫。<br /><a href="upgrade_300b3.php?step=backup"><b>如果您要備份資料庫，請按這裏</b></a>。</p>';
$upgrade_phrases['upgrade_300b3.php']['safe_mode_warning'] = '您的 PHP 目前運行在安全模式。當運行在安全模式時我們無法發文程式超時限制。因此，備份您的資料庫以便出錯後恢復顯得更加重要。';
$upgrade_phrases['upgrade_300b3.php']['upgrade_already_run'] = '我們偵測到您曾經嘗試運行過此升級程式。您必須將現在的資料庫恢復成 vB 2.2.x 的結構此升級程式才能繼續運行。';
$upgrade_phrases['upgrade_300b3.php']['moving_maxloggedin_datastore'] = '正在移動 maxloggedin 範本到新資料表';
$upgrade_phrases['upgrade_300b3.php']['new_datastore_values'] = '正在建立新的 Datastore 值';
$upgrade_phrases['upgrade_300b3.php']['removing_special_templates'] = '正在從範本資料表中移動特定的範本';
$upgrade_phrases['upgrade_300b3.php']['removing_orphan_pms'] = '正在刪除重覆的悄悄話';
$upgrade_phrases['upgrade_300b3.php']['rename_calendar_events'] = '正在重命名 calendar_events 為 event';
$upgrade_phrases['upgrade_300b3.php']['altering_x_table'] = '正在修改 %1$s 資料表 (步驟 %2$d ，共 %3$d 步)';
$upgrade_phrases['upgrade_300b3.php']['droping_event_date'] = '從 event 資料表中刪除事件日期';
$upgrade_phrases['upgrade_300b3.php']['changing_subject_to_title'] = '正在更改“subject”為“title”';
$upgrade_phrases['upgrade_300b3.php']['creating_pub_calendar'] = '正在建立公共日曆';
$upgrade_phrases['upgrade_300b3.php']['creating_priv_calendar'] = '正在建立私有日曆';
$upgrade_phrases['upgrade_300b3.php']['moving_pub_events'] = '正在移動公共事件到公共日曆';
$upgrade_phrases['upgrade_300b3.php']['moving_priv_events'] = '正在移動私有事件到私有日曆';
$upgrade_phrases['upgrade_300b3.php']['drop_public_field'] = '正在從事件表中刪除 public 列';
$upgrade_phrases['upgrade_300b3.php']['convert_forum_options'] = '正在轉換論壇選項儲存方式';
$upgrade_phrases['upgrade_300b3.php']['dropping_option_fields'] = '正在刪除選項 (步驟 %1$d ，共 %2$d 步)';
$upgrade_phrases['upgrade_300b3.php']['resetting_styleids'] = '正在重置 styleid 為預設論壇風格';
$upgrade_phrases['upgrade_300b3.php']['updating_forum_child_lists'] = '正在更新子論壇列表';
$upgrade_phrases['upgrade_300b3.php']['updating_counters_for_x'] = '正在更新論壇 <i>%1$s</i> 的計數器';
$upgrade_phrases['upgrade_300b3.php']['updating_lastpost_info_for_x'] = '正在更新論壇 <i>%1$s</i> 的最新文章訊息';
$upgrade_phrases['upgrade_300b3.php']['converting_priv_msg_x'] = '正在轉換悄悄話，%1$s';
$upgrade_phrases['upgrade_300b3.php']['insert_priv_msg_txt_from_x'] = '正在插入來自 <i>%1$s</i> 的悄悄話內容';
$upgrade_phrases['upgrade_300b3.php']['insert_priv_msg_from_x_to_x'] = '正在插入從 <i>%1$s</i> 發往 <i>%2$s</i> 的悄悄話';
$upgrade_phrases['upgrade_300b3.php']['update_priv_msg_multiple_recip'] = '正在更新悄悄話內容以顯示多回執';
$upgrade_phrases['upgrade_300b3.php']['insert_priv_msg_receipts'] = '正在插入悄悄話回執';
$upgrade_phrases['upgrade_300b3.php']['dropping_vb2_pm_table'] = '正在刪除 vBulletin 2 悄悄話資料表';
$upgrade_phrases['upgrade_300b3.php']['alter_user_table_for_vb3_pm'] = '正在修改用戶資料表以支援 vB3 悄悄話系統';
$upgrade_phrases['upgrade_300b3.php']['alter_user_table_vb3_password'] = '正在修改用戶資料表以支援 vB3 密碼系統';
$upgrade_phrases['upgrade_300b3.php']['priv_msg_import_complete'] = '悄悄話導入完成';
$upgrade_phrases['upgrade_300b3.php']['upgrading_users_x'] = '正在升級用戶，%1$s';
$upgrade_phrases['upgrade_300b3.php']['found_x_users'] = '此批找到 %1$d 位用戶…';
$upgrade_phrases['upgrade_300b3.php']['updating_priv_messages_for_x'] = '正在更新用戶 <i>%1$s</i> 的悄悄話總數';
$upgrade_phrases['upgrade_300b3.php']['inserting_user_details_usertextfield'] = '正在插入用戶細節到 <i>usertextfield</i> 資料表';
$upgrade_phrases['upgrade_300b3.php']['user_upgrades_complete'] = '用戶升級完成';
$upgrade_phrases['upgrade_300b3.php']['updating_user_table_options'] = '正在更新 user 資料表選項';
$upgrade_phrases['upgrade_300b3.php']['drop_user_option_fields'] = '正在刪除用戶選項 (步驟 %1$d ，共 3 步)';
$upgrade_phrases['upgrade_300b3.php']['update_access_masks'] = '正在更新用戶權限';
$upgrade_phrases['upgrade_300b3.php']['convert_new_birthday_format'] = '正在轉換生日到新格式';
$upgrade_phrases['upgrade_300b3.php']['insert_admin_perms_admin_table'] = '正在插入管理員權限到 administrator 資料表';
$upgrade_phrases['upgrade_300b3.php']['updating_announcements'] = '正在更新公告';
$upgrade_phrases['upgrade_300b3.php']['announcement_x'] = '公告: %1$s';
$upgrade_phrases['upgrade_300b3.php']['add_index_avatar_table'] = '正在新增索引到 avatar 資料表';
$upgrade_phrases['upgrade_300b3.php']['move_avatars_to_category'] = '正在移動頭像到“標準頭像”分類';
$upgrade_phrases['upgrade_300b3.php']['move_icons_to_category'] = '正在移動訊息圖示到“標準訊息圖示”分類';
$upgrade_phrases['upgrade_300b3.php']['move_smilies_to_category'] = '正在移動表情符號到“標準表情符號”分類';
$upgrade_phrases['upgrade_300b3.php']['update_avatars_per_page'] = '正在更新每頁的頭像';
$upgrade_phrases['upgrade_300b3.php']['updating_attachments'] = '正在更新附件…';
$upgrade_phrases['upgrade_300b3.php']['attachment_x'] = '附件: %1$d';
$upgrade_phrases['upgrade_300b3.php']['remove_orphan_attachments'] = '正在刪除重覆的附件';
$upgrade_phrases['upgrade_300b3.php']['populating_attachmenttype_table'] = '正在生成附件類型資料表';
$upgrade_phrases['upgrade_300b3.php']['updating_editpost_log'] = '正在升級編輯文章記錄，%1$s';
$upgrade_phrases['upgrade_300b3.php']['found_x_posts'] = '此批找到 %1$d 個文章…';
$upgrade_phrases['upgrade_300b3.php']['post_x'] = '文章: %1$d';
$upgrade_phrases['upgrade_300b3.php']['post_editlog_complete'] = '文章編輯記錄升級完成';
$upgrade_phrases['upgrade_300b3.php']['steps_may_take_several_minutes'] = '請注意，如果您資料庫中有大量文章，此步驟會花去<b>幾分鐘</b>的時間。';
$upgrade_phrases['upgrade_300b3.php']['altering_post_table'] = '正在修改 post 資料表…';
$upgrade_phrases['upgrade_300b3.php']['altering_thread_table'] = '正在修改 thread 資料表…';
$upgrade_phrases['upgrade_300b3.php']['inserting_moderated_threads'] = '正在插入等待驗證的主題';
$upgrade_phrases['upgrade_300b3.php']['inserting_moderated_posts'] = '正在插入等待驗證的文章';
$upgrade_phrases['upgrade_300b3.php']['update_posts_support_threaded'] = '正在更新文章以支援樹型模式，%1$s';
$upgrade_phrases['upgrade_300b3.php']['found_x_threads'] = '此批找到 %1$d 個主題…';
$upgrade_phrases['upgrade_300b3.php']['threaded_update_complete'] = '主題查看模式升級完成';
$upgrade_phrases['upgrade_300b3.php']['emptying_search'] = '正在清空搜尋索引';
$upgrade_phrases['upgrade_300b3.php']['emptying_wordlist'] = '正在清空詞語列表';
$upgrade_phrases['upgrade_300b3.php']['remove_bbcodes_hardcoded_now'] = '正在刪除內部定義的 BB 代碼 ([B], [I], [U], [FONT={option}], [SIZE={option}], [COLOR={option}])';
$upgrade_phrases['upgrade_300b3.php']['inserting_quote_bbcode'] = '正在插入 [QUOTE=<i>用戶名稱</i>]----[/QUOTE] BB 代碼標籤';
$upgrade_phrases['upgrade_300b3.php']['select_banned_groups'] = '請選擇所有包含“封禁用戶”的用戶群組';
$upgrade_phrases['upgrade_300b3.php']['explain_banned_groups'] = "在 vBulletin 3 中，“被封禁用戶”的用戶群組需要明確指定。<br /><br />\n如果您有任何“被封禁用戶”的用戶群組，請在這裏選擇那些組。";
$upgrade_phrases['upgrade_300b3.php']['user_groups'] = '用戶群組:';
$upgrade_phrases['upgrade_300b3.php']['update_some_usergroup_titles'] = '正在更新一些用戶群組的標題';
$upgrade_phrases['upgrade_300b3.php']['updating_usergroup_permissions'] = '正在更新用戶群組權限';
$upgrade_phrases['upgrade_300b3.php']['usergroup_x'] = '用戶群組: <i>%1$s</i>';
$upgrade_phrases['upgrade_300b3.php']['updating_usergroups'] = '正在更新用戶群組';
$upgrade_phrases['upgrade_300b3.php']['updating_generic_options'] = '正在更新用戶群組一般選項';
$upgrade_phrases['upgrade_300b3.php']['updating_usergroup_calendar'] = '正在更新用戶群組日曆權限';
$upgrade_phrases['upgrade_300b3.php']['creating_priv_calendar_perms'] = '正在建立私人日曆權限';
$upgrade_phrases['upgrade_300b3.php']['removing_orhpan_forum_perms'] = '正在刪除重覆的論壇權限';
$upgrade_phrases['upgrade_300b3.php']['backup_forum_perms'] = '正在備份論壇權限';
$upgrade_phrases['upgrade_300b3.php']['drop_old_forumperms'] = '正在刪除原論壇權限資料表';
$upgrade_phrases['upgrade_300b3.php']['usergroup_x_forum_y'] = '用戶群組: <i>%1$s</i> 在論壇 <i>%2$s</i>';
$upgrade_phrases['upgrade_300b3.php']['reinsert_forum_perms'] = '正在以新格式重新插入論壇權限';
$upgrade_phrases['upgrade_300b3.php']['remove_forum_perms_backup'] = '正在刪除論壇權限備份';
$upgrade_phrases['upgrade_300b3.php']['updating_moderator_perms'] = '正在更新版主權限';
$upgrade_phrases['upgrade_300b3.php']['moderator_x_forum_y'] = '論壇 <u>%2$s</u> 的版主 <i>%1$s</i> ';
$upgrade_phrases['upgrade_300b3.php']['deleted_not_needed'] = '已刪除 - 不再相關。';
$upgrade_phrases['upgrade_300b3.php']['insert_phrase_groups'] = '正在插入短語組';
$upgrade_phrases['upgrade_300b3.php']['inserting_task_x'] = '正在插入任務 %1$d';
$upgrade_phrases['upgrade_300b3.php']['scheduling_x'] = '正在安排 %1$s';
$upgrade_phrases['upgrade_300b3.php']['update_setting_group_x'] = '正在更新發文組: <i>%1$s</i>';
$upgrade_phrases['upgrade_300b3.php']['update_settings_within_x'] = '正在更新發文位於組: <i>%1$s</i>';
$upgrade_phrases['upgrade_300b3.php']['insert_phrases_nonstandard_groups'] = '正在為非標準發文組插入短語';
$upgrade_phrases['upgrade_300b3.php']['insert_phrases_nonstandard_settings'] = '正在插入非標準發文的短語';
$upgrade_phrases['upgrade_300b3.php']['saving_your_settings'] = '正在儲存您的發文為以後使用…';
$upgrade_phrases['upgrade_300b3.php']['building_lang_x'] = '正在建立語言: %1$s';
$upgrade_phrases['upgrade_300b3.php']['language_imported_sucessfully'] = '語言導入成功！';
$upgrade_phrases['upgrade_300b3.php']['ahelp_imported_sucessfully'] = '管理員幫助導入成功！';
$upgrade_phrases['upgrade_300b3.php']['renaming_style_table'] = '正在重命名 <b>style</b> 資料表';
$upgrade_phrases['upgrade_300b3.php']['removing_default_templates'] = '正在刪除預設範本 (它們將稍後被替換)';
$upgrade_phrases['upgrade_300b3.php']['updating_template_format'] = '正在更新範本為新格式…';
$upgrade_phrases['upgrade_300b3.php']['updating_template_x'] = '正在更新範本: <i>%1$s</i>';
$upgrade_phrases['upgrade_300b3.php']['populating_reputation_levels'] = '正在生成用戶聲望級別資料表';
$upgrade_phrases['upgrade_300b3.php']['set_reputation_to_neutral'] = '發文所有用戶為中立的聲望';
$upgrade_phrases['upgrade_300b3.php']['bbtitle_vb3_style'] = '%1$s vBulletin 3 風格';
$upgrade_phrases['upgrade_300b3.php']['please_read_txt'] = '請仔細閱讀下面的內容！';
$upgrade_phrases['upgrade_300b3.php']['replacement_upgrade_desc'] = '<p><b>注意:</b></p>
		<p>此系統將嘗試翻譯 vBulletin 2 的替換變數 (例如: <b>{firstaltcolor}</b>) 使其能夠正常工作在
		vBulletin 3 中。這將把您預設的替換變數翻譯成 vBulletin 3 的風格變數和 CSS 發文。</p>
		<p>此程式現在將掃描您的 vBulletin 2 風格並建立一個相應的 vBulletin 3 新風格。</p>
		<p>下面列出的風格包含您 vBulletin 2 變數的風格發文，並且可以直接在 vBulletin 3 中使用。</p>';
$upgrade_phrases['upgrade_300b3.php']['create_vb3_style_x'] = "正在建立 vBulletin 3 風格: <b>'%1\$s'</b>";
$upgrade_phrases['upgrade_300b3.php']['template_upgrade_desc'] = '<p><b>注意:</b></p>
		<p>vBulletin 3 的範本與 vBulletin 2 顯著不同。因此，任何自訂範本實質上在 vBulletin 3
		中是無用的。</p>
		<p>但是，當您想修改 vBulletin 3 的範本時，您或許要參考以前在 vBulletin 2 中修改的範本。
		所以，此系統將建立包含您自訂範本的新風格。</p>
		<p>這些風格將<i>無法</i>在 vBulletin 3 中使用，建立它們只是為了方便您修改和參照。</p>';
$upgrade_phrases['upgrade_300b3.php']['create_vb2_refernce_style'] = "正在為您的範本集“<b>%1\$s</b>”建立一個引用風格";
$upgrade_phrases['upgrade_300b3.php']['x_old_custom_templates'] = '%1$s - 舊自訂範本';
$upgrade_phrases['upgrade_300b3.php']['insert_styles_vb3_table'] = '正在插入風格到 vB3 style 資料表';
$upgrade_phrases['upgrade_300b3.php']['updating_style_parent_list'] = '正在更新主風格列表';
$upgrade_phrases['upgrade_300b3.php']['updating_user_to_new_style'] = '正在更新用戶使用此新風格';
$upgrade_phrases['upgrade_300b3.php']['settings_imported_sucessfully'] = '發文導入成功！';
$upgrade_phrases['upgrade_300b3.php']['translate_replacement_to_stylevars'] = '正在翻譯替換變數到風格變數';
$upgrade_phrases['upgrade_300b3.php']['no_value_to_translate'] = '此風格中沒有變數需要翻譯';
$upgrade_phrases['upgrade_300b3.php']['translating_replacement_to_css'] = '正在翻譯替換變數到 CSS';
$upgrade_phrases['upgrade_300b3.php']['body_bg_color_x'] = 'body 背景顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['body_text_color_x'] = 'body 內容顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['margin_width_x'] = 'margin 寬度: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['link_color_x'] = '連結顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['hover_link_color_x'] = 'hover 連結顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['page_bg_color_x'] = '頁面背景顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['page_text_color_x'] = '頁面內容顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['table_border_color_x'] = '表格邊界顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['category_strip_bg_color'] = '分類條背景顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['category_strip_text_color'] = '分類條內容顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['tbl_head_bg_color_x'] = '表格頭部背景顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['tbl_head_text_color_x'] = '表格頭部內容顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['first_alt_color_x'] = '第一交換顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['second_alt_color_x'] = '第二交換顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['normal_font_size'] = '正常字型大小: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['normal_font_family'] = '正常字型名稱: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['normal_font_color'] = '正常字型顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['small_font_size'] = '小字型大小: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['small_font_family'] = '小字型名稱: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['small_font_color'] = '小字型顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['highlight_font_size'] = '高亮字型大小: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['highlight_font_family'] = '高亮字型名稱: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['highlight_font_color'] = '高亮字型顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['time_color_x'] = '時間顏色: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['no_replacements_to_translate'] = '此風格中沒有變數需要翻譯成 CSS';
$upgrade_phrases['upgrade_300b3.php']['translating_remaining_replacements'] = '正在轉換剩餘的替換變數為 vB3 替換變數';
$upgrade_phrases['upgrade_300b3.php']['no_remaining_replacement_vars'] = '此風格中沒有其它變數需要翻譯';
$upgrade_phrases['upgrade_300b3.php']['translate_vb2_style_settings'] = '正在翻譯 vB2 風格發文';
$upgrade_phrases['upgrade_300b3.php']['add_css_headinclude_to_extra'] = '正在從 headinclude 範本新增 CSS 資料到此風格的“額外”CSS 中';
$upgrade_phrases['upgrade_300b3.php']['found_css_data'] = '從 headinclude 範本找到並成功新增 CSS 資料';
$upgrade_phrases['upgrade_300b3.php']['no_css_data_found'] = 'headinclude 範本中沒有找到 CSS 資料';
$upgrade_phrases['upgrade_300b3.php']['no_headinclude_found'] = '此風格中沒有 headinclude 範本';
$upgrade_phrases['upgrade_300b3.php']['insert_style_settings'] = '正在插入風格發文到資料庫';
$upgrade_phrases['upgrade_300b3.php']['moving_template_x_to_style_x'] = "正在移動範本從範本集“%1\$s”到引用風格“%2\$s”";
$upgrade_phrases['upgrade_300b3.php']['importing_faq_entries'] = '正在導入常見問題解答專案';
$upgrade_phrases['upgrade_300b3.php']['follow_users_contain_semicolons'] = '以下用戶名稱包含分號，當您進入控制面版時<b>必須</b>修改:';
$upgrade_phrases['upgrade_300b3.php']['download_semicolon_users'] = '我們建議您使用<a href=\"upgrade_300b3.php?step=$step&amp;do=downloadillegalusers\"><b>這個連結</b></a>下載不合法的用戶名稱列表為以後參考。';
$upgrade_phrases['upgrade_300b3.php']['no_illegal_users_found'] = '沒有找到不合法的用戶名稱';
$upgrade_phrases['upgrade_300b3.php']['remove_old_settings_storage'] = '正在刪除舊風格選項';
$upgrade_phrases['upgrade_300b3.php']['salt_admin_x'] = '正在混淆管理員密碼: <b>%1$s</b>';
$upgrade_phrases['upgrade_300b3.php']['build_forum_and_usergroup_cache'] = '正在建立論壇和用戶緩存… ';
$upgrade_phrases['upgrade_300b3.php']['upgrade_complete'] = "您已經成功升級到 vBulletin 3。<br />
<br />
	<font size=\"+1\"><b>您運行此論壇前還必須刪除如下檔案:</b><br />
	install/install.php</font><br />
	<br />
	當您刪除它後，按“繼續”按鈕繼續。<br />
	<br />
	請注意目前您的論壇為<b>關閉</b>狀態<br />
	<br />
	<b>當您返回控制面版時需要重建搜尋索引和統計。</b><br />
	<br />
	<b注意: 您的升級並沒有完成。您目前運行的版本是 " . VERSION . ".
	按 “<i>繼續</i>”繼續升級到更新版本。</b>";

$upgrade_phrases['upgrade_300b3.php']['public'] = '公共';
$upgrade_phrases['upgrade_300b3.php']['public_calendar'] = '公共日曆';
$upgrade_phrases['upgrade_300b3.php']['private'] = '私有';
$upgrade_phrases['upgrade_300b3.php']['private_calendar'] = '私人日曆';
$upgrade_phrases['upgrade_300b3.php']['deleted_user'] = '已刪除用戶';
$upgrade_phrases['upgrade_300b3.php']['standard_avatars'] = '標準頭像';
$upgrade_phrases['upgrade_300b3.php']['standard_icons'] = '標準訊息圖示';
$upgrade_phrases['upgrade_300b3.php']['standard_smilies'] = '標準表情符號';
$upgrade_phrases['upgrade_300b3.php']['avatar_setting_title'] = '每頁顯示頭像';
$upgrade_phrases['upgrade_300b3.php']['avatar_setting_desc'] = '在“編輯個人資料”的“編輯頭像”中每頁顯示多少頭像?';
$upgrade_phrases['upgrade_300b3.php']['registered_user'] = '註冊用戶';
// should be the values that vbulletin-language.xml contains
$upgrade_phrases['upgrade_300b3.php']['master_language_title'] = '繁體中文';
$upgrade_phrases['upgrade_300b3.php']['master_language_langcode'] = 'zh-CN';
$upgrade_phrases['upgrade_300b3.php']['master_language_charset'] = 'UTF-8';
$upgrade_phrases['upgrade_300b3.php']['master_language_decimalsep'] = '.';
$upgrade_phrases['upgrade_300b3.php']['master_language_thousandsep'] = ',';
$upgrade_phrases['upgrade_300b3.php']['master_language_just_created'] = '正在建立繁體中文語言';
$upgrade_phrases['upgrade_300b3.php']['settinggroups'] = array(
		'打開或者關閉論壇' => 'onoff',
		'一般發文' => 'general',
		'聯繫細節' => 'contact',
		'發文允許的代碼 (vB代碼/HTML代碼/等)' => 'postingallow',
		'論壇首頁選項' => 'forumhome',
		'用戶與註冊選項' => 'user',
		'會員列表選項' => 'memberlist',
		'文章顯示選項' => 'showthread',
		'論壇顯示選項' => 'forumdisplay',
		'搜尋選項' => 'search',
		'Email選項' => 'email',
		'日期/時間選項' => 'datetime',
		'屏蔽選項' => 'editpost',
		'IP地址記錄選項' => 'ip',
		'灌水檢查選項' => 'floodcheck',
		'禁止選項' => 'banning',
		'悄悄話選項' => 'pm',
		'屏蔽選項' => 'censor',
		'HTTP頭與輸出' => 'http',
		'版本訊息' => 'version',
		'範本' => 'templates',
		'上傳限制選項' => 'loadlimit',
		'投票' => 'poll',
		'頭像' => 'avatar',
		'附件' => 'attachment',
		'用戶自訂頭銜' => 'usertitle',
		'上傳選項' => 'upload',
		'會員線上狀態' => 'online',
		'語言選項' => 'OLDlanguage',
		'拼寫檢查' => 'OLDspellcheck',
		'日曆' => 'OLDcalendar'
	);
$upgrade_phrases['upgrade_300b3.php']['vb2_default_style_title'] = '預設';
$upgrade_phrases['upgrade_300b3.php']['new_vb2_default_style_title'] = 'vBulletin 2 預設';
$upgrade_phrases['upgrade_300b3.php']['cron_birthday'] = '生日 Email 發送';
$upgrade_phrases['upgrade_300b3.php']['cron_thread_views'] = '主題人氣更新';
$upgrade_phrases['upgrade_300b3.php']['cron_user_promo'] = '用戶提升';
$upgrade_phrases['upgrade_300b3.php']['cron_daily_digest'] = '每日訂閱發送';
$upgrade_phrases['upgrade_300b3.php']['cron_weekly_digest'] = '每週訂閱發送';
$upgrade_phrases['upgrade_300b3.php']['cron_activation'] = '啟動提醒 Email 發送';
$upgrade_phrases['upgrade_300b3.php']['cron_subscriptions'] = '即時訂閱發送';
$upgrade_phrases['upgrade_300b3.php']['cron_hourly_cleanup'] = '每小時清理 #1';
$upgrade_phrases['upgrade_300b3.php']['cron_hourly_cleaup2'] = '每小時清理 #2';
$upgrade_phrases['upgrade_300b3.php']['cron_attachment_views'] = '附件人氣更新';
$upgrade_phrases['upgrade_300b3.php']['cron_unban_users'] = '恢復臨時封禁用戶';
$upgrade_phrases['upgrade_300b3.php']['cron_stats_log'] = '每日統計日誌';
$upgrade_phrases['upgrade_300b3.php']['reputation_-999999'] = '聲名狼藉';
$upgrade_phrases['upgrade_300b3.php']['reputation_-50'] = '只能期待他慢慢抹去身上的污點';
$upgrade_phrases['upgrade_300b3.php']['reputation_-10'] = '在過去有過一些不好的行為';
$upgrade_phrases['upgrade_300b3.php']['reputation_0'] = '普普通通';
$upgrade_phrases['upgrade_300b3.php']['reputation_10'] = '向著好的方向發展';
$upgrade_phrases['upgrade_300b3.php']['reputation_50'] = '是將要出名的人啊';
$upgrade_phrases['upgrade_300b3.php']['reputation_150'] = '身上有一圈迷人的光環哦';
$upgrade_phrases['upgrade_300b3.php']['reputation_250'] = '即將成功的新星';
$upgrade_phrases['upgrade_300b3.php']['reputation_350'] = '即將成功的新星';
$upgrade_phrases['upgrade_300b3.php']['reputation_450'] = '星途閃耀';
$upgrade_phrases['upgrade_300b3.php']['reputation_550'] = '已經是明星了';
$upgrade_phrases['upgrade_300b3.php']['reputation_650'] = '有著人盡皆知的貢獻和榮耀';
$upgrade_phrases['upgrade_300b3.php']['reputation_1000'] = '絕對是天王巨星';
$upgrade_phrases['upgrade_300b3.php']['reputation_1500'] = '有著超越歷史的輝煌成就';
$upgrade_phrases['upgrade_300b3.php']['reputation_2000'] = '有著超越歷史的輝煌成就';
$upgrade_phrases['upgrade_300b3.php']['upgrade_from_vb2_not_supported'] = '
	<p>由於資料結構的不相容，無法從 vBulletin 2 直接升級到 vBulletin versions 3.8.x 或更新版本。</p>
	<p>如果您目前運行著 vBulletin 2，想要升級到最新版本的 vBulletin，請先從客戶區下載 vBulletin 3.6。</p>
	<p>上傳您從壓縮包中解壓縮得到的檔案，並運行升級腳本直至完成。</p>
	<p>在升級完成後，從客戶區下載最新版本的 vBulletin，並上傳解壓縮的檔案，然後繼續運行升級腳本直至完成。</p>
';

#####################################
# upgrade_300b4.php phrases
#####################################

$upgrade_phrases['upgrade_300b4.php']['steps'] = array(
	1 => '修改資料庫結構',
	2 => '正在新增和刪除資料',
	3 => '更新附件類型緩存',
	4 => '成功升級到 vBulletin ' . VERSION . '！'
);
$upgrade_phrases['upgrade_300b4.php']['default_avatar_category'] = '正在插入預設頭像分類';
$upgrade_phrases['upgrade_300b4.php']['insert_into_whosonline'] = "正在插入目前線上蜘蛛緩存到 %1$sdatastore";
$upgrade_phrases['upgrade_300b4.php']['delete_redundant_cron'] = '正在刪除多餘的計劃任務';
$upgrade_phrases['upgrade_300b4.php']['attachment_cache_rebuilt'] = '附件緩存已重建';
$upgrade_phrases['upgrade_300b4.php']['generic_avatars'] = '標準頭像';

#####################################
# upgrade_300b5.php phrases
#####################################

$upgrade_phrases['upgrade_300b5.php']['steps'] = array(
	1 => '修改資料庫結構',
	2 => '修改主題/文章資料表',
	3 => '更改發文',
	4 => '成功升級到 vBulletin ' . VERSION . '！'
);
$upgrade_phrases['upgrade_300b5.php']['alter_post_title'] = '正在修改 " . TABLE_PREFIX ."post 資料表的 title 列為 VARCHAR(250)<br /><i>(這在較大的論壇中可能花去一些時間)';
$upgrade_phrases['upgrade_300b5.php']['alter_thread_title'] = '正在修改 " . TABLE_PREFIX ."thread 資料表的 title 列為 VARCHAR(250)<br /><i>(這在較大的論壇中可能花去一些時間)';
$upgrade_phrases['upgrade_300b5.php']['disabled_timeout_admin'] = '成功禁用“管理員登入超時”。';
$upgrade_phrases['upgrade_300b5.php']['timeout_admin_not_changed'] = '“管理員登入超時”發文沒有更改。';
$upgrade_phrases['upgrade_300b5.php']['change_setting_value'] = '更改發文值？';
$upgrade_phrases['upgrade_300b5.php']['proceed'] = ' 繼續 ';
$upgrade_phrases['upgrade_300b5.php']['setting_info'] = '<b>禁用“管理員登入超時”發文？</b> ' .
					'<dfn>“管理員登入超時”增加了安全性，但是可能導致登入管理面版出現困難。<br />' .
					'如果您登入管理面版時曾經出現過問題，或是需要穿過一個代理伺服器登入管理面版' .
					'(例如美國線上的代理伺服器)，您就需要禁用此發文。 (選擇“是”)。</dfn>';
$upgrade_phrases['upgrade_300b5.php']['no_change_needed'] = '正在判斷是否需要修改發文值… 無需修改。';

#####################################
# upgrade_300b6.php phrases
#####################################

$upgrade_phrases['upgrade_300b6.php']['steps'] = array(
	1 => '正在為主題資料表新增索引',
	2 => '修改資料庫結構',
	3 => '更改訂閱資料',
	4 => '正在重命名一些範本和表情符號以適應新的所見即所得編輯器',
	5 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300b6.php']['alter_thread_table'] = '正在修改 %1$sthread 資料表…<br /><i>(這在較大的論壇中可能花去一些時間)';
$upgrade_phrases['upgrade_300b6.php']['remove_avatar_cache'] = '正在刪除頭像緩存';
$upgrade_phrases['upgrade_300b6.php']['update_userban'] = '正在修改臨時封禁用戶自動解封計劃任務運行在每小時的第十五分鐘';
$upgrade_phrases['upgrade_300b6.php']['subscription_active'] = '正在啟動訂閱選項';
$upgrade_phrases['upgrade_300b6.php']['rename_old_template'] = '正在重命名 <i>%1$s</i> 範本為 <i>%2$s</i>';
$upgrade_phrases['upgrade_300b6.php']['delete_vbcode_color'] = '正在刪除 <i>vbcode_color_options</i> 範本 (顏色現在在 clientscript/vbulletin_editor.js 檔案中定義)';
$upgrade_phrases['upgrade_300b6.php']['smilie_fixes'] = "正在把表情符號的名稱修改得更加漂亮 (並修復“embarra<b>s</b>ment”打字錯誤！)";

#####################################
# upgrade_300b7.php phrases
#####################################

$upgrade_phrases['upgrade_300b7.php']['steps'] = array(
	1 => '雜項升級 #1',
	2 => '正在修改用戶資料表',
	3 => '正在導入關於 BB 代碼修改的注意事項',
	4 => '正在修改 BB 代碼系統',
	5 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300b7.php']['redundant_stylevars'] = "正在從 " . TABLE_PREFIX . "template 資料表刪除重覆的風格變數";
$upgrade_phrases['upgrade_300b7.php']['renaming_some_templates'] = '正在重命名一些範本';
$upgrade_phrases['upgrade_300b7.php']['ban_removal_fix'] = '正在修改臨時封禁用戶自動解封計劃任務運行在每小時的第十五分鐘 (修正上一個升級程式的錯誤)';
$upgrade_phrases['upgrade_300b7.php']['promotion_lastrun_fix'] = '正在重置上次用戶提升操作運行時間到9月8日以進入修復進程';
$upgrade_phrases['upgrade_300b7.php']['default_charset'] = '發文預設語言字元集為 <i>UTF-8</i>。';
$upgrade_phrases['upgrade_300b7.php']['comma_var_names'] = '處理短語變數名中的逗號';
$upgrade_phrases['upgrade_300b7.php']['delete_quote_email_bbcode'] = '正在刪除 [quote] 和 [email] BB 代碼標籤 - 它們在內核中定義';
$upgrade_phrases['upgrade_300b7.php']['bbcode_update'] = "<h3>重要注意事項…</h3>" .
	 "<p>下面的步驟是<b>刪除</b> <i>[quote]</i>，<i>[quote=username]</i>，<i>[email]</i>，和 <i>[email=address]</i> BB 代碼定義，因為它們現在是在 vBulletin 程式內部定義的，並且被一個範本控制。</p>" .
	 "<p>如果您曾經對這些代碼進行過自訂，我們建議您現在訪問<a href=\"../{$vbulletin->config[Misc][admincpdir]}/bbcode.php?$session[sessionurl]\" target=\"_blank\" title=\"在新視窗打開 BB 代碼管理器\">BB 代碼管理器</a>並對您自訂的 HTML 做記錄。</p>" .
	 "<p>當本升級程式完成後，您便可以自訂 <b>bbcode_quote</b> 範本以達到您以前自訂它們的效果。</p>" .
	 "<p>按“下一步”按鈕繼續升級程式。</p>";

#####################################
# upgrade_300g.php phrases
#####################################

$upgrade_phrases['upgrade_300g.php']['steps'] = array(
	1 => '雜項升級 #1',
	2 => '語言和短語改變',
	3 => '付費訂閱',
	4 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300g.php']['remove_duplicate_templates'] = '正在刪除風格內重覆的範本...';
$upgrade_phrases['upgrade_300g.php']['done'] = '完成!';
$upgrade_phrases['upgrade_300g.php']['rename_searchindex_postindex'] = "正在重命名 " . TABLE_PREFIX . "searchindex 資料表為 " . TABLE_PREFIX . "postindex";
$upgrade_phrases['upgrade_300g.php']['removing_redundant_index_phrase'] = "正在刪除 " . TABLE_PREFIX . "phrase 資料表中重覆的索引";
$upgrade_phrases['upgrade_300g.php']['holiday_to_phrasetype'] = "正在新增節假日到 " . TABLE_PREFIX . "phrasetype 資料表";
$upgrade_phrases['upgrade_300g.php']['moving_holiday_type'] = "正在移動存在的節假日到新的短語類型";
$upgrade_phrases['upgrade_300g.php']['adding_x_to_phrasetype'] = '正在新增 %1$s 到 ' . TABLE_PREFIX . 'phrasetype 資料表';
$upgrade_phrases['upgrade_300g.php']['update_invalid_birthdays'] = "正在更新無效的生日";
$upgrade_phrases['upgrade_300g.php']['step_already_run'] = '此步驟無需運行';
$upgrade_phrases['upgrade_300g.php']['updating_subscription_expiry_times'] = '更新訂閱過期時間完成';

#####################################
# upgrade_300rc1.php phrases
#####################################

$upgrade_phrases['upgrade_300rc1.php']['steps'] = array(
	1 => '雜項升級 #1',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300rc1.php']['alter_reputation_negative'] = "正在修改聲望提升允許負值";
$upgrade_phrases['upgrade_300rc1.php']['phrase_varname_case_sens'] = "使短語變數名大小寫敏感";
$upgrade_phrases['upgrade_300rc1.php']['add_faq_entry'] = '正在新增常見問題解答專案';

#####################################
# upgrade_300rc2.php phrases
#####################################

$upgrade_phrases['upgrade_300rc2.php']['steps'] = array(
	1 => '成功升級到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_300rc3.php phrases
#####################################

$upgrade_phrases['upgrade_300rc3.php']['steps'] = array(
	1 => '修復一些資料表錯誤',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300rc3.php']['click_here_auto_redirect'] = '如果沒有自動重導向，請按這裏。';
$upgrade_phrases['upgrade_300rc3.php']['not_latest_files'] = '您沒有上傳所有最新的檔案！<br /><br /><b>請上傳最新的版本的 adminfunctions_profilefield.php 到 includes 目錄，然後刷新此頁。</b>';
$upgrade_phrases['upgrade_300rc3.php']['fix_sortorder'] = "正在修正 " . TABLE_PREFIX . "search 資料表中的 sortorder 欄位";
$upgrade_phrases['upgrade_300rc3.php']['fix_logdateoverride'] = "正在修正 " . TABLE_PREFIX . "language 資料表中的 logdateoverride 欄位";
$upgrade_phrases['upgrade_300rc3.php']['fix_filesize_customavatar'] = "正在為 " . TABLE_PREFIX . "customavatar 資料表新增 filesize 欄位";
$upgrade_phrases['upgrade_300rc3.php']['fix_filesize_customprofile'] = "正在為 " . TABLE_PREFIX . "customprofilepic 資料表新增 filesize 欄位";
$upgrade_phrases['upgrade_300rc3.php']['populate_avatar_filesize'] = '正在計算頭像檔案大小';
$upgrade_phrases['upgrade_300rc3.php']['populate_profile_filesize'] = '正在計算資料圖片檔案大小';

#####################################
# upgrade_300rc4.php phrases
#####################################

$upgrade_phrases['upgrade_300rc4.php']['steps'] = array(
	1 => '修復一些資料表錯誤',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300rc4.php']['increase_storage_dateoverride'] = "正在為 " . TABLE_PREFIX . "language 資料表的 dateoverride 欄位增容";
$upgrade_phrases['upgrade_300rc4.php']['increase_storage_timeoverride'] = "正在為 " . TABLE_PREFIX . "language 資料表的 timeoverride 欄位增容";
$upgrade_phrases['upgrade_300rc4.php']['increase_storage_registereddateoverride'] = "正在為 " . TABLE_PREFIX . "language 資料表的 registereddateoverride 欄位增容";
$upgrade_phrases['upgrade_300rc4.php']['increase_storage_calformat1override'] = "正在為 " . TABLE_PREFIX . "language 資料表的 calformat1override 欄位增容";
$upgrade_phrases['upgrade_300rc4.php']['increase_storage_calformat2override'] = "正在為 " . TABLE_PREFIX . "language 資料表的 calformat2override 欄位增容";
$upgrade_phrases['upgrade_300rc4.php']['increase_storage_logdateoverride'] = "正在為 " . TABLE_PREFIX . "language 資料表的 logdateoverride 欄位增容";
$upgrade_phrases['upgrade_300rc4.php']['adding_calendar_mardi_gras'] = "正在修改資料表 " . TABLE_PREFIX . "calendar 以支援新的預定義節日: 懺悔星期二和聖體節。您需要在日曆管理器中啟用這些節日";

#####################################
# upgrade_300.php phrases
#####################################

$upgrade_phrases['upgrade_300.php']['steps'] = array(
	1 => '修復一些資料表錯誤',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_300.php']['make_reputation_signed'] = '正在修改聲望為有符號整型';
$upgrade_phrases['upgrade_300.php']['add_birthday_search'] = '正在新增生日搜尋欄位';
$upgrade_phrases['upgrade_300.php']['add_index_birthday_search'] = '正在新增生日搜尋欄位索引';
$upgrade_phrases['upgrade_300.php']['populate_birhtday_search'] = '正在生成生日搜尋欄位';

#####################################
# upgrade_301.php phrases
#####################################

$upgrade_phrases['upgrade_301.php']['steps'] = array(
	1 => '成功升級到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_302.php phrases
#####################################

$upgrade_phrases['upgrade_302.php']['steps'] = array(
	1 => '資料表結構修改 1/4',
	2 => '資料表結構修改 2/4',
	3 => '資料表結構修改 3/4',
	4 => '資料表結構修改 4/4',
	5 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_302.php']['drop_pmpermissions'] = '正在刪除多餘的欄位';
$upgrade_phrases['upgrade_302.php']['add_thumbnail_filesize'] = '正在為 attachment 資料表新增縮圖大小欄位';
$upgrade_phrases['upgrade_302.php']['change_profilefield'] = '正在增加自訂欄位的儲存空間';
$upgrade_phrases['upgrade_302.php']['update_genericpermissions'] = '正在新增權限';
$upgrade_phrases['upgrade_302.php']['alter_poll_table'] = '正在新增 lastvote 欄位到 ' . TABLE_PREFIX . 'poll 資料表';
$upgrade_phrases['upgrade_302.php']['alter_user_table'] = '正在新增長 Email 支援到 ' . TABLE_PREFIX . 'user 資料表';
$upgrade_phrases['upgrade_302.php']['add_rss_faq'] = '正在新增 RSS 條目到 ' . TABLE_PREFIX . 'faq 資料表';
$upgrade_phrases['upgrade_302.php']['add_notes'] = '正在新增 notes 欄位到 ' . TABLE_PREFIX . 'administrator 資料表';
$upgrade_phrases['upgrade_302.php']['add_cpsession_table'] = '正在新增 cpsession 資料表';
$upgrade_phrases['upgrade_302.php']['fix_blank_charset'] = '正在新增預設的字元集';

#####################################
# upgrade_303.php phrases
#####################################

$upgrade_phrases['upgrade_303.php']['steps'] = array(
	1 => '資料表結構修改 1/1',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_303.php']['note'] = '<p>如果您啟用了縮圖功能，並將附件存儲為檔案，並且在升級到 3.0.2 之後沒有重建縮圖，那麼請在升級完畢後請重建縮圖。，否則您的縮圖將不能正常工作。</p>';
$upgrade_phrases['upgrade_303.php']['rebuild_usergroupcache'] = '正在重建用戶群組緩存';

#####################################
# upgrade_303 - 309.php phrases
#####################################

$upgrade_phrases['upgrade_304.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_305.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_306.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];

$upgrade_phrases['upgrade_307.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];
$upgrade_phrases['upgrade_307.php']['update_calendarpermissions'] = '正在修改日曆權限';
$upgrade_phrases['upgrade_307.php']['import_birthdaydatecut_option'] = '正在導入舊生日日期選項';

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
	1 => '資料表結構修改 1/6',
	2 => '資料表結構修改 2/6',
	3 => '資料表結構修改 3/6',
	4 => '資料表結構修改 4/6',
	5 => '資料表結構修改 5/6',
	5 => '資料表結構修改 6/6',
	7 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_350b1.php']['update_forumpermissions'] = '正在修改版面權限';
$upgrade_phrases['upgrade_350b1.php']['support_multiple_products'] = '增加多產品的支援';
$upgrade_phrases['upgrade_350b1.php']['update_adminpermissions'] = '正在修改管理權限';
$upgrade_phrases['upgrade_350b1.php']['cron_event_reminder'] = '事件提醒';

#####################################
# upgrade_350b2.php phrases
#####################################

$upgrade_phrases['upgrade_350b2.php']['steps'] = array(
	1 => '資料表結構修改 1/1',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_350b3.php phrases
#####################################

$upgrade_phrases['upgrade_350b3.php']['steps'] = array(
	1 => '正在轉換多種發文',
	2 => '正在升級支付系統',
	3 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_350b3.php']['translating_allowvbcodebuttons'] = '正在轉換 $vbulletin->options[\'allowvbcodebuttons\'] 和 $vbulletin->options[\'quickreply\'] 到新的 $vbulletin->options[\'editormodes\'] 整合發文';
$upgrade_phrases['upgrade_350b3.php']['translating_quickreply'] = '正在轉換 $vbulletin->options[\'quickreply\'] 和 $vbulletin->options[\'quickreplyclick\'] 到新的 $vbulletin->options[\'quickreply\'] 整合發文';
$upgrade_phrases['upgrade_350b3.php']['converting_phrases_x_of_y'] = '正在轉換短語 (第 %1$d 步 共 %2$d 步)';
$upgrade_phrases['upgrade_350b3.php']['paymentapi_data'] = '正在插入預設支付閘道 API 資料';
$upgrade_phrases['upgrade_350b1.php']['note'] = '<p><h3>您即將儲存頭像到檔案系統。vB 3.5.0 現在有個選項還可以儲存用戶照片到檔案系統。在您升級完成後，進入管理面版並將所有頭像通過 <em>頭像->用戶照片儲存類型</em> 移動到資料庫中。在這一過程完成後，返回到相同的地方，將照片移動到檔案系統中。現在您的頭像和用戶照片都將儲存在檔案系統中。如果您沒有按照上述方式做，您的用戶照片將無法顯示。</h3></p>';

#####################################
# upgrade_350b4.php phrases
#####################################

$upgrade_phrases['upgrade_350b4.php']['steps'] = array(
	1 => '資料表結構修改 1/1',
	2 => '正在升級支付系統',
	3 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_350b4.php']['adding_payment_api_x_settings'] = '正在新增支付閘道 API %1$s 發文';
$upgrade_phrases['upgrade_350b4.php']['invert_moderate_permission'] = '正在反轉“總是驗證此用戶群組的文章”權限';

#####################################
# upgrade_350rc1.php phrases
#####################################

$upgrade_phrases['upgrade_350rc1.php']['steps'] = array(
	1 => '發文產品管理系統',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_350rc1.php']['control_panel_hook_support'] = '正在新增控制面版鉤子支援';

#####################################
# upgrade_350rc2.php phrases
#####################################

$upgrade_phrases['upgrade_350rc2.php']['steps'] = array(
	1 => '更新產品欄位',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_350rc3.php phrases
#####################################

$upgrade_phrases['upgrade_350rc3.php']['steps'] = array(
	1 => '資料表結構修改',
	2 => '主題資料表修改',
	3 => '文章資料表修改',
	4 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_350rc3.php']['please_wait_message'] = '下一步可能會花去一些時間，請耐心等待。';
$upgrade_phrases['upgrade_350rc3.php']['updating_payment_api_x_settings'] = '正在更新支付閘道 API %1$s 發文';

#####################################
# upgrade_350.php phrases
#####################################

$upgrade_phrases['upgrade_350.php']['steps'] = array(
	1 => '資料表結構修改',
	2 => '主題資料表修改',
	3 => '成功升級到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_351.php phrases
#####################################

$upgrade_phrases['upgrade_351.php']['steps'] = array(
	1 => '資料表結構修改',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_351.php']['delete_vb_product'] = '從產品表中刪除 vBulletin。';

#####################################
# upgrade_352.php phrases
#####################################

$upgrade_phrases['upgrade_352.php']['steps'] =& $upgrade_phrases['upgrade_351.php']['steps'];

$upgrade_phrases['upgrade_352.php']['adding_skype_field'] = '正在為 user 資料表新增 Skype 欄位';

#####################################
# upgrade_353.php phrases
#####################################

$upgrade_phrases['upgrade_353.php']['steps'] =& $upgrade_phrases['upgrade_351.php']['steps'];

$upgrade_phrases['upgrade_353.php']['remove_352_xss_plugin'] = '如果安裝，則從 3.5.2 移除 XSS 修正外掛程式';

#####################################
# upgrade_354.php phrases
#####################################

$upgrade_phrases['upgrade_354.php']['steps'] =& $upgrade_phrases['upgrade_351.php']['steps'];

$upgrade_phrases['upgrade_355.php']['steps'] =& $upgrade_phrases['upgrade_301.php']['steps'];

#####################################
# upgrade_360b1.php phrases
#####################################

$upgrade_phrases['upgrade_360b1.php']['steps'] = array(
	1 => '大資料表修改 (1/2)',
	2 => '大資料表修改 (2/2)',
	3 => '資料表結構修改',
	4 => '資料表結構修改',
	5 => '資料表結構修改',
	6 => '資料表結構修改',
	7 => '簽名權限',
	8 => '違規',
	9 => '付費訂閱更新',
	10 => '超級版主權限更新',
	11 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_360b1.php']['please_wait_message'] = '下一步可能需要一些時間，請耐心等待。如果頁面停止裝載，您可以刷新頁面。';

$upgrade_phrases['upgrade_360b1.php']['updating_cron'] = '正在更新計劃任務';
$upgrade_phrases['upgrade_360b1.php']['updating_subscriptions'] = '正在更新付費訂閱';
$upgrade_phrases['upgrade_360b1.php']['updating_holidays'] = '正在更新節日';
$upgrade_phrases['upgrade_360b1.php']['updating_profilefields'] = '正在更新自訂資料欄目';
$upgrade_phrases['upgrade_360b1.php']['updating_reputationlevels'] = '正在更新聲望級別';
$upgrade_phrases['upgrade_360b1.php']['invert_banned_flag'] = "正在反轉“該用戶群組是一個‘封禁’用戶群組”選項";
$upgrade_phrases['upgrade_360b1.php']['install_canignorequota_permission'] = "正在發文“可以忽略限額”權限";
$upgrade_phrases['upgrade_360b1.php']['infractionlevel1_title'] = '垃圾廣告';
$upgrade_phrases['upgrade_360b1.php']['infractionlevel2_title'] = '侮辱其他會員';
$upgrade_phrases['upgrade_360b1.php']['infractionlevel3_title'] = '簽名違反規則';
$upgrade_phrases['upgrade_360b1.php']['infractionlevel4_title'] = '不適當的語言';
$upgrade_phrases['upgrade_360b1.php']['rssposter_title'] = 'RSS 發文者';
$upgrade_phrases['upgrade_360b1.php']['infractions_title'] = '違規清理';
$upgrade_phrases['upgrade_360b1.php']['ccbill_title'] = 'CCBill 逆向檢查';

$upgrade_phrases['upgrade_360b1.php']['rename_post_parsed'] = "正在重命名 " . TABLE_PREFIX . "post_parsed 資料表為 " . TABLE_PREFIX . "postparsed";

$upgrade_phrases['upgrade_360b1.php']['updating_thread_redirects'] = '正在更新主題重導向';

$upgrade_phrases['upgrade_360b1.php']['super_moderator_x_updated'] = '超級版主“%1$s”已更新';

$upgrade_phrases['upgrade_360b1.php']['lastpostid_notice'] = '<strong>為了完成升級，主題訊息和版面訊息<em>必須</em>在管理面版的更新計數器部分重建。</strong>';

#####################################
# upgrade_360b2.php phrases
#####################################

$upgrade_phrases['upgrade_360b2.php']['steps'] = array(
	1 => '資料表結構修改',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

#####################################
# upgrade_360b3.php phrases
#####################################

$upgrade_phrases['upgrade_360b3.php']['steps'] = array(
	1 => '成功升級到 vBulletin ' . VERSION . '！'
);


$upgrade_phrases['upgrade_360b4.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_360rc1.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_360rc2.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_360rc3.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_360.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_361.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];

$upgrade_phrases['upgrade_361.php']['rename_podcasturl'] = "正在重命名 " . TABLE_PREFIX . "podcasturl 資料表為 " . TABLE_PREFIX . "podcastitem";

$upgrade_phrases['upgrade_362.php']['steps'] =& $upgrade_phrases['upgrade_360b3.php']['steps'];
$upgrade_phrases['upgrade_363.php']['steps'] =& $upgrade_phrases['upgrade_360b3.php']['steps'];

$upgrade_phrases['upgrade_364.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_365.php']['steps'] =& $upgrade_phrases['upgrade_360b3.php']['steps'];
$upgrade_phrases['upgrade_366.php']['steps'] =& $upgrade_phrases['upgrade_360b2.php']['steps'];
$upgrade_phrases['upgrade_367.php']['steps'] =& $upgrade_phrases['upgrade_360b3.php']['steps'];
$upgrade_phrases['upgrade_368.php']['steps'] =& $upgrade_phrases['upgrade_360b3.php']['steps'];

$upgrade_phrases['upgrade_370b2.php']['steps'] = array(
	1 => '資料表建立',
	2 => '大資料表結構修改',
	3 => '其它資料表結構修改',
	4 => '預設資料插入',
	5 => '用戶列表重建',
	6 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370b2.php']['build_userlist'] = '<p>正在為 %1$s 重建用戶列表</p>';
$upgrade_phrases['upgrade_370b2.php']['build_userlist_complete'] = '<p>用戶列表重建完成</p>';

$upgrade_phrases['upgrade_370b3.php']['steps'] = array(
	1 => '資料表結構修改',
	2 => '修改資料表預設值',
	3 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370b4.php']['steps'] = array(
	1 => '其它資料表結構修改',
	2 => '資料表資料更新',
	3 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370b5.php']['steps'] = array(
	1 => '其它資料表結構修改',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370b6.php']['steps'] = array(
	1 => '其它資料表結構修改',
	2 => '插入全新論壇幫助',
	3 => '是否刪除舊論壇幫助?',
	4 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370b6']['inserting_vb37_faq_structure'] = '正在插入 vBulletin 3.8.0 論壇幫助結構';
$upgrade_phrases['upgrade_370b6']['delete_selected_faq_items'] = '刪除選擇的論壇幫助專案';
$upgrade_phrases['upgrade_370b6']['delete_faq_description'] = '
	在上一步中，我們插入了全新的 vBulletin 論壇幫助到您的論壇。
	這意味著您的論壇現在同時包含了新的論壇幫助和舊的論壇幫助。<br />
	<br />
	下面列出了所有舊論壇幫助專案。
	如果您沒有修改過舊的論壇幫助，那麼保持全選它們並刪除。
	如果您自己新增過論壇幫助，或者修改過存在的專案，那麼您需要取消選擇那些您需要保留的專案。<br />
	<br />
	在您完成選擇後，按列表底部的<strong>' . $upgrade_phrases['upgrade_370b6']['delete_selected_faq_items'] . '</strong>按鈕繼續。
	如果沒有選擇任何條目，它們將都不會被刪除，升級程式會繼續下一步操作。
';
$upgrade_phrases['upgrade_370b6']['reset_selection'] = '重置選擇';
$upgrade_phrases['upgrade_370b6']['selected_faq_items_deleted'] = '您選擇的幫助專案已經被刪除。';

$upgrade_phrases['upgrade_370rc1.php']['steps'] = $upgrade_phrases['upgrade_370b5.php']['steps'];

$upgrade_phrases['upgrade_370rc2.php']['steps'] = array(
	1 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370rc3.php']['dropping_old_table_x'] = '正在刪除舊資料表 %1$s';
$upgrade_phrases['upgrade_370rc3.php']['steps'] = array(
	1 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370rc4.php']['steps'] = array(
	1 => '正在進行範本安全修正',
	2 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_370rc4.php']['token_added_x_templates'] = '正在新增必要的安全標記到 %1$s 個自訂範本';

$upgrade_phrases['upgrade_370.php']['steps'] = array(
	1 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_371.php']['steps'] = array(
	1 => '成功升級到 vBulletin ' . VERSION . '！'
);

$upgrade_phrases['upgrade_380a2.php']['steps'] = array(
    1 => '資料表建立',
    2 => '其它資料表修改',
    3 => '轉換社群討論組',
    4 => '權限更新',
    5 => '成功升級 vBulletin ' . VERSION . '!'
);

$upgrade_phrases['upgrade_380a2.php']['alter_index_on_x'] = '正在修改 %1$s 的索引';
$upgrade_phrases['upgrade_380a2.php']['create_index_on_x'] = '正在替 %1$s 建立索引';
$upgrade_phrases['upgrade_380a2.php']['creating_default_group_category'] = '正在建立預設的社群討論組分類';
$upgrade_phrases['upgrade_380a2.php']['fulltext_index_on_x'] = '正在為 %1$s 建立全文索引';
$upgrade_phrases['upgrade_380a2.php']['convert_messages_to_discussion'] = '轉換社群討論組訊息到討論內';
$upgrade_phrases['upgrade_380a2.php']['set_discussion_titles'] = '初始化討論組標題';
$upgrade_phrases['upgrade_380a2.php']['update_last_post'] = '重建討論組的最新資訊';
$upgrade_phrases['upgrade_380a2.php']['update_discussion_counters'] = '更新討論組統計';
$upgrade_phrases['upgrade_380a2.php']['update_group_message_counters'] = '更新社群討論組訊息統計';
$upgrade_phrases['upgrade_380a2.php']['update_group_discussion_counters'] = '更新社群討論組統計';
$upgrade_phrases['upgrade_380a2.php']['uncategorized'] = '無分類';
$upgrade_phrases['upgrade_380a2.php']['uncategorized_description'] = '未分類的社群討論組';
$upgrade_phrases['upgrade_380a2.php']['move_groups_to_default_category'] = '正在移動未分類的社群討論組到「未分類」的分類';
$upgrade_phrases['upgrade_380a2.php']['updating_profile_categories'] = '正在為個人資料欄位增加隱私設定';
$upgrade_phrases['upgrade_380a2.php']['update_hv_options'] = '正在更新真人驗証選項';
$upgrade_phrases['upgrade_380a2.php']['update_album_update_counters'] = '正在更新相簿統計';
$upgrade_phrases['upgrade_380a2.php']['granting_permissions'] = '正在為新功能給與權限';

$upgrade_phrases['upgrade_380b1.php']['steps'] = array(
    1 => '成功升級 vBulletin ' . VERSION . '!'
);

$upgrade_phrases['upgrade_380b2.php']['steps'] = array(
	1 => '其它資料表修改',
	2 => '成功升級 vBulletin ' . VERSION . '!'
);

$upgrade_phrases['upgrade_380b3.php']['steps'] = array(
	1 => '其它資料表修改',
	2 => '成功升級 vBulletin ' . VERSION . '!'
);

$upgrade_phrases['upgrade_380b4.php']['steps'] = array(
	1 => '成功升級 vBulletin ' . VERSION . '!'
);

$upgrade_phrases['upgrade_380rc1.php']['rebuild_event_cache'] = '正在重建事件緩存';

$upgrade_phrases['upgrade_380rc1.php']['steps'] = array(
	1 => '緩存重建',
	2 => '成功升級 vBulletin ' . VERSION . '!'
);

$upgrade_phrases['upgrade_380rc2.php']['updating_mail_ssl_setting'] = '更新 SSL 郵件設置';
$upgrade_phrases['upgrade_380rc2.php']['steps'] = array(
	1 => '設置更新',
	2 => '成功升級 vBulletin ' . VERSION . '!'
);

$upgrade_phrases['upgrade_380.php']['steps'] = array(
	1 => '成功升級 vBulletin ' . VERSION . '!'
);

$upgrade_phrases['upgrade_381.php']['steps'] = array(
	1 => '其它資料表修改',
	2 => '成功升級 vBulletin ' . VERSION . '!'
);

$upgrade_phrases['upgrade_382.php']['steps'] = array(
	1 => '其它資料表修改',
	2 => '成功升級 vBulletin ' . VERSION . '!'
);

$upgrade_phrases['upgrade_383.php']['steps'] = array(
	1 => '成功升級 vBulletin ' . VERSION . '!'
);

$upgrade_phrases['upgrade_384.php']['steps'] = array(
	1 => '其它資料表修改',
	2 => '成功升級 vBulletin ' . VERSION . '!'
);

#####################################
# finalupgrade.php phrases
#####################################

$upgrade_phrases['finalupgrade.php']['steps'] = array(
	1 => '導入最新的選項',
	2 => '導入最新的管理員幫助',
	3 => '導入最新的語言',
	4 => '導入最新的風格',
	5 => '本步驟探測 word 表是否已經修改為正確的欄位',
	6 => '全部完成',
);

$upgrade_phrases['finalupgrade.php']['upgrade_start_message'] = "<p>本程式將升級您的範本、發文、語言和管理幫助到最新版本。</p>\n<p>按“下一步”按鈕繼續。";
$upgrade_phrases['finalupgrade.php']['upgrade_version_mismatch'] = '<p>您目前運行的 vBulletin (%1$s) 好像不是下載的版本 (%2$s)。</p>
		<p>這通常意味著您的升級沒有成功。請確保您上傳了所有最新的檔案，然後<a href="upgrade.php">按這裏</a>重試。</p>
		<p>如果您確認要繼續本部分的升級工作，<a href="finalupgrade.php?step=1">請按這裏</a>。</p>';

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 31742 $
|| ####################################################################
\*======================================================================*/
?>