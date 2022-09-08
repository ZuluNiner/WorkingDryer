class Z9_Dryer: Inventory_Base
{
	const string SOUND_WORKING = "dryer_SoundSet";
	const string SOUND_FINISHED = "dryerFinished_SoundSet";
	const string SOUND_TURN_ON = "spotlight_turn_on_SoundSet";
	const string SOUND_TURN_OFF = "spotlight_turn_off_SoundSet";
	
	protected EffectSound m_SoundWorking;
	protected EffectSound m_SoundFinished;
	protected EffectSound m_SoundTurnOn;
	protected EffectSound m_SoundTurnOff;
	
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionPlugIn);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionUnplugThisByCord);
		AddAction(ActionTurnOnWhileOnGround);
		AddAction(ActionTurnOffWhileOnGround);
		AddAction(ActionPlaceObject);
		AddAction(ActionPlugTargetIntoThis);
	}
	
	override void OnWork(float energyConsumed)
	{
		float totalWetness = 0;
		CargoBase cargo = GetInventory().GetCargo();
		for (int i = 0; i < cargo.GetItemCount(); i++)
		{
			ItemBase item = ItemBase.Cast(cargo.GetItem(i));
			float wetness = item.GetWet();
			if(wetness != 0.049)
				totalWetness = totalWetness+wetness;
			AddWetnessToItem(item, -0.15);
		}
		if(totalWetness == 0)
			GetCompEM().SwitchOff();
	}
	
	override void OnSwitchOn()
	{
		super.OnSwitchOn();

		//sound (client only)
		PlaySoundSet(m_SoundTurnOn, SOUND_TURN_ON, 0, 0);
	}

	override void OnSwitchOff()
	{
		super.OnSwitchOff();

		//sound (client only)
		PlaySoundSet(m_SoundTurnOff, SOUND_TURN_OFF, 0, 0);
	}

	override void OnWorkStart()
	{
		PlaySoundSetLoop(m_SoundWorking, SOUND_WORKING, 0.1, 0.3);
	}

	override void OnWorkStop()
	{
		StopSoundSet(m_SoundWorking);
		PlaySoundSet(m_SoundFinished, SOUND_FINISHED, 0, 0);
	}
	protected void AddWetnessToItem(ItemBase item, float amount)
	{
		float wetness = item.GetWet();
		if(amount > wetness)
			wetness = wetness - wetness;
		else
			wetness = wetness + amount;
		wetness = Math.Clamp(wetness, 0, 1); //wetness <0-1>
		item.SetWet(wetness);
	}
	
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		return true;
	}
	override bool CanSwapItemInCargo(EntityAI child_entity, EntityAI new_entity)
	{
		return true;
	}
}