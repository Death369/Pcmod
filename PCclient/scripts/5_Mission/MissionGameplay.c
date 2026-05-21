modded class MissionGameplay
{
	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, target, rpc_type, ctx);
		
		if (rpc_type == 36901)
		{
			CfgPcconfigHandler.OnRPC(GetGame().GetPlayer(), ctx);
		}
	}
}
