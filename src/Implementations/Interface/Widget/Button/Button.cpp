#include "Interface/Widget/Button/Button.h"

Button::base::base() : Widget()
{
	textureIndexes = { "Empty", "Empty", "Empty", "Empty" };
	x = y = 0.f;
	btnState = state::def;
	setState(state::def);
}

Button::base::base(std::initializer_list<std::string> textureIndexes_) : base()
{
	if (textureIndexes_.size() < 1)
		return;
	int i = 0;
	for (auto index : textureIndexes_)
		textureIndexes[i++] = index;
	setState(state::def);
}

Button::base::~base()
{

}

Button::state Button::base::getState()
{
	return btnState;
}

Button::state Button::base::checkState(float mouse_x, float mouse_y, bool mouse_click, bool _set_state)
{
	state _state = state::def;
	if (!btn.visible())
		_state = state::def;
	else
	{
		if (btnState == state::disabled)
			_state = state::disabled;
		if ((mouse_x >= x) && (mouse_x <= x + btn.width()) && (mouse_y >= y) && (mouse_y <= y + btn.height()))
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

void Button::base::setState(state state_)
{
	btnState = state_;
	if (textureIndexes[btnState] != "Empty")
		btn.assignTexture(textureIndexes[btnState]);
	else
		btn.assignTexture(textureIndexes[state::def]);
}

void Button::base::onClick(EventHandler handler_, EventHadlerParam handlerParam_)
{
	handler = handler_;
	handlerParam = handlerParam_;
}

void Button::base::click()
{
	if (handlerParam)        // если задан handlerParam, вызываем handler с ним
		(*handler)(handlerParam);  
	else        // иначе приводим к void(*)() и вызываем handler без параметров
		((void(*)())(*handler))(); 
}

Button::text::text() : base()
{
	btnText.setOrigin(0.f, 0.f);
	bounds = btnText.getGlobalBounds();
}

Button::text::text(const std::string& str_) : base()
{
	str = str_;
	setText(str_.c_str());
}

Button::text::~text()
{
	
}

void Button::text::setText(const std::string& str_)
{
	str = str_;
	btnText.setString(str.c_str());
	bounds = btnText.getGlobalBounds();
	btnText.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	btnText.setPosition(x + btn.width() / 2.f, y + btn.height() / 2.f);
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


void Button::text::setPosition(sf::Vector2f position)
{
	bounds.left = x + (bounds.left - x);
	bounds.top = y + (bounds.top - y);
	float shift_x = btn.width() / 2.f, shift_y = btn.height() / 2.f;
	x = position.x;
	y = position.y;
	btn.setPosition(position);
	btnText.setPosition(x + shift_x, y + shift_y);
}

void Button::text::setWidth(int width)
{
	if (width <= 0)
		return;
	float factor = float(width) / btn.width();
	btn.scale(factor);
	btnText.setScale(sf::Vector2f(factor, factor));
}

void Button::text::drawIn(sf::RenderWindow& window)
{
	if (!btn.visible())
		return;
	btn.drawIn(window);
	window.draw(btnText);
}

Button::icon::icon() : base()
{
	
}

Button::icon::~icon()
{
	
}

void Button::icon::assignIcon(std::string index)
{
	iconSprite.assignTexture(index);
}


void Button::icon::setPosition(sf::Vector2f position)
{
	x = position.x;
	y = position.y;
	btn.setPosition(position);
	iconSprite.setPosition(position);
}

void Button::icon::drawIn(sf::RenderWindow& window)
{
	if (!btn.visible())
		return;
	btn.drawIn(window);
	iconSprite.drawIn(window);
}
