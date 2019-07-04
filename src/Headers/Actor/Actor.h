//Любой объект который может быть помещён на игровую локацию

#pragma once

#include <SFML/Graphics.hpp>
#include "..//..//Functions/Functions.h"
#include "..//Flipbook/Flipbook.h"

class Actor
{
    //Координаты
    double x;
    double y;

    //Параметры тела
    double r;
    double m;

    //Свойства тела

    //Физика
    bool attractable; //Способность быть притянутым гравитацией
    bool touchable; //Наличие реакции на столкновение(уничтожение, нанесение урона объекту столкновения)
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    //Графика
    Flipbook sprite;

public:
    //Конструкторы и Деструкторы
    Actor();
    Actor(const double x_, const double y_, const double r_, const double m_, const bool attractable_, const bool touchable_, const sf::Vector2f velocity_, const Flipbook sprite_);
    Actor(const Actor& temp);
    ~Actor();

    //Управление
    double getX() const;
    double getY() const;
    double getR() const;
    double getM() const;
    bool isAttractable() const;
    bool isTouchable() const;
    double setPosition(const double x_, const double y_, const sf::Vector2f velocity_ = sf::Vector2f(0, 0));
    double addAcceleration(const sf::Vector2f acceleration_);
    void gravitation(const Actor& temp);

    //Отображение
    void updateAnimation();
    void draw();

    //Действия с коллизиями
    virtual void Collide(const Actor& agent); //Что испытает объект
};