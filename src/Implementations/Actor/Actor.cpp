﻿#pragma once

#include "Actor/Actor.h"

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

Actor::Actor(float x_, float y_, float r_, float m_, bool attractable_, 
	bool touchable_, const sf::Vector2f velocity_, const Flipbook sprite_)
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

void Actor::gravitation(const Actor& temp)
{
    if (!attractable) 
		return;
    float d = sqrt((x - temp.x) * (x - temp.x) + (y - temp.y) * (y - temp.y)); //заменить на Distance
    float f = G * (m * temp.m) / (d * d);
    addAcceleration(sf::Vector2f((temp.x - x) / d * f / m, (temp.y - y) / d * f / m));
}

void Actor::updateAnimation()
{

}

void Actor::draw()
{

}

void Actor::collide(const Actor& agent)
{

}