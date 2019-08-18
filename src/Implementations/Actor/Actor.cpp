#pragma once

#include "Actor/Actor.h"

Actor::Actor()
{
    x = 0;
    y = 0;
    m = 0;
    collisionBoxes.clear();
    attractable = false;
    touchable = false;
    velocity = sf::Vector2f(0,0);
    acceleration = sf::Vector2f(0, 0);
    sprite.assignTexture("Empty");
    sprite.setPosition(sf::Vector2f(x, y));
}

Actor::Actor(float x_, float y_, float m_, std::vector <Square> collisionBoxes_, bool attractable_, bool touchable_, const sf::Vector2f velocity_, const std::string texture_)
{
    x = x_;
    y = y_;
    m = m_;
    collisionBoxes = collisionBoxes_;
    attractable = attractable_;
    touchable = touchable_;
    velocity = velocity_;
    sprite.assignTexture(texture_);
    sprite.setPosition(sf::Vector2f(x, y));
}

Actor::Actor(const Actor& temp)
{
    x = temp.x;
    y = temp.y;
    m = temp.m;
    collisionBoxes = temp.collisionBoxes;
    attractable = temp.attractable;
    touchable = temp.touchable;
    velocity = temp.velocity;
    acceleration = temp.acceleration;
    sprite = temp.sprite;
    sprite.setPosition(sf::Vector2f(x, y));
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
    return y;
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
    sprite.setPosition(sf::Vector2f(x, y));
}

void Actor::move(float dx, float dy)
{
    x += dx;
    y += dy;
    sprite.setPosition(sf::Vector2f(x, y));
}

void Actor::addAcceleration(const sf::Vector2f acceleration_)
{
    acceleration += acceleration_;
}

void Actor::addVelocity(const sf::Vector2f velocity_)
{
    velocity += velocity_;
}

void Actor::rotate(int angle_)
{
    int angle = angle_;
    float angle_rad = angle_ / 180 * Pi;
    for (int i = 0; i < collisionBoxes.size(); i++)
    {
        collisionBoxes[i].x = collisionBoxes[i].x * cos(angle_rad) - collisionBoxes[i].y * sin(angle_rad);
        collisionBoxes[i].y = collisionBoxes[i].x * sin(angle_rad) + collisionBoxes[i].y * cos(angle_rad);
    }
    sprite.rotate(angle_);
}

void Actor::setRotation(int angle_)
{
    this->rotate(angle_ - angle);
}

void Actor::impactAcceleration()
{
    velocity += acceleration;
}

void Actor::impactVelocity()
{
    x += velocity.x;
    y += velocity.y;
    sprite.setPosition(sf::Vector2f(x, y));
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