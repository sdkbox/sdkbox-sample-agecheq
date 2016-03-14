#ifndef __PluginAgeCheqJS_h__
#define __PluginAgeCheqJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginAgeCheq_class;
extern JSObject *jsb_sdkbox_PluginAgeCheq_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginAgeCheqJS_PluginAgeCheq(JSContext *cx, JS::HandleObject global);
void register_all_PluginAgeCheqJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginAgeCheqJS_PluginAgeCheq(JSContext *cx, JSObject* global);
void register_all_PluginAgeCheqJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginAgeCheqJS_PluginAgeCheq_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginAgeCheqJS_PluginAgeCheq_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAgeCheqJS_PluginAgeCheq_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAgeCheqJS_PluginAgeCheq_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAgeCheqJS_PluginAgeCheq_associateData(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAgeCheqJS_PluginAgeCheq_associateData(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAgeCheqJS_PluginAgeCheq_check(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAgeCheqJS_PluginAgeCheq_check(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

