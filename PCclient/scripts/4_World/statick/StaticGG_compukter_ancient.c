class GG_compukter_ancient extends GG_compukter
{
    void GG_compukter_ancientTimer()
	{
		--CanCheckGG_compukter;
	}

    override void Garbage_BinTimerStart()
    {
    	m_CheckGG_compukterTimer = new Timer;
		++CanCheckGG_compukter;
		m_CheckGG_compukterTimer.Run(60*timer_city, this, "GG_compukter_ancientTimer");
    }
}