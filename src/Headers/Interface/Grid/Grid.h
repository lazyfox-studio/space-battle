#pragma once

#include "Interface/Widget/Widget.h"
#include <vector>
#include <cmath>

// Менеджер блочной верстки
class Grid
{
public:
	struct Element
	{
		Widget* widget = nullptr;  // Указатель на элемент интерфейса
		unsigned cols = 0U;        // Количество занимаемых колонок (1-12)
		unsigned offset = 0U;      // Количество пустых колонок слева (1-12)
		unsigned rowspan = 0U;     // Количество объединяемых строк (для "угловых" конструкций)

		Element() = default;
		Element(const Element&) = default;
		Element(Widget* widget_);
		Element(std::pair<Widget*, unsigned> element);
		Element(std::pair<Widget*, std::initializer_list<unsigned>> element);
	};
	typedef std::vector<std::vector<Element>> Elements;
	Elements widgets;
private:
	sf::Vector2f position;
	float width;
	float margin;
public:

	Grid();
	Grid(const Grid& temp) = default;
	explicit Grid(float width_, sf::Vector2f position_ = sf::Vector2f(0.f, 0.f), float margin_ = 0U);
	explicit Grid(float width_, Elements widgets_, sf::Vector2f position_ = sf::Vector2f(0.f, 0.f), float margin_ = 0U);
	Grid(std::initializer_list<std::initializer_list<Element>> widgets_);
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

// Пример построения Grid:
// grid = {
//    { std::make_pair(widgetPtr1, {3}), std::make_pair(widgetPtr2, {6, 3}) },
//    { std::make_pair(widgetPtr3, {2}), std::make_pair(widgetPtr4, {2}), std::make_pair(widgetPtr5, {2}) },
//    { std::make_pair(widgetPtr6, {12}) },
//    { std::make_pair(widgetPtr7, {1}), std::make_pair(widgetPtr8, {10, 1}) }
// };