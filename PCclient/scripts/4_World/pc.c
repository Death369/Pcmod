class GG_SYSBLOCK extends ItemBase
{
	const string SOUND_HUMMING = "pcom_SoundSet";
	const string SOUND_TURN_ON = "spotlight_turn_on_SoundSet";
	const string SOUND_TURN_OFF = "spotlight_turn_off_SoundSet";
	const string SOUND_POST_OK = "pcom_post_ok_SoundSet";
	const string SOUND_POST_ERR = "pcom_post_err_SoundSet";
	const string SOUND_STARTUP = "pcom_startup_SoundSet";
	const string SOUND_SHUTDOWN = "pcom_shutdown_SoundSet";

	protected EffectSound m_SoundHummingLoop;
	protected EffectSound m_SoundTurnOn;
	protected EffectSound m_SoundTurnOff;
	protected EffectSound m_SoundPost;
	protected EffectSound m_SoundSys;
	
	ChemlightLight m_Light;
	static vector 	m_LightLocalPosition 	= "0.6 0.3 0.3";
	static vector 	m_LightLocalOrientation = "0 0 0";

	override void EEItemAttached ( EntityAI item, string slot_name )
	{
		super.EEItemAttached (item, slot_name);
	}	
	
	override void EEItemDetached ( EntityAI item, string slot_name )
	{
		super.EEItemDetached ( item, slot_name );
		if (slot_name == "monitor")
		{
			if (m_Light)
				m_Light.FadeOut(0.05);
			m_Light = NULL;
		}
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionPlugIn); 
		AddAction(ActionTogglePlaceObject); 
		AddAction(ActionUnplugThisByCord); 
		AddAction(ActionTurnOnWhileOnGround);
		AddAction(ActionTurnOffWhileOnGround); 
		AddAction(ActionPlugTargetIntoThis);
		AddAction(ActionDeployObject);
		AddAction(ActionRepositionPluggedItem);
	}

	override void OnSwitchOn()
	{
		super.OnSwitchOn();
	}
	
	bool HasHDD() { EntityAI ent = FindAttachmentBySlotName("hdd"); return ent && !ent.IsRuined(); }
	bool HasOS() { EntityAI ent = FindAttachmentBySlotName("hdd_os"); return ent && !ent.IsRuined(); }
	bool HasCPU() { EntityAI ent = FindAttachmentBySlotName("cpu"); return ent && !ent.IsRuined(); }
	bool HasMBOARD() { EntityAI ent = FindAttachmentBySlotName("mboard"); return ent && !ent.IsRuined(); }
	bool HasRAM() { EntityAI ent = FindAttachmentBySlotName("ram"); return ent && !ent.IsRuined(); }
	bool HasMONITOR() { EntityAI ent = FindAttachmentBySlotName("monitor"); return ent && !ent.IsRuined(); }
	bool HasMOUSE() { EntityAI ent = FindAttachmentBySlotName("mouse"); return ent && !ent.IsRuined(); }
	bool HasKEYBOARD() { EntityAI ent = FindAttachmentBySlotName("keyboard"); return ent && !ent.IsRuined(); }
	
	override void OnSwitchOff()
	{
		super.OnSwitchOff();
		PlaySoundSet(m_SoundTurnOff, SOUND_TURN_OFF, 0, 0);
		if (m_Light) m_Light.FadeOut(0.05);
		m_Light = NULL;
		SwitchOn(false);
	}
	
	override void OnWorkStart()
	{
		super.OnWorkStart();
		PlaySoundSetLoop(m_SoundHummingLoop, SOUND_HUMMING, 0.1, 0.3);	
        if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
        {
			if (!HasMBOARD() || !HasCPU() || !HasOS() || !HasRAM())
				PlaySoundSet(m_SoundPost, SOUND_POST_ERR, 0, 0);
			else
			{
				PlaySoundSet(m_SoundPost, SOUND_POST_OK, 0, 0);
				PlaySoundSet(m_SoundSys, SOUND_STARTUP, 0, 0);
			}

			m_Light = ChemlightLight.Cast( ScriptedLightBase.CreateLight(ChemlightLight, "0 0 0", 0.08) );
			m_Light.AttachOnObject(this, m_LightLocalPosition, m_LightLocalOrientation);
			m_Light.SetRadiusTo( 2 );
			m_Light.SetIntensity( 1, 0 );
			m_Light.SetBrightnessTo(1);
			m_Light.SetAmbientColor(0.33, 0.33, 1);
			m_Light.SetDiffuseColor(0.33, 0.33, 1);
			m_Light.SetCastShadow(true);
			m_Light.SetFlareVisible(false);
        }
		SwitchOn(true);
	}

	override void OnWork( float consumed_energy )
	{
		super.OnWork(consumed_energy);
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
		StopSoundSet(m_SoundHummingLoop);
		
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
			PlaySoundSet(m_SoundSys, SOUND_SHUTDOWN, 0, 0);

		if (m_Light) m_Light.FadeOut(0.05);
		m_Light = NULL;
		SwitchOn(false);
	}

	override bool IsDeployable() { return true; }
	override bool IsTwoHandedBehaviour() { return true; }

	override bool CanPutInCargo( EntityAI parent )
    {
        if( !super.CanPutInCargo(parent) ) {return false;}        
        if ( !HasMONITOR() && !HasMOUSE() && !HasKEYBOARD()) return true;
        return false;
    }
    
    override bool CanPutIntoHands(EntityAI parent)
    {
        if( !super.CanPutIntoHands( parent ) ) return false;
        if ( !HasMONITOR() && !HasMOUSE() && !HasKEYBOARD() ) return true;
        return false;
    }	
};

modded class ActionDeployObject
{    
    void SetupAnimation( ItemBase item )
    {
        if ( item.IsDeployable() )
        {
            if ( item.IsHeavyBehaviour() )
                m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_HEAVY;
            else if ( item.IsOneHandedBehaviour() )
                m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_1HD; 
            else if ( item.IsTwoHandedBehaviour() )
                m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_2HD;
            else
                m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_1HD; 
        }
        else
        {
            if ( item.IsHeavyBehaviour() )
                m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_PLACING_HEAVY;
            else if ( item.IsOneHandedBehaviour() )
                m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_PLACING_1HD; 
            else if ( item.IsTwoHandedBehaviour() )
                m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_PLACING_2HD;
            else
                m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_1HD; 
        }
    }
};