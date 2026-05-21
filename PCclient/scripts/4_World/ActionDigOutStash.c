class ActionDigOutStashCity: ActionContinuousBase
{	
	void ActionDigOutStashCity()
	{
		m_CallbackClass = ActionDigOutStashCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGUPCACHE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTCursor;
	}

	override string GetText() { return "#STR_dig_out"; }
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		return ( targetObject && targetObject.GetType() == "UndergroundCity" );
	}
};

class ActionDigOutStashPolice: ActionDigOutStashCity
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		return ( targetObject && targetObject.GetType() == "UndergroundPolice" );
	}
};

class ActionDigOutStashArmy: ActionDigOutStashCity
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		return ( targetObject && targetObject.GetType() == "UndergroundArmy" );
	}
};

class ActionDigOutStashQuest: ActionDigOutStashCity
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		return ( targetObject && targetObject.GetType() == "UndergroundQuest" );
	}
};

class ActionDigOutStashLegacy: ActionDigOutStashCity
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		return ( targetObject && targetObject.GetType() == "UndergroundLegacy" );
	}
};