
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    CCLOG("Sample Startup");
    
    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);
    
    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));
    
    // add test menu
    createTestMenu();
    
    return true;
}

void HelloWorld::createTestMenu()
{
    sdkbox::PluginAgeCheq::setListener(this);
    
    auto menu = Menu::create();
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("check", "sans", 24), [](Ref*){
        CCLOG("check");
        sdkbox::PluginAgeCheq::check("1426");
        sdkbox::PluginAgeCheq::associateData("1426", "ikfill");
    }));
    
    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}


void HelloWorld::checkResponse(const std::string& rtn, const std::string& rtnmsg,
                               int apiversion, int checktype, bool appauthorized,
                               bool appblocked, int parentverified, bool under13,
                               bool under18, bool underdevage, int trials)
{
    CCLOG("checkResponse");
    CCLOG("  rtn: %s", rtn.c_str());
    CCLOG("  rtnmsg: %s", rtnmsg.c_str());
    CCLOG("  apiversion: %d", apiversion);
    CCLOG("  checktype: %d", checktype);
    CCLOG("  appauthorized: %s", appauthorized ? "YES" : "NO");
    CCLOG("  appblocked: %s", appblocked ? "YES" : "NO");
    CCLOG("  parentverified: %s", parentverified ? "YES" : "NO");
    CCLOG("  under13: %s", under13 ? "YES" : "NO");
    CCLOG("  under18: %s", under18 ? "YES" : "NO");
    CCLOG("  underdevage: %s", underdevage ? "YES" : "NO");
    CCLOG("  trials: %d", trials);
}

void HelloWorld::associateDataResponse(const std::string& rtn,
                                       const std::string& rtnmsg)
{
    CCLOG("associateDataResponse");
    CCLOG("  rtn: %s", rtn.c_str());
    CCLOG("  rtnmsg: %s", rtnmsg.c_str());
}

