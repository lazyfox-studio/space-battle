#pragma once

#include "LuaScript/LuaEnv.h"

class LuaScript
{
	LuaEnv* env;
	LuaScript() = default;
	LuaScript(const LuaScript&) = default;
public:
	LuaScript(LuaEnv& env_);
	LuaScript(LuaEnv& env_, const std::string filename_);
	~LuaScript() = default;

	int execute(const std::string filename_);
};