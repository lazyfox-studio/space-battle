#pragma once

#include <SFML/Graphics.hpp>
#include "Global/WindowControl.h"

// Виджет (элемент графического интерфейса)
class Widget
{
protected:
	// Координаты элемента
	float x;
	float y;

	// Указатель на окно (для отслеживания углов)
	WindowControl::screenCorners* corners;
public:
	// Конструкторы и деструктор
	Widget();
	Widget(const Widget& temp);
	Widget(sf::Sprite&);
	~Widget();

	virtual void drawIn(sf::RenderWindow& window);
};