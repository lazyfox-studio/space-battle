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
	LuaEnv(const LuaEnv& temp);
	~LuaEnv();
	luabridge::LuaRef getGlobal(const std::string varName);
	luabridge::Namespace getGlobalNamespace();
	template<typename T> void push(const std::string ptrName, T* ptr);
};

template<typename T>
void LuaEnv::push(const std::string ptrName, T* ptr)
{
	luabridge::push(L, ptr);
	lua_setglobal(L, ptrName.c_str());
}
