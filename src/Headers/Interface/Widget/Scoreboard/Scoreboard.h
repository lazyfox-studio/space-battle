#pragma once

#include "Interface/Widget/Widget.h"
#include "Tables/FontTable.h"
#include <string>

// Счетчик
class Scoreboard : Widget
{
	std::string index;
	int counter;
	std::string strDescription, strCounter;
	sf::Text textDescription, textCounter;
public:
	Scoreboard();
	Scoreboard(std::string index_, const std::string& str_, int counter_ = 0);
	~Scoreboard();

	int getCounter() const;
	sf::FloatRect getLocalBounds() const;
	sf::FloatRect getGlobalBounds() const;

	int increaseCounter(int delta);
	void setCounter(int counter_);
	void setText(const std::string& str_);
	void setFont(std::string index_);
	void setSize(unsigned fontSize);
	void setColor(const sf::Color color);
	void setPosition(const sf::Vector2f position);

	void update();
	void drawIn(sf::RenderWindow& window);
};