#include "Interface/Map/Map.h"

Map::Map(Elements elements_)
{
	elements = elements_;
}

sf::Vector2f Map::getPosition() const
{
	return position;
}

void Map::setPosition(sf::Vector2f position_)
{
	position = position_;
	update();
}

void Map::update()
{
	if (elements.empty())
		return;
	for (auto element : elements)
	{
		sf::Vector2f global(position.x + element.local.x, position.y + element.local.y);
		element.widget->setPosition(global);
	}
}

void Map::drawIn(sf::RenderWindow& window)
{
	for (auto element : elements)
		element.widget->drawIn(window);
}
