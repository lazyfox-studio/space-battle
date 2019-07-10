#pragma once

#include "Actor/Actor.h"

Actor::Actor()
{
    x = 0;
    y = 0;
    height = 0;
    widht = 0;
    m = 0;
    attractable = false;
    touchable = false;
    velocity = sf::Vector2f(0,0);
    acceleration = sf::Vector2f(0, 0);
    //Что-то со спрайтом
}

Actor::Actor(float x_, float y_, float height_, float widht_, float m_, bool attractable_, 
	bool touchable_, const sf::Vector2f velocity_, const Flipbook sprite_)
{
    x = x_;
    y = y_;
    height = height_;
    widht = widht_;
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
    height = temp.height;
    widht = temp.widht;
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

float Actor::getX() const
{
    return x;
}

float Actor::getY() const
{
    return x;
}

float Actor::getR() const
{
    return r;
}

float Actor::getM() const
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

float Actor::distance(const Actor& temp) const
{
	return sqrt((x - temp.x) * (x - temp.x) + (y - temp.y) * (y - temp.y));
}

void Actor::setPosition(float x_, float y_, const sf::Vector2f velocity_)
{
    x = x_;
    y = y_;
    velocity = velocity_;
}

void Actor::addAcceleration(const sf::Vector2f acceleration_)
{
    acceleration = acceleration + acceleration_;
}

void Actor::updateAnimation()
{

}

void Actor::drawIn(sf::RenderWindow& window)
{

}

void Actor::collide(const Actor& agent)
{

}