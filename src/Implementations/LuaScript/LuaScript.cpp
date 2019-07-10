#include "LuaScript/LuaScript.h"

unsigned LuaScript::states = 0U;
lua_State* LuaScript::L = nullptr;

LuaScript::LuaScript()
{
	states++;
	if (!L)
		L = luaL_newstate();
}

LuaScript::LuaScript(const std::string filename_)
{
	if (luaL_loadfile(L, filename.c_str()) || lua_pcall(L, 0, 0, 0)) {
		return;
	}
	states++;
	filename = filename_;
}

LuaScript::~LuaScript()
{
	if(--states == 0U)
		lua_close(L);
}

luabridge::LuaRef LuaScript::getGlobal(const std::string varName)
{
	return luabridge::getGlobal(L, varName.c_str());
}
