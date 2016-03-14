
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    sdkbox.PluginAgeCheq:init()
    sdkbox.PluginAgeCheq:setListener(function(data)
        if "checkResponse" == data.event then
            dump(data)
        elseif "associateDataResponse" == data.event then
            dump(data)
        end
    end)

    local label1 = cc.Label:createWithSystemFont("check", "sans", 28)
    local item1 = cc.MenuItemLabel:create(label1)
    item1:onClicked(function()
        print("check")
        sdkbox.PluginAgeCheq:check("1426")
        sdkbox.PluginAgeCheq:associateData("1426", "ikfill")
    end)

    local menu = cc.Menu:create(item1)
    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)
end

return MainScene
