#include "Interface/Widget/Button/Button.h"

Button::type::type(int _width)
{
	width = _width;
}

Button::type::type(int _width, const char* def, const char* clicked, const char* hovered, const char* disabled)
{
	width = _width;
	assignTexture(def, clicked, hovered, disabled);
}

void Button::type::assignTexture(state _state, const char* file)
{
	if (stateExists[_state])
		delete texture[_state];
	if (!texture[_state])
		texture[_state] = new sf::Texture;
	texture[_state]->loadFromFile(file);
	texture[_state]->setSmooth(true);
	stateExists[_state] = true;
}

void Button::type::assignTexture(const char* def, const char* clicked, const char* hovered, const char* disabled)
{
	assignTexture(state::def, def);
	if (clicked[0])
		assignTexture(state::clicked, clicked);
	if (hovered[0])
		assignTexture(state::hovered, hovered);
	if (disabled[0])
		assignTexture(state::disabled, disabled);
}

Button::btn::btn()
{
	visible = true;
	prototype = nullptr;
	sprite.setOrigin(0.f, 0.f);
	x = y = 0.f;
	width = height = 0;
	btnState = state::def;
	a_void_void = nullptr;
	a_void_ptr = nullptr;
	atype = action_type::no;
}

Button::btn::btn(type* p)
{
	visible = true;
	prototype = p;
	sprite.setOrigin(0.f, 0.f);
	x = y = 0.f;
	width = prototype->texture[state::def]->getSize().x;
	height = prototype->texture[state::def]->getSize().y;
	btnState = state::def;
	a_void_void = nullptr;
	a_void_ptr = nullptr;
	atype = action_type::no;
}

Button::btn::~btn()
{

}

Button::state Button::btn::getState()
{
	return btnState;
}

Button::state Button::btn::checkState(float mouse_x, float mouse_y, bool mouse_click, bool _set_state)
{
	state _state = state::def;
	if (!visible)
		_state = state::def;
	else
	{
		if (btnState == state::disabled)
			_state = state::disabled;
		if ((mouse_x >= x) && (mouse_x <= x + width) && (mouse_y >= y) && (mouse_y <= y + height))
		{
			if (mouse_click)
			{
				_state = state::clicked;
				click();
			}
			else
				_state = state::hovered;
		}
	}
	if (_set_state)
		setState(_state);
	return _state;
}

void Button::btn::setState(state _state)
{
	btnState = _state;
	if (prototype->stateExists[btnState])
		sprite.setTexture(*(prototype->texture[btnState]));
	else
		sprite.setTexture(*(prototype->texture[state::def]));
}

void Button::btn::onClick(void(*func)())
{
	a_void_void = func;
	atype = action_type::void_void;
}

void Button::btn::onClick(void(*func)(void*), void* ptr)
{
	a_void_ptr = func;
	atype = action_type::void_ptr;
	a_subject = ptr;
}

void Button::btn::click()
{
	switch (atype)
	{
	case action_type::void_void:
		if (a_void_void)
			(*a_void_void)();
		break;
	case action_type::void_ptr:
		if (a_void_ptr)
			(*a_void_ptr)(a_subject);
		break;
	}
}

Button::text::text() : btn()
{
	str = nullptr;
	btnText.setOrigin(0.f, 0.f);
	bounds = btnText.getGlobalBounds();
}

Button::text::text(type* p) : btn(p)
{
	setState(state::def);
	str = nullptr;
	btnText.setOrigin(0.f, 0.f);
	setWidth(p->width);
	bounds = btnText.getGlobalBounds();
}

Button::text::text(type* p, const char* _str) : btn(p)
{
	setState(state::def);
	str = nullptr;
	setText(_str);
	setWidth(p->width);
}

Button::text::~text()
{
	if (str)
		delete[] str;
	// ~btn();
}

void Button::text::setText(const char* _str)
{
	if (str)
		delete[] str;
	int len = 0;
	for (; _str[len]; len++);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
		str[i] = _str[i];
	str[len] = 0;
	btnText.setString(str);
	bounds = btnText.getGlobalBounds();
	btnText.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	btnText.setPosition(x + width / 2.f, y + height / 2.f);
	bounds = btnText.getGlobalBounds();
}

void Button::text::setColor(sf::Color color)
{
	btnText.setFillColor(color);
}

void Button::text::setSize(unsigned size)
{
	btnText.setCharacterSize(size);
	bounds = btnText.getGlobalBounds();
}

void Button::text::assignFont(sf::Font* font)
{
	btnFont = font;
	btnText.setFont(*btnFont);
}

void Button::text::setState(state _state)
{
	btnState = _state;
	if (prototype->stateExists[btnState])
		sprite.setTexture(*(prototype->texture[btnState]));
	else
		sprite.setTexture(*(prototype->texture[state::def]));
}

void Button::text::setPosition(float _x, float _y)
{
	bounds.left = _x + (bounds.left - x);
	bounds.top = _y + (bounds.top - y);
	float shift_x = width / 2.f, shift_y = height / 2.f;
	x = _x;
	y = _y;
	sprite.setPosition(x, y);
	btnText.setPosition(x + shift_x, y + shift_y);
}

void Button::text::setWidth(int _width)
{
	if (_width <= 0)
		return;
	float factor = float(_width) / float(width);
	sprite.setScale(factor, factor);
	btnText.setScale(factor, factor);
	width = _width;
	height = (int)(height * factor);
}

void Button::text::drawIn(sf::RenderWindow& window)
{
	if (!visible)
		return;
	window.draw(sprite);
	window.draw(btnText);
}

Button::icon::icon() : btn()
{
	iconTexture = new sf::Texture;
}

Button::icon::icon(type* p) : btn(p)
{
	setState(state::def);
	iconTexture = new sf::Texture;
}

Button::icon::~icon()
{
	delete iconTexture;
	// ~btn();
}

void Button::icon::assignIcon(const char* file)
{
	iconTexture->loadFromFile(file);
	iconTexture->setSmooth(true);
	iconSprite.setTexture(*iconTexture);
}

void Button::icon::setState(state _state)
{
	btnState = _state;
	if (prototype->stateExists[btnState])
		sprite.setTexture(*(prototype->texture[btnState]));
	else
		sprite.setTexture(*(prototype->texture[state::def]));
}

void Button::icon::setPosition(float _x, float _y)
{
	x = _x;
	y = _y;
	sprite.setPosition(x, y);
	iconSprite.setPosition(x, y);
}

void Button::icon::drawIn(sf::RenderWindow& window)
{
	if (!visible)
		return;
	window.draw(sprite);
	window.draw(iconSprite);
}
