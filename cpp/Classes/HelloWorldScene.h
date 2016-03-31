#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginAgeCheq/PluginAgeCheq.h"

class HelloWorld : public cocos2d::Layer, public sdkbox::AgeCheqListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
    void createTestMenu();

    void checkResponse(const std::string& rtn, const std::string& rtnmsg,
                       int apiversion, int checktype, bool appauthorized,
                       bool appblocked, int parentverified, bool under13,
                       bool under18, bool underdevage, int trials);
    
    void associateDataResponse(const std::string& rtn,
                               const std::string& rtnmsg);
    
    cocos2d::Label* _resultLabel;
};

#endif // __HELLOWORLD_SCENE_H__
