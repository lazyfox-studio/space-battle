#include "Interface/Widget/Scoreboard/Scoreboard.h"

Scoreboard::Scoreboard()
{
	setFont("Empty");
	setCounter(0);
}

Scoreboard::Scoreboard(std::string index_, const std::string& str_, int counter_)
{
	setFont(index_);
	setText(str_);
	setCounter(counter_);
}

Scoreboard::~Scoreboard()
{

}

int Scoreboard::getCounter() const
{
	return counter;
}

sf::FloatRect Scoreboard::getLocalBounds() const
{
	sf::FloatRect bounds = textDescription.getLocalBounds();
	bounds.width += textCounter.getLocalBounds().width;
	return bounds;
}

sf::FloatRect Scoreboard::getGlobalBounds() const
{
	sf::FloatRect bounds = textDescription.getGlobalBounds();
	bounds.width += textCounter.getLocalBounds().width;
	return bounds;
}

int Scoreboard::increaseCounter(int delta)
{
	setCounter(counter + delta);
	return counter;
}

void Scoreboard::setCounter(int counter_)
{
	if (counter != counter_)
	{
		counter = counter_;
		strCounter = std::to_string(counter);
	}
}

void Scoreboard::setText(const std::string& strDescription_)
{
	strDescription = strDescription_;
	textDescription.setString(strDescription.c_str());
}

void Scoreboard::setFont(std::string index_)
{
	index = index_;
	textDescription.setFont(FontTable::fonts[index].font);
	textCounter.setFont(FontTable::fonts[index].font);

}

void Scoreboard::setSize(unsigned fontSize)
{
	textDescription.setCharacterSize(fontSize);
	textCounter.setCharacterSize(fontSize);
}

void Scoreboard::setColor(const sf::Color color)
{
	textDescription.setFillColor(color);
	textCounter.setFillColor(color);
}

void Scoreboard::setPosition(const sf::Vector2f position)
{
	textDescription.setPosition(position);
	textCounter.setPosition(sf::Vector2f(position.x + textDescription.getLocalBounds().width, position.y));
}

void Scoreboard::update()
{
	setPosition(textDescription.getPosition());
}

void Scoreboard::drawIn(sf::RenderWindow& window)
{
	window.draw(textDescription);
	window.draw(textCounter);
}
