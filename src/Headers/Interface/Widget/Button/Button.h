#pragma once

#include <SFML/Graphics.hpp>
#include "Interface/Widget/Widget.h"
#include "Flipbook/Flipbook.h"
#include <array>
#include <string>

namespace Button
{
	// Общий вариативный функтор-обработчик
	/*template<typename ...Types> 
	struct eventHandler {};*/

	// Специализация функтора для пакетного синтаксиса handler<RT(T1, T2, ...)>
	/*template<typename RType, typename ...ATypes>
	struct eventHandler<RType(ATypes...)>
	{
		typename RType(*FT)(ATypes...);
		FT handleFunc;
		eventHandler(FT handleFunc_) : handleFunc(handleFunc_) {};
		RType operator()(ATypes... args) { return handleFunc(args...); }
	};*/

	// Положение кнопки (нажата, отпущена)
	enum state
	{
		def,      // default
		clicked,
		hovered,
		disabled
	};

	// Пустая кнопка
	class base : public ::Widget
	{
	protected:
		typedef std::string TTD;
		typedef void* EventHadlerParam;
		typedef void(*EventHandler)(EventHadlerParam);
		state btnState;
		Flipbook btn;
		std::array<TTD, 4> textureIndexes;
		EventHandler handler;
		EventHadlerParam handlerParam;

	public:
		base();
		base(std::initializer_list<TTD> textureIndexes_);
		virtual ~base();

		state getState();
		state checkState(float mouse_x, float mouse_y, bool mouse_click, bool set_state = false);
		virtual void setState(state state_);
		virtual void setPosition(sf::Vector2f position) = 0;
		virtual void drawIn(sf::RenderWindow& window) = 0;
		void onClick(EventHandler handler_, EventHadlerParam handlerParam_ = nullptr);
		void click();

		void makeVisible();
		void makeUnvisible();
	};

	// Кнопка с текстом
	class text : base
	{
		std::string str;
		sf::Font* btnFont;
		sf::Text btnText;
		sf::FloatRect bounds;   // границы текстового спрайта
	public:
		text();
		explicit text(const std::string& str_);
		~text();

		void setText(const std::string& str_);
		void setColor(sf::Color color);
		void setSize(unsigned size);
		void assignFont(sf::Font* font_);
		void setPosition(sf::Vector2f position);
		void setWidth(int width);
		void drawIn(::sf::RenderWindow& window);
	};

	// Кнопка с иконкой
	class icon : public base
	{
		Flipbook iconSprite;
	public:
		icon();
		~icon();

		void assignIcon(TTD index);
		void setPosition(sf::Vector2f position);
		void drawIn(sf::RenderWindow& window);
	};
}