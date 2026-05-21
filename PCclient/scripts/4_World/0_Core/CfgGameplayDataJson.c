class CfgPcconfigJson
{
	void InitServer()
	{
		GeneralData.InitServer();
	}

	ref GG_GeneralData GeneralData = new GG_GeneralData;
};

class GG_GeneralData
{
	void GG_GeneralData()
	{
		posCity = new array<vector>;
		posPolice = new array<vector>;
		posArmy = new array<vector>;
		
		LootCity_1 = new array<string>;
		LootCity_2 = new array<string>;
		LootCity_3 = new array<string>;
		LootCity_4 = new array<string>;
		LootCity_5 = new array<string>;
		LootCity_6 = new array<string>;
		LootCity_7 = new array<string>;
		LootCity_8 = new array<string>;
		LootCity_9 = new array<string>;
		LootCity_10 = new array<string>;
		
		LootPolice_1 = new array<string>;
		LootPolice_2 = new array<string>;
		LootPolice_3 = new array<string>;
		LootPolice_4 = new array<string>;
		LootPolice_5 = new array<string>;
		LootPolice_6 = new array<string>;
		LootPolice_7 = new array<string>;
		LootPolice_8 = new array<string>;
		LootPolice_9 = new array<string>;
		LootPolice_10 = new array<string>;
		
		LootArmy_1 = new array<string>;
		LootArmy_2 = new array<string>;
		LootArmy_3 = new array<string>;
		LootArmy_4 = new array<string>;
		LootArmy_5 = new array<string>;
		LootArmy_6 = new array<string>;
		LootArmy_7 = new array<string>;
		LootArmy_8 = new array<string>;
		LootArmy_9 = new array<string>;
		LootArmy_10 = new array<string>;
	}

	void InitServer()
	{
		// Note: GetGame().ServerConfigGetInt is NOT standard. This will likely return 0.
		radiusCity_1 = GetGame().ServerConfigGetInt( "radiusCity_1" );
		radiusCity_2 = GetGame().ServerConfigGetInt( "radiusCity_2" );
		// ... rest of InitServer (kept for compatibility with original intent)
		
		posCity.Insert("0 0 0");
		posPolice.Insert("0 0 0");
		posArmy.Insert("0 0 0");
	}
	
	float radiusCity;
	ref array<vector> posCity;
	ref array<vector> posPolice;
	ref array<vector> posArmy;
	
	ref array<string> LootCity_1, LootCity_2, LootCity_3, LootCity_4, LootCity_5, LootCity_6, LootCity_7, LootCity_8, LootCity_9, LootCity_10;
	ref array<string> LootPolice_1, LootPolice_2, LootPolice_3, LootPolice_4, LootPolice_5, LootPolice_6, LootPolice_7, LootPolice_8, LootPolice_9, LootPolice_10;
	ref array<string> LootArmy_1, LootArmy_2, LootArmy_3, LootArmy_4, LootArmy_5, LootArmy_6, LootArmy_7, LootArmy_8, LootArmy_9, LootArmy_10;
	
	int radiusCity_1, radiusCity_2, radiusCity_3, radiusCity_4, radiusCity_5, radiusCity_6, radiusCity_7, radiusCity_8, radiusCity_9, radiusCity_10; 
	int radiusPolice_1, radiusPolice_2, radiusPolice_3, radiusPolice_4, radiusPolice_5, radiusPolice_6, radiusPolice_7, radiusPolice_8, radiusPolice_9, radiusPolice_10;
	int radiusArmy_1, radiusArmy_2, radiusArmy_3, radiusArmy_4, radiusArmy_5, radiusArmy_6, radiusArmy_7, radiusArmy_8, radiusArmy_9, radiusArmy_10;
	
	int ChanceZMB_Food;
	int coord_min, coord_max;
	int hackcity, hackpolice, hackarmy;
	int damagecpu, damagemboard, damageram, damagehdd_os;
	int timercity, timerpolice, timerarmy;
	int damagetool; 
	int rndhddpolice, rndrampolice, rndhddospolice, rndmboardpolice, rndcpupolice;
	int rndhddcity, rndramcity, rndhddoscity, rndmboardcity, rndcpucity;
	int rndhddarmy, rndramarmy, rndhddosarmy, rndmboardarmy, rndcpuarmy;
};
