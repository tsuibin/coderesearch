function vB_QuickEditor_GroupMessage_Vars(args)
{
	this.init();
}

vB_QuickEditor_GroupMessage_Vars.prototype.init = function()
{
	this.target = "group.php";
	this.postaction = "message";

	this.objecttype = "gmid";
	this.getaction = "message";

	this.ajaxtarget = "group.php";
	this.ajaxaction = "quickedit";
	this.deleteaction = "deletemessage";

	this.messagetype = "gmessage_text_";
	this.containertype = "gmessage_qe";
	this.responsecontainer = "commentbits";
}