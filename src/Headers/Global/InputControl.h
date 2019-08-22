#pragma once

#include "../../Functions/Scripting/Scripting.h"
#include "Actor/Pawn/Character/Character.h"
#include "VirtualDevice/VirtualKeyboard.h"
#include "VirtualDevice/VitualMouse.h"
#include <map>
#include <functional>

// Контроллер управления персонажем (привязывается к Charachter)
class InputControl
{
	typedef std::function<void(void)> CFunc;
	typedef sf::Keyboard::Key KBKey;
	enum class Mode
	{
		control,
		input,
		somethingElse,
	};
	Character* slave;
	Mode mode;

	std::map<KBKey, CFunc> controlFunctions;
	void loadControlFunctions();
	void setControlFunctions();
	void callControlFunction(KBKey keyCode);
	
	static std::map<KBKey, const std::string> keyStrings;
public:
	InputControl();
	InputControl(const InputControl& temp) = default;
	InputControl(Character& slave_);
	InputControl(Character* slave_);
	~InputControl() = default;

	void processEvent(sf::Event event);
};