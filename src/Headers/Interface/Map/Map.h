#pragma once

#include "Interface/Widget/Widget.h"
#include <vector>

// �������� ������������ ��������
class Map
{
public:
	struct Element
	{
		Widget* widget = nullptr;                     // ��������� �� ������� ����������
		sf::Vector2f local = sf::Vector2f(0.f, 0.f);  // ���������� ������������ ���� ����
	};
	typedef std::vector<Element> Elements;
	Elements elements;

private:
	sf::Vector2f position;

public:
	Map() = default;
	Map(const Map& temp) = default;
	Map(Elements elements_);

	sf::Vector2f getPosition() const;

	void setPosition(sf::Vector2f position_);
	void update();
	void drawIn(sf::RenderWindow& window);
};