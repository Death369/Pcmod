modded class PlayerBase
{
	override void Init()
	{
		super.Init();

		DayzPlayerItemBehaviorCfg twoHanded = new DayzPlayerItemBehaviorCfg;
		twoHanded.SetTwoHanded();

		DayzPlayerItemBehaviorCfg toolsOneHanded = new DayzPlayerItemBehaviorCfg;
		toolsOneHanded.SetToolsOneHanded();

		DayzPlayerItemBehaviorCfg heavyItemBehaviour = new DayzPlayerItemBehaviorCfg;
		heavyItemBehaviour.SetHeavyItems();

		GetDayZPlayerType().AddItemInHandsProfileIK("GG_HDD", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/rice.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("GG_RAM", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/rice.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("GG_MBOARD", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/rice.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("GG_CPU", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/rice.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("GG_MOUSE", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/rice.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("GG_KEYBOARD", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/rice.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("GG_MONITOR", "dz/anims/workspaces/player/player_main/props/player_main_2h_pot.asi", twoHanded, "dz/anims/anm/player/ik/vehicles/BatteryTruck.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("GG_SYSBLOCK", "dz/anims/workspaces/player/player_main/props/player_main_2h_pot.asi", twoHanded, "dz/anims/anm/player/ik/vehicles/BatteryTruck.anm");
	}
}