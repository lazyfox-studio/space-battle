#pragma once

#include "SFML/Graphics.hpp"

// Виджет (элемент графического интерфейса)
class Widget
{
protected:
	// Координаты элемента
	float x;
	float y;

public:
	// Конструкторы и деструктор
	Widget();
	Widget(const Widget& temp);
	Widget(sf::Sprite&);
	virtual ~Widget();

	virtual sf::FloatRect getLocalBounds() const = 0;

	virtual void setPosition(sf::Vector2f) = 0;
	virtual void setWidth(float) = 0;
	virtual void drawIn(sf::RenderWindow&) = 0;
};