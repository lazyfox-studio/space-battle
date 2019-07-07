#pragma once

#include <SFML/Graphics.hpp>

class WindowControl
{
protected:
    sf::Window window;
    unsigned height; //������ ����
    unsigned width; //������ ����
public:
    WindowControl();
    WindowControl(const WindowControl& temp);
    WindowControl(unsigned height_, unsigned width_);
    ~WindowControl();

    void resize(unsigned height_, unsigned width_); //��������� �������� ����
    void close(); //�������� ����
};