#include "Scripting.h"

namespace Scripting
{
	LuaEnv lua = LuaEnv();
	
	void init()
	{
		lua.getGlobalNamespace()
			.beginClass<Actor>("Actor")
			.addFunction("setPosition", &(Actor::setPosition))
			.addFunction("test", &(Actor::test))
			.endClass()
			.addFunction("playSound", playSound);
	}

	void playSound(const std::string sound)
	{
		// haha
	}
}