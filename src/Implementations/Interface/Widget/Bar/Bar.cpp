#include "Interface\Widget\Bar\Bar.h"

Bar::Bar()
{
	bar.assignTexture(TTD::TextureEmpty);
	background.assignTexture(TTD::TextureEmpty);
	min = 0.f;
	max = 1.f;
	current = nullptr;
}

Bar::Bar(const Bar& temp)
{
	bar = temp.bar;
	background = temp.background;
	min = temp.min;
	max = temp.max;
	current = temp.current;
}

Bar::Bar(float min_, float max_, TTD barTexture, TTD backgroundTexture)
{
	bar.assignTexture(barTexture);
	background.assignTexture(backgroundTexture);
	min = min_;
	max = max_;
	current = nullptr;
}

Bar::Bar(float* current_, float min_, float max_, TTD barTexture, TTD backgroundTexture)
	: Bar(min_, max_, barTexture, backgroundTexture)
{
	current = current_;
}

Bar::~Bar()
{

}

float Bar::getMin() const
{
	return min;
}

float Bar::getMax() const
{
	return max;
}

float Bar::getCurrent() const
{
	return current ? *current : 0.f;
}

void Bar::setMin(float min_)
{
	min = min_;
}

void Bar::setMax(float max_)
{
	max = max_;
}

void Bar::trackValue(float* current_)
{
	current = current_;
}

void Bar::setWidth(float width_)
{
	float factor = width_ / bar.width();
	bar.scale(factor);
	background.scale(factor);
}

void Bar::update()
{
	float percentage = current ? *current / (max - min) : 0.f;
	background.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(background.width(), background.height())));
	bar.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i((int)(bar.width() * percentage), bar.height())));
}

void Bar::drawIn(sf::RenderWindow& window)
{
	update();
	bar.drawIn(window);
	background.drawIn(window);
}
