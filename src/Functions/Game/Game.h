#pragma once

#include <SFML/Graphics.hpp>
#include "LuaScript/LuaEnv.h"
#include "Tables/FontTable.h"
#include "Tables/MusicTable.h"
#include "Tables/TextureTable.h"

namespace Game
{
	LuaEnv lua = LuaEnv();

	void init();
}