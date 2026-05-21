class GG_HDD extends ItemBase
{
	protected float m_StashPosX;
	protected float m_StashPosY;
	protected float m_StashPosZ;
	protected float m_DecryptionProgress = 0;
	protected bool m_HasSpawnedStash = false;

	void GG_HDD()
	{
		RegisterNetSyncVariableFloat("m_StashPosX");
		RegisterNetSyncVariableFloat("m_StashPosY");
		RegisterNetSyncVariableFloat("m_StashPosZ");
		RegisterNetSyncVariableFloat("m_DecryptionProgress", 0.0, 100.0);
		RegisterNetSyncVariableBool("m_HasSpawnedStash");
	}

	override void EEInit()
	{
		super.EEInit();
		// Ensure internal progress matches quantity on spawn/load
		if (GetQuantity() > 0) m_DecryptionProgress = GetQuantity();
	}

	void SetStashPos(vector pos) 
	{ 
		m_StashPosX = pos[0];
		m_StashPosY = pos[1];
		m_StashPosZ = pos[2];
		SetSynchDirty();
	}
	
	vector GetStashPos() 
	{ 
		vector pos = "0 0 0";
		pos[0] = m_StashPosX;
		pos[1] = m_StashPosY;
		pos[2] = m_StashPosZ;
		return pos; 
	}

	bool HasValidStashPos()
	{
		return (m_StashPosX != 0 || m_StashPosZ != 0);
	}
	
	void AddProgress(float val) 
	{ 
		if (IsDecrypted()) return;

		m_DecryptionProgress += val;
		if (m_DecryptionProgress > 100) m_DecryptionProgress = 100;
		
		SetQuantity(m_DecryptionProgress);
		SetSynchDirty();
	}
	
	float GetProgress() { 
		// Always return the highest value between sync var and quantity
		if (GetQuantity() > m_DecryptionProgress) m_DecryptionProgress = GetQuantity();
		return m_DecryptionProgress; 
	}

	bool IsDecrypted() { return GetProgress() >= 100; }

	void SetStashSpawned(bool val) 
	{ 
		m_HasSpawnedStash = val; 
		SetSynchDirty();
	}
	
	bool HasSpawnedStash() { return m_HasSpawnedStash; }

	void ForceDecrypt() 
	{ 
		m_DecryptionProgress = 100;
		SetQuantity(100);
		SetSynchDirty();
	}
}

class GG_HDD_OS extends GG_HDD {}
class GG_HDD_OS_Police extends GG_HDD_OS {}
class GG_HDD_OS_Army extends GG_HDD_OS {}
class GG_HDD_City extends GG_HDD {}
class GG_HDD_Police extends GG_HDD {}
class GG_HDD_Army extends GG_HDD {}
class GG_HDD_Quest extends GG_HDD {}
class GG_HDD_Legacy extends GG_HDD {}
