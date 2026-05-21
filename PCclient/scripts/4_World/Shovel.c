modded class Shovel extends ItemBase
{

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDigOutStashCity);
		AddAction(ActionDigOutStashPolice);
		AddAction(ActionDigOutStashArmy);
		AddAction(ActionDigOutStashQuest);
		AddAction(ActionDigOutStashLegacy);
	}
}