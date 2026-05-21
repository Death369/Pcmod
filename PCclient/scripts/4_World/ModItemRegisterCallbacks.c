modded class ModItemRegisterCallbacks
{
  

	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
		super.RegisterOneHanded( pType, pBehavior );
		
		pType.AddItemInHandsProfileIK("GG_HDD_OS",   "dz/anims/workspaces/player/player_main/player_main_1h.asi", 					pBehavior,	"dz/anims/anm/player/ik/gear/tuna.anm");
		pType.AddItemInHandsProfileIK("GG_HDD_City",   "dz/anims/workspaces/player/player_main/player_main_1h.asi", 					pBehavior,	"dz/anims/anm/player/ik/gear/tuna.anm");
		pType.AddItemInHandsProfileIK("GG_HDD_Police",   "dz/anims/workspaces/player/player_main/player_main_1h.asi", 					pBehavior,	"dz/anims/anm/player/ik/gear/tuna.anm");
		pType.AddItemInHandsProfileIK("GG_HDD_Army",   "dz/anims/workspaces/player/player_main/player_main_1h.asi", 					pBehavior,	"dz/anims/anm/player/ik/gear/tuna.anm");
		pType.AddItemInHandsProfileIK("GG_RAM", "dz/anims/workspaces/player/player_main/player_main_1h.asi", 					pBehavior,	"dz/anims/anm/player/ik/gear/tuna.anm");
		pType.AddItemInHandsProfileIK("GG_MBOARD", "dz/anims/workspaces/player/player_main/player_main_1h.asi", 					pBehavior,	"dz/anims/anm/player/ik/gear/tuna.anm");
		pType.AddItemInHandsProfileIK("GG_CPU", "dz/anims/workspaces/player/player_main/player_main_1h.asi", 					pBehavior,	"dz/anims/anm/player/ik/gear/tuna.anm");
		pType.AddItemInHandsProfileIK("GG_MOUSE", "dz/anims/workspaces/player/player_main/player_main_1h.asi", 					pBehavior,	"dz/anims/anm/player/ik/gear/tuna.anm");
		pType.AddItemInHandsProfileIK("GG_KEYBOARD", "dz/anims/workspaces/player/player_main/player_main_1h.asi", 					pBehavior,	"dz/anims/anm/player/ik/gear/tuna.anm");

	}
	
	override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
		super.RegisterTwoHanded( pType, pBehavior );
		
		
		pType.AddItemInHandsProfileIK("GG_MONITOR", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_bat.asi",  pBehavior,	"dz/anims/anm/player/ik/two_handed/mountain_g.anm");
		pType.AddItemInHandsProfileIK("GG_SYSBLOCK", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_bat.asi",  						pBehavior,	"dz/anims/anm/player/ik/two_handed/mountain_g.anm");
		pType.AddItemInHandsProfileIK("Empty_SYSBLOCK", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_bat.asi",  						pBehavior,	"dz/anims/anm/player/ik/two_handed/mountain_g.anm");
		
	}
	
	override void RegisterHeavy( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
	{
		super.RegisterHeavy( pType, pBehavior );
			
		/* pType.AddItemInHandsProfileIK("BP_mil_case",  "dz/anims/workspaces/player/player_main/player_main_heavy.asi", 							pBehavior,	"dz/anims/anm/player/ik/heavy/tent_party_packed.anm");				
		pType.AddItemInHandsProfileIK("BP_locker_bl",  "dz/anims/workspaces/player/player_main/player_main_heavy.asi", 							pBehavior,	"dz/anims/anm/player/ik/heavy/55galDrum.anm");		
		pType.AddItemInHandsProfileIK("BP_big_mill_tent",  "dz/anims/workspaces/player/player_main/player_main_heavy.asi", 						pBehavior,	"dz/anims/anm/player/ik/heavy/tent_party_packed.anm");		
		pType.AddItemInHandsProfileIK("BP_Cooler_Zil",  "dz/anims/workspaces/player/player_main/player_main_heavy.asi", 						pBehavior,	"dz/anims/anm/player/ik/heavy/55galDrum.anm");		 */
    }	

};