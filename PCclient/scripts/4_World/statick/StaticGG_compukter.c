class GG_compukter extends ItemBase
{
	

    int CanCheckGG_compukter = 0;
    ref Timer   m_CheckGG_compukterTimer;

    void GG_compukterTimer()
	{
		--CanCheckGG_compukter;
	}
	int timer_city = CfgPcconfigHandler.Gettimercity();
    void Garbage_BinTimerStart()
    {
    	m_CheckGG_compukterTimer = new Timer;

		++CanCheckGG_compukter;
		m_CheckGG_compukterTimer.Run(60*timer_city, this, "GG_compukterTimer");

    }

    bool CanLootGG_compukter()
    {
        if ( CanCheckGG_compukter == 0 )
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