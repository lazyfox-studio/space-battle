#pragma once

#include "LuaScript/LuaScript.h"
#include "Actor/Actor.h"

namespace Scripting
{
	extern LuaEnv lua;

	void init();
	void playSound(const std::string sound);
}