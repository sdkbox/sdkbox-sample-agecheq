

#ifndef __js__PluginAgeCheqJSHelper_H_
#define __js__PluginAgeCheqJSHelper_H_

#include "jsapi.h"
#include "jsfriendapi.h"

#if MOZJS_MAJOR_VERSION >= 31
void register_all_PluginAgeCheqJS_helper(JSContext* cx, JS::HandleObject global);
#else
void register_all_PluginAgeCheqJS_helper(JSContext* cx, JSObject* global);
#endif

#endif /* defined(__PluginAgeCheqJSHelper_H_) */
