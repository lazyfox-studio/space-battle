//Класс управления, привязывается к Character'у
#pragma once

#include "..//Actor/Pawn/Character/Character.h"

class Control
{
    Character* slave;
    
public:
    Control(const Character& slave_);
    Control(const Character* slave_);
};