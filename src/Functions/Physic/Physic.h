#pragma once

#include "Actor/Actor.h"
#include "../Constants.h"

namespace Physic
{
    //Ньютоновское притяжение
    void Gravitation(Actor a, Actor b);
    //Притяжение по оси Y
    void VerticalAcceleration(Actor a);
    //Проверка коллизий
    void Collisions(Actor a, Actor b);
}