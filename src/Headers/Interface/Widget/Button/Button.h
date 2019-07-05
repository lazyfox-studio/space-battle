#pragma once

#include <SFML/Graphics.hpp>
#include "Interface/Widget/Widget.h"

namespace Button
{
	// Положение кнопки (нажата, отпущена)
	enum state
	{
		def,      // default
		clicked,
		hovered,
		disabled
	};

	// Тип действия (надо будет убрать и использовать variadic template)
	enum action_type
	{
		no,
		void_void,
		void_arg,
		void_ref,
		void_ptr,
		void_this
	};

	// Набор текстур для кнопки
	struct type
	{
		sf::Texture* texture[4] = { 0 };
		bool stateExists[4] = { 0 };
		int width = 0;
		type(int);
		type(int, const char* def, const char* clicked = "", const char* hovered = "", const char* disabled = "");
		void assignTexture(state, const char*);
		void assignTexture(const char* def, const char* clicked = "", const char* hovered = "", const char* disabled = "");
	};

	// Пустая кнопка
	class btn : public ::Widget
	{
	protected:
		int width;
		int height;
		state btnState;
		type* prototype;
		sf::Sprite sprite;
		void (*a_void_void)();
		void (*a_void_ptr)(void*);
		action_type atype;
		void* a_subject;

	public:
		bool visible;
		btn();
		btn(type*);
		virtual ~btn();

		state getState();
		int getWidth()
		{
			return width;
		}
		int getHeight()
		{
			return height;
		}
		state checkState(float mouse_x, float mouse_y, bool mouse_click, bool set_state = false);
		virtual void setState(state);
		virtual void setPosition(float, float) = 0;
		virtual void drawIn(sf::RenderWindow&) = 0;

		void onClick(void(*func)());
		void onClick(void(*func)(void*), void*);
		void click();
	};

	// Кнопка с текстом
	class text : public btn
	{
		char* str;              // нужно будет сделать еще и для wchar_t
		sf::Font* btnFont;
		sf::Text btnText;
		sf::FloatRect bounds;   // границы текстового спрайта
	public:
		text();
		text(type*);
		text(type*, const char*);
		~text();

		void setText(const char*);
		void setColor(sf::Color);
		void setSize(unsigned);
		void assignFont(sf::Font*);
		void setState(state);
		void setPosition(float, float);
		void setWidth(int);
		void drawIn(::sf::RenderWindow&);
	};

	// Кнопка с иконкой
	class icon : public btn
	{
		sf::Texture* iconTexture;
		sf::Sprite iconSprite;
	public:
		icon();
		icon(type*);
		~icon();

		void assignIcon(const char*);
		void setState(state);
		void setPosition(float, float);
		void drawIn(sf::RenderWindow&);
	};
}