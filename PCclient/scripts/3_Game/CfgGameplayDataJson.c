
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

	
	void InitServer()
	{
		radiusCity_1 = GetGame().ServerConfigGetInt( "radiusCity_1" );
		radiusCity_2 = GetGame().ServerConfigGetInt( "radiusCity_2" );
		radiusCity_3 = GetGame().ServerConfigGetInt( "radiusCity_3" );
		radiusCity_4 = GetGame().ServerConfigGetInt( "radiusCity_4" );
		radiusCity_5 = GetGame().ServerConfigGetInt( "radiusCity_5" );
		radiusCity_6 = GetGame().ServerConfigGetInt( "radiusCity_6" );
		radiusCity_7 = GetGame().ServerConfigGetInt( "radiusCity_7" );
		radiusCity_8 = GetGame().ServerConfigGetInt( "radiusCity_8" );
		radiusCity_9 = GetGame().ServerConfigGetInt( "radiusCity_9" );
		radiusCity_10 = GetGame().ServerConfigGetInt( "radiusCity_10" );
		
		radiusPolice_1 = GetGame().ServerConfigGetInt( "radiusPolice_1" );
		radiusPolice_2 = GetGame().ServerConfigGetInt( "radiusPolice_2" );
		radiusPolice_3 = GetGame().ServerConfigGetInt( "radiusPolice_3" );
		radiusPolice_4 = GetGame().ServerConfigGetInt( "radiusPolice_4" );
		radiusPolice_5 = GetGame().ServerConfigGetInt( "radiusPolice_5" );
		radiusPolice_6 = GetGame().ServerConfigGetInt( "radiusPolice_6" );
		radiusPolice_7 = GetGame().ServerConfigGetInt( "radiusPolice_7" );
		radiusPolice_8 = GetGame().ServerConfigGetInt( "radiusPolice_8" );
		radiusPolice_9 = GetGame().ServerConfigGetInt( "radiusPolice_9" );
		radiusPolice_10 = GetGame().ServerConfigGetInt( "radiusPolice_10" );
		
		radiusArmy_1 = GetGame().ServerConfigGetInt( "radiusArmy_1" );
		radiusArmy_2 = GetGame().ServerConfigGetInt( "radiusArmy_2" );
		radiusArmy_3 = GetGame().ServerConfigGetInt( "radiusArmy_3" );
		radiusArmy_4 = GetGame().ServerConfigGetInt( "radiusArmy_4" );
		radiusArmy_5 = GetGame().ServerConfigGetInt( "radiusArmy_5" );
		radiusArmy_6 = GetGame().ServerConfigGetInt( "radiusArmy_6" );
		radiusArmy_7 = GetGame().ServerConfigGetInt( "radiusArmy_7" );
		radiusArmy_8 = GetGame().ServerConfigGetInt( "radiusArmy_8" );
		radiusArmy_9 = GetGame().ServerConfigGetInt( "radiusArmy_9" );
		radiusArmy_10 = GetGame().ServerConfigGetInt( "radiusArmy_10" );
		
		hackcity = GetGame().ServerConfigGetInt( "hackcity" );
		hackpolice = GetGame().ServerConfigGetInt( "hackpolice" );
		hackarmy = GetGame().ServerConfigGetInt( "hackarmy" );
		
		damagecpu = GetGame().ServerConfigGetInt( "damagecpu" );
		damagemboard = GetGame().ServerConfigGetInt( "damagemboard" );
		damageram = GetGame().ServerConfigGetInt( "damageram" );
		damagehdd_os = GetGame().ServerConfigGetInt( "damagehdd_os" );
		
		timercity = GetGame().ServerConfigGetInt( "timercity" );
		timerpolice = GetGame().ServerConfigGetInt( "timerpolice" );
		timerarmy = GetGame().ServerConfigGetInt( "timerarmy" );
		
		damagetool = GetGame().ServerConfigGetInt( "damagetool" );
		
		rndhddpolice = GetGame().ServerConfigGetInt( "rndhddpolice" );
		rndrampolice = GetGame().ServerConfigGetInt( "rndrampolice" );
		rndhddospolice = GetGame().ServerConfigGetInt( "rndhddospolice" );
		rndmboardpolice = GetGame().ServerConfigGetInt( "rndmboardpolice" );
		rndcpupolice = GetGame().ServerConfigGetInt( "rndcpupolice" );
		
		rndhddcity = GetGame().ServerConfigGetInt( "rndhddcity" );
		rndramcity = GetGame().ServerConfigGetInt( "rndramcity" );
		rndhddoscity = GetGame().ServerConfigGetInt( "rndhddoscity" );
		rndmboardcity = GetGame().ServerConfigGetInt( "rndmboardcity" );
		rndcpucity = GetGame().ServerConfigGetInt( "rndcpucity" );
		
		rndhddarmy = GetGame().ServerConfigGetInt( "rndhddarmy" );
		rndramarmy = GetGame().ServerConfigGetInt( "rndramarmy" );
		rndhddosarmy = GetGame().ServerConfigGetInt( "rndhddosarmy" );
		rndmboardarmy = GetGame().ServerConfigGetInt( "rndmboardarmy" );
		rndcpuarmy = GetGame().ServerConfigGetInt( "rndcpuarmy" );
		
		
		
		radiusCity = GetGame().ServerConfigGetInt( "radiusCity" );
		
		
		
		posCity.Insert(Vector(0, 0, 0));
		posPolice.Insert(Vector(0, 0, 0));
		posArmy.Insert(Vector(0, 0, 0));
		
		
		LootCity_1.Insert("");
		LootCity_2.Insert("");
		LootCity_3.Insert("");
		LootCity_4.Insert("");
		LootCity_5.Insert("");
		LootCity_6.Insert("");
		LootCity_7.Insert("");
		LootCity_8.Insert("");
		LootCity_9.Insert("");
		LootCity_10.Insert("");
		
		LootPolice_1.Insert("");
		LootPolice_2.Insert("");
		LootPolice_3.Insert("");
		LootPolice_4.Insert("");
		LootPolice_5.Insert("");
		LootPolice_6.Insert("");
		LootPolice_7.Insert("");
		LootPolice_8.Insert("");
		LootPolice_9.Insert("");
		LootPolice_10.Insert("");
		
		LootArmy_1.Insert("");
		LootArmy_2.Insert("");
		LootArmy_3.Insert("");
		LootArmy_4.Insert("");
		LootArmy_5.Insert("");
		LootArmy_6.Insert("");
		LootArmy_7.Insert("");
		LootArmy_8.Insert("");
		LootArmy_9.Insert("");
		LootArmy_10.Insert("");
		
	}
	float radiusCity;

	ref array<vector> posCity;
	ref array<vector> posPolice;
	ref array<vector> posArmy;
	
	ref array<string> LootCity_1;
	ref array<string> LootCity_2;
	ref array<string> LootCity_3;
	ref array<string> LootCity_4;
	ref array<string> LootCity_5;
	ref array<string> LootCity_6;
	ref array<string> LootCity_7;
	ref array<string> LootCity_8;
	ref array<string> LootCity_9;
	ref array<string> LootCity_10;
	
	ref array<string> LootPolice_1;
	ref array<string> LootPolice_2;
	ref array<string> LootPolice_3;
	ref array<string> LootPolice_4;
	ref array<string> LootPolice_5;
	ref array<string> LootPolice_6;
	ref array<string> LootPolice_7;
	ref array<string> LootPolice_8;
	ref array<string> LootPolice_9;
	ref array<string> LootPolice_10;
	
	ref array<string> LootArmy_1;
	ref array<string> LootArmy_2;
	ref array<string> LootArmy_3;
	ref array<string> LootArmy_4;
	ref array<string> LootArmy_5;
	ref array<string> LootArmy_6;
	ref array<string> LootArmy_7;
	ref array<string> LootArmy_8;
	ref array<string> LootArmy_9;
	ref array<string> LootArmy_10;
	
	
	int radiusCity_1; int radiusCity_2; int radiusCity_3; int radiusCity_4; int radiusCity_5; int radiusCity_6; int radiusCity_7; int radiusCity_8; int radiusCity_9; int radiusCity_10; 
	int radiusPolice_1; int radiusPolice_2; int radiusPolice_3; int radiusPolice_4; int radiusPolice_5; int radiusPolice_6; int radiusPolice_7; int radiusPolice_8; int radiusPolice_9; int radiusPolice_10;
	int radiusArmy_1; int radiusArmy_2; int radiusArmy_3; int radiusArmy_4; int radiusArmy_5; int radiusArmy_6; int radiusArmy_7; int radiusArmy_8; int radiusArmy_9; int radiusArmy_10;
	
	int ChanceZMB_Food;
	
	int coord_min; int coord_max;
	
	int hackcity; int hackpolice; int hackarmy;
	
	int damagecpu; int damagemboard; int damageram; int damagehdd_os;
	
	int timercity; int timerpolice; int timerarmy;
	
	int damagetool; 
	
	int rndhddpolice; int rndrampolice; int rndhddospolice; int rndmboardpolice; int rndcpupolice;
	
	int rndhddcity; int rndramcity; int rndhddoscity; int rndmboardcity; int rndcpucity;
	
	int rndhddarmy; int rndramarmy; int rndhddosarmy; int rndmboardarmy; int rndcpuarmy;

};
