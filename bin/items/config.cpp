class CfgPatches
{
	class WorkingDryer
	{
		units[] = {};
		weapons[] = {};
		name = "Working Dryer";
		author = "Z9";
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Z9_DryerKit: Inventory_Base
	{
		scope = 2;
		displayName = "Working Dryer Kit";
		descriptionShort = "A deployable kit for a working dryer to dry your gear.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		// hologramMaterial="washing_machine";
		// hologramMaterialPath="dz\structures\furniture\eletrical_appliances\washing_machine\data";
		itemSize[] = {10,5};
		weight = 280;
		physLayer = "item_large";
		heavyItem = 1;
		attachments[] = {};
		rotationFlags = 2;
		itemBehaviour = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
				class GlobalArmor
				{
					class Projectile
					{
						class Health
						{
							damage = 0;
						};
						class Blood
						{
							damage = 0;
						};
						class Shock
						{
							damage = 0;
						};
					};
					class FragGrenade
					{
						class Health
						{
							damage = 0;
						};
						class Blood
						{
							damage = 0;
						};
						class Shock
						{
							damage = 0;
						};
					};
				};
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory: AnimSourceHidden{};
			class Placing: AnimSourceHidden{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class crafting_1
				{
					soundSet = "FenceKit_crafting_1_SoundSet";
					id = 1111;
				};
				class crafting_2
				{
					soundSet = "FenceKit_crafting_2_SoundSet";
					id = 1112;
				};
				class crafting_3
				{
					soundSet = "FenceKit_crafting_3_SoundSet";
					id = 1113;
				};
				class crafting_4
				{
					soundSet = "FenceKit_crafting_4_SoundSet";
					id = 1114;
				};
				class crafting_5
				{
					soundSet = "FenceKit_crafting_5_SoundSet";
					id = 1115;
				};
			};
		};
	};
	
	class Z9_DryerKitPlacing: Z9_DryerKit
	{
		displayName = "This is a hologram";
		descriptionShort = "Nothing to see here, move along";
		scope = 2;
		model="dz\structures\furniture\eletrical_appliances\washing_machine\washing_machine.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\consumables\data\pile_of_planks_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\fence_pile_of_planks.rvmat"};
		hologramMaterial="washing_machine";
		hologramMaterialPath="dz\structures\furniture\eletrical_appliances\washing_machine\data";
		alignHologramToTerain = 1;
		slopeTolerance = 0.3;
		yawPitchRollLimit[] = {15,15,15};
	};
	
	class Z9_Dryer: Inventory_Base
	{
		scope=2;
		displayName="Clothes Dryer";
		descriptionShort="A handy appliance that allows you to dry your clothes and equipment when powered.";
		model="dz\structures\furniture\eletrical_appliances\washing_machine\washing_machine.p3d";
		rotationFlags=2;
		slopeTolerance=0.40000001;
		yawPitchRollLimit[]={45,45,45};
		weight=45000;
		itemSize[]={10,10};
		itemBehaviour=0;
		carveNavmesh=1;
		heavyItem=1;
		physLayer = "item_large";
		// hologramMaterial="washing_machine";
		// hologramMaterialPath="dz\structures\furniture\eletrical_appliances\washing_machine\data";
		overrideDrawArea = "8.0";
		class Cargo
		{
			itemsCargoSize[]={10,10};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		repairableWithKits[]={7};
		repairCosts[]={25};
		class EnergyManager
		{
			hasIcon=1;
			switchOnAtSpawn=0;
			energyUsagePerSecond=0.025;
			cordTextureFile="DZ\gear\camping\Data\plug_orange_CO.paa";
			plugType=2;
			compatiblePlugTypes[]={2,6};
			cordLength=10;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class walk
				{
					soundSet = "powergenerator_movement_walk_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpPowerGenerator_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpPowerGenerator_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "powergenerator_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};