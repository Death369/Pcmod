class ActionActivateSysblock: ActionContinuousBase
{
	void ActionActivateSysblock()
	{
		m_CallbackClass = ActionCraftImprovisedFeetCoverCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "Подготовить блок";
	}
	
	override void CreateConditionComponents()  
	{		
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !item.IsRuined() )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	override bool HasTarget()
	{
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		EntityAI item_ingredient = action_data.m_MainItem;
		EntityAI cover;
		
		cover = action_data.m_Player.SpawnEntityOnGroundPos("GG_SYSBLOCK", action_data.m_Player.GetPosition());
		action_data.m_MainItem.Delete();
		
		MiscGameplayFunctions.TransferItemProperties(item_ingredient, cover);
	}
};