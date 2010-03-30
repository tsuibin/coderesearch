<?php
/*======================================================================*\
|| #################################################################### ||
|| # vBulletin [#]version[#] - Licence Number [#]license[#]
|| # ---------------------------------------------------------------- # ||
|| # Copyright ©2000-[#]year[#] Jelsoft Enterprises Ltd. All Rights Reserved. ||
|| # This file may not be redistributed in whole or significant part. # ||
|| # ---------------- VBULLETIN IS NOT FREE SOFTWARE ---------------- # ||
|| # http://www.vbulletin.com | http://www.vbulletin.com/license.html # ||
|| #################################################################### ||
\*======================================================================*/

function get_adsense_templates()
{
	#####################
	## LOW (text)
	#####################

	$ad_navbar_below_low_text = '<if condition="$GLOBALS[\'vbulletin\']->adsense_pub_id">
<div style="width:728px; margin:0 auto; padding-bottom:1em">
<script type="text/javascript"><!--
google_ad_client = "{$GLOBALS[\'vbulletin\']->adsense_pub_id}";
google_ad_host = "{$GLOBALS[\'vbulletin\']->adsense_host_id}";
google_ad_width = 728;
google_ad_height = 15;
google_ad_format = "728x15_0ads_al_s";
google_ad_channel = "";
google_color_border = "$stylevar[page_bgcolor_hex]";
google_color_bg = "$stylevar[page_bgcolor_hex]";
google_color_link = "$stylevar[body_link_n_fgcolor_hex]";
google_color_text = "$stylevar[body_fgcolor_hex]";
google_color_url = "$stylevar[body_link_n_fgcolor_hex]";
google_ui_features = "rc:6";
//-->
</script>
<script type="text/javascript"
  src="http://pagead2.googlesyndication.com/pagead/show_ads.js">
</script>
</div>
</if>';

	$ad_footer_start_low_text = '<if condition="$GLOBALS[\'vbulletin\']->adsense_pub_id">
<div style="width:468px; margin:0 auto; padding-top:1em">
<script type="text/javascript"><!--
google_ad_client = "{$GLOBALS[\'vbulletin\']->adsense_pub_id}";
google_ad_host = "{$GLOBALS[\'vbulletin\']->adsense_host_id}";
google_ad_width = 468;
google_ad_height = 60;
google_ad_format = "468x60_as";
google_ad_type = "text";
google_ad_channel = "";
google_color_border = "$stylevar[page_bgcolor_hex]";
google_color_bg = "$stylevar[page_bgcolor_hex]";
google_color_link = "$stylevar[body_link_n_fgcolor_hex]";
google_color_text = "$stylevar[body_fgcolor_hex]";
google_color_url = "$stylevar[body_link_n_fgcolor_hex]";
google_ui_features = "rc:6";
//-->
</script>
<script type="text/javascript"
  src="http://pagead2.googlesyndication.com/pagead/show_ads.js">
</script>
</div>
</if>';

	#####################
	## HIGH (text)
	#####################

	$ad_footer_start_high_text = '<if condition="$GLOBALS[\'vbulletin\']->adsense_pub_id">
<div style="width:728px; margin:0 auto; padding-top:1em">
<script type="text/javascript"><!--
google_ad_client = "{$GLOBALS[\'vbulletin\']->adsense_pub_id}";
google_ad_host = "{$GLOBALS[\'vbulletin\']->adsense_host_id}";
google_ad_width = 728;
google_ad_height = 90;
google_ad_format = "728x90_as";
google_ad_type = "text";
google_ad_channel = "";
google_color_border = "$stylevar[page_bgcolor_hex]";
google_color_bg = "$stylevar[page_bgcolor_hex]";
google_color_link = "$stylevar[body_link_n_fgcolor_hex]";
google_color_text = "$stylevar[body_fgcolor_hex]";
google_color_url = "$stylevar[body_link_n_fgcolor_hex]";
google_ui_features = "rc:6";
//-->
</script>
<script type="text/javascript"
  src="http://pagead2.googlesyndication.com/pagead/show_ads.js">
</script>
</div>
</if>';


	$ad_navbar_below_high_text = '<if condition="$GLOBALS[\'vbulletin\']->adsense_pub_id">
<div style="width:728px; margin:0 auto; padding-bottom:1em">
<script type="text/javascript"><!--
google_ad_client = "{$GLOBALS[\'vbulletin\']->adsense_pub_id}";
google_ad_host = "{$GLOBALS[\'vbulletin\']->adsense_host_id}";
google_ad_width = 728;
google_ad_height = 90;
google_ad_format = "728x90_as";
google_ad_type = "text";
google_ad_channel = "";
google_color_border = "$stylevar[alt2_bgcolor_hex]";
google_color_bg = "$stylevar[alt1_bgcolor_hex]";
google_color_link = "$stylevar[body_link_n_fgcolor_hex]";
google_color_text = "$stylevar[body_fgcolor_hex]";
google_color_url = "$stylevar[body_link_n_fgcolor_hex]";
google_ui_features = "rc:6";
//-->
</script>
<script type="text/javascript"
  src="http://pagead2.googlesyndication.com/pagead/show_ads.js">
</script>
</div>
</if>';

	$ad_showthread_firstpost_start_high_text = '<if condition="$GLOBALS[\'vbulletin\']->adsense_pub_id">
<if condition="!$bbuserinfo[\'userid\']">
<div style="float:right; width:300px; height:250px; margin-left:10px">
<script type="text/javascript"><!--
google_ad_client = "{$GLOBALS[\'vbulletin\']->adsense_pub_id}";
google_ad_host = "{$GLOBALS[\'vbulletin\']->adsense_host_id}";
google_ad_width = 300;
google_ad_height = 250;
google_ad_format = "300x250_as";
google_ad_type = "text";
google_ad_channel = "";
google_color_border = "$stylevar[alt1_bgcolor_hex]";
google_color_bg = "$stylevar[alt2_bgcolor_hex]";
google_color_link = "$stylevar[body_link_n_fgcolor_hex]";
google_color_text = "$stylevar[body_fgcolor_hex]";
google_color_url = "$stylevar[body_link_n_fgcolor_hex]";
google_ui_features = "rc:6";
//-->
</script>
<script type="text/javascript"
  src="http://pagead2.googlesyndication.com/pagead/show_ads.js">
</script>
</div>
</if>
</if>';


	// ######################## THE ARRAY ###########################

	$ad_showthread_firstpost_sig = '<if condition="$GLOBALS[\'vbulletin\']->adsense_pub_id">
<if condition="!$bbuserinfo[\'userid\']">
<div style="clear:both"></div>
</if>
</if>';

	return array(
		'low-text' => array(
			'ad_navbar_below' => $ad_navbar_below_low_text,
			'ad_showthread_firstpost_start' => '',
			'ad_showthread_firstpost_sig' => '',
			'ad_footer_start' => $ad_footer_start_low_text,
		),
		'low-image' => array(
			'ad_navbar_below' => remove_adsense_text_only_limit($ad_navbar_below_low_text),
			'ad_showthread_firstpost_start' => '',
			'ad_showthread_firstpost_sig' => '',
			'ad_footer_start' => remove_adsense_text_only_limit($ad_footer_start_low_text),
		),

		'high-text' => array(
			'ad_navbar_below' => $ad_navbar_below_high_text,
			'ad_showthread_firstpost_start' => $ad_showthread_firstpost_start_high_text,
			'ad_showthread_firstpost_sig' => $ad_showthread_firstpost_sig,
			'ad_footer_start' => $ad_footer_start_high_text,
		),
		'high-image' => array(
			'ad_navbar_below' => remove_adsense_text_only_limit($ad_navbar_below_high_text),
			'ad_showthread_firstpost_start' => remove_adsense_text_only_limit($ad_showthread_firstpost_start_high_text),
			'ad_showthread_firstpost_sig' => $ad_showthread_firstpost_sig,
			'ad_footer_start' => remove_adsense_text_only_limit($ad_footer_start_high_text),
		),

		'remove' => array(
			'ad_navbar_below' => '',
			'ad_showthread_firstpost_start' => '',
			'ad_showthread_firstpost_sig' => '',
			'ad_footer_start' => '',
		),
	);
}

function remove_adsense_text_only_limit($adsense_string)
{
	return str_replace(
		'google_ad_type = "text";',
		'google_ad_type = "text_image";',
		$adsense_string
	);
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision:  $
|| ####################################################################
\*======================================================================*/