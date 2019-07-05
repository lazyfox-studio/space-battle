#pragma once

#include "../Widget.h"
#include <string>

// Счетчик
class Scoreboard : Widget
{
	std::string str;
	int counter;
	sf::Font* font;
	sf::Text text;
	sf::FloatRect textBounds;
public:
	Scoreboard();
	Scoreboard(sf::Font* font_, const std::string& str_, int counter_ = 0);

	void setText(const std::string& str_);
	void setFont(sf::Font* font_);
	void setColor(const sf::Color color);
	void setPosition(const sf::Vector2f position);
};