class GG_compukter_rare extends GG_compukter
{
    void GG_compukter_rareTimer()
	{
		--CanCheckGG_compukter;
	}

    override void Garbage_BinTimerStart()
    {
    	m_CheckGG_compukterTimer = new Timer;
		++CanCheckGG_compukter;
		m_CheckGG_compukterTimer.Run(60*timer_city, this, "GG_compukter_rareTimer");
    }
}