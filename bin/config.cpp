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