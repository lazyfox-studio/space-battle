#include "Game.h"

namespace Game
{
	LuaEnv lua = LuaEnv();

	void init()
	{
		// Инициализация таблиц (загрузка скриптов)
		TextureTable::init();
		FontTable::init();
		MusicTable::init();
	}
}