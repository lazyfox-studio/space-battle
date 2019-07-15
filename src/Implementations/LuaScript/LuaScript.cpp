#include "LuaScript/LuaScript.h"


LuaScript::LuaScript(LuaEnv& env_)
{
	env = &env_;
}

LuaScript::LuaScript(LuaEnv& env_, const std::string filename_)
{
	env = &env_;
	if (luaL_loadfile(env->L, filename_.c_str()))
		return;
	else if (lua_pcall(env->L, 0, 0, 0))
		return;
}

int LuaScript::execute(const std::string filename_)
{
	int status = luaL_loadfile(env->L, filename_.c_str());
	if (status)
		return status;
	else if (lua_pcall(env->L, 0, 0, 0))
		return status;
	return status;
}
