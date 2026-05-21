modded class GG_compukter
{
	Timer GetCheckTimer() 
	{ 
		if (!m_CheckGG_compukterTimer) m_CheckGG_compukterTimer = new Timer();
		return m_CheckGG_compukterTimer; 
	}
	void SetCanCheck(int val) { CanCheckGG_compukter = val; }
};

modded class GG_compukter_police
{
	Timer GetCheckTimer() 
	{ 
		if (!m_CheckGG_compukter_policeTimer) m_CheckGG_compukter_policeTimer = new Timer();
		return m_CheckGG_compukter_policeTimer; 
	}
	void SetCanCheck(int val) { CanCheckGG_compukter_police = val; }
};

modded class GG_compukter_army
{
	Timer GetCheckTimer() 
	{ 
		if (!m_CheckGG_compukter_armyTimer) m_CheckGG_compukter_armyTimer = new Timer();
		return m_CheckGG_compukter_armyTimer; 
	}
	void SetCanCheck(int val) { CanCheckGG_compukter_army = val; }
};
