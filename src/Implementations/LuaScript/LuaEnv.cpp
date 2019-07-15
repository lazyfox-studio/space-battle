#include "..\..\Headers\LuaScript\LuaEnv.h"

LuaEnv::LuaEnv()
{
	L = luaL_newstate();
}

LuaEnv::~LuaEnv()
{
	lua_close(L);
}

luabridge::LuaRef LuaEnv::getGlobal(const std::string varName)
{
	return luabridge::getGlobal(L, varName.c_str());
}

luabridge::Namespace LuaEnv::getGlobalNamespace()
{
	return luabridge::getGlobalNamespace(L);
}
