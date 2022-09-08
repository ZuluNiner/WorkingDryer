modded class ModItemRegisterCallbacks
{
	override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterHeavy(pType, pBehavior);
		pType.AddItemInHandsProfileIK("Z9_DryerKit", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/tent_large.anm");
	}
}
class Z9_DryerKit extends KitBase
{
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
		
		if ( GetGame().IsServer() )
		{
			Z9_Dryer dryer = Z9_Dryer.Cast( GetGame().CreateObjectEx( "Z9_Dryer", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			dryer.SetPosition( position );
			dryer.SetOrientation( orientation );
			
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
			
			SetIsDeploySound( true );
		}
	}
	
	override bool DoPlacingHeightCheck()
	{
		return true;
	}

	override float HeightCheckOverride()
	{
		return 1.6;
	}
	
	override string GetDeploySoundset()
	{
		return "placeSpotlight_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "spotlight_deploy_SoundSet";
	}
	
	override string GetDeployFinishSoundset()
	{
		return "Shelter_Site_Build_Finish_SoundSet";
	}
	
	override void DisassembleKit(ItemBase item)
	{
		return;
	}
}