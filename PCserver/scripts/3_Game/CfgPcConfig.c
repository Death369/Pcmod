class CfgPcServerConfig
{
	float GlobalDamageMultiplier; 
	bool OnlyOnePartPerCheck; // If true, only one item will drop per screwdriver action
	ref PC_ToolData ToolData;
	ref PC_DrivesData DrivesData;
	ref PC_OSData OSData;
	ref PC_RepairData RepairData;
	ref array<ref PC_CoordinatesData> CoordinatesData;
	
	ref array<ref PC_LootSet> LootSetsCity;
	ref array<ref PC_LootSet> LootSetsPolice;
	ref array<ref PC_LootSet> LootSetsArmy;
	ref array<ref PC_LootSet> LootSetsQuest;
	ref array<ref PC_LootSet> LootSetsLegacy;

	ref array<ref PC_StaticObjectData> StaticComputerData;

	void CfgPcServerConfig()
	{
		ToolData = new PC_ToolData();
		DrivesData = new PC_DrivesData();
		OSData = new PC_OSData();
		RepairData = new PC_RepairData();
		GlobalDamageMultiplier = 1.0;
		OnlyOnePartPerCheck = false;
		CoordinatesData = new array<ref PC_CoordinatesData>;
		LootSetsCity = new array<ref PC_LootSet>;
		LootSetsPolice = new array<ref PC_LootSet>;
		LootSetsArmy = new array<ref PC_LootSet>;
		LootSetsQuest = new array<ref PC_LootSet>;
		LootSetsLegacy = new array<ref PC_LootSet>;
		StaticComputerData = new array<ref PC_StaticObjectData>;
	}

	static ref CfgPcServerConfig Load()
	{
		string folder = "$profile:PCmod\\";
		string path = folder + "config.json";
		CfgPcServerConfig config = new CfgPcServerConfig();

		if (!FileExist(folder)) MakeDirectory(folder);

		if (FileExist(path))
		{
			JsonFileLoader<CfgPcServerConfig>.JsonLoadFile(path, config);
		}
		else
		{
			config.Defaults();
			config.Save();
		}
		return config;
	}

	void Save()
	{
		string folder = "$profile:PCmod\\";
		if (!FileExist(folder)) MakeDirectory(folder);
		JsonFileLoader<CfgPcServerConfig>.JsonSaveFile(folder + "config.json", this);
	}

	void Defaults()
	{
		// --- BALANCED PLAY CONFIGURATION ---
		GlobalDamageMultiplier = 1.0; 
		OnlyOnePartPerCheck = false;
		ToolData.ToolDamageShovel = 15; 
		ToolData.ToolDamageScrew = 8;

		// Parameters: dCPU, dMB, dRAM, dHDD, dCase, dMs, dKbd, dMon, hackTime(sec), restockTime(min), spawn chances...
		DrivesData.CityDriveData.Defaults(0.5, 0.5, 0.5, 0.5, 0.2, 0.1, 0.1, 0.1, 600, 60, 40, 40, 40, 30, 20);
		DrivesData.PoliceDriveData.Defaults(0.8, 0.8, 0.8, 0.8, 0.4, 0.2, 0.2, 0.2, 1200, 120, 35, 35, 35, 25, 15);
		DrivesData.ArmyDriveData.Defaults(1.5, 1.5, 1.5, 1.5, 0.8, 0.4, 0.4, 0.4, 1800, 180, 30, 30, 30, 20, 10);
		DrivesData.QuestDriveData.Defaults(2.5, 2.5, 2.5, 2.5, 1.2, 0.6, 0.6, 0.6, 2700, 240, 15, 15, 15, 10, 5);
		DrivesData.LegacyDriveData.Defaults(4.0, 4.0, 4.0, 4.0, 2.0, 1.0, 1.0, 1.0, 3600, 300, 10, 10, 10, 5, 2);

		DrivesData.ChanceQuestHDD = 5;
		DrivesData.ChanceLegacyHDD = 2;

		OSData.NormalSpeed = 1.0;
		OSData.PoliceSpeed = 1.5; 
		OSData.ArmySpeed = 2.0;  
		OSData.ChanceOSPolice = 5;
		OSData.ChanceOSArmy = 2;

		// 1. Realistic Coordinates (Chernarus Example)
		AddCoord("6500 0 2500", 100, 50);   // Cherno Area
		AddCoord("4500 0 10300", 100, 50);  // NWAF Area
		AddCoord("1500 0 14000", 100, 50);  // Tisy Area
		AddCoord("12000 0 9000", 100, 50);  // Berezino Area
		AddCoord("2500 0 5000", 100, 50);   // Zelenogorsk Area

		// 2. Loot Sets
		PC_LootSet citySet1 = new PC_LootSet("Urban Survivalist");
		citySet1.Items.Insert(CreatePreset("PeachesCan", 100, 100));
		citySet1.Items.Insert(CreatePreset("SodaCan_Pipsi", 100, 100));
		LootSetsCity.Insert(citySet1);

		PC_LootSet polSet1 = new PC_LootSet("Patrol Unit");
		polSet1.Items.Insert(CreatePreset("PoliceJacket", 100, 100));
		polSet1.Items.Insert(CreatePreset("Glock19", 100, 100));
		LootSetsPolice.Insert(polSet1);

		PC_LootSet armSet1 = new PC_LootSet("Assault Kit");
		armSet1.Items.Insert(CreatePreset("M4A1", 100, 100));
		armSet1.Items.Insert(CreatePreset("PlateCarrierVest", 100, 100));
		LootSetsArmy.Insert(armSet1);

		PC_LootSet qstSet1 = new PC_LootSet("Spec-Ops Night");
		qstSet1.Items.Insert(CreatePreset("NVGoggles", 100, 100));
		qstSet1.Items.Insert(CreatePreset("FAL", 100, 100));
		LootSetsQuest.Insert(qstSet1);

		PC_LootSet legSet1 = new PC_LootSet("Legacy Spetsnaz");
		legSet1.Items.Insert(CreatePreset("ASVAL", 100, 100));
		legSet1.Items.Insert(CreatePreset("VSS", 100, 100));
		LootSetsLegacy.Insert(legSet1);

				// --- REPAIR SETTINGS ---
		RepairData.CanRepairCase = true;
		RepairData.RepairToolCase = "EpoxyPutty";
		RepairData.CanRepairMouse = true;
		RepairData.RepairToolMouse = "ElectronicRepairKit";
		RepairData.CanRepairKeyboard = true;
		RepairData.RepairToolKeyboard = "ElectronicRepairKit";
		RepairData.CanRepairMonitor = true;
		RepairData.RepairToolMonitor = "ElectronicRepairKit";

		// --- STATIC COMPUTER SPAWNS (Examples) ---
		AddPC("GG_compukter", "6500 6.2 2500", "0 0 0");        // City Office
		AddPC("GG_compukter_police", "10500 10.5 2300", "0 0 0"); // Police Station
		AddPC("GG_compukter_army", "4500 15.2 10300", "0 0 0");   // NWAF Barracks
		AddPC("GG_compukter_rare", "1500 20.0 14000", "0 0 0");   // Tisy Secret Lab
		AddPC("GG_compukter_ancient", "13479 6.2 4467", "0 0 0"); // Your Test Spot
	}

	void AddCoord(vector pos, int rad, int addRad)
	{
		PC_CoordinatesData cd = new PC_CoordinatesData();
		cd.Coordinates = pos; cd.Radius = rad; cd.AdditionalRadius = addRad;
		CoordinatesData.Insert(cd);
	}

	void AddPC(string cName, vector pos, vector orient)
	{
		PC_StaticObjectData pc = new PC_StaticObjectData();
		pc.Classname = cName; pc.Coordinates = pos; pc.Orientation = orient;
		StaticComputerData.Insert(pc);
	}

	PC_LootPreset CreatePreset(string name, int chance, int health)
	{
		PC_LootPreset p = new PC_LootPreset();
		p.Classname = name; p.Chance = chance; p.HealthMin = health; p.HealthMax = health;
		p.QuantityMin = 100; p.QuantityMax = 100;
		return p;
	}
};

class PC_ToolData { int ToolDamageShovel; int ToolDamageScrew; };

class PC_OSData
{
	float NormalSpeed;
	float PoliceSpeed;
	float ArmySpeed;
	int ChanceOSPolice;
	int ChanceOSArmy;
};

class PC_DriveSettings
{
	float DamageCPU; float DamageMBoard; float DamageRAM; float DamageHDD_OS; float DamageCase;
	float DamageMouse; float DamageKeyboard; float DamageMonitor;
	int HackTime; int RestockTime;
	int ChanceMBoard; int ChanceCPU; int ChanceRAM; int ChanceHDD; int ChanceHDD_OS;

	void Defaults(float dCPU, float dMB, float dRAM, float dHDD, float dCase, float dMs, float dKbd, float dMon, int hTime, int rTime, int cMB, int cCPU, int cRAM, int cHDD, int cHDD_OS)
	{
		DamageCPU = dCPU; DamageMBoard = dMB; DamageRAM = dRAM; DamageHDD_OS = dHDD; DamageCase = dCase;
		DamageMouse = dMs; DamageKeyboard = dKbd; DamageMonitor = dMon;
		HackTime = hTime; RestockTime = rTime;
		ChanceMBoard = cMB; ChanceCPU = cCPU; ChanceRAM = cRAM; ChanceHDD = cHDD; ChanceHDD_OS = cHDD_OS;
	}
};

class PC_DrivesData
{
	ref PC_DriveSettings CityDriveData;
	ref PC_DriveSettings PoliceDriveData;
	ref PC_DriveSettings ArmyDriveData;
	ref PC_DriveSettings QuestDriveData;
	ref PC_DriveSettings LegacyDriveData;
	int ChanceQuestHDD;
	int ChanceLegacyHDD;

	void PC_DrivesData() { 
		CityDriveData = new PC_DriveSettings(); 
		PoliceDriveData = new PC_DriveSettings(); 
		ArmyDriveData = new PC_DriveSettings(); 
		QuestDriveData = new PC_DriveSettings(); 
		LegacyDriveData = new PC_DriveSettings(); 
	}
};

class PC_CoordinatesData { vector Coordinates; int Radius; int AdditionalRadius; };
class PC_AttachmentData { string AttClassname; int AttHealthMin; int AttHealthMax; int AttQuantityMin; int AttQuantityMax; int AttChance; };

class PC_LootPreset
{
	string Classname;
	int HealthMin; int HealthMax;
	int QuantityMin; int QuantityMax;
	int Chance;
	ref array<ref PC_AttachmentData> Attachments;
	void PC_LootPreset() { Attachments = new array<ref PC_AttachmentData>; }
};

class PC_LootSet
{
	string SetName;
	ref array<ref PC_LootPreset> Items;
	void PC_LootSet(string n = "") { SetName = n; Items = new array<ref PC_LootPreset>; }
};

class PC_StaticObjectData { string Classname; vector Coordinates; vector Orientation; };
class PC_RepairData
{
	bool CanRepairCase; string RepairToolCase;
	bool CanRepairMouse; string RepairToolMouse;
	bool CanRepairKeyboard; string RepairToolKeyboard;
	bool CanRepairMonitor; string RepairToolMonitor;
};
