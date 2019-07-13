#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tables/TextureTable.h"
#include "Actor/Actor.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

    Actor tester(5, 5, 10, 10, 0, 0, false, false, sf::Vector2f(0, 0), "Spaceship1");
    

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