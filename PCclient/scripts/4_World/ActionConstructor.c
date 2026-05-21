modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);

		actions.Insert( ActionDigOutStashCity);
		actions.Insert( ActionDigOutStashPolice);
		actions.Insert( ActionDigOutStashArmy);
		actions.Insert( ActionDigOutStashQuest);
		actions.Insert( ActionDigOutStashLegacy);
		actions.Insert( ActionActivateSysblock);

    }
}
