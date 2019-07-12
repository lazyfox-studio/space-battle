﻿#pragma once

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

	virtual void drawIn(sf::RenderWindow& window) = 0;
};