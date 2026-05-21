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
		UpdateDisplay();
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
		UpdateDisplay();
	}

	void UpdateDisplay() 
	{ 
		#ifndef SERVER
		if (!GetGame() || !HasMONITOR() || !HasOS() || !GetCompEM() || !GetCompEM().IsWorking()) 
		{ 
			ClearDisplay(); 
			return; 
		}
		
		EntityAI h_ent = FindAttachmentBySlotName("hdd");
		if (!h_ent) 
		{
			SetObjectTexture(0, "PCclient\\HDD\\data\\OS.paa");
			for (int l = 1; l <= 10; l++) { SetObjectTexture(l, ""); }
			return;
		}
		
		GG_HDD h_drv = GG_HDD.Cast(h_ent);
		if (!h_drv) return;

		if (h_drv.IsDecrypted())
		{
			vector v_pos = h_drv.GetStashPos();
			float v_x = v_pos[0];
			float v_z = v_pos[2];
			int i_x = (int)v_x;
			int i_z = (int)v_z;
			string s_x = i_x.ToString();
			string s_z = i_z.ToString();

			SetObjectTexture(0, "PCclient\\HDD\\data\\OS_LOC.paa");
			
			for (int i = 0; i < 5; i++) {
				if (i < s_x.Length()) SetDigit(i + 1, s_x.Substring(i, 1));
				else SetObjectTexture(i + 1, "");
			}
			for (int j = 0; j < 5; j++) {
				if (j < s_z.Length()) SetDigit(j + 6, s_z.Substring(j, 1));
				else SetObjectTexture(j + 6, "");
			}
		}
		else
		{
			float f_p = h_drv.GetProgress();
			int i_p = (int)f_p;
			string p_s = i_p.ToString() + "%";
			
			SetObjectTexture(0, "PCclient\\HDD\\data\\OS.paa");
			for (int k = 0; k < 10; k++) {
				if (k < p_s.Length()) SetDigit(k + 1, p_s.Substring(k, 1));
				else SetObjectTexture(k + 1, "");
			}
		}
		#endif
	}

	void SetDigit(int sIdx, string v)
	{
		#ifndef SERVER
		if (v == "%") SetObjectTexture(sIdx, "PCclient\\HDD\\letter1\\100.paa");
		else SetObjectTexture(sIdx, "PCclient\\HDD\\cifra\\" + v + ".paa");
		#endif
	}

	void ClearDisplay()
	{
		#ifndef SERVER
		SetObjectTexture(0, "");
		for (int m = 1; m <= 10; m++) { SetObjectTexture(m, ""); }
		#endif
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
		#ifndef SERVER
		PlaySoundSet(m_SoundTurnOff, SOUND_TURN_OFF, 0, 0);
		#endif
		if (m_Light) m_Light.FadeOut(0.05);
		m_Light = NULL;
		SwitchOn(false);
	}
	
	override void OnWorkStart()
	{
		super.OnWorkStart();
		#ifndef SERVER
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
		#endif
		SwitchOn(true);
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
		#ifndef SERVER
		StopSoundSet(m_SoundHummingLoop);
		
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
			PlaySoundSet(m_SoundSys, SOUND_SHUTDOWN, 0, 0);
		#endif

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
    override void SetupAnimation( ItemBase item )
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