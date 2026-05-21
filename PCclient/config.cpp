class CfgPatches
{
	class PCclient
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgMods
{
	class PCclient
	{
		dir="PCclient";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="PCclient";
		credits="";
		author="GG";
		authorID="0";
		version=1;
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"PCclient/gui/imagesets/cj_icons.imageset"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"PCclient/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"PCclient/Scripts/5_Mission"
				};
			};
		};
	};
};
class CfgVehicles
{
	class Edible_Base;
	class Inventory_Base;
	class Switchable_Base;
	class Powered_Base;
	class FishingRod_Base;
	class Lockpick
	{
	};
	class UndergroundCity: Inventory_Base
	{
		scope=2;
		displayName="#STR_Pile_of_dirt";
		model="\DZ\gear\camping\underground_stash.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
	class UndergroundPolice: Inventory_Base
	{
		scope=2;
		displayName="#STR_Pile_of_dirt";
		model="\DZ\gear\camping\underground_stash.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
	class UndergroundArmy: Inventory_Base
	{
		scope=2;
		displayName="#STR_Pile_of_dirt";
		model="\DZ\gear\camping\underground_stash.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
	class UndergroundQuest: UndergroundArmy
	{
	};
	class UndergroundLegacy: UndergroundArmy
	{
	};
	class GG_HDD: Inventory_Base
	{
		canBeSplit=0;
		stackedUnit="percentage";
		quantityBar=1;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		scope=2;
		displayName="";
		descriptionShort="";
		model="\PCclient\HDD\hdd.p3d";
		itemSize[]={2,2};
		weight=400;
		hiddenSelections[]=
		{
			"zbytek"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1.01,
							
							{
								"PCclient\HDD\data\hdd.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\hdd.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\hdd_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\hdd_damage.rvmat"
							}
						},
						
						{
							0.0099999998,
							
							{
								"PCclient\HDD\data\hdd_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class GG_HDD_OS: GG_HDD
	{
		scope=2;
		displayName="OS Drive (Basic)";
		descriptionShort="Standard boot disk. Required to start the PC system. Provides 1x decryption speed.";
		model="\PCclient\HDD\hdd.p3d";
		itemSize[]={2,2};
		inventorySlot[]=
		{
			"hdd_os"
		};
		weight=400;
		hiddenSelectionsTextures[]=
		{
			"PCclient\HDD\data\HargDisk_OS.paa",
			"PCclient\HDD\data\HargDisk_OS.paa",
			"PCclient\HDD\data\HargDisk_OS.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\hdd.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\hdd.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\hdd_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\hdd_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\hdd_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class GG_HDD_Police: GG_HDD
	{
		scope=2;
		displayName="Encrypted Drive (Police)";
		descriptionShort="Encrypted drive found in police stations. Contains coordinates for police stashes.";
		model="\PCclient\HDD\hdd.p3d";
		itemSize[]={2,2};
		inventorySlot[]=
		{
			"hdd"
		};
		weight=400;
		
		
		
		hiddenSelectionsTextures[]=
		{
			"PCclient\HDD\data\HargDisk_MENT.paa",
			"PCclient\HDD\data\HargDisk_MENT.paa",
			"PCclient\HDD\data\HargDisk_MENT.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\hdd.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\hdd.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\hdd_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\hdd_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\hdd_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class GG_HDD_Army: GG_HDD
	{
		scope=2;
		displayName="Encrypted Drive (Military)";
		descriptionShort="Highly encrypted military drive. Contains coordinates for high-tier army stashes.";
		model="\PCclient\HDD\hdd.p3d";
		itemSize[]={2,2};
		inventorySlot[]=
		{
			"hdd"
		};
		weight=400;
		
		
		
		hiddenSelectionsTextures[]=
		{
			"PCclient\HDD\data\HargDisk_ARMY.paa",
			"PCclient\HDD\data\HargDisk_ARMY.paa",
			"PCclient\HDD\data\HargDisk_ARMY.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\hdd.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\hdd.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\hdd_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\hdd_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\hdd_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class GG_HDD_City: GG_HDD
	{
		scope=2;
		displayName="Encrypted Drive (City)";
		descriptionShort="Common encrypted drive. Contains coordinates for standard city stashes.";
		model="\PCclient\HDD\hdd.p3d";
		itemSize[]={2,2};
		inventorySlot[]=
		{
			"hdd"
		};
		weight=400;
		
		
		
		hiddenSelectionsTextures[]=
		{
			"PCclient\HDD\data\HargDisk_COL.paa",
			"PCclient\HDD\data\HargDisk_COL.paa",
			"PCclient\HDD\data\HargDisk_COL.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\hdd.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\hdd.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\hdd_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\hdd_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\hdd_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class GG_HDD_Quest: GG_HDD
	{
		scope=2;
		displayName="Encrypted Drive (Quest)";
		descriptionShort="Rare encrypted drive. Contains coordinates for specialized quest stashes.";
		model="\PCclient\HDD\hdd.p3d";
		itemSize[]={2,2};
		inventorySlot[]=
		{
			"hdd"
		};
		weight=400;
		
		
		
		hiddenSelectionsTextures[]=
		{
			"PCclient\HDD\data\HargDisk_COL.paa",
			"PCclient\HDD\data\HargDisk_COL.paa",
			"PCclient\HDD\data\HargDisk_COL.paa"
		};
		class DamageSystem: DamageSystem
		{
		};
	};
	class GG_HDD_Legacy: GG_HDD
	{
		scope=2;
		displayName="Encrypted Drive (Legacy)";
		descriptionShort="Ancient encrypted drive. Contains coordinates for extremely rare legacy stashes.";
		model="\PCclient\HDD\hdd.p3d";
		itemSize[]={2,2};
		inventorySlot[]=
		{
			"hdd"
		};
		weight=400;
		
		
		
		hiddenSelectionsTextures[]=
		{
			"PCclient\HDD\data\HargDisk_ARMY.paa",
			"PCclient\HDD\data\HargDisk_ARMY.paa",
			"PCclient\HDD\data\HargDisk_ARMY.paa"
		};
		class DamageSystem: DamageSystem
		{
		};
	};
	class GG_HDD_OS_Police: GG_HDD_OS
	{
		scope=2;
		displayName="OS Drive (Police)";
		descriptionShort="Optimized Police Operating System. Increases decryption speed.";
		hiddenSelectionsTextures[]=
		{
			"PCclient\HDD\data\HargDisk_MENT.paa",
			"PCclient\HDD\data\HargDisk_MENT.paa",
			"PCclient\HDD\data\HargDisk_MENT.paa"
		};
	};
	class GG_HDD_OS_Army: GG_HDD_OS
	{
		scope=2;
		displayName="OS Drive (Army)";
		descriptionShort="High-performance Military Operating System. Maximum decryption speed.";
		hiddenSelectionsTextures[]=
		{
			"PCclient\HDD\data\HargDisk_ARMY.paa",
			"PCclient\HDD\data\HargDisk_ARMY.paa",
			"PCclient\HDD\data\HargDisk_ARMY.paa"
		};
	};
	class GG_RAM: Inventory_Base
	{
		scope=2;
		displayName="RAM";
		descriptionShort="";
		model="\PCclient\HDD\ram.p3d";
		itemSize[]={2,1};
		inventorySlot[]=
		{
			"ram"
		};
		weight=190;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\ram.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\ram.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\ram_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\ram_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\ram_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class GG_MBOARD: Inventory_Base
	{
		scope=2;
		displayName="Motherboard";
		descriptionShort="";
		model="\PCclient\HDD\mboard.p3d";
		itemSize[]={2,3};
		inventorySlot[]=
		{
			"mboard"
		};
		weight=600;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\mboard.rvmat",
								"PCclient\HDD\data\mboardback.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\mboard.rvmat",
								"PCclient\HDD\data\mboardback.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\mboard_damage.rvmat",
								"PCclient\HDD\data\mboardback_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\mboard_damage.rvmat",
								"PCclient\HDD\data\mboardback_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\mboard_destruct.rvmat",
								"PCclient\HDD\data\mboardback_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class GG_CPU: Inventory_Base
	{
		scope=2;
		displayName="CPU";
		descriptionShort="";
		model="\PCclient\HDD\cpu.p3d";
		itemSize[]={1,1};
		inventorySlot[]=
		{
			"cpu"
		};
		weight=190;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\cpu.rvmat",
								"PCclient\HDD\data\cpuback.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\cpu.rvmat",
								"PCclient\HDD\data\cpuback.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\cpu_damage.rvmat",
								"PCclient\HDD\data\cpuback_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\cpu_damage.rvmat",
								"PCclient\HDD\data\cpuback_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\cpu_destruct.rvmat",
								"PCclient\HDD\data\cpuback_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class GG_SYSBLOCK: Inventory_Base
	{
		repairableWithKits[]={8,2};
		repairCosts[]={25.0,25.0};
		scope=2;
		displayName="#STR_GG_SYSBLOCK";
		descriptionShort="";
		model="\PCclient\HDD\sysblock.p3d";
		simulation="inventoryItem";
		itemSize[]={3,4};
		attachments[]=
		{
			"mboard",
			"cpu",
			"hdd",
			"hdd_os",
			"ram",
			"monitor",
			"mouse",
			"keyboard"
		};
		hiddenSelections[]=
		{
			"display",
			"letter_1",
			"letter_2",
			"letter_3",
			"letter_4",
			"letter_5",
			"letter_6",
			"letter_7",
			"letter_8",
			"letter_9",
			"letter_10"
		};
		weight=2500;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\PCall.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\PCall.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\PCall_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\PCall_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\PCall_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.1;
			cordTextureFile="DZ\gear\camping\Data\plug_black_CO.paa";
			plugType=2;
			cordLength=5;
		};
		class AnimationSources
		{
			class clips_keyboard
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class clips_mouse
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class clips_sysblock
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
	};
	class Empty_SYSBLOCK: Inventory_Base
	{
		scope=2;
		displayName="#STR_GG_SYSBLOCK";
		descriptionShort="#STR_GG_SYSBLOCK";
		model="\PCclient\HDD\sysblock.p3d";
		simulation="inventoryItem";
		itemSize[]={3,4};
		weight=2500;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\PCall.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\PCall.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\PCall_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\PCall_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\PCall_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.1;
			cordTextureFile="DZ\gear\camping\Data\plug_black_CO.paa";
			plugType=2;
			cordLength=5;
		};
		class AnimationSources
		{
			class clips_keyboard
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class clips_mouse
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class clips_sysblock
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
	};
	class GG_MONITOR: Inventory_Base
	{
		repairableWithKits[]={2};
		repairCosts[]={25.0};
		scope=2;
		displayName="Monitor";
		descriptionShort="";
		model="\PCclient\HDD\monitor.p3d";
		itemSize[]={4,4};
		canBeDigged=0;
		weight=16500;
		inventorySlot[]=
		{
			"monitor"
		};
		itemBehaviour=0;
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\PCall.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\PCall.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\PCall_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\PCall_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\PCall_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class GG_MOUSE: Inventory_Base
	{
		repairableWithKits[]={2};
		repairCosts[]={25.0};
		scope=2;
		displayName="Mouse";
		descriptionShort="";
		model="\PCclient\HDD\mouse.p3d";
		itemSize[]={2,1};
		inventorySlot[]=
		{
			"mouse"
		};
		weight=190;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\PCall.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\PCall.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\PCall_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\PCall_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\PCall_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class GG_KEYBOARD: Inventory_Base
	{
		repairableWithKits[]={2};
		repairCosts[]={25.0};
		scope=2;
		displayName="Keyboard";
		descriptionShort="";
		model="\PCclient\HDD\keyboard.p3d";
		itemSize[]={4,1};
		inventorySlot[]=
		{
			"keyboard"
		};
		weight=500;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PCclient\HDD\data\PCall.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PCclient\HDD\data\PCall.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PCclient\HDD\data\PCall_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PCclient\HDD\data\PCall_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PCclient\HDD\data\PCall_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class GG_compukter: Inventory_Base
	{
		scope=2;
		displayName="#STR_GG_compukter";
		descriptionShort="";
		visibilityModifier=0.94999999;
		model="\PCclient\view.p3d";
		carveNavmesh=1;
		handheld="false";
		weight=10000;
		physLayer="item_large";
		itemSize[]={16,16};
		canBeDigged=0;
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100000000000;
				};
			};
		};
	};
	class GG_compukter_police: Inventory_Base
	{
		scope=2;
		displayName="#STR_GG_compukter";
		descriptionShort="";
		visibilityModifier=0.94999999;
		model="\PCclient\view.p3d";
		carveNavmesh=1;
		handheld="false";
		weight=10000;
		physLayer="item_large";
		itemSize[]={16,16};
		canBeDigged=0;
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100000000000;
				};
			};
		};
	};
	class GG_compukter_army: Inventory_Base
	{
		scope=2;
		displayName="#STR_GG_compukter";
		descriptionShort="";
		visibilityModifier=0.94999999;
		model="\PCclient\view.p3d";
		carveNavmesh=1;
		handheld="false";
		weight=10000;
		physLayer="item_large";
		itemSize[]={16,16};
		canBeDigged=0;
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100000000000;
				};
			};
		};
	};
	class GG_compukter_rare: GG_compukter_army
	{
		displayName="Advanced Workstation";
		descriptionShort="A high-end workstation likely containing encrypted quest data.";
	};
	class GG_compukter_ancient: GG_compukter_army
	{
		displayName="Encrypted Mainframe";
		descriptionShort="An ancient mainframe terminal. Its drives may contain legacy archives.";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxymboard: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"mboard"
		};
		model="\PCclient\HDD\mboard.p3d";
	};
	class Proxycpu: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"cpu"
		};
		model="\PCclient\HDD\cpu.p3d";
	};
	class Proxyhdd: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"hdd"
		};
		model="\PCclient\HDD\hdd.p3d";
	};
	class Proxyram: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"ram"
		};
		model="\PCclient\HDD\ram.p3d";
	};
	class Proxymonitor: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"monitor"
		};
		model="\PCclient\HDD\monitor.p3d";
	};
	class Proxymouse: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"mouse"
		};
		model="\PCclient\HDD\mouse.p3d";
	};
	class Proxykeyboard: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"keyboard"
		};
		model="\PCclient\HDD\keyboard.p3d";
	};
};
class CfgSlots
{
	class Slot_mboard
	{
		name="mboard";
		displayName="#STR_Slot_mboard";
		ghostIcon="set:cj_pc_icons image:cj_mainboard";
	};
	class Slot_cpu
	{
		name="cpu";
		displayName="#STR_Slot_cpu";
		ghostIcon="set:cj_pc_icons image:cj_cpu";
	};
	class Slot_hdd
	{
		name="hdd";
		displayName="#STR_Slot_hdd";
		ghostIcon="set:cj_pc_icons image:cj_hdd_broken";
	};
	class Slot_hdd_os
	{
		name="hdd_os";
		displayName="#STR_Slot_hdd_os";
		ghostIcon="set:cj_pc_icons image:cj_hdd";
	};
	class Slot_ram
	{
		name="ram";
		displayName="#STR_Slot_ram";
		ghostIcon="set:cj_pc_icons image:cj_ram";
	};
	class Slot_monitor
	{
		name="monitor";
		displayName="#STR_Slot_monitor";
		ghostIcon="set:cj_pc_icons image:cj_screen";
	};
	class Slot_mouse
	{
		name="mouse";
		displayName="#STR_Slot_mouse";
		ghostIcon="set:cj_pc_icons image:cj_mouse";
	};
	class Slot_keyboard
	{
		name="keyboard";
		displayName="#STR_Slot_keyboard";
		ghostIcon="set:cj_pc_icons image:cj_keyboard";
	};
};






