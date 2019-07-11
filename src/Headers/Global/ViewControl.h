#pragma once

#include <SFML/Graphics.hpp>

// Контроллер отображения и камеры
class ViewControl
{
protected:
    float x;
    float y;
    float scale; //Масштаб
    float leftUpperCorner;
    float rightLowerCorner;

public:
    ViewControl();
    ViewControl(const ViewControl& temp);
    ViewControl(float x_, float y_, float scale_);
    //Конструктор PiP View'a
    ~ViewControl();

    //Движение камеры
    void move(float x_, float y_);
    void move(sf::Vector2f vector);
    void setPosition(float x_, float y_);
    void setPosition(sf::Vector2f vector);
    void setScale(float scale_);
    
    /*template<typename Type> void drawLocal(Type)
    {

    } РИСУЕТ ОТНОСИТЕЛЬНО СЕБЯ*/
};