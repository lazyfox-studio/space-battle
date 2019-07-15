#include "Scripting.h"

namespace Scripting
{
	LuaEnv lua = LuaEnv();
	
	void init()
	{
		try {
			lua.getGlobalNamespace()
				.beginClass<Actor>("Actor")
				.addFunction("setPosition", &(Actor::setPosition))
				.addFunction("test", &(Actor::test))
				.endClass()
				.addFunction("playSound", playSound)
				.endNamespace();
		}
		catch (luabridge::LuaException& e)
		{
			std::cerr << e.what();
		}
		catch (...)
		{
			std::cerr << "something bad\n";
		}
	}

	void playSound(const std::string sound)
	{
		// haha
	}
}