#include "LuaScript/LuaScript.h"
#include "..\..\Headers\LuaScript\LuaScript.h"

unsigned LuaScript::states = 0U;
//lua_State* LuaScript::L = nullptr;

LuaScript::LuaScript()
{
	states++;
	//if (!L)
		L = luaL_newstate();
}

LuaScript::LuaScript(const std::string filename_) : LuaScript()
{
	if (luaL_loadfile(L, filename_.c_str()))
		return;
	else if (lua_pcall(L, 0, 0, 0))
		return;
	filename = filename_;
}

LuaScript::~LuaScript()
{
	//if (--states == 0U)
	//{
		lua_close(L);
		L = nullptr;
	//}
}

std::string LuaScript::getFilename() const
{
	return filename;
}

int LuaScript::execute(const std::string filename_)
{
	int status = luaL_loadfile(L, filename_.c_str());
	if (status)
		return status;
	else if (lua_pcall(L, 0, 0, 0))
		return status;
	filename = filename_;
	return status;
}

luabridge::LuaRef LuaScript::getGlobal(const std::string varName)
{
	if (filename.empty())
		throw std::exception("File not executed.");
	return luabridge::getGlobal(L, varName.c_str());
}
