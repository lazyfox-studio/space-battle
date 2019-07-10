#pragma once

#include "Actor/Actor.h"
#include "Constants.h"

namespace Physic
{
    //Ньютоновское притяжение
    void gravitation(Actor& a, Actor& b);
    //Притяжение по оси Y
    void verticalAcceleration(Actor& a);
    //Проверка коллизий
    void collisions(Actor& a, Actor& b);
}