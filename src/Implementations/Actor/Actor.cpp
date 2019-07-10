#pragma once

#include "Actor/Actor.h"

Actor::Actor()
{
	cmp->x = 0;
	cmp->y = 0;
	cmp->height = 0;
	cmp->width = 0;
    m = 0;
    attractable = false;
    touchable = false;
    velocity = sf::Vector2f(0,0);
    acceleration = sf::Vector2f(0, 0);
    //Что-то со спрайтом
}

Actor::Actor(float x_, float y_, float height_, float width_, unsigned componentType, float m_, bool attractable_,
	bool touchable_, const sf::Vector2f velocity_, const Flipbook sprite_)
{
	cmp->x = x_;
	cmp->y = y_;
	cmp->height = height_;
	cmp->width = width_;
    m = m_;
    attractable = attractable_;
    touchable = touchable_;
    velocity = velocity_;
    sprite = sprite_;
}

Actor::Actor(const Actor& temp)
{
	*cmp = *(temp.cmp);
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
    return cmp->x;
}

float Actor::getY() const
{
    return cmp->y;
}

float Actor::getHeight() const
{
    return cmp->height;
}

float Actor::getWidth() const
{
    return cmp->width;
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
	return sqrt((cmp->x - temp.cmp->x) * (cmp->x - temp.cmp->x) + (cmp->y - temp.cmp->y) * (cmp->y - temp.cmp->y));
}

void Actor::setPosition(float x_, float y_, const sf::Vector2f velocity_)
{
    cmp->x = x_;
	cmp->y = y_;
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