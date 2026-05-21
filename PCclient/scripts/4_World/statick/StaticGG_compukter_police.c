class GG_compukter_police extends ItemBase
{

    int CanCheckGG_compukter_police = 0;
    ref Timer   m_CheckGG_compukter_policeTimer;

	void GG_compukter_police()
	{
		RegisterNetSyncVariableInt("CanCheckGG_compukter_police");
	}

    void GG_compukter_policeTimer()
	{
		--CanCheckGG_compukter_police;
	}
	int timer_police = CfgPcconfigHandler.Gettimerpolice();
    void Garbage_BinTimerStart()
    {
    	m_CheckGG_compukter_policeTimer = new Timer;

		++CanCheckGG_compukter_police;
		m_CheckGG_compukter_policeTimer.Run(60*timer_police, this, "GG_compukter_policeTimer");

    }

    bool CanLootGG_compukter_police()
    {
        if ( CanCheckGG_compukter_police == 0 )
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