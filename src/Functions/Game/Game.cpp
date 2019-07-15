#include "Game.h"

namespace Game
{
	LuaEnv lua = LuaEnv();

	void init()
	{
		// ������������� ������ (�������� ��������)
		TextureTable::init();
		FontTable::init();
		MusicTable::init();
	}
}