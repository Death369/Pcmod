modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);

		actions.Insert( ActionCheckGG_compukter);
		actions.Insert( ActionCheckGG_compukter_police);
		actions.Insert( ActionCheckGG_compukter_army);
		actions.Insert( ActionCheckGG_compukter_rare);
		actions.Insert( ActionCheckGG_compukter_ancient);
    }
}
