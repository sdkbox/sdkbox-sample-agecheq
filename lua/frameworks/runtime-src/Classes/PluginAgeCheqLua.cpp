#include "PluginAgeCheqLua.hpp"
#include "PluginAgeCheq/PluginAgeCheq.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginAgeCheqLua_PluginAgeCheq_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAgeCheq",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAgeCheqLua_PluginAgeCheq_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginAgeCheq::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAgeCheq:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAgeCheqLua_PluginAgeCheq_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAgeCheqLua_PluginAgeCheq_associateData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAgeCheq",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAgeCheq:associateData");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginAgeCheq:associateData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAgeCheqLua_PluginAgeCheq_associateData'", nullptr);
            return 0;
        }
        sdkbox::PluginAgeCheq::associateData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAgeCheq:associateData",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAgeCheqLua_PluginAgeCheq_associateData'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAgeCheqLua_PluginAgeCheq_check(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAgeCheq",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAgeCheq:check");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAgeCheqLua_PluginAgeCheq_check'", nullptr);
            return 0;
        }
        sdkbox::PluginAgeCheq::check(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAgeCheq:check",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAgeCheqLua_PluginAgeCheq_check'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginAgeCheqLua_PluginAgeCheq_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginAgeCheq)");
    return 0;
}

int lua_register_PluginAgeCheqLua_PluginAgeCheq(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginAgeCheq");
    tolua_cclass(tolua_S,"PluginAgeCheq","sdkbox.PluginAgeCheq","",nullptr);

    tolua_beginmodule(tolua_S,"PluginAgeCheq");
        tolua_function(tolua_S,"init", lua_PluginAgeCheqLua_PluginAgeCheq_init);
        tolua_function(tolua_S,"associateData", lua_PluginAgeCheqLua_PluginAgeCheq_associateData);
        tolua_function(tolua_S,"check", lua_PluginAgeCheqLua_PluginAgeCheq_check);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginAgeCheq).name();
    g_luaType[typeName] = "sdkbox.PluginAgeCheq";
    g_typeCast["PluginAgeCheq"] = "sdkbox.PluginAgeCheq";
    return 1;
}
TOLUA_API int register_all_PluginAgeCheqLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginAgeCheqLua_PluginAgeCheq(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

