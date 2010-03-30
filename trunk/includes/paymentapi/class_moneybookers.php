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

if (!isset($GLOBALS['vbulletin']->db))
{
	exit;
}

/**
* Class that provides payment verification and form generation functions
*
* @package	vBulletin
* @version	$Revision: 25144 $
* @date		$Date: 2007-12-14 05:45:31 -0600 (Fri, 14 Dec 2007) $
*/
class vB_PaidSubscriptionMethod_moneybookers extends vB_PaidSubscriptionMethod
{
	/**
	* The variable indicating if this payment provider supports recurring transactions
	*
	* @var	bool
	*/
	var $supports_recurring = false;

	/**
	* Perform verification of the payment, this is called from the payment gateway
	*
	* @return	bool	Whether the payment is valid
	*/
	function verify_payment()
	{
		$this->registry->input->clean_array_gpc('p', array(
			'pay_to_email'           => TYPE_STR,
			'merchant_id'            => TYPE_STR,
			'transaction_id'         => TYPE_STR,
			'mb_transaction_id'      => TYPE_UINT,
			'status'                 => TYPE_STR,
			'md5sig'                 => TYPE_STR,
			'amount'                 => TYPE_STR,
			'currency'               => TYPE_STR,
			'mb_amount'              => TYPE_STR,
			'mb_currency'            => TYPE_STR,
		));

		$this->transaction_id = $this->registry->GPC['mb_transaction_id'];

		$check_hash = strtoupper(md5($this->registry->GPC['merchant_id'] . $this->registry->GPC['transaction_id'] . strtoupper(md5(strtolower($this->settings['mbsecret']))) . $this->registry->GPC['mb_amount'] . $this->registry->GPC['mb_currency'] . $this->registry->GPC['status']));

		if ($check_hash == $this->registry->GPC['md5sig'] AND strtolower($this->registry->GPC['pay_to_email']) == strtolower($this->settings['mbemail']))
		{
			if (intval($this->registry->GPC['status']) == 2)
			{
				$this->paymentinfo = $this->registry->db->query_first("
					SELECT paymentinfo.*, user.username
					FROM " . TABLE_PREFIX . "paymentinfo AS paymentinfo
					INNER JOIN " . TABLE_PREFIX . "user AS user USING (userid)
					WHERE hash = '" . $this->registry->db->escape_string($this->registry->GPC['transaction_id']) . "'
				");
				// lets check the values
				if (!empty($this->paymentinfo))
				{
					$sub = $this->registry->db->query_first("SELECT * FROM " . TABLE_PREFIX . "subscription WHERE subscriptionid = " . $this->paymentinfo['subscriptionid']);
					$cost = unserialize($sub['cost']);
					$this->paymentinfo['currency'] = strtolower($this->registry->GPC['currency']);
					$this->paymentinfo['amount'] = floatval($this->registry->GPC['amount']);
					if (doubleval($this->registry->GPC['amount']) == doubleval($cost["{$this->paymentinfo[subscriptionsubid]}"]['cost'][strtolower($this->registry->GPC['currency'])]))
					{
						$this->type = 1;
						return true;
					}
				}
			}
		}
		return false;
	}

	/**
	* Test that required settings are available, and if we can communicate with the server (if required)
	*
	* @return	bool	If the vBulletin has all the information required to accept payments
	*/
	function test()
	{
		return (!empty($this->settings['mbemail']) AND !empty($this->settings['mbsecret']));
	}

	/**
	* Generates HTML for the subscription form page
	*
	* @param	string		Hash used to indicate the transaction within vBulletin
	* @param	string		The cost of this payment
	* @param	string		The currency of this payment
	* @param	array		Information regarding the subscription that is being purchased
	* @param	array		Information about the user who is purchasing this subscription
	* @param	array		Array containing specific data about the cost and time for the specific subscription period
	*
	* @return	array		Compiled form information
	*/
	function generate_form_html($hash, $cost, $currency, $subinfo, $userinfo, $timeinfo)
	{
		global $vbphrase, $vbulletin, $stylevar, $show;

		$currency = strtoupper($currency);

		$form['action'] = 'https://www.moneybookers.com/app/payment.pl';
		$form['method'] = 'post';

		// load settings into array so the template system can access them
		$settings =& $this->settings;

		eval('$form[\'hiddenfields\'] .= "' . fetch_template('subscription_payment_moneybookers') . '";');
		return $form;
	}

}

/*======================================================================*\
|| ####################################################################
|| # Downloaded: [#]zipbuilddate[#]
|| # CVS: $RCSfile$ - $Revision: 25144 $
|| ####################################################################
\*======================================================================*/
?>