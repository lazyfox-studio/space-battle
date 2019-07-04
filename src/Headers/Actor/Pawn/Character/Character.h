//Управляемый игроком(ами) объект

#pragma once
#include "..//Pawn.h"
#include "..//..//..//Global/Control.h"

class Character : Pawn
{
    friend class Control;
};