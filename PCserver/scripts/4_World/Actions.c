// PCserver Action Overrides

modded class ActionCheckGG_compukter
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		GG_compukter targetPC = GG_compukter.Cast(action_data.m_Target.GetObject());
		if (targetPC)
		{
			PCLootHelper.SpawnPCParts(targetPC, "City");
			PCLootHelper.DamageTool(action_data.m_MainItem, false);
			
			PC_DriveSettings settings = PCLootHelper.GetDriveSettings("City");
			int restock = 60;
			if (settings) restock = settings.RestockTime * 60;
			
			targetPC.GetCheckTimer().Stop();
			targetPC.SetCanCheck(1);
			targetPC.GetCheckTimer().Run(restock, targetPC, "GG_compukterTimer");
		}
	}
}

modded class ActionCheckGG_compukter_police
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		GG_compukter_police targetPC = GG_compukter_police.Cast(action_data.m_Target.GetObject());
		if (targetPC)
		{
			PCLootHelper.SpawnPCParts(targetPC, "Police");
			PCLootHelper.DamageTool(action_data.m_MainItem, false);
			
			PC_DriveSettings settings = PCLootHelper.GetDriveSettings("Police");
			int restock = 120;
			if (settings) restock = settings.RestockTime * 60;

			targetPC.GetCheckTimer().Stop();
			targetPC.SetCanCheck(1);
			targetPC.GetCheckTimer().Run(restock, targetPC, "GG_compukter_policeTimer");
		}
	}
}

modded class ActionCheckGG_compukter_army
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		GG_compukter_army targetPC = GG_compukter_army.Cast(action_data.m_Target.GetObject());
		if (targetPC)
		{
			PCLootHelper.SpawnPCParts(targetPC, "Army");
			PCLootHelper.DamageTool(action_data.m_MainItem, false);
			
			PC_DriveSettings settings = PCLootHelper.GetDriveSettings("Army");
			int restock = 180;
			if (settings) restock = settings.RestockTime * 60;

			targetPC.GetCheckTimer().Stop();
			targetPC.SetCanCheck(1);
			targetPC.GetCheckTimer().Run(restock, targetPC, "GG_compukter_armyTimer");
		}
	}
}

modded class ActionCheckGG_compukter_rare
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		GG_compukter_rare targetPC = GG_compukter_rare.Cast(action_data.m_Target.GetObject());
		if (targetPC)
		{
			PCLootHelper.SpawnPCParts(targetPC, "Quest");
			PCLootHelper.DamageTool(action_data.m_MainItem, false);
			
			PC_DriveSettings settings = PCLootHelper.GetDriveSettings("Quest");
			int restock = 240;
			if (settings) restock = settings.RestockTime * 60;

			targetPC.GetCheckTimer().Stop();
			targetPC.SetCanCheck(1);
			targetPC.GetCheckTimer().Run(restock, targetPC, "GG_compukter_rareTimer");
		}
	}
}

modded class ActionCheckGG_compukter_ancient
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		GG_compukter_ancient targetPC = GG_compukter_ancient.Cast(action_data.m_Target.GetObject());
		if (targetPC)
		{
			PCLootHelper.SpawnPCParts(targetPC, "Legacy");
			PCLootHelper.DamageTool(action_data.m_MainItem, false);
			
			PC_DriveSettings settings = PCLootHelper.GetDriveSettings("Legacy");
			int restock = 300;
			if (settings) restock = settings.RestockTime * 60;

			targetPC.GetCheckTimer().Stop();
			targetPC.SetCanCheck(1);
			targetPC.GetCheckTimer().Run(restock, targetPC, "GG_compukter_ancientTimer");
		}
	}
}

modded class ActionDigOutStashCity
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		Object target = action_data.m_Target.GetObject();
		if (target && target.GetType() == "UndergroundCity")
		{
			PCLootHelper.SpawnStashLoot(ItemBase.Cast(target), "City");
			PCLootHelper.DamageTool(action_data.m_MainItem, true);
			target.Delete();
		}
	}
}

modded class ActionDigOutStashPolice
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		Object target = action_data.m_Target.GetObject();
		if (target && target.GetType() == "UndergroundPolice")
		{
			PCLootHelper.SpawnStashLoot(ItemBase.Cast(target), "Police");
			PCLootHelper.DamageTool(action_data.m_MainItem, true);
			target.Delete();
		}
	}
}

modded class ActionDigOutStashArmy
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		Object target = action_data.m_Target.GetObject();
		if (target && target.GetType() == "UndergroundArmy")
		{
			PCLootHelper.SpawnStashLoot(ItemBase.Cast(target), "Army");
			PCLootHelper.DamageTool(action_data.m_MainItem, true);
			target.Delete();
		}
	}
}

modded class ActionDigOutStashQuest
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		Object target = action_data.m_Target.GetObject();
		if (target && target.GetType() == "UndergroundQuest")
		{
			PCLootHelper.SpawnStashLoot(ItemBase.Cast(target), "Quest");
			PCLootHelper.DamageTool(action_data.m_MainItem, true);
			target.Delete();
		}
	}
}

modded class ActionDigOutStashLegacy
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		Object target = action_data.m_Target.GetObject();
		if (target && target.GetType() == "UndergroundLegacy")
		{
			PCLootHelper.SpawnStashLoot(ItemBase.Cast(target), "Legacy");
			PCLootHelper.DamageTool(action_data.m_MainItem, true);
			target.Delete();
		}
	}
}
modded class ActionRepairPart
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !super.ActionCondition(player, target, item) ) return false;
		
		Object targetObj = target.GetObject();
		if (!targetObj) return false;
		
		string type = targetObj.GetType();
		CfgPcServerConfig cfg = PCLootHelper.m_Config;
		if (!cfg || !cfg.RepairData) return true;

		if (type == "GG_SYSBLOCK")
		{
			if (!cfg.RepairData.CanRepairCase) return false;
			return GetGame().IsKindOf(item.GetType(), cfg.RepairData.RepairToolCase);
		}
		if (type == "GG_MONITOR")
		{
			if (!cfg.RepairData.CanRepairMonitor) return false;
			return GetGame().IsKindOf(item.GetType(), cfg.RepairData.RepairToolMonitor);
		}
		if (type == "GG_MOUSE")
		{
			if (!cfg.RepairData.CanRepairMouse) return false;
			return GetGame().IsKindOf(item.GetType(), cfg.RepairData.RepairToolMouse);
		}
		if (type == "GG_KEYBOARD")
		{
			if (!cfg.RepairData.CanRepairKeyboard) return false;
			return GetGame().IsKindOf(item.GetType(), cfg.RepairData.RepairToolKeyboard);
		}

		return true;
	}
}


