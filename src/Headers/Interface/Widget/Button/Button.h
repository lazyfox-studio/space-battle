#pragma once
/*
#include <SFML/Graphics.hpp>
#include "Interface/Widget/Widget.h"
#include "Flipbook/Flipbook.h"
#include <array>
#include <string>

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


	// Пустая кнопка
	class base : public ::Widget
	{
	protected:
		state btnState;
		void (*a_void_void)();
		void (*a_void_ptr)(void*);
		action_type atype;
		void* a_subject;

		Flipbook sprite;
		std::array<TextureTableDictionary, 4> textureIndexes;

	public:
		base();
		base();
		virtual ~base();

		state getState();
		state checkState(float mouse_x, float mouse_y, bool mouse_click, bool set_state = false);
		virtual void setState(state);
		virtual void setPosition(float, float) = 0;
		virtual void drawIn(sf::RenderWindow&) = 0;

		void onClick(void(*func)());
		void onClick(void(*func)(void*), void*);
		void click();

		void makeVisible();
		void makeUnvisible();
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
		text(const char*);
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
		~icon();

		void assignIcon(const char*);
		void setState(state);
		void setPosition(float, float);
		void drawIn(sf::RenderWindow&);
	};
}*/