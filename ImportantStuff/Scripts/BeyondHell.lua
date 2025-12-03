local Items = {
    --Trinkets
    ["/Game/World_DLC1/Items/Trinkets/Rings/BurdenOfTheSciolist/Ring_BurdenOfTheSciolist.Ring_BurdenOfTheSciolist_C"] = {
        ['Skill/ModDamageBonus']=25
    },
    ["/Game/World_DLC3/Items/Trinkets/Amulets/ReactionChain/Amulet_ReactionChain.Amulet_ReactionChain_C"] = {
        ["ModPowerConversion"] = 0.2
    },
	--Relics
	["/Game/World_DLC1/Items/Relics/BrokenHeart/Relic_Consumable_BrokenHeart.Relic_Consumable_BrokenHeart_C"] = {
		["HealthPercetage"] = 0.499999,
	},
    --Skills
    ["/Game/World_Base/Items/Archetypes/Engineer/Skills/Skill_FlameThrower/Weapon_Deployable_FlameThrower.Weapon_Deployable_FlameThrower_C"] = {
        ["DeployedDamageScalar"]=0.7,
        ["BurningDamage"]=200,
        ["BurningDuration"]=10
    },
    ["/Game/World_Base/Items/Archetypes/Challenger/Skills/WarStomp/Skill_WarStomp.Skill_WarStomp_C"] = {
        ["ShockwaveDamage"]=250,
        ["ShockwaveRange"]=800,
        ["CooldownTime"]=40
    },
    ["/Game/World_Base/Items/Archetypes/Summoner/Skills/MinionHollow/Skill_SummonHollowMinion.Skill_SummonHollowMinion_C"] = {
        ["MaxSummons"]= 3,
        ["MaxCharges"] = 3, 
        ["Charges"] = 3,
        ["CooldownTime"]= 20
    },
    ["/Game/World_Base/Items/Archetypes/Summoner/Skills/MinionFlyer/Skill_SummonFlyerMinion.Skill_SummonFlyerMinion_C"] = {
        ["CooldownTime"]= 30
    },
    ["/Game/World_Base/Items/Archetypes/Summoner/Skills/MinionBrute/Skill_SummonBruteMinion.Skill_SummonBruteMinion_C"] = {
        ["CooldownTime"]= 60
    },
    ["/Game/Characters/Player/Base/Character_Player_ComputedStats.Character_Player_ComputedStats_C"] = {
        ["SkillCooldownModMin"]=-95
    },
    ["/Game/World_Base/Items/Archetypes/Engineer/Skills/Skill_Gatling/Weapon_Deployable_Gatling.Weapon_Deployable_Gatling_C"] = {
        ["DeployedDamageScalar"]=0.7
    },
    ["/Game/World_Base/Items/Archetypes/Engineer/Skills/Skill_ImpactCannon/Weapon_Deployable_ImpactCannon.Weapon_Deployable_ImpactCannon_C"] = {
        ["DeployedDamageScalar"]=0.7
    },
    --Mods
    ["/Game/World_Jungle/Items/Mods/Mod_AstralBurst/Mod_AstralBurst.Mod_AstralBurst_C"] = {
        ["ProjectileDamage"]=45,
        ["MaxCharges"]=2
    },
    ["/Game/World_Root/Items/Mods/Mod_Skewer/Mod_Skewer.Mod_Skewer_C"] = {
        ["ImpactDamage"]=150,
        ["TrapDamage"]=35
    },
    ["/Game/World_DLC3/Items/Mods/Voidlight/Mod_Voidlight.Mod_Voidlight_C"] = {
        ["BaseProjectileDamage"]=200,
        ["DamageBuffPerEmpowerment"]=100
    },
    --Weapons
	
}
local function ContainsKey(Key)
    for Item,Values in pairs(Items) do
        --Log("Checking \n%s\n%s", Item,Key)
        if Item==Key then return true end
    end
    return false
end

NotifyOnNewObject("/Script/GunfireRuntime.Equipment", function(Item)
    ExecuteInGameThread(function()
        local ItemClass = Item:GetClass():GetFullName():sub(25)
        --Log("Item Loaded: %s",ItemClass)
        if not ContainsKey(ItemClass) then return end
        --Log("Item Found: %s",Item:GetFullName())
        for Stat, Value in pairs(Items[ItemClass]) do
            --Log("Instance Item Set: %s %s %.1f",Item:GetFullName(),Stat,Value)
            Item:SetPropertyValue(Stat,Value)
        end
    end)
end)

local function GetDefault(asset)
    return asset:gsub("%.",".Default__")
end

 local function ModifyStat (asset,name,value)
    local Item = StaticFindObject(asset)
    if not Item:IsValid() then return end
    --Log(asset)
    --Log('Key:'..name..', Value: '..value)
	Item:SetPropertyValue(name, value)
end

local function ModifyStats(asset,StatPairs)
	local Item = StaticFindObject(asset)
    if not Item:IsValid() then return end
	Log(asset)
	for k,x in pairs(StatPairs) do
		--Log('Key:'..k..', Value: '..x)
		Item:SetPropertyValue(k, x)
	end
end

local function BulkSet()
    for Item,Stats in pairs(Items) do 
        local DItem = StaticFindObject(GetDefault(Item))
        for Stat,Value in pairs(Stats) do
            if DItem:IsValid() then 
                --Log("Default Item Set: %s %s %.1f",Item,Stat,Value)
                DItem:SetPropertyValue(Stat,Value) 
            end
        end
    end
end

function SetStats()
    Log("Overriding Item Stats")
    BulkSet()
end