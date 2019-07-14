#pragma once
#include "Actor/Pawn/Pawn.h"

// Персонаж (управляемый игроком объект)
class Character : Pawn
{
    friend class InputControl;
};