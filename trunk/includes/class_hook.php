<?php
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

// to call a hook:
//	require_once(DIR . '/includes/class_hook.php');
//	($hook = vBulletinHook::fetch_hook('unique_hook_name')) ? eval($hook) : false;

/**
* Works the vBulletin Plugin Hook System
*
* @package 		vBulletin
* @version		$Revision: 27366 $
* @author		Kier & Mike
* @date 		$Date: 2008-08-07 06:33:46 -0500 (Thu, 07 Aug 2008) $
* @copyright 	http://www.vbulletin.com/license.html
*
*/
class vBulletinHook
{
	/**
	* This holds the plugin data
	*
	* @var    array
	*/
	var $pluginlist = array();

	/**
	* This keeps track of which hooks have been used
	*
	* @var	array
	*/
	var $hookusage = array();

	/**
	* Constructor - unserializes the plugin data from the datastore when class is initiated
	*
	* @return	none
	*/
	function vBulletinHook()
	{
	}

	/**
	* Sets the plugin list array
	*/
	function set_pluginlist(&$pluginlist)
	{
		$this->pluginlist =& $pluginlist;
	}

	/**
	* Singleton emulation - use this function to instantiate the class
	*
	* @return	vBulletinHook
	*/
	function &init()
	{
		static $instance;

		if (!$instance)
		{
			$instance = new vBulletinHook();
		}

		return $instance;
	}

	/**
	* Returns any code attached to a hook with a specific name
	*
	* @param	string	hookname	The name of the hook (location) to be executed
	*
	* @return	string
	*/
	function fetch_hook_object($hookname)
	{
		if (!empty($this->pluginlist["$hookname"]))
		{
			if (!isset($this->hookusage["$hookname"]))
			{
				$this->hookusage["$hookname"] = true;
			}
			return $this->pluginlist["$hookname"];
		}
		else
		{
			if (!isset($this->hookusage["$hookname"]))
			{
				$this->hookusage["$hookname"] = false;
			}
			return '';
		}
	}

	/**
	* Returns any code attached to a hook with a specific name. Used when the object is not in scope already.
	*
	* @param	string	hookname	The name of the hook (location) to be executed
	*
	* @return	string
	*/
	function fetch_hook($hookname = false)
	{
		if (!$hookname)
		{
			return false;
		}
		
		$obj =& vBulletinHook::init();
		return $obj->fetch_hook_object($hookname);
	}

	/**
	* Builds the datastore for the hooks into the database.
	*/
	function build_datastore(&$dbobject)
	{
		$code = array();
		$admincode = array();

		$adminlocations = array();

		require_once(DIR . '/includes/class_xml.php');
		$handle = opendir(DIR . '/includes/xml/');
		while (($file = readdir($handle)) !== false)
		{
			if (!preg_match('#^hooks_(.*).xml$#i', $file, $matches))
			{
				continue;
			}

			$xmlobj = new vB_XML_Parser(false, DIR . "/includes/xml/$file");
			$xml = $xmlobj->parse();

			if (!is_array($xml['hooktype'][0]))
			{
				$xml['hooktype'] = array($xml['hooktype']);
			}

			foreach ($xml['hooktype'] AS $key => $hooktype)
			{
				if (!is_numeric($key))
				{
					continue;
				}

				if (!is_array($hooktype['hook']))
				{
					$hooktype['hook'] = array($hooktype['hook']);
				}

				foreach ($hooktype['hook'] AS $hook)
				{
					if ((is_array($hook) AND !empty($hook['admin'])) OR !empty($hooktype['admin']))
					{
						$adminlocations[(is_string($hook) ? $hook : $hook['value'])] = true;
					}
				}
			}
		}

		$plugins = $dbobject->query_read("
			SELECT plugin.*,
				IF(product.productid IS NULL, 0, 1) AS foundproduct,
				IF(plugin.product = 'vbulletin', 1, product.active) AS productactive
			FROM " . TABLE_PREFIX . "plugin AS plugin
			LEFT JOIN " . TABLE_PREFIX . "product AS product ON(product.productid = plugin.product)
			WHERE plugin.active = 1
				AND plugin." . "phpcode <> ''
			ORDER BY plugin.executionorder ASC
		");
		while ($plugin = $dbobject->fetch_array($plugins))
		{
			if ($plugin['foundproduct'] AND !$plugin['productactive'])
			{
				continue;
			}
			else if (!empty($adminlocations["$plugin[hookname]"]))
			{
				$admincode["$plugin[hookname]"] .= "$plugin[phpcode]\r\n";
			}
			else
			{
				$code["$plugin[hookname]"] .= "$plugin[phpcode]\r\n";
			}
		}
		$dbobject->free_result($plugins);

		build_datastore('pluginlist', serialize($code), 1);
		build_datastore('pluginlistadmin', serialize($admincode), 1);

		return true;
	}

	/**
	* Fetches the array of hooks that have been used.
	*/
	function fetch_hookusage()
	{
		$obj =& vBulletinHook::init();
		return $obj->hookusage;
	}
}


/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 27366 $
|| ####################################################################
\*======================================================================*/
?>