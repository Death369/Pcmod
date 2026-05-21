class PCSpawnHelper
{
	static void SpawnStashAt(vector center, string type)
	{
		CfgPcServerConfig m_PcConfig = PCLootHelper.m_Config;
		if (!m_PcConfig) return;

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

		vector spawnPos = GetRandomPointInRadius(center, radius, addRadius);
		
		string className = "UndergroundCity";
		if (type == "Police") className = "UndergroundPolice";
		else if (type == "Army") className = "UndergroundArmy";
		else if (type == "Quest") className = "UndergroundQuest";
		else if (type == "Legacy") className = "UndergroundLegacy";

		GetGame().CreateObjectEx(className, spawnPos, ECE_PLACE_ON_SURFACE);
		Print("[PCserver] Spawned " + className + " at " + spawnPos + " for finished hack.");
	}

	static vector GetRandomPointInRadius(vector center, float radius, float additionalRadius)
	{
		for (int i = 0; i < 20; i++)
		{
			float angle = Math.RandomFloat(0, Math.PI * 2);
			float dist = Math.RandomFloat(0, radius);
			vector pos = center;
			pos[0] = pos[0] + (Math.Cos(angle) * dist);
			pos[2] = pos[2] + (Math.Sin(angle) * dist);
			pos[1] = GetGame().SurfaceY(pos[0], pos[2]);

			array<Object> objects = new array<Object>;
			GetGame().GetObjectsAtPosition(pos, additionalRadius, objects, null);
			bool collision = false;
			foreach (Object obj : objects)
			{
				if (obj.IsInherited(House) || obj.IsInherited(RockBase) || obj.IsInherited(TreeHard) || obj.IsInherited(Building)) { collision = true; break; }
			}
			if (!collision) return pos;
		}
		return center;
	}
}
