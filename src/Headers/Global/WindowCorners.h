#pragma once

#include <SFML/Graphics.hpp>
#include <array>

// Координаты угловых точек окна
class WindowCorners
{
	friend class Level;
	sf::Vector2f topLeft;
	sf::Vector2f topRight;
	sf::Vector2f bottomLeft;
	sf::Vector2f bottomRight;
	WindowCorners();
public:
	inline sf::Vector2f getTopLeft() const { return topLeft; }
	inline sf::Vector2f getTopRight() const { return topRight; }
	inline sf::Vector2f getBottomLeft() const { return bottomLeft; }
	inline sf::Vector2f getBottomRight() const { return bottomRight; }
	inline std::array<sf::Vector2f, 4> get() const;
};