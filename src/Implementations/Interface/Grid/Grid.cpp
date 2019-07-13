#include "Interface/Grid/Grid.h"

void Grid::update()
{
	if (widgets.empty())
		return;
	float topMargin = 0.0f;
	for (auto row : widgets)
	{
		if (row.empty())
			continue;
		float widgetWidth = floor((width - margin * (row.size() - 1)) / row.size());
		float maxHeight = 0.0f;
		int i = 0;
		for (auto widget : row)
		{
			sf::FloatRect bounds = widget->getLocalBounds();
			if (bounds.height > maxHeight)
				maxHeight = bounds.height;
			widget->setWidth(widgetWidth);
			widget->setPosition(sf::Vector2f(position.x + topMargin, position.y + i * (widgetWidth + margin)));
			i++;
		}
		topMargin += maxHeight + margin;
	}
}

void Grid::drawIn(sf::RenderWindow& window)
{
	for (auto row : widgets)
		for (Widget* widget : row)
			widget->drawIn(window);
}

Grid::Grid()
{
	width = margin = 0.0f;
	position.x = position.y = 0.0f;
}

Grid::Grid(float width_, sf::Vector2f position_, float margin_)
{
	position = position_;
	width = width_;
	margin = margin_;
}

Grid::Grid(float width_, GridElements widgets_, sf::Vector2f position_, float margin_)
{
	position = position_;
	width = width_;
	widgets = widgets_;
	margin = margin_;
}


float Grid::getWidth() const
{
	return width;
}

float Grid::getMargin() const
{
	return margin;
}

sf::Vector2f Grid::getPosition() const
{
	return position;
}

void Grid::setWidth(float width_)
{
	width = width_;
	update();
}

void Grid::setMargin(float margin_)
{
	margin = margin_;
	update();
}

void Grid::setPosition(sf::Vector2f position_)
{
	position = position_;
	update();
}
