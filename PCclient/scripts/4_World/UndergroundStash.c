class UndergroundCity extends ItemBase
{
	override void EOnInit(IEntity other, int extra) //!EntityEvent.INIT
	{
		vector pos = GetPosition();
		vector surfOrient = GetGame().GetSurfaceOrientation(pos[0], pos[2]);
		SetOrientation(surfOrient);
	}
	
	override bool CanDisplayCargo()
	{
		super.CanDisplayCargo();
		return false;
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	
	override bool CanReleaseCargo(EntityAI cargo)
	{
		return false;
	}
	
	override bool CanReceiveItemIntoHands(EntityAI item_to_hands)
	{
		return false;
	}
	
	override bool CanSaveItemInHands(EntityAI item_in_hands)
	{
		return false;
	}
	
	override bool CanPutIntoHands(EntityAI parent)
	{
		super.CanPutIntoHands( parent );
		return false;
	}
	
	override bool IsInventoryVisible()
	{
		return false;
	}
}

class UndergroundPolice extends UndergroundCity {}
class UndergroundArmy extends UndergroundCity {}
class UndergroundQuest extends UndergroundCity {}
class UndergroundLegacy extends UndergroundCity {}