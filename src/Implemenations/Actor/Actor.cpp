#pragma once

#include "../../Headers/Actor/Actor.h"

Actor::Actor()
{
    x = 0;
    y = 0;
    r = 0;
    attractable = false;
    touchable = false;
    velocity = sf::Vector2f(0,0);
    acceleration = sf::Vector2f(0, 0);
    //Что-то со спрайтом
}

Actor::Actor(const double x_, const double y_, const double r_, const bool attractable_, const bool touchable_, const sf::Vector2f velocity_, const Flipbook sprite_)
{
    x = x_;
    y = y_;
    r = r_;
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
    attractable = temp.attractable;
    touchable = temp.touchable;
    velocity = temp.velocity;
    acceleration = temp.acceleration;
    sprite = temp.sprite;
}

double Actor::getX()
{
    return x;
}

double Actor::getY()
{
    return x;
}

double Actor::setPosition(const double x_, const double y_, const sf::Vector2f velocity_ = sf::Vector2f(0, 0))
{
    x = x_;
    y = y_;
    velocity = velocity_;
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