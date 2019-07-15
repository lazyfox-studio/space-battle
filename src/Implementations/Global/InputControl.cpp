#include "Global/InputControl.h"

std::map<InputControl::KBKey, const std::string> InputControl::keyStrings = {
	std::make_pair(InputControl::KBKey::W, "W")
};

/*void InputControl::setControlFunctions()
{
	controlFunctions[KBKey::W] = [this]() { ((Actor*)slave)->setPosition(0.f, 0.f); };
}

void InputControl::callControlFunction(KBKey keyCode)
{
	auto CFuncIter = controlFunctions.find(keyCode);
	if (CFuncIter != controlFunctions.end())
		((*CFuncIter).second)();
}*/

void InputControl::loadControlFunctions()
{
	LuaScript script(Scripting::lua);
	script.execute("config/Controls/Control.lua");
}

void InputControl::callControlFunction(KBKey code)
{
	const std::string& sCode = keyStrings[code];
	luabridge::LuaRef func = Scripting::lua.getGlobal("InputControl")["Control"][sCode];
	if (func.isNil())
		return;
	func((Actor*)slave);
}

InputControl::InputControl()
{
	//setControlFunctions();
	slave = nullptr;
	mode = Mode::control;
}

InputControl::InputControl(Character& slave_)
{
	//setControlFunctions();
	slave = &slave_;
	mode = Mode::control;
}

InputControl::InputControl(Character* slave_)
{
	//setControlFunctions();
	slave = slave_;
	mode = Mode::control;
}

void InputControl::processEvent(sf::Event event)
{
	if(mode == Mode::control)
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			callControlFunction(event.key.code);
			break;
		case sf::Event::MouseButtonPressed:
			// do something
			break;
		}
}
