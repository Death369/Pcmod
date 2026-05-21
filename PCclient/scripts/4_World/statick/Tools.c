
modded class Screwdriver extends ToolBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionCheckGG_compukter);
		AddAction(ActionCheckGG_compukter_police);
		AddAction(ActionCheckGG_compukter_army);
		AddAction(ActionCheckGG_compukter_rare);
		AddAction(ActionCheckGG_compukter_ancient);
	}
};