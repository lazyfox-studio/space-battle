#include "Game.h"

namespace Game
{
	void init()
	{
		// Инициализация таблиц (загрузка скриптов)
		TextureTable::init();
		FontTable::init();
		MusicTable::init();
	}
}