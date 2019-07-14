#include "Global/InputControl.h"

void InputControl::setControlFunctions()
{
	controlFunctions[KBKey::W] = [this]() { ((Actor*)slave)->setPosition(0.f, 0.f); };
}

void InputControl::callControlFunction(KBKey keyCode)
{
	auto CFuncIter = controlFunctions.find(keyCode);
	if (CFuncIter != controlFunctions.end())
		((*CFuncIter).second)();
}

InputControl::InputControl()
{
	setControlFunctions();
	slave = nullptr;
	mode = Mode::control;
}

InputControl::InputControl(Character& slave_)
{
	setControlFunctions();
	slave = &slave_;
	mode = Mode::control;
}

InputControl::InputControl(Character* slave_)
{
	setControlFunctions();
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
