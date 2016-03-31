
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

    local resultLabel = cc.Label:createWithSystemFont("Response:None", "sans", 16);
    resultLabel:setPosition(display.width/2, size.height + 200);
    self:addChild(resultLabel);
    self.resultLabel = resultLabel;
    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    sdkbox.PluginAgeCheq:init()
    sdkbox.PluginAgeCheq:setListener(function(data)
        if "checkResponse" == data.event then
            dump(data)

            local strInfo = "checkResponse:"
                .. "\n    rtn:" .. data.rtn
                .. "\n    rtnmsg:" .. data.rtnmsg
                .. "\n    apiversion:" .. data.apiversion
                .. "\n    checktype:" .. data.checktype
                .. "\n    appauthorized:" .. tostring(data.appauthorized)
                .. "\n    appblocked:" .. tostring(data.appblocked)
                .. "\n    parentverified:" .. data.parentverified
                .. "\n    under13:" .. tostring(data.under13)
                .. "\n    under18:" .. tostring(data.under18)
                .. "\n    underdevage:" .. tostring(data.underdevage)
                .. "\n    trials:" .. data.trials

            self.resultLabel:setString(strInfo)

        elseif "associateDataResponse" == data.event then
            dump(data)

            local strInfo = self.resultLabel:getString()
                .. "\nassociateDataResponse:"
                .. "\n    rtn:" .. data.rtn
                .. "\n    rtnmsg:" .. data.rtnmsg

            self.resultLabel:setString(strInfo)
        end
    end)

    local label1 = cc.Label:createWithSystemFont("Check", "sans", 28)
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
