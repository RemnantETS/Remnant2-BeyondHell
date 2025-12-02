function SetAffixTable (boss,modtable)
	local Boss = StaticFindObject(boss)
    if not Boss:IsValid() then return end

	local Table = StaticFindObject(modtable)
	if not Table:IsValid() then return end
    Log("Overriding"..boss)
	Boss:SetPropertyValue("ModTable", Table)
end

function SetAffixes()
	Log("Overriding Boss Affixes")
	SetAffixTable("/Game/World_Jungle/Characters/Root_Flyer/Blueprints/Mothermind/Char_Root_Flyer_Mothermind.Default__Char_Root_Flyer_Mothermind_C","/Game/World_Base/Affixes/Overrides/Char_MotherMind_Affixes.Char_MotherMind_Affixes")
	SetAffixTable("/Game/World_Fae/Characters/Fae_Knight/Blueprints/Miniboss/Char_Fae_Knight_Miniboss.Default__Char_Fae_Knight_Miniboss_C","/Game/World_Base/Affixes/Overrides/Char_RedPrince_Affixes.Char_RedPrince_Affixes")
	SetAffixTable("/Game/World_DLC2/Characters/Pan_Living_Stone_Kiln/Blueprints/Miniboss/Char_LS_Kiln_Miniboss.Default__Char_LS_Kiln_Miniboss_C","/Game/World_Base/Affixes/Overrides/Char_CindercladMonolith_Affixes.Char_CindercladMonolith_Affixes")
end