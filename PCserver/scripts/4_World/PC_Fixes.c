modded class GG_SYSBLOCK
{
	ref Timer m_PcDmgTimer;

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		if (slot_name == "keyboard") SetAnimationPhase("clips_keyboard", 0);
		if (slot_name == "mouse") SetAnimationPhase("clips_mouse", 0);
		if (slot_name == "monitor") SetAnimationPhase("clips_sysblock", 0);
		if (GetGame().IsServer() && GetCompEM() && GetCompEM().IsWorking()) UpdateDisplay();
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		if (slot_name == "keyboard") SetAnimationPhase("clips_keyboard", 1);
		if (slot_name == "mouse") SetAnimationPhase("clips_mouse", 1);
		if (slot_name == "monitor") SetAnimationPhase("clips_sysblock", 1);
		if (GetGame().IsServer() && GetCompEM() && GetCompEM().IsWorking()) UpdateDisplay();
	}

	override void OnWorkStart()
	{
		if (GetGame().IsServer())
		{
			if (!HasMBOARD() || !HasCPU() || !HasOS())
			{
				if (GetCompEM()) GetCompEM().SwitchOff();
				return;
			}
			UpdateDisplay();
			if (!m_PcDmgTimer) m_PcDmgTimer = new Timer();
			m_PcDmgTimer.Run(60, this, "ServerUpdateLoop", null, true); Print("[PCserver] Debug: Hacking Timer Started.");
		}
		super.OnWorkStart();
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
		if (GetGame().IsServer())
		{
			ClearDisplay();
			if (m_PcDmgTimer) m_PcDmgTimer.Stop();
		}
	}

	void ServerUpdateLoop()
	{
		ApplyComponentDamageAndDecrypt();
		UpdateDisplay();
	}

	void UpdateDisplay() { 
		if (!HasMONITOR() || !HasOS()) { ClearDisplay(); return; }
		EntityAI h_ent = FindAttachmentBySlotName("hdd");
		GG_HDD h_drv = GG_HDD.Cast(h_ent); Print("[PCserver] Debug: Component Update Loop Tick.");	

		if (!h_drv)
		{
			SetObjectTexture(0, "PCclient\\HDD\\data\\OS.paa");
			for (int l = 1; l <= 10; l++) { SetObjectTexture(l, ""); }
			return;
		}

		if (GetGame().IsServer() && !h_drv.HasValidStashPos())
		{
			CfgPcServerConfig cfg = PCLootHelper.m_Config;
			if (cfg && cfg.CoordinatesData && cfg.CoordinatesData.Count() > 0)
			{
				PC_CoordinatesData picked = cfg.CoordinatesData.GetRandomElement();
				if (picked.Coordinates != "0 0 0")
				{
					h_drv.SetStashPos(picked.Coordinates);
					Print("[PCserver] Auto-Assigned Stash Position to HDD: " + picked.Coordinates);
				}
			}
		}

		if (h_drv.IsDecrypted())
		{
			SetObjectTexture(0, "PCclient\\HDD\\data\\OS_LOC.paa");
			vector p = h_drv.GetStashPos();
			float fx = p[0];
			float fz = p[2];
			int pX = (int)fx;
			int pZ = (int)fz;
			string sX = pX.ToString();
			string sZ = pZ.ToString();

			int i;
			for (i = 0; i < 5; i++) {
				if (i < sX.Length()) SetDigit(i + 1, sX.Substring(i, 1));
				else SetObjectTexture(i + 1, "");
			}
			for (i = 0; i < 5; i++) {
				if (i < sZ.Length()) SetDigit(i + 6, sZ.Substring(i, 1));
				else SetObjectTexture(i + 6, "");
			}
		}
		else
		{
			SetObjectTexture(0, "PCclient\\HDD\\data\\OS.paa");
			string pStr = ((int)h_drv.GetProgress()).ToString() + "%";
			for (int k = 0; k < 10; k++) {
				if (k < pStr.Length()) SetDigit(k + 1, pStr.Substring(k, 1));
				else SetObjectTexture(k + 1, "");
			}
		}
	}

	void SetDigit(int sIdx, string v)
	{
		if (v == "%") SetObjectTexture(sIdx, "PCclient\\HDD\\letter1\\100.paa");
		else SetObjectTexture(sIdx, "PCclient\\HDD\\cifra\\" + v + ".paa");
	}

	void ClearDisplay()
	{
		SetObjectTexture(0, "");
		for (int m = 1; m <= 10; m++) { SetObjectTexture(m, ""); }
	}

	void ApplyComponentDamageAndDecrypt()
	{
		ItemBase mb = ItemBase.Cast(FindAttachmentBySlotName("mboard"));
		ItemBase cp = ItemBase.Cast(FindAttachmentBySlotName("cpu"));
		ItemBase os = ItemBase.Cast(FindAttachmentBySlotName("hdd_os"));

		if (!mb || mb.GetHealth("", "") <= 0 || !cp || cp.GetHealth("", "") <= 0 || !os || os.GetHealth("", "") <= 0 || GetHealth("", "") <= 0)
		{
			Print("[PCserver] Critical Failure: Shutdown triggered by ruined component.");
			if (GetCompEM()) GetCompEM().SwitchOff();
			return;
		}

		GG_HDD h_drv = GG_HDD.Cast(FindAttachmentBySlotName("hdd"));
		GG_HDD_OS os_drv = GG_HDD_OS.Cast(FindAttachmentBySlotName("hdd_os"));

		string hType = "City";
		if (h_drv && !h_drv.IsRuined())
		{
			if (h_drv.IsInherited(GG_HDD_Police)) hType = "Police";
			else if (h_drv.IsInherited(GG_HDD_Army)) hType = "Army";
			else if (h_drv.IsInherited(GG_HDD_Quest)) hType = "Quest";
			else if (h_drv.IsInherited(GG_HDD_Legacy)) hType = "Legacy";

			PC_DriveSettings hSet = PCLootHelper.GetDriveSettings(hType);
			if (hSet && hSet.HackTime > 0)
			{
				float osSpeed = PCLootHelper.GetOSSpeed(os_drv);
				float aP = (100.0 / (float)hSet.HackTime) * osSpeed;
				h_drv.AddProgress(aP); 

				if (h_drv.IsDecrypted() && !h_drv.HasSpawnedStash())
				{
					h_drv.SetStashSpawned(true);
					PCSpawnHelper.SpawnStashAt(h_drv.GetStashPos(), hType);
					h_drv.SetHealth("", "", 0);
				}
			}
		}

		PC_DriveSettings dSet = PCLootHelper.GetDriveSettings(hType);
		if (!dSet) return;

		float dmgMult = 1.0;
		CfgPcServerConfig cfg = PCLootHelper.m_Config;
		if (cfg) dmgMult = cfg.GlobalDamageMultiplier;

		ApplyDamageToSlot("mboard", dSet.DamageMBoard * dmgMult);
		ApplyDamageToSlot("cpu", dSet.DamageCPU * dmgMult);
		ApplyDamageToSlot("ram", dSet.DamageRAM * dmgMult);
		ApplyDamageToSlot("hdd_os", dSet.DamageHDD_OS * dmgMult);
		ApplyDamageToSlot("mouse", dSet.DamageMouse * dmgMult);
		ApplyDamageToSlot("keyboard", dSet.DamageKeyboard * dmgMult);
		ApplyDamageToSlot("monitor", dSet.DamageMonitor * dmgMult);

		float caseDmg = dSet.DamageCase * dmgMult;
		if (caseDmg > 0) AddHealth("", "", -(GetMaxHealth("", "") * (caseDmg / 100.0)));
	}

	void ApplyDamageToSlot(string sl, float pt)
	{
		ItemBase it = ItemBase.Cast(FindAttachmentBySlotName(sl));
		if (it) {
			it.AddHealth("", "", -(it.GetMaxHealth("", "") * (pt / 100.0)));
		}
	}
};