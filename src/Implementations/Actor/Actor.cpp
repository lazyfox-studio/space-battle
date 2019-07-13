#pragma once

#include "Actor/Actor.h"

Actor::Actor()
{
    component = new Component;
    m = 0;
    attractable = false;
    touchable = false;
    velocity = sf::Vector2f(0,0);
    acceleration = sf::Vector2f(0, 0);
    sprite.assignTexture("Empty");
    sprite.setPosition(sf::Vector2f(component->x, component->y));
}

Actor::Actor(float x_, float y_, float height_, float width_, unsigned componentType, float m_, bool attractable_,
	bool touchable_, const sf::Vector2f velocity_, const std::string texture_)
{
    component = new Component(x_,y_,height_,width_);
    m = m_;
    attractable = attractable_;
    touchable = touchable_;
    velocity = velocity_;
    sprite.assignTexture(texture_);
    sprite.setPosition(sf::Vector2f(component->x, component->y));
}

Actor::Actor(const Actor& temp)
{
	*component = *(temp.component);
    m = temp.m;
    attractable = temp.attractable;
    touchable = temp.touchable;
    velocity = temp.velocity;
    acceleration = temp.acceleration;
    sprite = temp.sprite;
    sprite.setPosition(sf::Vector2f(component->x, component->y));
}

Actor::~Actor()
{

}

float Actor::getX() const
{
    return component->x;
}

float Actor::getY() const
{
    return component->y;
}

float Actor::getHeight() const
{
    return component->height;
}

float Actor::getWidth() const
{
    return component->width;
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
	return sqrt((component->x - temp.component->x) * (component->x - temp.component->x) + (component->y - temp.component->y) * (component->y - temp.component->y));
}

void Actor::setPosition(float x_, float y_, const sf::Vector2f velocity_)
{
    component->x = x_;
	component->y = y_;
    velocity = velocity_;
    sprite.setPosition(sf::Vector2f(component->x, component->y));
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
    sprite.drawIn(window);
}

void Actor::collide(const Actor& agent)
{

}