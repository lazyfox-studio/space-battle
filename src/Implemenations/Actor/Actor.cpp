#pragma once

#include "../../Headers/Actor/Actor.h"

Actor::Actor()
{
    x = 0;
    y = 0;
    r = 0;
    m = 0;
    attractable = false;
    touchable = false;
    velocity = sf::Vector2f(0,0);
    acceleration = sf::Vector2f(0, 0);
    //Что-то со спрайтом
}

Actor::Actor(const double x_, const double y_, const double r_, const double m_, const bool attractable_, const bool touchable_, const sf::Vector2f velocity_, const Flipbook sprite_)
{
    x = x_;
    y = y_;
    r = r_;
    m = m_;
    attractable = attractable_;
    touchable = touchable_;
    velocity = velocity_;
    sprite = sprite_;
}

Actor::Actor(const Actor& temp)
{
    x = temp.x;
    y = temp.y;
    r = temp.r;
    m = temp.m;
    attractable = temp.attractable;
    touchable = temp.touchable;
    velocity = temp.velocity;
    acceleration = temp.acceleration;
    sprite = temp.sprite;
}

Actor::~Actor()
{

}

double Actor::getX() const
{
    return x;
}

double Actor::getY() const
{
    return x;
}

double Actor::getR() const
{
    return r;
}

double Actor::getM() const
{
    return m;
}

bool Actor::isAttractable() const
{
    return attractable;
}

bool Actor::isTouchable() const
{
    return touchable;
}

double Actor::setPosition(const double x_, const double y_, const sf::Vector2f velocity_ = sf::Vector2f(0, 0))
{
    x = x_;
    y = y_;
    velocity = velocity_;
}

double Actor::addAcceleration(const sf::Vector2f acceleration_)
{
    acceleration = acceleration + acceleration_;
}

void Actor::gravitation(const Actor& temp)
{
    if (!isAttractable) return;
    double d = sqrt((getX() - temp.getX()) * (getX() - temp.getX()) + (getY() - temp.getY()) * (getY() - temp.getY())); //заменить на Distance
    double f = (m * temp.m) / (d * d) * G;
    addAcceleration(sf::Vector2f((temp.getX() - getX()) / d * f / getM(), (temp.getY() - getY()) / d * f / getM()));
}

void Actor::updateAnimation()
{

}

void Actor::draw()
{

}

void Actor::Collide(const Actor& agent)
{

}