////////////////////////////////////////////////////////////////////
//DeRap: WorkingDryer\config.bin
//Produced from mikero's Dos Tools Dll version 8.35
//https://mikero.bytex.digital/Downloads
//'now' is Wed Sep 07 21:34:34 2022 : 'file' last modified on Wed Dec 31 16:00:01 1969
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgMods
{
	class WorkingDryer
	{
		type = "mod";
		dir = "WorkingDryer";
		name = "Working Dryer";
		author = "Z9";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"WorkingDryer/scripts/4_World"};
			};
		};
	};
};
class CfgPatches
{
	class WorkingDryerScripts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
