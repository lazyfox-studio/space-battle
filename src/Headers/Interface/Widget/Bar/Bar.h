#pragma once

#include <SFML/Graphics.hpp>
#include "Interface/Widget/Widget.h"
#include "Flipbook/Flipbook.h"

// Полоса прогресса
class Bar : Widget
{
	typedef std::string TTD;
	Flipbook bar, background;
	float min, max;
	float* current;
public:
	Bar();
	Bar(const Bar& temp);
	Bar(float min_ = 0.f, float max_ = 1.f, TTD barTexture = "Empty", TTD backgroundTexture = "Empty");
	explicit Bar(float* current_, float min_ = 0.f, float max_ = 1.f, TTD barTexture = "Empty", TTD backgroundTexture = "Empty");
	~Bar();

	float getMin() const;
	float getMax() const;
	float getCurrent() const;

	void setMin(float min_);
	void setMax(float max_);
	void trackValue(float* current_);

	void setWidth(float width_); // Пропорционально меняет ширину спрайта
	void update();
	void drawIn(sf::RenderWindow& window);
};