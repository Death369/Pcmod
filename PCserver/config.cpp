class CfgPatches
{
	class PCserver
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"PCclient"
		};
	};
};
class CfgMods
{
	class PCserver
	{
		dir="PCserver";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="PCserver";
		credits="";
		author="";
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
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"PCserver/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"PCserver/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"PCserver/Scripts/5_Mission"
				};
			};
		};
	};
};
