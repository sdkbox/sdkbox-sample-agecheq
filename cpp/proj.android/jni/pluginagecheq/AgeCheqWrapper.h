
#ifndef _PLUGIN_AGECHEQ_WRAPPER_H_
#define _PLUGIN_AGECHEQ_WRAPPER_H_

#include "PluginAgeCheq.h"
#include "CocosMacros.h"

#define TAG        "AgeCheq"
#define VERSION    "3.02"
#define IOS_VERSION     "ios: v3.02:03.25.2015"
#define ANDROID_VERSION "android: v3.03 05.15.2015"
NS_COCOS_BEGIN

class AgeCheqWrapper {
public:
    static AgeCheqWrapper* getInstance();
    
    virtual bool init()=0;
    virtual void setListener(AgeCheqListener* listener)=0;
    virtual AgeCheqListener* getListener()=0;
    virtual void removeListener()=0;
    virtual void check(const std::string& ACPin)=0;
    virtual void associateData(const std::string& ACPin, const std::string& Data)=0;
};

class AgeCheqWrapperDisabled : public AgeCheqWrapper {
public:
    bool init() { return false; }
    void setListener(AgeCheqListener* listener) {}
    AgeCheqListener* getListener() { return NULL; }
    void removeListener() {}
    void check(const std::string& ACPin) {}
    void associateData(const std::string& ACPin, const std::string& Data) {}
};

class AgeCheqWrapperEnabled : public AgeCheqWrapper {
public:
    bool init();
    void setListener(AgeCheqListener* listener);
    AgeCheqListener* getListener();
    void removeListener();
    void check(const std::string& ACPin);
    void associateData(const std::string& ACPin,
                              const std::string& Data);

protected:
    bool nativeConfigure(const std::string appID, const std::string devKey);
    const char* nativeSDKVersion();

    AgeCheqListener* _listener = nullptr;
    std::string _appID = "";
    std::string _devKey = "";
};

NS_COCOS_END

#endif
