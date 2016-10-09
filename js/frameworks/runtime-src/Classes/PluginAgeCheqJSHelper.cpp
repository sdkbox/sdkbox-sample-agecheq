#include "PluginAgeCheqJSHelper.h"
#include "PluginAgeCheq/PluginAgeCheq.h"
#include "SDKBoxJSHelper.h"

extern JSObject* jsb_sdkbox_PluginAgeCheq_prototype;
static JSContext* s_cx = nullptr;

class AgeCheqListenerJS : public sdkbox::AgeCheqListener, public sdkbox::JSListenerBase
{
public:
    AgeCheqListenerJS():sdkbox::JSListenerBase() {
    }

    void checkResponse(const std::string& rtn,
                               const std::string& rtnmsg,
                               int apiversion,
                               int checktype,
                               bool appauthorized,
                               bool appblocked,
                               int parentverified,
                               bool under13,
                               bool under18,
                               bool underdevage,
                               int trials) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = "checkResponse";
        JS::RootedObject obj(cx, getJSDelegate());
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif
        jsval dataVal[11];
        dataVal[0] = std_string_to_jsval(cx, rtn);;
        dataVal[1] = std_string_to_jsval(cx, rtnmsg);
        dataVal[2] = INT_TO_JSVAL(apiversion);
        dataVal[3] = INT_TO_JSVAL(checktype);
        dataVal[4] = BOOLEAN_TO_JSVAL(appauthorized);
        dataVal[5] = BOOLEAN_TO_JSVAL(appblocked);
        dataVal[6] = INT_TO_JSVAL(parentverified);
        dataVal[7] = BOOLEAN_TO_JSVAL(under13);
        dataVal[8] = BOOLEAN_TO_JSVAL(under18);
        dataVal[9] = BOOLEAN_TO_JSVAL(underdevage);
        dataVal[10] = INT_TO_JSVAL(trials);

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(sizeof(dataVal)/sizeof(*dataVal), dataVal), &retval);
#else
            JS_CallFunctionName(cx, obj, func_name, sizeof(dataVal)/sizeof(*dataVal), dataVal, &retval);
#endif
        }
    }

    void associateDataResponse(const std::string& rtn,
                                       const std::string& rtnmsg) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = "associateDataResponse";
        JS::RootedObject obj(cx, getJSDelegate());
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif
        jsval dataVal[2];
        dataVal[0] = std_string_to_jsval(cx, rtn);;
        dataVal[1] = std_string_to_jsval(cx, rtnmsg);

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(sizeof(dataVal)/sizeof(*dataVal), dataVal), &retval);
#else
            JS_CallFunctionName(cx, obj, func_name, sizeof(dataVal)/sizeof(*dataVal), dataVal, &retval);
#endif
        }
    }

};

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginAgeCheqJS_PluginAgeCheq_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#else
bool js_PluginAgeCheqJS_PluginAgeCheq_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginAgeCheqJS_PluginAgeCheq_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    s_cx = cx;
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    if (argc == 1) {

        if (!args.get(0).isObject())
        {
            ok = false;
        }

        JSB_PRECONDITION2(ok, cx, false, "js_PluginAgeCheqJS_PluginAgeCheq_setIAPListener : Error processing arguments");
        AgeCheqListenerJS* wrapper = new AgeCheqListenerJS();
        wrapper->setJSDelegate(args.get(0));
        sdkbox::PluginAgeCheq::setListener(wrapper);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginAgeCheqJS_PluginAgeCheq_setIAPListener : wrong number of arguments");
    return false;
}


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginAgeCheqJS_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginAgeCheq", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginAgeCheqJS_PluginAgeCheq_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#else
void register_all_PluginAgeCheqJS_helper(JSContext* cx, JSObject* global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, JS::RootedObject(cx, global), "sdkbox.PluginAgeCheq", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginAgeCheqJS_PluginAgeCheq_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginAgeCheqJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginAgeCheq", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginAgeCheqJS_PluginAgeCheq_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#endif
