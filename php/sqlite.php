<?php
	$db = sqlite_open('phpbb');
	if($db)
	{
		//$rs = sqlite_query($db, 'select * from t1');
		
		//$arr = sqlite_fetch_array($rs,SQLITE_ASSOC);
		$arr = sqlite_array_query($db,"select * from t1",SQLITE_ASSOC);
		foreach($arr as $val=>$key)
		{
			echo 'Name: '.$arr[$val]['name'] . '<br />' . 'Age: '.$arr[$val]['age'] . '<br />';

		}
//		var_dump($arr);
	}else{
		echo "can't open db";
	}
	

?>
