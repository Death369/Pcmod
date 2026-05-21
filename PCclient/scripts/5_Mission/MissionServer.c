modded class MissionServer extends MissionBase
{
	
	override void OnInit()
	{
		//Print("OnInit()");
		super.OnInit();
		//CfgGameplayHandler.LoadData();
		CfgPcconfigHandler.LoadData();
		m_FiringPos = new array<vector>;
	}
	
}
