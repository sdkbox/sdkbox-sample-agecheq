
#ifndef __PLUGIN_AGECHEQ_LUA_HELPER_H__
#define __PLUGIN_AGECHEQ_LUA_HELPER_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

TOLUA_API int register_all_PluginAgeCheqLua_helper(lua_State* L);

#endif
