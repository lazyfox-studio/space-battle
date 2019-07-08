﻿#pragma once

#include <SFML/Graphics.hpp>
#include <array>

// Window Controller (контроллер окна - обертка для sf::RenderWindow)
class WindowControl
{
protected:
    sf::Window window;

    unsigned height; // Высота окна
    unsigned width;  // Ширина окна

public:
    WindowControl();
    WindowControl(const WindowControl& temp);
    WindowControl(unsigned height_, unsigned width_);
    ~WindowControl();

    void resize(unsigned height_, unsigned width_); // Изменение размеров окна
    void close(); // Закрытие окна

};