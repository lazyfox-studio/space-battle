#include "Interface/Widget/Widget.h"

Widget::Widget()
{
	// do something...
}

Widget::Widget(const Widget& temp)
{
	x = temp.x;
	y = temp.y;
}

Widget::Widget(sf::Sprite&)
{
	// coerce somehow from sprite...
}

Widget::~Widget()
{
	// just destroy!!
}
