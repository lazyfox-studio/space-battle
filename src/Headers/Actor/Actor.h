#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include "Constants.h"
#include "Flipbook/Flipbook.h"
#include "Math/Component/Component.h"
#include "Math/Component/Rectangle/Rectangle.h"
#include "Math/Component/Ellipse/Ellipse.h"

// Actor (объект, который может быть помещён на игровую локацию)
class Actor
{
protected:
     
    // Компонента тела
    Component *component;

    // Параметры тела
    float m;      // Масса

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
    Actor(float x_, float y_, float height_, float width_, unsigned componentType, float m_, bool attractable_, bool touchable_, const sf::Vector2f velocity_, const std::string texture_);
    Actor(const Actor& temp);
    ~Actor();

    // Аксессоры
    float getX() const;
    float getY() const;
    float getr() const;
    float getR() const;
    float getM() const;
    bool isAttractable() const;
    bool isTouchable() const;
	float distance(const Actor& temp) const;

	// Управление
    void setPosition(float x_, float y_, const sf::Vector2f velocity_ = sf::Vector2f(0, 0));
    void move(float dx, float dy);
    void addAcceleration(const sf::Vector2f acceleration_);
    void addVelocity(const sf::Vector2f velocity_);
    void rotate(int angle_);
    void setRotation(int angle_);
    void impactAcceleration();
    void impactVelocity();


    // Отображение
    void updateAnimation();
    void drawIn(sf::RenderWindow& window);

    //Действия с коллизиями
    virtual void collide(const Actor& agent); //Что испытает объект

	void test(int n) { std::cout << "test: " << n << "\n"; }
};