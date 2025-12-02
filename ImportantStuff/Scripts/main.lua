GlobalAr = nil
local ModName = "[BeyondHell] "

function Log(Message, ...)
    printf(Message .. "\n", ...)
    if type(GlobalAr) == "userdata" and GlobalAr:type() == "FOutputDevice" then
        GlobalAr:Log(Message)
    end
end

function printf(format, ...)
    print(ModName .. string.format(format, ...))
end

local function GetModActor()
    local Actors = FindAllOf("ModActor_C")
    if not Actors then return false end
    for _,Actor in ipairs(Actors) do
        if Actor:GetClass():GetFullName():match("Z_BeyondHell_P") then
            return Actor
        end
    end
    return false
end

require("AffixTableManager")
require("DescriptionOverride")
require("BeyondHell")


RegisterHook("/Script/Engine.PlayerController:ClientRestart", function(self, NewPawn)
    ExecuteInGameThread(function()
	if GetModActor() then
		Log("Found ModActor")
        	SetStats()
		SetAffixes()
		SetDescriptions()
	else
		Log("Missing ModActor")
	end
    end)
end)


NotifyOnNewObject("/Script/UMG.WrapBox", function(newObject)
    ExecuteAsync(function()
        local name = newObject:GetFullName()
	if name:match("ArchetypeList") then
		newObject:SetPropertyValue("WrapSize", 800)
		newObject:SetPropertyValue("InnerSlotPadding", {X=-50.0,Y=-50.0})
	end
    end)
end)