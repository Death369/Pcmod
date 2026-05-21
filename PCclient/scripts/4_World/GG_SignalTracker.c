class GG_SignalTracker extends ItemBase
{
	protected ref Timer m_PingTimer;
	protected const string SOUND_PING = "pcom_ping_SoundSet";
	protected bool m_TrackerPingSynch = false;

	void GG_SignalTracker()
	{
		RegisterNetSyncVariableBool("m_TrackerPingSynch");
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}

	override bool IsInventoryVisible() { return true; }

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		if (m_TrackerPingSynch)
		{
			EffectSound sound;
			PlaySoundSet(sound, SOUND_PING, 0, 0);
			m_TrackerPingSynch = false;
		}
	}

	override void OnWorkStart()
	{
		super.OnWorkStart();
		if (GetGame().IsServer())
		{
			if (!m_PingTimer) m_PingTimer = new Timer();
			m_PingTimer.Run(1.0, this, "ServerUpdatePing", null, true);
		}
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
		if (GetGame().IsServer() && m_PingTimer) m_PingTimer.Stop();
	}

	void ServerUpdatePing()
	{
		float closestDist = 99999;
		vector pos = GetPosition();

		array<Object> objects = new array<Object>;
		GetGame().GetObjectsAtPosition(pos, 500, objects, null);

		foreach (Object obj : objects)
		{
			GG_HDD drive = GG_HDD.Cast(obj);
			if (drive && drive.IsDecrypted())
			{
				float dist = vector.Distance(pos, drive.GetStashPos());
				if (dist < closestDist) closestDist = dist;
			}
		}

		if (closestDist < 500)
		{
			m_TrackerPingSynch = true;
			SetSynchDirty();
			
			float interval = 0.2 + (closestDist / 500.0) * 2.0;
			m_PingTimer.Stop();
			m_PingTimer.Run(interval, this, "ServerUpdatePing", null, false);
		}
	}
}