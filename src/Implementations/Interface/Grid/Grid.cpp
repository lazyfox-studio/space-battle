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
		float leftMargin = 0.0f;
		float colWidth = (width - 11.f * margin) / 12.f;
		float maxHeight = 0.0f;
		int i = 0;
		for (auto element : row)
		{
			sf::FloatRect bounds = element.widget->getLocalBounds();
			if (bounds.height > maxHeight)
				maxHeight = bounds.height;
			float widgetWidth = colWidth * element.cols + margin * (element.cols - 1);
			float offsetWidth = colWidth * element.offset + margin * (element.offset - 1);
			// потом сюда еще добавлю расчет сдвига при объединении строк (rowspan > 0)
			element.widget->setWidth(widgetWidth);
			element.widget->setPosition(sf::Vector2f(position.x + topMargin, position.y + leftMargin + offsetWidth));
			leftMargin += widgetWidth + offsetWidth + margin;
			i++;
		}
		topMargin += maxHeight + margin;
	}
}

void Grid::drawIn(sf::RenderWindow& window)
{
	for (auto row : widgets)
		for (auto element : row)
			element.widget->drawIn(window);
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

Grid::Grid(float width_, Elements widgets_, sf::Vector2f position_, float margin_)
{
	position = position_;
	width = width_;
	widgets = widgets_;
	margin = margin_;
}

Grid::Grid(std::initializer_list<std::initializer_list<Element>> widgets_)
{
	for (auto row : widgets_)
	{
		widgets.push_back(std::vector<Grid::Element>());
		size_t index = widgets.size() - 1;
		for (auto element : row)
			widgets[index].push_back(element);
	}
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

Grid::Element::Element(Widget* widget_)
{
	widget = widget_;
	cols = offset = rowspan = 0U;
}

Grid::Element::Element(std::pair<Widget*, unsigned> element)
{
	widget = element.first;
	cols = element.second;
	offset = rowspan = 0U;
}

Grid::Element::Element(std::pair<Widget*, std::initializer_list<unsigned>> element)
{
	widget = element.first;
	cols = offset = rowspan = 0U;
	int i = 0;
	for (unsigned value : element.second)
		if (++i == 1)
			cols = value;
		else if (i == 2)
			offset = value;
		else if (i == 3)
			rowspan = value;
		else
			break;
}