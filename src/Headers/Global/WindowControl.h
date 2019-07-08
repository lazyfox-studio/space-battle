#pragma once

#include <SFML/Graphics.hpp>
#include <array>

// Window Controller (контроллер окна - обертка для sf::RenderWindow)
class WindowControl
{
public:
	// Координаты угловых точек окна
	class corners
	{
		friend class WindowControl;
		sf::Vector2f topLeft;
		sf::Vector2f topRight;
		sf::Vector2f bottomLeft;
		sf::Vector2f bottomRight;
		corners();
	public:
		inline sf::Vector2f getTopLeft() const { return topLeft; }
		inline sf::Vector2f getTopRight() const { return topRight; }
		inline sf::Vector2f getBottomLeft() const { return bottomLeft; }
		inline sf::Vector2f getBottomRight() const { return bottomRight; }
		inline std::array<sf::Vector2f, 4> get() const;
	};

protected:
    sf::Window window;
	WindowControl::corners windowCorners;

    unsigned height; // Высота окна
    unsigned width;  // Ширина окна

public:
    WindowControl();
    WindowControl(const WindowControl& temp);
    WindowControl(unsigned height_, unsigned width_);
    ~WindowControl();

	corners& getCorners() const;
    void resize(unsigned height_, unsigned width_); // Изменение размеров окна
    void close(); // Закрытие окна

};