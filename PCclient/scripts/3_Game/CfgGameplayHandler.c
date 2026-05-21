class CfgPcconfigHandler
{
	private static string m_Path = "$mission:cfgpcconfig.json";
	
	static ref CfgPcconfigJson m_Data = new CfgPcconfigJson;
	//---------------------------------------------------------------------------------------
	static bool LoadData()
	{
		if ( !FileExist( m_Path ) )
		{
			m_Path = "";
			GetGame().GetWorldName( m_Path );
			m_Path = string.Format("DZ/worlds/%1/ce/cfgpcconfig.json", m_Path );
		}
		
		
		JsonFileLoader<CfgPcconfigJson>.JsonLoadFile( m_Path, m_Data );//we are allowed to read the file, so we replace the default data with data from json
		//OnLoaded();
		return true;
	}
	
	//---------------------------------------------------------------------------------------
	static void OnLoaded()
	{
		GetGame().GetMission().OnGameplayDataHandlerLoad();
		DayZGame.Cast(GetGame()).OnGameplayDataHandlerLoad();
		ObjectSpawnerHandler.OnGameplayDataHandlerLoad();
	}
	
	//---------------------------------------------------------------------------------------
	static void SyncDataSend(notnull Man player)
	{
		GetGame().RPCSingleParam(player, 36901, new Param1<CfgPcconfigJson>(m_Data), true, player.GetIdentity());
	}
	
	//---------------------------------------------------------------------------------------
	
	static void OnRPC(Man player, ParamsReadContext ctx)
	{
		Param1<CfgPcconfigJson> data = new Param1<CfgPcconfigJson>(null);
		
		if ( ctx.Read(data) )
			m_Data = data.param1;
		else
			ErrorEx("datasynced - failed to read");
		
		player.OnGameplayDataHandlerSync();
	}


	static int Gethackcity() { return m_Data.GeneralData.hackcity; }
	static int Gethackpolice() { return m_Data.GeneralData.hackpolice; }
	static int Gethackarmy() { return m_Data.GeneralData.hackarmy; }
	
	
	
	static int Getdamagecpu() { return m_Data.GeneralData.damagecpu; }
	static int Getdamagemboard() { return m_Data.GeneralData.damagemboard; }
	static int Getdamageram() { return m_Data.GeneralData.damageram; }
	static int Getdamagehdd_os() { return m_Data.GeneralData.damagehdd_os; }
	
	
	static int Gettimercity() { return m_Data.GeneralData.timercity; }
	static int Gettimerpolice() { return m_Data.GeneralData.timerpolice; }
	static int Gettimerarmy() { return m_Data.GeneralData.timerarmy; }
	
	
	static int Getdamagetool() { return m_Data.GeneralData.damagetool; }
	
	
	static int Getrndhddpolice() { return m_Data.GeneralData.rndhddpolice; }
	static int Getrndrampolice() { return m_Data.GeneralData.rndrampolice; }
	static int Getrndhddospolice() { return m_Data.GeneralData.rndhddospolice; }
	static int Getrndmboardpolice() { return m_Data.GeneralData.rndmboardpolice; }
	static int Getrndcpupolice() { return m_Data.GeneralData.rndcpupolice; }
	
	
	static int Getrndhddcity() { return m_Data.GeneralData.rndhddcity; }
	static int Getrndramcity() { return m_Data.GeneralData.rndramcity; }
	static int Getrndhddoscity() { return m_Data.GeneralData.rndhddoscity; }
	static int Getrndmboardcity() { return m_Data.GeneralData.rndmboardcity; }
	static int Getrndcpucity() { return m_Data.GeneralData.rndcpucity; }
		
	
	static int Getrndhddarmy() { return m_Data.GeneralData.rndhddarmy; }
	static int Getrndramarmy() { return m_Data.GeneralData.rndramarmy; }
	static int Getrndhddosarmy() { return m_Data.GeneralData.rndhddosarmy; }
	static int Getrndmboardarmy() { return m_Data.GeneralData.rndmboardarmy; }
	static int Getrndcpuarmy() { return m_Data.GeneralData.rndcpuarmy; }
	
	
	
	static int GetradiusCity_1() { return m_Data.GeneralData.radiusCity_1; }
	static int GetradiusCity_2() { return m_Data.GeneralData.radiusCity_2; }
	static int GetradiusCity_3() { return m_Data.GeneralData.radiusCity_3; }
	static int GetradiusCity_4() { return m_Data.GeneralData.radiusCity_4; }
	static int GetradiusCity_5() { return m_Data.GeneralData.radiusCity_5; }
	static int GetradiusCity_6() { return m_Data.GeneralData.radiusCity_6; }
	static int GetradiusCity_7() { return m_Data.GeneralData.radiusCity_7; }
	static int GetradiusCity_8() { return m_Data.GeneralData.radiusCity_8; }
	static int GetradiusCity_9() { return m_Data.GeneralData.radiusCity_9; }
	static int GetradiusCity_10() { return m_Data.GeneralData.radiusCity_10; }
		
		
	static int GetradiusPolice_1() { return m_Data.GeneralData.radiusPolice_1; }
	static int GetradiusPolice_2() { return m_Data.GeneralData.radiusPolice_2; }
	static int GetradiusPolice_3() { return m_Data.GeneralData.radiusPolice_3; }
	static int GetradiusPolice_4() { return m_Data.GeneralData.radiusPolice_4; }
	static int GetradiusPolice_5() { return m_Data.GeneralData.radiusPolice_5; }
	static int GetradiusPolice_6() { return m_Data.GeneralData.radiusPolice_6; }
	static int GetradiusPolice_7() { return m_Data.GeneralData.radiusPolice_7; }
	static int GetradiusPolice_8() { return m_Data.GeneralData.radiusPolice_8; }
	static int GetradiusPolice_9() { return m_Data.GeneralData.radiusPolice_9; }
	static int GetradiusPolice_10() { return m_Data.GeneralData.radiusPolice_10; }
		
	
	
	static int GetradiusArmy_1() { return m_Data.GeneralData.radiusArmy_1; }
	static int GetradiusArmy_2() { return m_Data.GeneralData.radiusArmy_2; }
	static int GetradiusArmy_3() { return m_Data.GeneralData.radiusArmy_3; }
	static int GetradiusArmy_4() { return m_Data.GeneralData.radiusArmy_4; }
	static int GetradiusArmy_5() { return m_Data.GeneralData.radiusArmy_5; }
	static int GetradiusArmy_6() { return m_Data.GeneralData.radiusArmy_6; }
	static int GetradiusArmy_7() { return m_Data.GeneralData.radiusArmy_7; }
	static int GetradiusArmy_8() { return m_Data.GeneralData.radiusArmy_8; }
	static int GetradiusArmy_9() { return m_Data.GeneralData.radiusArmy_9; }
	static int GetradiusArmy_10() { return m_Data.GeneralData.radiusArmy_10; }

		
		
	static vector GetpositionCity() { return m_Data.GeneralData.posCity.GetRandomElement(); }
	static vector GetpositionPolice() { return m_Data.GeneralData.posPolice.GetRandomElement(); }
	static vector GetpositionArmy() { return m_Data.GeneralData.posArmy.GetRandomElement(); }
		

		
	static TStringArray GetLootCity_1() { return m_Data.GeneralData.LootCity_1; }
	static TStringArray GetLootCity_2() { return m_Data.GeneralData.LootCity_2; }
	static TStringArray GetLootCity_3() { return m_Data.GeneralData.LootCity_3; }
	static TStringArray GetLootCity_4() { return m_Data.GeneralData.LootCity_4; }	
	static TStringArray GetLootCity_5() { return m_Data.GeneralData.LootCity_5; }
	static TStringArray GetLootCity_6() { return m_Data.GeneralData.LootCity_6; }
	static TStringArray GetLootCity_7() { return m_Data.GeneralData.LootCity_7; }
	static TStringArray GetLootCity_8() { return m_Data.GeneralData.LootCity_8; }
	static TStringArray GetLootCity_9() { return m_Data.GeneralData.LootCity_9; }
	static TStringArray GetLootCity_10() { return m_Data.GeneralData.LootCity_10; }
		
	static TStringArray GetLootPolice_1() { return m_Data.GeneralData.LootPolice_1; }
	static TStringArray GetLootPolice_2() { return m_Data.GeneralData.LootPolice_2; }
	static TStringArray GetLootPolice_3() { return m_Data.GeneralData.LootPolice_3; }
	static TStringArray GetLootPolice_4() { return m_Data.GeneralData.LootPolice_4; }	
	static TStringArray GetLootPolice_5() { return m_Data.GeneralData.LootPolice_5; }
	static TStringArray GetLootPolice_6() { return m_Data.GeneralData.LootPolice_6; }
	static TStringArray GetLootPolice_7() { return m_Data.GeneralData.LootPolice_7; }
	static TStringArray GetLootPolice_8() { return m_Data.GeneralData.LootPolice_8; }
	static TStringArray GetLootPolice_9() { return m_Data.GeneralData.LootPolice_9; }
	static TStringArray GetLootPolice_10() { return m_Data.GeneralData.LootPolice_10; }
		
		
	static TStringArray GetLootArmy_1() { return m_Data.GeneralData.LootArmy_1; }
	static TStringArray GetLootArmy_2() { return m_Data.GeneralData.LootArmy_2; }
	static TStringArray GetLootArmy_3() { return m_Data.GeneralData.LootArmy_3; }
	static TStringArray GetLootArmy_4() { return m_Data.GeneralData.LootArmy_4; }	
	static TStringArray GetLootArmy_5() { return m_Data.GeneralData.LootArmy_5; }
	static TStringArray GetLootArmy_6() { return m_Data.GeneralData.LootArmy_6; }
	static TStringArray GetLootArmy_7() { return m_Data.GeneralData.LootArmy_7; }
	static TStringArray GetLootArmy_8() { return m_Data.GeneralData.LootArmy_8; }
	static TStringArray GetLootArmy_9() { return m_Data.GeneralData.LootArmy_9; }
	static TStringArray GetLootArmy_10() { return m_Data.GeneralData.LootArmy_10; }
	
}
