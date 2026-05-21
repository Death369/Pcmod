class CfgPcconfigHandler
{
	private static string m_Path = "$mission:cfgpcconfig.json";
	
	static ref CfgPcconfigJson m_Data = new CfgPcconfigJson;
	
	static bool LoadData()
	{
		if ( !FileExist( m_Path ) )
		{
			m_Path = "";
			GetGame().GetWorldName( m_Path );
			m_Path = string.Format("DZ/worlds/%1/ce/cfgpcconfig.json", m_Path );
		}
		
		JsonFileLoader<CfgPcconfigJson>.JsonLoadFile( m_Path, m_Data );
		return true;
	}
	
	static void SyncDataSend(notnull Man player)
	{
		GetGame().RPCSingleParam(player, 36901, new Param1<CfgPcconfigJson>(m_Data), true, player.GetIdentity());
	}
	
	static void OnRPC(Man player, ParamsReadContext ctx)
	{
		Param1<CfgPcconfigJson> data = new Param1<CfgPcconfigJson>(null);
		
		if ( ctx.Read(data) )
			m_Data = data.param1;
		else
			ErrorEx("[PCmod] failed to read synced data");
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
}
