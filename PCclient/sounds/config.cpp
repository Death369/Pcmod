class CfgPatches
{
	class PCclient
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Sounds_Effects",
			"DZ_Data"
		};
	};
};
class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class pcom_SoundShader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"PCclient\sounds\PConWork",
				1
			}
		};
		volume=1;
		range=20;
	};
	class pcomdeploy_SoundShader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"PCclient\sounds\PISI",
				1
			}
		};
		volume=1;
		range=20;
	};
	class pcom_post_ok_SoundShader: baseCharacter_SoundShader
	{
		samples[]= {{"PCclient\sounds\1_beep", 1}};
		volume=0.8;
		range=10;
	};
	class pcom_post_err_SoundShader: baseCharacter_SoundShader
	{
		samples[]= {{"PCclient\sounds\3_beep", 1}};
		volume=1.0;
		range=15;
	};
	class pcom_ping_SoundShader: baseCharacter_SoundShader
	{
		samples[]= {{"PCclient\sounds\signal", 1}};
		volume=0.8;
		range=10;
	};
	class pcom_startup_SoundShader: baseCharacter_SoundShader
	{
		samples[]= {{"PCclient\sounds\startup", 1}};
		volume=0.8;
		range=15;
	};
	class pcom_shutdown_SoundShader: baseCharacter_SoundShader
	{
		samples[]= {{"PCclient\sounds\shutdown", 1}};
		volume=0.8;
		range=10;
	};
};
class CfgSoundSets
{
	class baseCharacter_SoundSet;
	class pcom_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"pcom_SoundShader"
		};
	};
	class pcomdeploy_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"pcomdeploy_SoundShader"
		};
	};
	class pcom_post_ok_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]= {"pcom_post_ok_SoundShader"};
	};
	class pcom_post_err_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]= {"pcom_post_err_SoundShader"};
	};
	class pcom_ping_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]= {"pcom_ping_SoundShader"};
	};
	class pcom_startup_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]= {"pcom_startup_SoundShader"};
	};
	class pcom_shutdown_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]= {"pcom_shutdown_SoundShader"};
	};
};
