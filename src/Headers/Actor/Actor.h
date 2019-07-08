#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "../Constants.h"
#include "../Flipbook/Flipbook.h"

// Actor (объект, который может быть помещён на игровую локацию)
class Actor
{
protected:
    // Координаты
    float x;
    float y;

    // Параметры тела
    float r; // Радиус вписывающей окружности
    float m; // Масса

    // Свойства тела

    // Физика
    bool attractable; // Способность быть притянутым гравитацией
    bool touchable;   // Наличие реакции на столкновение(уничтожение, нанесение урона объекту столкновения)
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    //Графика
    Flipbook sprite;

public:
    //Конструкторы и Деструкторы
    Actor();
    Actor(float x_, float y_, float r_, float m_, bool attractable_, bool touchable_, const sf::Vector2f velocity_, const Flipbook sprite_);
    Actor(const Actor& temp);
    ~Actor();

    // Аксессоры
    float getX() const;
    float getY() const;
    float getR() const;
    float getM() const;
    bool isAttractable() const;
    bool isTouchable() const;
	float distance(const Actor& temp) const;

	// Управление
    void setPosition(float x_, float y_, const sf::Vector2f velocity_ = sf::Vector2f(0, 0));
    void addAcceleration(const sf::Vector2f acceleration_);
    void gravitation(const Actor& temp);

    // Отображение
    void updateAnimation();
    void drawIn(sf::RenderWindow& window);

    //Действия с коллизиями
    virtual void collide(const Actor& agent); //Что испытает объект
};