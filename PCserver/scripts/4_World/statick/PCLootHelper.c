class PCLootHelper
{
	static ref CfgPcServerConfig m_Config;

	static void Init(CfgPcServerConfig config)
	{
		m_Config = config;
	}

	static PC_DriveSettings GetDriveSettings(string hddType)
	{
		if (!m_Config) return null;
		if (hddType == "City") return m_Config.DrivesData.CityDriveData;
		if (hddType == "Police") return m_Config.DrivesData.PoliceDriveData;
		if (hddType == "Army") return m_Config.DrivesData.ArmyDriveData;
		if (hddType == "Quest") return m_Config.DrivesData.QuestDriveData;
		if (hddType == "Legacy") return m_Config.DrivesData.LegacyDriveData;
		return null;
	}

	static void DamageTool(ItemBase toolItem, bool wasShovel)
	{
		if (!toolItem || !m_Config) return;
		int damageAmount = m_Config.ToolData.ToolDamageScrew;
		if (wasShovel) damageAmount = m_Config.ToolData.ToolDamageShovel;
		toolItem.AddHealth("", "", -damageAmount);
	}

	static string GetOSClassname(string areaType)
	{
		// Default Area Logic
		string result = "GG_HDD_OS";
		if (areaType == "Police") result = "GG_HDD_OS_Police";
		if (areaType == "Army") result = "GG_HDD_OS_Army";

		// Optional Configuration Logic (Upgrades)
		if (m_Config && m_Config.OSData)
		{
			int r = Math.RandomInt(0, 100);
			if (r < m_Config.OSData.ChanceOSArmy) return "GG_HDD_OS_Army";
			if (r < m_Config.OSData.ChanceOSPolice) return "GG_HDD_OS_Police";
		}

		return result;
	}

	static float GetOSSpeed(GG_HDD_OS osDrive)
	{
		if (!osDrive || !m_Config || !m_Config.OSData) return 1.0;
		if (osDrive.IsInherited(GG_HDD_OS_Army)) return m_Config.OSData.ArmySpeed;
		if (osDrive.IsInherited(GG_HDD_OS_Police)) return m_Config.OSData.PoliceSpeed;
		return m_Config.OSData.NormalSpeed;
	}

	static void SpawnPCParts(ItemBase targetObj, string areaType)
	{
		if (!GetGame().IsServer() || !m_Config) return;
		PC_DriveSettings driveSet = GetDriveSettings(areaType);
		if (!driveSet) return;

		if (m_Config.OnlyOnePartPerCheck)
		{
			// LOGIC FOR ONLY ONE DROP
			array<string> possibleDrops = new array<string>;
			
			// Fill potential list based on chances
			if (Math.RandomInt(0, 100) < driveSet.ChanceHDD) possibleDrops.Insert("GG_HDD_" + areaType);
			if (Math.RandomInt(0, 100) < driveSet.ChanceRAM) possibleDrops.Insert("GG_RAM");
			if (Math.RandomInt(0, 100) < driveSet.ChanceCPU) possibleDrops.Insert("GG_CPU");
			if (Math.RandomInt(0, 100) < driveSet.ChanceMBoard) possibleDrops.Insert("GG_MBOARD");
			
			string osClass = GetOSClassname(areaType);
			if (Math.RandomInt(0, 100) < driveSet.ChanceHDD_OS) possibleDrops.Insert(osClass);

			// Special HDD rare drops
			if (areaType == "Quest" && Math.RandomInt(0, 100) < m_Config.DrivesData.ChanceQuestHDD) possibleDrops.Insert("GG_HDD_Quest");
			if (areaType == "Legacy" && Math.RandomInt(0, 100) < m_Config.DrivesData.ChanceLegacyHDD) possibleDrops.Insert("GG_HDD_Legacy");

			if (possibleDrops.Count() > 0)
			{
				string picked = possibleDrops.GetRandomElement();
				CheckAndSpawn(targetObj, picked, 100); // 100% since it was already rolled
			}
		}
		else
		{
			// ORIGINAL MULTI-DROP LOGIC
			CheckAndSpawn(targetObj, "GG_HDD_" + areaType, driveSet.ChanceHDD);
			CheckAndSpawn(targetObj, "GG_RAM", driveSet.ChanceRAM);
			CheckAndSpawn(targetObj, "GG_CPU", driveSet.ChanceCPU);
			CheckAndSpawn(targetObj, "GG_MBOARD", driveSet.ChanceMBoard);
			CheckAndSpawn(targetObj, GetOSClassname(areaType), driveSet.ChanceHDD_OS);

			if (areaType == "Quest" && m_Config.DrivesData.ChanceQuestHDD > 0)
				CheckAndSpawn(targetObj, "GG_HDD_Quest", m_Config.DrivesData.ChanceQuestHDD);
			
			if (areaType == "Legacy" && m_Config.DrivesData.ChanceLegacyHDD > 0)
				CheckAndSpawn(targetObj, "GG_HDD_Legacy", m_Config.DrivesData.ChanceLegacyHDD);
		}
	}

	static void SpawnStashLoot(ItemBase targetObj, string areaType)
	{
		if (!GetGame().IsServer() || !m_Config) return;

		array<ref PC_LootSet> activeSets;
		if (areaType == "City") activeSets = m_Config.LootSetsCity;
		else if (areaType == "Police") activeSets = m_Config.LootSetsPolice;
		else if (areaType == "Army") activeSets = m_Config.LootSetsArmy;
		else if (areaType == "Quest") activeSets = m_Config.LootSetsQuest;
		else if (areaType == "Legacy") activeSets = m_Config.LootSetsLegacy;

		// 1. Select exactly ONE set from the available sets for this tier
		if (activeSets && activeSets.Count() > 0)
		{
			PC_LootSet selectedSet = activeSets.GetRandomElement();
			if (selectedSet && selectedSet.Items)
			{
				foreach (PC_LootPreset lootPreset : selectedSet.Items)
				{
					if (Math.RandomInt(0, 100) < lootPreset.Chance)
					{
						SpawnPresetItem(targetObj.GetPosition(), lootPreset);
					}
				}
			}
		}

		// 2. PC parts removed (no longer a reward for digging)
	}

	static void SpawnPresetItem(vector spawnAt, PC_LootPreset presetInfo)
	{
		EntityAI spawnedItem = EntityAI.Cast(GetGame().CreateObjectEx(presetInfo.Classname, spawnAt, ECE_PLACE_ON_SURFACE));
		if (!spawnedItem) return;

		spawnedItem.SetHealth01("", "", Math.RandomInt(presetInfo.HealthMin, presetInfo.HealthMax) / 100.0);

		ItemBase itemBase = ItemBase.Cast(spawnedItem);
		if (itemBase && itemBase.HasQuantity())
		{
			itemBase.SetQuantity(itemBase.GetQuantityMax() * (Math.RandomInt(presetInfo.QuantityMin, presetInfo.QuantityMax) / 100.0));
		}

		foreach (PC_AttachmentData attInfo : presetInfo.Attachments)
		{
			if (attInfo.AttClassname != "" && Math.RandomInt(0, 100) < attInfo.AttChance)
			{
				EntityAI attObj = spawnedItem.GetInventory().CreateAttachment(attInfo.AttClassname);
				if (attObj)
				{
					attObj.SetHealth01("", "", Math.RandomInt(attInfo.AttHealthMin, attInfo.AttHealthMax) / 100.0);
					ItemBase attBase = ItemBase.Cast(attObj);
					if (attBase && attBase.HasQuantity())
					{
						attBase.SetQuantity(attBase.GetQuantityMax() * (Math.RandomInt(attInfo.AttQuantityMin, attInfo.AttQuantityMax) / 100.0));
					}
				}
			}
		}
	}

	static void CheckAndSpawn(ItemBase source, string cName, int spawnChance)
	{
		if (Math.RandomInt(0, 100) < spawnChance)
		{
			ItemBase createdItem = ItemBase.Cast(GetGame().CreateObjectEx(cName, source.GetPosition(), ECE_PLACE_ON_SURFACE));
			if (createdItem && createdItem.IsInherited(GG_HDD) && !createdItem.IsInherited(GG_HDD_OS))
			{
				GG_HDD drive = GG_HDD.Cast(createdItem);
				if (m_Config && m_Config.CoordinatesData && m_Config.CoordinatesData.Count() > 0)
				{
					PC_CoordinatesData picked = m_Config.CoordinatesData.GetRandomElement();
					if (picked.Coordinates != "0 0 0") 
					{
						drive.SetStashPos(picked.Coordinates);
						Print("[PCserver] Drive Created. Assigned Stash Position: " + picked.Coordinates);
					}
				}
			}
		}
	}
};
