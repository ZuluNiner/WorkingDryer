#define _ARMA_

class CfgPatches
{
	class Z9_Sounds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Sounds_Effects","DZ_Data"};
	};
};
class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class dryer_SoundShader: baseCharacter_SoundShader
	{
		samples[] = {{"WorkingDryer\sounds\dryer_working",1}};
		volume = 2;
		range = 20;
	};
	class dryerFinished_SoundShader: baseCharacter_SoundShader
	{
		samples[] = {{"WorkingDryer\sounds\dryer_finished",1}};
		volume = 1;
		range = 40;
	};
};
class CfgSoundSets
{
	class baseCharacter_SoundSet;
	class dryer_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[] = {"dryer_SoundShader"};
	};
	class dryerFinished_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[] = {"dryerFinished_SoundShader"};
	};
};