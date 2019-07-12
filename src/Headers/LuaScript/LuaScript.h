#pragma once

#include <string>
extern "C" {
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}
#include "LuaBridge/LuaBridge.h"

class LuaScript
{
	//static lua_State* L;
	lua_State* L;
	static unsigned states;
	std::string filename;
public:
	LuaScript();
	LuaScript(const std::string filename_);
	~LuaScript();

	std::string getFilename() const;
	int execute(const std::string filename_);
	luabridge::LuaRef getGlobal(const std::string varName);
};