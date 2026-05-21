class ActionCheckGG_compukterCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(5);
	}
};

class ActionCheckGG_compukter: ActionContinuousBase
{
	ref Timer		m_CheckGG_compukterTimer;

	void ActionCheckGG_compukter()
	{
		m_CallbackClass = ActionCheckGG_compukterCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_HIGH;

	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTCursor;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		GG_compukter m_CheckRandomLoot = GG_compukter.Cast( targetObject );

		if ( m_CheckRandomLoot && m_CheckRandomLoot.CanLootGG_compukter() )
		{
			return true;
		}
		return false;
	}

	override bool HasProgress()
	{
		return true;
	}

	override string GetText()
	{
		return "#STR_disassemble";
	}
	override void OnStartAnimationLoop( ActionData action_data )
	{

		private EffectSound sound;
		action_data.m_Player.PlaySoundSet( sound , "pcomdeploy_SoundSet", 0, 0 );
	}
	

}