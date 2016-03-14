
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
            cc.log("QUIT");
        });
        var menu = new cc.Menu(quit);
        var size = quit.getContentSize();
        menu.x = winsize.width - size.width / 2 - 16;
        menu.y = size.height / 2 + 16;
        this.addChild(menu);

        return true;
    },

    createTestMenu:function() {
        sdkbox.PluginAgeCheq.init();
        sdkbox.PluginAgeCheq.setListener({
            checkResponse : function (rtn, rtnmsg, apiversion, checktype, appauthorized, appblocked, parentverified, under13, under18, underdevage, trials) {
                cc.log("checkResponse rtn:" + rtn + " rtnmsg:" + rtnmsg
                    + " apiversion:" + apiversion + " checktype:" + checktype
                    + " appauthorized:" + appauthorized + " appblocked:" + appblocked
                    + " parentverified:" + parentverified + " under13:" + under13
                    + " under18:" + under18 + " underdevage:" + underdevage + " trials:" + trials);
            },
            associateDataResponse : function (rtn, rtnmsg) {
                cc.log("associateDataResponse rtn:" + rtn + " rtnmsg:" + rtnmsg);
            }
        });

        var item1 = new cc.MenuItemLabel(new cc.LabelTTF("check", "sans", 28), function() {
            cc.log("check");
            sdkbox.PluginAgeCheq.check("1426");
            sdkbox.PluginAgeCheq.associateData("1426", "ikfill");
        });

        var winsize = cc.winSize;
        var menu = new cc.Menu(item1);
        menu.x = winsize.width / 2;
        menu.y = winsize.height / 2;
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

