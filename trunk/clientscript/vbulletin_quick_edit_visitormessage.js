function vB_QuickEditor_VisitorMessage_Vars(args)
{
	this.init();
}

vB_QuickEditor_VisitorMessage_Vars.prototype.init = function()
{
	this.target = "visitormessage.php";
	this.postaction = "message";

	this.objecttype = "vmid";
	this.getaction = "message";

	this.ajaxtarget = "visitormessage.php";
	this.ajaxaction = "quickedit";
	this.deleteaction = "deletevm";

	this.messagetype = "vmessage_text_";
	this.containertype = "vmessage";
	this.responsecontainer = "commentbits";
}