#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tables/DTextureTable.h"
#include "Actor/Actor.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	// test
	DTextureTable::load("Empty");
	DTexture t = DTextureTable::get("Empty");
	std::cout << t.width;

    Actor tester(5, 5, 10, 10, 0, 0, false, false, sf::Vector2f(0, 0), "Empty");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
        tester.drawIn(window);
		window.draw(shape);
		window.display();
	}

	return 0;
}