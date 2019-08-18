#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Functions/Game/Game.h"
#include "Functions/Scripting/Scripting.h"

#include "Headers/Logger/Logger.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	Game::init();
	Scripting::init();

    Logger::start();
    Logger::log("Hello");
    Logger::log("World");

	LuaScript script(Scripting::lua, "config/Test.lua");
    Actor tester(5, 5, 5, std::vector <Square> (), false, false, sf::Vector2f(0, 0), "Spaceship1");
	try
	{
		(Scripting::lua.getGlobal("someFunc"))(&tester); // print test: 123
	}
	catch (luabridge::LuaException& e)
	{
		std::cerr << e.what();
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
        window.draw(shape);
        tester.drawIn(window);
		window.display();
	}

	return 0;
}