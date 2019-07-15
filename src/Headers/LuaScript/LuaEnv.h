#pragma once

#include <string>
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#include "LuaBridge/LuaBridge.h"

class LuaEnv
{
	friend class LuaScript;
	lua_State* L;
public:
	LuaEnv();
	LuaEnv(const LuaEnv&) = default;
	~LuaEnv();
	luabridge::LuaRef getGlobal(const std::string varName);
	luabridge::Namespace getGlobalNamespace();
};
