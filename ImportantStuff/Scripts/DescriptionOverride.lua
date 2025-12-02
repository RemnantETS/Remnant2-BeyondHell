local UEHelpers = require("UEHelpers")

function UEHelpers.GetKismetTextLibrary(ForceInvalidateCache)
    local DefaultObject

    if not ForceInvalidateCache then
        DefaultObject = ModRef:GetSharedVariable("UEHelpers_KismetTextLibrary")
        if DefaultObject and DefaultObject:IsValid() then return DefaultObject end
    end

    DefaultObject = StaticFindObject("/Script/Engine.Default__KismetTextLibrary")
    ModRef:SetSharedVariable("UEHelpers_KismetTextLibrary", DefaultObject)
    if not DefaultObject:IsValid() then error(string.format("%s not found", "/Script/Engine.Default__KismetTextLibrary")) end

    return DefaultObject
end

local function SetDescription (item,description)
    local KTL = UEHelpers.GetKismetTextLibrary(true)
	local item = StaticFindObject(item)
    if not item:IsValid() then return end
	item:SetPropertyValue("Description", KTL:Conv_StringToText(description))
end
local function SetFlavor (item,description)
    local KTL = UEHelpers.GetKismetTextLibrary(true)
	local item = StaticFindObject(item)
    if not item:IsValid() then return end
	item:SetPropertyValue("FlavorText", KTL:Conv_StringToText(description))
end

function SetDescriptions()
    Log("Overriding Descriptions and Flavor Text.")
	--SetDescription("/Game/World_Base/Items/Gems/Ranged/MetaGems/Ingenuity/MetaGem_Ingenuity.Default__MetaGem_Ingenuity_C","It is foolish to underestimate one's opponent, but it is perhaps an even greater folly to overestimate one's own weapon. One must take care not to push their weapon beyond its limits, lest it fail them when they need it most.\n\nBattles are won with superior weaponry, but wars are won with superior maintenance.")
    --SetFlavor("/Game/World_Base/Items/Gems/Ranged/MetaGems/Ingenuity/MetaGem_Ingenuity.Default__MetaGem_Ingenuity_C","\"You got too much faith in people, stranger. Guns are loyal, but people ain't. With people, you can give, and give, and give, and they'll keep on takin'... but the gun at your side? For every minute it takes away, it'll pay back an hour.\"")
	--SetAffixTable("/Game/World_Fae/Characters/Fae_Knight/Blueprints/Miniitem/Char_Fae_Knight_Miniitem.Default__Char_Fae_Knight_Miniitem_C","/Game/World_Base/Affixes/Overrides/Char_RedPrince_Affixes.Char_RedPrince_Affixes")
	--SetAffixTable("/Game/World_DLC2/Characters/Pan_Living_Stone_Kiln/Blueprints/Miniitem/Char_LS_Kiln_Miniitem.Default__Char_LS_Kiln_Miniitem_C","/Game/World_Base/Affixes/Overrides/Char_CindercladMonolith_Affixes.Char_CindercladMonolith_Affixes")
end