modded class MissionServer
{
	ref CfgPcServerConfig m_PcConfig;
	static MissionServer m_Instance;

	void MissionServer()
	{
		m_Instance = this;
	}

	override void OnInit()
	{
		super.OnInit();

		Print("--------------------------------------------------");
		Print("[PCserver] PCserver Logic Initialized Successfully");
		Print("--------------------------------------------------");

		m_PcConfig = CfgPcServerConfig.Load();
		PCLootHelper.Init(m_PcConfig);

		SpawnStaticPCWorldObjects();
	}

	void SpawnStaticPCWorldObjects()
	{
		if (!m_PcConfig || !m_PcConfig.StaticComputerData) return;

		Print("[PCserver] Spawning Manual Static Computers from Config...");
		foreach (PC_StaticObjectData objData : m_PcConfig.StaticComputerData)
		{
			if (objData.Coordinates == "0 0 0") continue;

			// Spawn with persistence (removed | 2)
			Object obj = GetGame().CreateObjectEx(objData.Classname, objData.Coordinates, ECE_PLACE_ON_SURFACE);
			if (obj)
			{
				obj.SetOrientation(objData.Orientation);
				Print("[PCserver] Spawned Manual: " + objData.Classname + " at " + objData.Coordinates);
			}
		}
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		CfgPcconfigHandler.SyncDataSend(player);
	}

	CfgPcServerConfig GetConfig() { return m_PcConfig; }

	void SpawnStashAt(vector center, string type)
	{
		float radius = 5;
		float addRadius = 2;
		
		foreach (PC_CoordinatesData cd : m_PcConfig.CoordinatesData)
		{
			if (vector.Distance(cd.Coordinates, center) < 1.0)
			{
				radius = cd.Radius;
				addRadius = cd.AdditionalRadius;
				break;
			}
		}

		vector spawnPos = PCSpawnHelper.GetRandomPointInRadius(center, radius, addRadius);
		
		string className = "UndergroundCity";
		if (type == "Police") className = "UndergroundPolice";
		else if (type == "Army") className = "UndergroundArmy";
		else if (type == "Quest") className = "UndergroundQuest";
		else if (type == "Legacy") className = "UndergroundLegacy";

		GetGame().CreateObjectEx(className, spawnPos, ECE_PLACE_ON_SURFACE);
		Print("[PCserver] Spawned " + className + " at " + spawnPos + " for finished hack.");
	}
};
