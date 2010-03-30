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

if (!isset($GLOBALS['vbulletin']->db))
{
	exit;
}

/**
* Human Verification class for Image Verification
*
* @package 		vBulletin
* @version		$Revision: 27657 $
* @date 		$Date: 2008-09-03 10:36:05 -0500 (Wed, 03 Sep 2008) $
*
*/
class vB_HumanVerify_Image extends vB_HumanVerify_Abstract
{
	/**
	* Constructor
	*
	* @return	void
	*/
	function vB_HumanVerify_Image(&$registry)
	{
		parent::vB_HumanVerify_Abstract($registry);
	}

	/**
	* Verify is supplied token/reponse is valid
	*
	*	@param	array	Values given by user 'input' and 'hash'
	*
	* @return	bool
	*/
	function verify_token($input)
	{
		$input['input'] = trim(str_replace(' ', '', $input['input']));

		if ($this->delete_token($input['hash'], $input['input']))
		{
			return true;
		}
		else
		{
			$this->error = 'humanverify_image_wronganswer';
			return false;
		}
	}

	/**
	 * Returns the HTML to be displayed to the user for Human Verification
	 *
	 * @param	string	Passed to template
	 *
	 * @return 	string	HTML to output
	 *
	 */
	function output_token($var_prefix = 'humanverify')
	{
		global $vbphrase, $stylevar, $show;
		$vbulletin =& $this->registry;

		$humanverify = $this->generate_token();

		eval('$output = "' . fetch_template('humanverify_image') . '";');

		return $output;
	}

	/**
	* Call this class' answer function via a middleman since it has an argument
	*
	* @return	string
	*/
	function fetch_answer()
	{
		return $this->fetch_answer_string();
	}

	/**
	* Generate a random string for image verification
	*
	* @param	int		Length of result
	*
	* @return	string
	*/
	function fetch_answer_string($length = 6)
	{
		$somechars = '234689ABCEFGHJMNPQRSTWY';
		$morechars = '234689ABCEFGHJKMNPQRSTWXYZabcdefghjkmnpstwxyz';

		for ($x = 1; $x <= $length; $x++)
		{
			$chars = ($x <= 2 OR $x == $length) ? $morechars : $somechars;
			$number = vbrand(1, strlen($chars));
			$word .= substr($chars, $number - 1, 1);
	 	}

	 	return $word;
	}
}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 27657 $
|| ####################################################################
\*======================================================================*/
?>
