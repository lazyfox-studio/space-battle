#pragma once

#include <SFML/Graphics.hpp>

// Виджет (элемент графического интерфейса)
class Widget
{
protected:
	// Координаты элемента
	float x;
	float y;

public:

	// Координаты угловых точек окна (общие для всех объектов)
	struct screenCorners
	{
		static sf::Vector2f topLeft;
		static sf::Vector2f topRight;
		static sf::Vector2f bottomLeft;
		static sf::Vector2f bottomRight;
	};
};