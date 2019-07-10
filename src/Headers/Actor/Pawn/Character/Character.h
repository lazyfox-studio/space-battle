#pragma once
#include "../Pawn.h"
#include "../../../Global/InputControl.h"

// Персонаж (управляемый игроком объект)
class Character : Pawn
{
    friend class InputControl;
};