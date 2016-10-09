
#include "PluginAgeCheqLuaHelper.h"
#include "PluginAgeCheq/PluginAgeCheq.h"
#include "SDKBoxLuaHelper.h"

class AgeCheqListenerLua : public sdkbox::AgeCheqListener {
public:
	AgeCheqListenerLua(): mLuaHandler(0) {
	}

	~AgeCheqListenerLua() {
		resetHandler();
	}

	void setHandler(int luaHandler) {
		if (mLuaHandler == luaHandler) {
			return;
		}
		resetHandler();
		mLuaHandler = luaHandler;
	}

	void resetHandler() {
		if (0 == mLuaHandler) {
			return;
		}

        LUAENGINE->removeScriptHandler(mLuaHandler);
		mLuaHandler = 0;
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
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("checkResponse")));
        dict.insert(std::make_pair("rtn", LuaValue::stringValue(rtn)));
        dict.insert(std::make_pair("rtnmsg", LuaValue::stringValue(rtnmsg)));
        dict.insert(std::make_pair("apiversion", LuaValue::intValue(apiversion)));
        dict.insert(std::make_pair("checktype", LuaValue::intValue(checktype)));
        dict.insert(std::make_pair("appauthorized", LuaValue::booleanValue(appauthorized)));
        dict.insert(std::make_pair("appblocked", LuaValue::booleanValue(appblocked)));
        dict.insert(std::make_pair("parentverified", LuaValue::intValue(parentverified)));
        dict.insert(std::make_pair("under13", LuaValue::booleanValue(under13)));
        dict.insert(std::make_pair("under18", LuaValue::booleanValue(under18)));
        dict.insert(std::make_pair("underdevage", LuaValue::booleanValue(underdevage)));
        dict.insert(std::make_pair("trials", LuaValue::intValue(trials)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void associateDataResponse(const std::string& rtn,
                                       const std::string& rtnmsg) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("associateDataResponse")));
        dict.insert(std::make_pair("rtn", LuaValue::stringValue(rtn)));
        dict.insert(std::make_pair("rtnmsg", LuaValue::stringValue(rtnmsg)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

private:
	int mLuaHandler;
};

int lua_PluginAgeCheqLua_PluginAgeCheq_setListener(lua_State* tolua_S) {
	int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAgeCheq",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        AgeCheqListenerLua* lis = static_cast<AgeCheqListenerLua*> (sdkbox::PluginAgeCheq::getListener());
        if (NULL == lis) {
            lis = new AgeCheqListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginAgeCheq::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAgeCheq::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAgeCheqLua_PluginAgeCheq_setListener'.",&tolua_err);
#endif
    return 0;
}


int extern_PluginAgeCheq(lua_State* L) {
	if (NULL == L) {
		return 0;
	}

	lua_pushstring(L, "sdkbox.PluginAgeCheq");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginAgeCheqLua_PluginAgeCheq_setListener);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_all_PluginAgeCheqLua_helper(lua_State* L) {
	tolua_module(L,"sdkbox",0);
	tolua_beginmodule(L,"sdkbox");

	extern_PluginAgeCheq(L);

	tolua_endmodule(L);
	return 1;
}


