#pragma once

#include "Functions.h"

double Distance(const Actor& a, const Actor& b)
{
    return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
}