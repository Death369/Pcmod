modded class GG_compukter
{
	Timer GetCheckTimer() { return m_CheckGG_compukterTimer; }
	void SetCanCheck(int val) { CanCheckGG_compukter = val; }
};

modded class GG_compukter_police
{
	Timer GetCheckTimer() { return m_CheckGG_compukter_policeTimer; }
	void SetCanCheck(int val) { CanCheckGG_compukter_police = val; }
};

modded class GG_compukter_army
{
	Timer GetCheckTimer() { return m_CheckGG_compukter_armyTimer; }
	void SetCanCheck(int val) { CanCheckGG_compukter_army = val; }
};
