#pragma once
#include "../Pawn.h"
#include "../../../Global/Control.h"

// Персонаж (управляемый игроком объект)
class Character : Pawn
{
    friend class Control;
};