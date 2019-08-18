#pragma once

#include <vector>

#include "Actor/Actor.h"

namespace Service
{
    //Вызов функции для всех пар Actor
    void foreachActorPair(void* function(Actor&, Actor&), std::vector <Actor> actors);
}