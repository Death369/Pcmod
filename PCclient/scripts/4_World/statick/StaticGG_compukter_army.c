class GG_compukter_army extends ItemBase
{

    int CanCheckGG_compukter_army = 0;
    ref Timer   m_CheckGG_compukter_armyTimer;

	void GG_compukter_army()
	{
		RegisterNetSyncVariableInt("CanCheckGG_compukter_army");
	}

    void GG_compukter_armyTimer()
	{
		--CanCheckGG_compukter_army;
	}
	int timer_army = CfgPcconfigHandler.Gettimerarmy();
    void Garbage_BinTimerStart()
    {
    	m_CheckGG_compukter_armyTimer = new Timer;

		++CanCheckGG_compukter_army;
		m_CheckGG_compukter_armyTimer.Run(60*timer_army, this, "GG_compukterTimer");

    }

    bool CanLootGG_compukter_army()
    {
        if ( CanCheckGG_compukter_army == 0 )
        {
            return true;
        }
        return false;
    }

    override bool CanPutInCargo( EntityAI parent )
    {
        if( !super.CanPutInCargo(parent) ) {return false;}        
        if ( GetNumberOfItems() == 0)
        {
            return false;
        }
        return false;
    }
    
    override bool CanPutIntoHands(EntityAI parent)
    {
        if( !super.CanPutIntoHands( parent ) )
        {
            return false;
        }
        if ( GetNumberOfItems() == 0 )
        {
            return false;
        }
        return false;

    }
}