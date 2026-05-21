class Empty_SYSBLOCK extends ItemBase
{
	void Empty_SYSBLOCK()
	{
		
	}
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionActivateSysblock);
		
	}
}