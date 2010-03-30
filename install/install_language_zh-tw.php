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
	'languagecode' => 'zh_TW',
	'charset' => 'UTF-8'
);

$authenticate_phrases['install_title'] = '中文裝載程式';
$authenticate_phrases['new_installation'] = '全新裝載';
$authenticate_phrases['enter_system'] = '進入裝載系統';
$authenticate_phrases['enter_cust_num'] = '請匯入您的用戶號';
$authenticate_phrases['customer_number'] = '用戶號';
$authenticate_phrases['cust_num_explanation'] = '這是您登入 vBulletin 用戶區使用的用戶號';
$authenticate_phrases['cust_num_success'] = '用戶號驗證成功。';
$authenticate_phrases['redirecting'] = '正在重定導...';

$phrasetype['global'] = '整體 (GLOBAL)';
$phrasetype['cpglobal'] = '控制面板(整體) (Control Panel Global)';
$phrasetype['cppermission'] = '權限 (Permissions)';
$phrasetype['forum'] = '討論區相關 (Forum-Related)';
$phrasetype['calendar'] = '行事曆 (Calendar)';
$phrasetype['attachment_image'] = '附加檔案/影像 (Attachment/Image)';
$phrasetype['style'] = '風格工具 (Style Tools)';
$phrasetype['logging'] = '日誌工具 (Logging Tools)';
$phrasetype['cphome'] = '控制面板首頁 (Control Panel Home Pages)';
$phrasetype['promotion'] = '提升工具 (Promotion Tools)';
$phrasetype['user'] = '會員工具(整體) (User Tools (global))';
$phrasetype['help_faq'] = '論壇幫助管理 (FAQ / Help Management)';
$phrasetype['sql'] = 'SQL 工具 (SQL Tools)';
$phrasetype['subscription'] = '訂閲工具 (Subscription Tools)';
$phrasetype['language'] = '語系工具 (Language Tools)';
$phrasetype['bbcode'] = 'BB 代碼工具 (BB Code Tools)';
$phrasetype['stats'] = '統計工具 (Statistics Tools)';
$phrasetype['diagnostics'] = '診斷工具 (Diagnostic Tools)';
$phrasetype['maintenance'] = '維護工具 (Maintenance Tools)';
$phrasetype['profile'] = '會員資料項目工具 (Profile Field Tools)';
$phrasetype['cprofilefield'] = '自定訂用户資料欄目 (Custom Profile Fields)';
$phrasetype['thread'] = '主題工具 (Thread Tools)';
$phrasetype['timezone'] = '時區 (Timezones)';
$phrasetype['banning'] = '停權工具 (Banning Tools)';
$phrasetype['reputation'] = '聲望 (Reputation)';
$phrasetype['wol'] = '線上訊息 (Who\\\'s Online)';
$phrasetype['threadmanage'] = '主題管理 (Thread Management)';
$phrasetype['pm'] = '私人訊息 (Private Messaging)';
$phrasetype['cpuser'] = '控制面板會員管理 (Control Panel User Management)';
$phrasetype['register'] = '註冊 (Register)';
$phrasetype['accessmask'] = '存取權限 (Access Masks)';
$phrasetype['cron'] = '計劃任務 (Scheduled Tasks)';
$phrasetype['moderator'] = '版主 (Moderators)';
$phrasetype['cpoption'] = '控制面板選項 (Control Panel Options)';
$phrasetype['cprank'] = '控制面板會員等級 (Control Panel User Ranks)';
$phrasetype['cpusergroup'] = '控制面板會員群組 (Control Panel User Groups)';
$phrasetype['holiday'] = '節假日 (Holidays)';
$phrasetype['posting'] = '發文 (Posting)';
$phrasetype['poll'] = '投票 (Polls)';
$phrasetype['fronthelp'] = '前台論壇說明 (Frontend FAQ/Help)';
$phrasetype['search'] = '搜尋 (Searching)';
$phrasetype['showthread'] = '顯示主題 (Show Thread)';
$phrasetype['postbit'] = '文章區塊 (Postbit)';
$phrasetype['forumdisplay'] = '討論區顯示 (Forum Display)';
$phrasetype['messaging'] = '即時訊息 (Messaging)';
$phrasetype['inlinemod'] = '快速管理 (Inline Moderation)';
$phrasetype['plugins'] = '插件系統 (Plugin System)';
$phrasetype['front_end_error'] = '錯誤訊息 (Error Messages)';
$phrasetype['front_end_redirect'] = '前台轉址訊息 (Front-End Redirect Messages)';
$phrasetype['email_body'] = '郵件內容文字 (Email Body Text)';
$phrasetype['email_subj'] = '郵件主題文字 (Email Subject Text)';
$phrasetype['vbulletin_settings'] = '論壇設定 (vBulletin Settings)';
$phrasetype['cp_help'] = '控制面板說明内容 (Control Panel Help Text)';
$phrasetype['faq_title'] = '論壇說明標題 (FAQ Title)';
$phrasetype['faq_text'] = '論壇說明內容 (FAQ Text)';
$phrasetype['stop_message'] = '控制面板停止訊息 (Control Panel Stop Message)';
$phrasetype['reputationlevel'] = '聲望級彆 (Reputation Levels)';
$phrasetype['infraction'] = '會員警告 (User Infractions)';
$phrasetype['infractionlevel'] = '會員警告級彆 (User Infraction Levels)';
$phrasetype['notice'] = '通知 (Notices)';
$phrasetype['prefix'] = '主題前綴 (Thread Prefixes)';
$phrasetype['prefixadmin'] = '主題前綴 (管理) (Thread Prefixes (Admin))';
$phrasetype['album'] = '相冊 (Albums)';
$phrasetype['hvquestion'] = '真人驗證問題 (Human Verification Questions)';
$phrasetype['socialgroups'] = '社會興趣討論群組 (Social Groups)';

#####################################
# custom phrases
#####################################

$customphrases['cprofilefield']['field1_title'] = '個人說明';
$customphrases['cprofilefield']['field1_desc']  = '您的個人說明';
$customphrases['cprofilefield']['field2_title'] = '住址';
$customphrases['cprofilefield']['field2_desc']  = '您的居住地';
$customphrases['cprofilefield']['field3_title'] = '興趣';
$customphrases['cprofilefield']['field3_desc']  = '您的愛好, 等等';
$customphrases['cprofilefield']['field4_title'] = '職業';
$customphrases['cprofilefield']['field4_desc']  = '您的工作';

$customphrases['reputationlevel']['reputation1']  = '現在聲名狼藉';
$customphrases['reputationlevel']['reputation2']  = '只能期待他慢慢抹去身上的污點';
$customphrases['reputationlevel']['reputation3']  = '在過去有過一些不好的行為';
$customphrases['reputationlevel']['reputation4']  = '是普普通通的會員';
$customphrases['reputationlevel']['reputation5']  = '正向着好的方向發展';
$customphrases['reputationlevel']['reputation6']  = '是一個將要出名的人';
$customphrases['reputationlevel']['reputation7']  = '身上有一圈迷人的光環哦';
$customphrases['reputationlevel']['reputation8']  = '即將成為的新星';
$customphrases['reputationlevel']['reputation9']  = '是一位成功的新星';
$customphrases['reputationlevel']['reputation10'] = '的星途閃耀';
$customphrases['reputationlevel']['reputation11'] = '已經是超級明星了';
$customphrases['reputationlevel']['reputation12'] = '有着人盡皆知的貢獻和榮耀';
$customphrases['reputationlevel']['reputation13'] = '已經是前無古人後無來者';
$customphrases['reputationlevel']['reputation14'] = '有着超越歷史的輝煌成就';
$customphrases['reputationlevel']['reputation15'] = '絶對是天王巨星';

$customphrases['infractionlevel']['infractionlevel1_title'] = '垃圾廣告';
$customphrases['infractionlevel']['infractionlevel2_title'] = '侮辱其他會員';
$customphrases['infractionlevel']['infractionlevel3_title'] = '簽名違反規則';
$customphrases['infractionlevel']['infractionlevel4_title'] = '不適當的語言';

#####################################
# phrases for import systems
#####################################
$vbphrase['importing_language'] = '正在導入語言';
$vbphrase['importing_style'] = '正在導入風格';
$vbphrase['importing_admin_help'] = '正在導入管理員輔助說明';
$vbphrase['importing_settings'] = '正在導入設定選項';
$vbphrase['please_wait'] = '請稍候';
$vbphrase['language'] = '語言';
$vbphrase['master_language'] = '主語言';
$vbphrase['admin_help'] = '管理員輔助說明';
$vbphrase['style'] = '風格';
$vbphrase['styles'] = '風格';
$vbphrase['settings'] = '設定';
$vbphrase['master_style'] = '主風格';
$vbphrase['templates'] = '樣板';
$vbphrase['css'] = 'CSS';
$vbphrase['stylevars'] = '風格變數';
$vbphrase['replacement_variables'] = '替代變數';
$vbphrase['controls'] = '控制';
$vbphrase['rebuild_style_information'] = '重建風格資訊';
$vbphrase['updating_style_information_for_each_style'] = '正在更新每個風格資訊';
$vbphrase['updating_styles_with_no_parents'] = '正在更新無父風格的風格集';
$vbphrase['updated_x_styles'] = '已更新 %1$s 個風格';
$vbphrase['no_styles_needed_updating'] = '没有風格需要更新';
$vbphrase['yes'] = '是';
$vbphrase['no'] = '否';

#####################################
# global upgrade phrases
#####################################
$vbphrase['refresh'] = '清除';
$vbphrase['vbulletin_message'] = 'vBulletin 資訊';
$vbphrase['create_table'] = '正在建立 %1$s 資料表';
$vbphrase['remove_table'] = '正在移除 %1$s 資料表';
$vbphrase['alter_table'] = '正在修改 %1$s 資料表';
$vbphrase['update_table'] = '正在更新 %1$s 資料表';
$vbphrase['upgrade_start_message'] = "<p>此程式將把您的 vBulletin 升級到版本 <b>" . VERSION . "</b>。</p>\n<p>點撃“下一步”按鈕繼續。</p>";
$vbphrase['upgrade_wrong_version'] = "<p>您的 vBulletin 版本不符合此程式的執行條件 (需要在版本 <b>" . PREV_VERSION . "</b> 的基礎上執行)。</p>\n<p>請確認您執行的程式檔是否正確。</p>\n<p>如果您確信正確，<a href=\"" . THIS_SCRIPT . "?step=1\">請點撃這裡繼續執行</a>。</p>";
$vbphrase['file_not_found'] = '啊哦, ./install/%1$s 好像不存在！';
$vbphrase['importing_file'] = '正在導入 %1$s';
$vbphrase['ok'] = '完成';
$vbphrase['query_took'] = '執行查詢花去 %1$s 秒。';
$vbphrase['done'] = '完成';
$vbphrase['proceed'] = '繼續';
$vbphrase['reset'] = '重置';
$vbphrase['vbulletin_copyright'] = 'vBulletin v' . VERSION . ', 版權所有 &copy;2000 - [#]year[#], Jelsoft Enterprises Ltd.';
$vbphrase['vbulletin_copyright_orig'] = $vbphrase['vbulletin_copyright'];
$vbphrase['xml_error_x_at_line_y'] = 'XML 錯誤: %1$s 在第 %2$s 行';
$vbphrase['default_data_type'] = '正在插入預設資料到 %1$s';
$vbphrase['processing_complete_proceed'] = '處理完成 - 繼續';
#####################################
# upgradecore phrases
#####################################

$installcore_phrases['php_version_too_old'] = 'vBulletin ' . VERSION . ' 需要 PHP 版本在 4.3.3 以上。您目前的 PHP 版本是 ' . PHP_VERSION . '。請聯繫主機商升級。';
$installcore_phrases['mysql_version_too_old'] = 'vBulletin ' . VERSION . ' 需要 MySQL 版本在 4.0.16 以上。您目前的 MySQL 版本是 %1$s。請聯繫主機商升級。';
$installcore_phrases['need_xml'] = 'vBulletin ' . VERSION . ' 需要 PHP 支援 XML 函數。請聯繫主機商啓用這些函數。';
$installcore_phrases['need_mysql'] = 'vBulletin ' . VERSION . ' 需要 PHP 支援 MySQL 函數。請聯繫主機商啓用這些函數。';
$installcore_phrases['need_config_file'] = '請確認您已經修改了 config.php.new 的設定值并將其重命名為 config.php.';
$installcore_phrases['step_x_of_y'] = ' (第 %1$d 步，共 %2$d 步)';
$installcore_phrases['vb3_install_script'] = 'vBulletin ' . VERSION . ' 中文版裝載程式';
$installcore_phrases['may_take_some_time'] = '(有些步驟需要一定的時間，請耐心等待)';
$installcore_phrases['step_title'] = '第 %1$d 步) %2$s';
$installcore_phrases['batch_complete'] = '批處理完成！如果您没有被自動重定導，請點撃右邊的按鈕。';
$installcore_phrases['next_batch'] = ' 下一批';
$installcore_phrases['next_step'] = '下一步 (%1$d/%2$d)';
$installcore_phrases['click_button_to_proceed'] = '點撃右邊的按鈕繼續。';
$installcore_phrases['page_x_of_y'] = '第 %1$d 頁，共 %2$d 頁';
$installcore_phrases['eaccelerator_too_old'] = 'eAccelerator for PHP 必須升級到 0.9.3 或更高版本。請瀏覧<a href="http://www.vbulletin.com/forum/showthread.p' . 'hp?p=979044#post979044">這個帖子</a>以了解更多資訊。';
$upgradecore_phrases['apc_too_old'] = '您的伺服器正在執行 <a href="http://pecl.p' . 'hp.net/package/APC/">Alternative PHP Cache</a> (APC) 的一個版本，而這個版本不相容 vBulletin。請升級到 APC 3.0.0 或更高版本。';
$installcore_phrases['mmcache_not_supported'] = 'Turck MMCache 已經被 eAcclerator 取代，無法正確支援 vBulletin。請瀏覧<a href="http://www.vbulletin.com/forum/showthread.p' . 'hp?p=979044#post979044">這個帖子</a>以了解更多資訊。';
$installcore_phrases['dbname_is_mysql'] = '在 <em>includes/config.php</em> 中的 <code>$config[\'Database\'][\'dbname\']</code> 指定的資料庫名不能為 <strong>mysql</strong>，因為這是一個保留的資料庫名。<br />執行被終止以避免可能發生的損害。';

#####################################
# install.php phrases
#####################################
$install_phrases['steps'] = array(
	1  => '確認配置',
	2  => '連線到資料程式庫',
	3  => '建立資料表',
	4  => '修改資料表',
	5  => '正在插入預設資料',
	6  => '正在導入語言',
	7  => '正在導入風格資訊',
	8  => '正在導入管理員輔助說明',
	9  => '抓取預設設定',
	10 => '導入預設設定',
	11 => '抓取用户資料',
	12 => '設定預設資料',
	13 => '裝載完成'
);
$install_phrases['welcome'] = '<p style="font-size:10pt"><b>歡迎使用 vBulletin 3.8 中文版</b></p>
	<p>您即將開始裝載本程式。</p>
	<p>點撃 <b>[下一步]</b> 按鈕將開始裝載程式。</p>
	<p>為了避免裝載時瀏覧器崩潰，我們强烈建議您關閉瀏覧器上的第三方工具軸，例如 <b>Google、MSN、Alexa</b> 工具軸等。</p>';
$install_phrases['turck'] = '<p>您的伺服器裝載了 <strong>Turck MMCache</strong>。<strong>Turck MMCache</strong> 不支援新版本的 PHP，可能會導致 vBulletin 出現問題。我們建議您將其禁用，或升級到 eAccelerator 的新版本。</p>';
$install_phrases['cant_find_config'] = '我們無法定位“includes/config.php”檔案，請確認此檔案存在。';
$install_phrases['cant_read_config'] = '我們無法讀取“includes/config.php”檔案，請確保此檔案可讀。';
$install_phrases['config_exists'] = '配置檔案存在并可讀。';
$install_phrases['attach_to_db'] = '正在嘗試連線到資料程式庫';
$install_phrases['no_db_found_will_create'] = '没有找到資料程式庫，正在嘗試建立。';
$install_phrases['attempt_to_connect_again'] = '正在嘗試重新連線。';
$install_phrases['database_functions_not_detected'] = '選取的資料程式庫類別 \'%1$s\' 并没有編譯在您的 PHP 中。';
$install_phrases['unable_to_create_db'] = '無法建立資料程式庫。請確認在“inculdes/config.php”中定義的資料程式庫名存在，或者要求您的主機提供商幫您建立一個資料程式庫。';
$install_phrases['database_creation_successful'] = '資料程式庫成功建立！';
$install_phrases['connect_failed'] = '連線失敗: 資料程式庫不規則錯誤。';
$install_phrases['db_error_num'] = '錯誤號: %1$s';
$install_phrases['db_error_desc'] = '錯誤說明: %1$s';
$install_phrases['check_dbserver'] = '請確保資料程式庫和伺服器正確配置并重試。';
$install_phrases['connection_succeeded'] = '連線成功！資料程式庫已經存在。';
$install_phrases['vb_installed_maybe_upgrade'] = '您已經裝載了 vBulletin。您是否想<a href="upgrade.php">升級</a>？';
$install_phrases['wish_to_empty_db'] = '您想<b><a href="install.php?step=3&emptydb=true">清空</a></b>資料程式庫以進行全新裝載嗎？';
$install_phrases['no_connect_permission'] = '資料程式庫連線失敗，因為您没有足够的許可權。請檢查在“includes/config.php”匯入的資料程式庫用户名密碼是否正確。';
$install_phrases['empty_db'] = '<p align="center"><font color="Red">危險，老兄! 危險啊!<br /><h1 align="center">清空資料程式庫?</h1></font></p>
<p align="center">點撃“是”，您的整個資料程式庫將被清空。</p>
<p align="center">如果您的資料程式庫中存在除了 vBulletin 以外的其他資料，<b>不要</b>選取“是”，<br />否則這些資料將<br><b>不可挽回的被移除</b>。</p>
<p align="center">這是您最後一次機會阻止您的資料被移除！</p>
<p align="center"><a href="install.php?step=3&emptydb=true&confirm=true">[ <b>是</b>，清空該資料程式庫的<b>所有</b>資料 ]</a></p>
<p align="center"><a href="install.php?step=2">[ <b>否</b>，不要清空該資料程式庫 ]</a></p>
<p align="center" class="smallfont">vBulletin、Jelsoft Enterprises Ltd. 及 vBulletin 中文不承擔任何<br />由于進行此運算元據丢失而帶來的損失。</p>';
$install_phrases['reset_database'] = '重置資料庫';
$install_phrases['delete_tables_instructions'] = '<p>下面列表出您的資料庫中所有的資料表。被辨認為屬於 vBulletin 的資料表已經自動為您選取了。可能有一些另外列出的資料表無法自動辨認。</p>
<p style="font-size:12pt">在點選<em>刪除選擇的資料表</em>按鈕後，所有選擇的資料表和他們的資料將會<strong>永久不可逆回的刪除</strong>。</p>
<p><a href="install.php?step=2">如果您不想刪除任何資料表並且繼續安裝，請點這裡。</a></p>
<p>vBulletin 和 Jelsoft Enterprises Ltd. 不承擔任何由於經行此操作而造成的損失。</p>';
$install_phrases['select_deselect_all_tables'] = '選擇/取消所有的資料表';
$install_phrases['delete_selected_tables'] = '刪除選項中的資料表';
$install_phrases['mysql_strict_mode'] = 'MySQL 正執行在 Strict 型態。您可以繼續，但是 vBulletin 的某些功能會不正常。<strong>强烈建議</strong>您在 includes/config.php 檔案中將 <code>$config[\'Database\'][\'force_sql_mode\']</code> 設定為 <code>true</code>!';
$install_phrases['resetting_db'] = '正在清空資料程式庫...';
$install_phrases['succeeded'] = '成功';
$install_phrases['script_reported_errors'] = '裝載程式在建立資料表的時候出現錯誤。僅當您覺得此錯誤不嚴重的情况下才可以繼續裝載。';
$install_phrases['errors_were'] = '錯誤是:';
$install_phrases['tables_setup'] = '資料表成功建立。';
$install_phrases['general_settings'] = '常規設定';
$install_phrases['bbtitle'] = '<b>論壇標題</b> <dfn>論壇的標題，察看在論壇的每一頁。</dfn>';
$install_phrases['hometitle'] = '<b>首頁標題</b> <dfn>您的首頁名稱，察看在論壇每一頁底部。例如，<em>http://www.example.com/forums</em></dfn>';
$install_phrases['bburl'] = '<b>論壇網址</b> <dfn>論壇的網址 (不含括最後的“/”)。</dfn>';
$install_phrases['homeurl'] = '<b>首頁網址</b> <dfn>您首頁的網址，察看在論壇每一頁底部。</dfn>';
$install_phrases['webmasteremail'] = '<b>網站管理員電子郵件位址</b> <dfn>網站管理員的電子郵件位址。</dfn>';
$install_phrases['cookiepath'] = '<b>Cookie 儲存路徑</b> <dfn>Cookie 儲存的路徑。如果您在同一個域名下執行了多個論壇，便需要將它設定為每個論壇所在的目録名。否則，填寫 / 便可以了。<br /><br />Cookie 路徑建議的有效值已在旁邊的下拉框中列出。如果您認為還有更加合適的不同的設定，選中核取框并在下面的匯入框中匯入合適的值。<br /><br />請注意路徑<b>總是</b>應當以正斜杠結尾，例如 \'/forums/\'、\'/vbulletin/\' 等。<br /><br /><span class="modlasttendays">匯入錯誤的路徑，會導致您無法登入論壇。</span></dfn>';
$install_phrases['cookiedomain'] = '<b>Cookie 范圍名</b> <dfn>Cookie 所影響的域名。修改此選項預設值最常見的原因是，您的論壇有兩個不同的網址，例如 example.com 和 forums.example.com。要使用户在以兩個不同的域名存取論壇時，都能保持登入狀態，您需要將此選項設定為 <b>.example.com</b> (注意域名需要以<b>點</b>開頭)。<br /><br />Cookie 域名建議的有效值已在旁邊的下拉框中列出。如果您認為還有更加合適的不同的設定，選中核取框并在下面的匯入框中匯入合適的值。<br /><br /><span class="modlasttendays">若您没有把握，最好在這裡什麽也不填寫，因為錯誤的設定會導致您無法登入論壇。</span></dfn>';
$install_phrases['suggested_settings'] = '建議的設定';
$install_phrases['custom_setting'] = '自定訂設定';
$install_phrases['use_custom_setting'] = '使用自定訂設定 (在下面指定)';
$install_phrases['blank'] = '(空)';
$install_phrases['fill_in_for_admin_account'] = '請填寫下面的表單，把自己設定成管理員';
$install_phrases['username'] = '用户名';
$install_phrases['password'] = '密碼';
$install_phrases['confirm_password'] = '確認密碼';
$install_phrases['email_address'] = '電子郵件';
$install_phrases['complete_all_data'] = '您没有填寫全部資料。<br /><br />請點撃“下一步”按鈕傳回重填。';
$install_phrases['password_not_match'] = '“密碼”和“確認密碼”兩處填寫的密碼不一致！<br /><br />請點撃“下一步”按鈕傳回并修正。';
$install_phrases['admin_added'] = '管理員已添加';
$install_phrases['install_complete'] = '<p>您已經成功的裝載了 vBulletin 3。<br />
	<br />
	<font size="+1"><b>您執行此論壇前還必須移除如下檔案:</b><br />
	install/install.php</font><br />
	<br />
	當您移除它後，您可以進入您的控制面板。
	<br />
	進入控制面板可以<b><a href="../%1$s/index.php">點撃這裡</a>。</b>';

$install_phrases['alter_table_type_x'] = '正在改變資料表 ' . TABLE_PREFIX . '%1$s 為 %2$s 類別';
$install_phrases['default_calendar'] = '預設行事曆';
$install_phrases['category_title'] = '主分類';
$install_phrases['category_desc'] = '主分類說明';
$install_phrases['forum_title'] = '主版面';
$install_phrases['forum_desc'] = '主版面說明';
$install_phrases['posticon_1'] = '帖子';
$install_phrases['posticon_2'] = '箭號';
$install_phrases['posticon_3'] = '燈泡';
$install_phrases['posticon_4'] = '警告';
$install_phrases['posticon_5'] = '問題';
$install_phrases['posticon_6'] = '酷';
$install_phrases['posticon_7'] = '微笑';
$install_phrases['posticon_8'] = '生氣';
$install_phrases['posticon_9'] = '難過';
$install_phrases['posticon_10'] = '呲牙';
$install_phrases['posticon_11'] = '尷尬';
$install_phrases['posticon_12'] = '眨眼';
$install_phrases['posticon_13'] = '很差';
$install_phrases['posticon_14'] = '不錯';
$install_phrases['generic_avatars'] = '標准頭像';
$install_phrases['generic_smilies'] = '標准表情圖像';
$install_phrases['generic_icons'] = '標准資訊圖像';
// should be the values that vbulletin-language.xml contains
$install_phrases['master_language_title'] = '簡體中文';
$install_phrases['master_language_langcode'] = 'zh-CN';
$install_phrases['master_language_charset'] = 'UTF-8';
$install_phrases['master_language_decimalsep'] = '.';
$install_phrases['master_language_thousandsep'] = ',';
$install_phrases['default_style'] = '預設風格';
$install_phrases['smilie_smile'] = '微笑';
$install_phrases['smilie_embarrass'] = '困窘';
$install_phrases['smilie_grin'] = '尷尬';
$install_phrases['smilie_wink'] = '眨眼';
$install_phrases['smilie_tongue'] = '吐舌';
$install_phrases['smilie_cool'] = '酷';
$install_phrases['smilie_roll'] = '諷刺';
$install_phrases['smilie_mad'] = '瘋狂';
$install_phrases['smilie_eek'] = '驚訝';
$install_phrases['smilie_confused'] = '困惑';
$install_phrases['smilie_frown'] = '難過';
$install_phrases['socialgroups_uncategorized'] = '未分類';
$install_phrases['socialgroups_uncategorized_description'] = '未分類的討論群組';
$install_phrases['usergroup_guest_title'] = '游客/未登入用户';
$install_phrases['usergroup_guest_usertitle'] = '游客';
$install_phrases['usergroup_registered_title'] = '註冊會員';
$install_phrases['usergroup_activation_title'] = '等待郵件驗證會員';
$install_phrases['usergroup_coppa_title'] = '等待管理員 (或 COPPA) 驗證會員';
$install_phrases['usergroup_super_title'] = '超級版主';
$install_phrases['usergroup_super_usertitle'] = '超級版主';
$install_phrases['usergroup_admin_title'] = '管理員';
$install_phrases['usergroup_admin_usertitle'] = '論壇管理員';
$install_phrases['usergroup_mod_title'] = '版主';
$install_phrases['usergroup_mod_usertitle'] = '版主';
$install_phrases['usergroup_banned_title'] = '封禁用户';
$install_phrases['usergroup_banned_usertitle'] = '封禁用户';
$install_phrases['usertitle_jnr'] = '初級會員';
$install_phrases['usertitle_mbr'] = '普通會員';
$install_phrases['usertitle_snr'] = '進階會員';

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 31381 $
|| ####################################################################
\*======================================================================*/
?>