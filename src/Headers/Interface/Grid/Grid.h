#pragma once

#include "Interface/Widget/Widget.h"
#include <vector>
#include <cmath>

// Менеджер блочной верстки
class Grid
{
public:
	typedef std::vector<std::vector<Widget*>> GridElements;
	GridElements widgets;
private:
	sf::Vector2f position;
	float width;
	float margin;
public:

	Grid();
	Grid(const Grid& temp) = default;
	explicit Grid(float width_, sf::Vector2f position_ = sf::Vector2f(0.f, 0.f), float margin_ = 10U);
	explicit Grid(float width_, GridElements widgets_, sf::Vector2f position_ = sf::Vector2f(0.f, 0.f), float margin_ = 10U);
	~Grid() = default;

	float getWidth() const;
	float getMargin() const;
	sf::Vector2f getPosition() const;

	void setWidth(float width_);
	void setMargin(float margin_);
	void setPosition(sf::Vector2f position_);

	void update(); // Вычисление позиций и размеров элементов
	void drawIn(sf::RenderWindow& window);
};