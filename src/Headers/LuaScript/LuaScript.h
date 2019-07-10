#pragma once

#include <string>
extern "C" {
	# include "lua.h"
	# include "lauxlib.h"
	# include "lualib.h"
}
#include "LuaBridge/LuaBridge.h"

class LuaScript
{
	static lua_State* L;
	static unsigned states;
	std::string filename;
public:
	LuaScript();
	LuaScript(const std::string filename_);
	~LuaScript();

	luabridge::LuaRef getGlobal(const std::string varName);
};