	local Items = {
	--Trinkets--
	["/Game/World_DLC1/Items/Trinkets/Rings/BurdenOfTheSciolist/Ring_BurdenOfTheSciolist.Ring_BurdenOfTheSciolist_C"] = {
		["Skill/ModDamageBonus"] = 25
	},
	["/Game/World_DLC3/Items/Trinkets/Amulets/ReactionChain/Amulet_ReactionChain.Amulet_ReactionChain_C"] = {
		["ModPowerConversion"] = 0.2
	},
	["/Game/World_DLC1/Items/Trinkets/Rings/AtonementFold/Ring_AtonementFold.Ring_AtonementFold_C"] = {
		["CritChance"] = 10
	},
	["/Game/World_DLC2/Items/Relics/ProfaneHeart/Relic_Consumable_ProfaneHeart.Relic_Consumable_ProfaneHeart_C"] = {
		["LifeStealPassiveBuff"] = 1.5
	},

	--Skills--
	["/Game/Characters/Player/Base/Character_Player_ComputedStats.Character_Player_ComputedStats_C"] = {
		["SkillCooldownModMin"] = -95
	},
	["/Game/World_Base/Items/Archetypes/Challenger/Skills/WarStomp/Skill_WarStomp.Skill_WarStomp_C"] = {
		["ShockwaveDamage"] = 250,
		["ShockwaveRange"] = 800,
		["CooldownTime"] = 40
	},
	["/Game/World_Base/Items/Archetypes/Summoner/Skills/MinionHollow/Skill_SummonHollowMinion.Skill_SummonHollowMinion_C"] = {
		["MaxSummons"] = 3,
		["MaxCharges"] = 3,
		["Charges"] = 3,
		["CooldownTime"] = 20
	},
	["/Game/World_Base/Items/Archetypes/Summoner/Skills/MinionFlyer/Skill_SummonFlyerMinion.Skill_SummonFlyerMinion_C"] = {
		["CooldownTime"] = 30
	},
	["/Game/World_Base/Items/Archetypes/Summoner/Skills/MinionBrute/Skill_SummonBruteMinion.Skill_SummonBruteMinion_C"] = {
		["CooldownTime"] = 60
	},
	["/Game/World_Base/Items/Archetypes/Engineer/Skills/Skill_FlameThrower/Weapon_Deployable_FlameThrower.Weapon_Deployable_FlameThrower_C"] = {
		["DeployedDamageScalar"] = 1.0,
		["BurningDamage"] = 300,
		["BurningDuration"] = 5
	},
	["/Game/World_Base/Items/Archetypes/Engineer/Skills/Skill_Gatling/Weapon_Deployable_Gatling.Weapon_Deployable_Gatling_C"] = {
		["DeployedDamageScalar"] = 0.7
	},
	["/Game/World_Base/Items/Archetypes/Archon/Skills/HavocForm/Skill_HavocForm.Skill_HavocForm_C"] = {
		["FireSkillDurationReduction"] = 0.0,
		["ShieldSkillDurationReduction"] = 0.0,
		["EvadeSkillDurationReduction"] = 0.0,
		["PrimaryDamage"] = 48,
		["Damage"] = 48
	},
	
	--Weapons--
	["/Game/World_Base/Items/Weapons/Melee/Standard/Hammer/AtomSmasher/Weapon_AtomSmasher.Weapon_AtomSmasher_C"] = {
		["MeleeSpeedMod"] = 15,
		["BuffDuration"] = 10
	},
	["/Game/World_DLC2/Items/Weapons/Thorn/Weapon_Thorn.Weapon_Thorn_C"] = {
		["SingleNeedleExplisionDamage"] = 20,
		["BaseBlowbackDamage"] = 60
	},
	["/Game/Events/Valentines/Items/Weapons/Corrupted_Savior/Weapon_CorruptedSavior.Weapon_CorruptedSavior_C"] = {
		["NumModChargesToReachFastestFireRate"] = 3,
		["ModPowerDecay"] = 0
	},
	["/Game/World_DLC2/Items/Weapons/CrystalStaff/Weapon_CrystalStaff.Weapon_CrystalStaff_C"] = {
		["ModDuration"] = 20
	},
	["/Game/World_DLC1/Items/Weapons/Melee/Scythe/Scythe_Ritualist/Weapon_RitualistScythe.Weapon_RitualistScythe_C"] = {
		["DamageBuff"] = 35
	},
	["/Game/World_Base/Items/Weapons/Melee/Standard/Hatchet/KrellAxe/Weapon_KrellAxe.Weapon_KrellAxe_C"] = {
		["ShockDamage"] = 100,
		["Stamina Cost"] = 15
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/RedDoeStaff/Weapon_RedDoeStaff.Weapon_RedDoeStaff_C"] = {
		["DamageChargeThreshold"] = 200,
		["RedDoeDamage"] = 200
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/Godsplitter/Weapon_Godsplitter.Weapon_Godsplitter_C"] = {
		["Duration"] = 3
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/WorldsEdge/Weapon_WorldsEdge.Weapon_WorldsEdge_C"] = {
		["StaminaCost"] = 20
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/HuntressSpear/Weapon_HuntressSpear.Weapon_HuntressSpear_C"] = {
		["Stamina Cost"] = 15
	},
	["/Game/World_DLC3/Items/Weapons/DarkMatterGauntlets/Weapon_DarkMatterGauntlets.Weapon_DarkMatterGauntlets_C"] = {
		["ChargeAttackBuffReduction"] = 0.5,
		["InChargeTimerMax"] = 3.0,
		["ModDuration"] = 20.0,
		["BeamDamage"] = 75.0
	},
	["/Game/World_DLC2/Items/Weapons/Flail_Mirage/Weapon_Mirage.Weapon_Mirage_C"] = {
		["CycloneDPS"] = 70,
		["CycloneExposedDuration"] = 6
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/FeralJudgment/Weapon_FeralJudgment.Weapon_FeralJudgment_C"] = {
		["DamageDelay"] = 1.0,
		["DeathSentenceDamagePerHit"] = 35,
		["BleedingTargetDamageMod"] = 35
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/Dreamcatcher/Weapon_Dreamcatcher.Weapon_Dreamcatcher_C"] = {
		["ReverieDuration"] = 30,
		["DamageChargeThreshold"] = 200,
		["DreamwaveDamageMod"] = 3.5,
		["DreamwaveMoveScalarBonus"] = 0.05
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/TalRatha_Hammer/Weapon_TalRatha_Hammer.Weapon_TalRatha_Hammer_C"] = {
		["BuffDuration"] = 15,
		["Range"] = 600,
		["AcidDamage"] = 250,
		["AcidDuration"] = 3,
		["SlamAcidDamage"] = 250,
		["SlamAcidDuration"] = 6
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/Nightshade/Weapon_Nightshade.Weapon_Nightshade_C"] = {
		["MeleeHealthStealMod"] = 10,
		["Duration"] = 10
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/HerosSword/Weapon_HerosSword.Weapon_HerosSword_C"] = {
		["StaminaCost"] = 2
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/Stonebreaker/Weapon_Stonebreaker.Weapon_Stonebreaker_C"] = {
		["ShockwaveDamage"] = 150,
		["ShockwaveVelocity"] = 1500
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/AtomSplitter/Weapon_AtomSplitter.Weapon_AtomSplitter_C"] = {
		["ChargeDistanceMultiplier"] = 5,
		["StaminaCost"] = 5,
		["StaminaCostHeavy"] = 7
	},

	--Mods--
	["/Game/World_Jungle/Items/Mods/Mod_AstralBurst/Mod_AstralBurst.Mod_AstralBurst_C"] = {
		["ProjectileDamage"] = 45,
		["MaxCharges"] = 2
	},
	["/Game/World_Root/Items/Mods/Mod_Skewer/Mod_Skewer.Mod_Skewer_C"] = {
		["ImpactDamage"] = 150,
		["TrapDamage"] = 35
	},
	["/Game/World_Base/Items/Weapons/LongGuns/Special/AlphaOmega/Mod_BetaRay.Mod_BetaRay_C"] = {
		["RateOfFire"] = 2.5
	},
	["/Game/World_Base/Items/Weapons/LongGuns/Special/AlphaOmega/Mod_BetaRay/Action_Buff_BetaRayMark.Action_Buff_BetaRayMark_C"] = {
		["DamageScalarIncreasePerBonusLevel"] = 0.75
	},
	["/Game/World_Fae/Items/Mods/Mod_BloodDraw/Mod_BloodDraw.Mod_BloodDraw_C"] = {
		["ImpactDamage"] = 330,
		["BleedDuration"] = 10,
		["NumProjectilesIndex"] = 6,
		["AttachDamage"] = 200
	},
	["/Game/World_Base/Items/Weapons/LongGuns/Special/Merciless/Mod_Bloodline/Mod_Bloodline.Mod_Bloodline_C"] = {
		["Damage"] = 225,
		["RateOfFire"] = 2
	},
	["/Game/World_Nerud/Items/Mods/Bore/Mod_Bore.Mod_Bore_C"] = {
		["BoreDuration"] = 15,
		["BurrowDamage"] = 80
	},
	["/Game/World_Base/Items/Weapons/HandGuns/Special/Enigma/Mod_ChaosDriver/Mod_ChaosDriver.Mod_ChaosDriver_C"] = {
		["LinkDamagePerSecond"] = 50,
		["MaxTetherDistance"] = 2000,
		["ShockDamage"] = 50
	},
	["/Game/World_Base/Items/Mods/ConcussiveShot/Mod_ConcussiveShot.Mod_ConcussiveShot_C"] = {
		["MaxCharges"] = 3,
		["BlastDamage"] = 200,
		["MaxRange"] = 1200
	},
	["/Game/World_DLC1/Items/Mods/Mod_CreepingMist/Mod_CreepingMist.Mod_CreepingMist_C"] = {
		["MistMaxRadius"] = 1000,
		["StatusEffectDebuff"] = -35,
		["CritChanceBuff"] = 10
	},
	["/Game/World_Base/Items/Weapons/HandGuns/Special/Sorrow/Mod_Eulogy/Mod_Eulogy.Mod_Eulogy_C"] = {
		["PenetrationDamage"] = 50
	},
	["/Game/World_Fae/Items/Mods/Mod_Familiar/Mod_Familiar.Mod_Familiar_C"] = {
		["Damage"] = 35,
		["UnmodifiedDuration"] = 20
	},
	["/Game/World_Jungle/Items/Mods/Mod_Fargazer/Mod_Fargazer.Mod_Fargazer_C"] = {
		["DOTDuration"] = 10,
		["Damage"] = 25
	},
	["/Game/World_Fae/Items/Mods/Mod_Firestorm/Mod_Firestorm.Mod_Firestorm_C"] = {
		["DOTDamage"] = 125,
		["BurnDamage"] = 200
	},
	["/Game/World_DLC2/Items/Mods/FlyingBombTrap/Mod_FlyingBombTrap.Mod_FlyingBombTrap_C"] = {
		["Duration"] = 30,
		["TrapDamage"] = 150,
		["AcidDamage"] = 200,
		["MaxTrapsFired"] = 20,
		["FireDelay"] = 1.5,
		["AOERadius"] = 500,
		["TrapRadius"] = 250,
		["RingDamage"] = 150
	},
	["/Game/Events/Valentines/Items/Weapons/Corrupted_Savior/Mod_FusionCannon.Mod_FusionCannon_C"] = {
		["Damage"] = 125
	},
	["/Game/World_DLC1/Items/Mods/Mod_KnightGuard/Mod_KnightGuard.Mod_KnightGuard_C"] = {
		["Damage"] = 85
	},
	["/Game/World_DLC1/Items/Weapons/Anguish/Mod/Mod_LoathTheWeak.Mod_LoathTheWeak_C"] = {
		["AOEDamage"] = 25,
		["NeedleExplosionDelay"] = 1
	},
	["/Game/Events/Valentines/Items/Weapons/CorruptedNebula/Mod_NanoPhase/Mod_NanoPhase.Mod_NanoPhase_C"] = {
		["ExplosionBaseDamage"] = 75,
		["CorrodedDOTDuration"] = 5
	},
	["/Game/World_Base/Items/Weapons/HandGuns/Special/Nebula/Mod_NanoSwarm/Mod_NanoSwarm.Mod_NanoSwarm_C"] = {
		["Damage"] = 6,
		["Duration"] = 15
	},	
	["/Game/World_DLC1/Items/Mods/Mod_RingOfSpears/Mod_RingOfSpears.Mod_RingOfSpears_C"] = {
		["SpearImpactBaseDamage"] = 125,
		["ProximityTickBaseDamage"] = 15,
		["SecondaryUseAnimation"] = FName("Action_UtilityBreathOfTheDesert")
	},
	["/Game/World_Jungle/Items/Mods/Mod_Rootlash/Mod_Rootlash.Mod_Rootlash_C"] = {
		["Damage"] = 50,
		["RateOfFire"] = 2
	},
	["/Game/World_DLC2/Items/Weapons/Monolith/Mod_Sandstorm/Mod_Sandstorm.Mod_Sandstorm_C"] = {
		["CycloneDPS"] = 65
	},
	["/Game/World_Base/Items/Mods/ScrapShot/Mod_ScrapShot.Mod_ScrapShot_C"] = {
		["DOTDamage"] = 35,
		["CaltropDuration"] = 15,
		["BlastRadius"] = 400
	},
	["/Game/World_Base/Items/Weapons/HandGuns/Special/Meridian/Mod_Screamer/Mod_Screamer.Mod_Screamer_C"] = {
		["Damage"] = 300,
		["RateOfFire"] = 2.5,
		["BlastRadius"] = 400
	},
	["/Game/World_Base/Items/Weapons/LongGuns/Special/Sporebloom/Mod_SporeShot/Mod_SporeShot.Mod_SporeShot_C"] = {
		["DOTDamage"] = 100,
		["Damage"] = 325
	},
	["/Game/World_Base/Items/Weapons/LongGuns/Special/Sagittarius/Mod_Starfall/Mod_Starfall.Mod_Starfall_C"] = {
		["ArrowImpactDamage"] = 300,
		["ExplosionDamage"] = 60,
		["Duration"] = 10,
		["StarFragmentBlastRadius"] = 300
	},
	["/Game/World_Nerud/Items/Mods/StasisBeam/Mod_StasisBeam.Mod_StasisBeam_C"] = {
		["Damage"] = 75,
		["MaxCharges"] = 50
	},
	["/Game/World_Jungle/Items/Mods/Mod_Tremor/Mod_Tremor.Mod_Tremor_C"] = {
		["Damage"] = 100,
		["QuakeDuration"] = 10
	},
	["/Game/World_DLC3/Items/Mods/Voidlight/Mod_Voidlight.Mod_Voidlight_C"] = {
		["BaseProjectileDamage"] = 200,
		["DamageBuffPerEmpowerment"] = 100,
		["PhysicalDamageThreshold"] = 80
	},
	["/Game/World_Fae/Items/Mods/Mod_VoltaicRondure/Mod_VoltaicRondure.Mod_VoltaicRondure_C"] = {
		["OrbDamage"] = 50,
		["ShockDamage"] = 60
	},
	["/Game/World_Base/Items/Weapons/Melee/Special/SpectralBlade/Weapon_SpectralBlade.Weapon_SpectralBlade_C"] = {
		["SlashBaseDamage"] = 100,
		["AuraRadius"] = 1000
	},
	["/Game/World_Base/Items/Weapons/LongGuns/Special/CorruptedDeceit/Mod_Windfall/Mod_Windfall.Mod_Windfall_C"] = {
		["FreezeDuration"] = 5
	},
	["/Game/World_Fae/Items/Mods/Mod_Witchfire/Mod_Witchfire.Mod_Witchfire_C"] = {
		["BurnDamage"] = 250,
		["BurnDuration"] = 5,
		["FireDamage"] = 250,
		["Duration"] = 15
	},

}
local function ContainsKey(Key)
	for Item,Values in pairs(Items) do
		--Log("Checking \n%s\n%s", Item,Key)
		if Item == Key then return true end
	end
	return false
end
NotifyOnNewObject("/Script/GunfireRuntime.Equipment", function(Item)
    ExecuteInGameThread(function()
        local ItemClass = Item:GetClass():GetFullName():sub(25)
        if not ContainsKey(ItemClass) then return end
		Log("EquipmentLoad: "..ItemClass)
        for Stat, Value in pairs(Items[ItemClass]) do
            Item:SetPropertyValue(Stat,Value)
        end
    end)
end)
NotifyOnNewObject("/Script/GunfireSaveSystem.PersistenceComponent", function(Item)
    ExecuteAsync(function()
        Item = Item:GetOuter()
        local ItemClass = Item:GetClass():GetFullName():sub(25)
		if not ContainsKey(ItemClass) then return end
		Log("PersistenceLoad: "..ItemClass)
        for Stat, Value in pairs(Items[ItemClass]) do
            Item:SetPropertyValue(Stat,Value)
        end
    end)
end)

local function GetDefault(asset)
    return asset:gsub("%.",".Default__")
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