#pragma once

#include <SFML/Graphics.hpp>
#include "Tables/FontTable.h"
#include "Tables/MusicTable.h"
#include "Tables/TextureTable.h"

namespace Game
{
	extern LuaEnv lua;

	void init();
}