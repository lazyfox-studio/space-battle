#pragma once

#include "Physics.h"

void Physics::gravitation(Actor& a, Actor& b)
{
    if (!(a.getM() && b.getM())) 
		return; // Масса 0 -> нет притяжения
    if (!a.isAttractable() || !b.isAttractable()) 
		return; // Нет смысла притягивать
    float d = a.distance(b);
    float f = G * (a.getM() * b.getM()) / (d * d);
    if (a.isAttractable()) 
		a.addAcceleration(sf::Vector2f((b.getX() - a.getX()) / d * f / a.getM(), (b.getY() - a.getY()) / d * f / a.getM()));
    if (b.isAttractable()) 
		b.addAcceleration(sf::Vector2f((a.getX() - b.getX()) / d * f / b.getM(), (a.getY() - b.getY()) / d * f / b.getM()));
    }

void Physics::acceleration(Actor& a, char axis, char direction)
{
    if (!a.isAttractable()) return;
    if (axis == 'y')
    {
        if (direction == '+')
        {
            a.addAcceleration(sf::Vector2f(0, g));
        }
        else
        {
            a.addAcceleration(sf::Vector2f(0, -g));
        }
    }
    else
    {
        if (direction == '+')
        {
            a.addAcceleration(sf::Vector2f(g, 0));
        }
        else
        {
            a.addAcceleration(sf::Vector2f(-g, 0));
        }
    }
}

void Physics::collisionCheck(Actor& a, Actor& b)
{

}