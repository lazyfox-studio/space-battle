#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include "ViewControl.h"

// Window Controller (контроллер окна - обертка для sf::RenderWindow)
class WindowControl
{
public:
    sf::Window window;
protected:
    unsigned height; // Высота окна
    unsigned width;  // Ширина окна

    friend class ViewControl;

private:
    WindowControl();
    WindowControl(const WindowControl& temp);
    WindowControl(unsigned height_, unsigned width_);
    ~WindowControl();
public:
    void resize(unsigned height_, unsigned width_); // Изменение размеров окна
    void close(); // Закрытие окна

};