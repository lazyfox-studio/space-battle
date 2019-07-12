#pragma once

#include <cmath>
#include "Actor/Actor.h"
#include "Constants.h"

namespace Physics
{
    // Ньютоновское притяжение
    void gravitation(Actor& a, Actor& b);

    // Притяжение по оси Y
    void verticalAcceleration(Actor& a);

    // Проверка коллизий
    void collisions(Actor& a, Actor& b);

	// Расстояние
	template<typename Type1, typename Type2>
	void distance(const Type1& a, const Type2& b);
}

template<typename Type1, typename Type2>
void Physics::distance(const Type1& a, const Type2& b)
{
	float x1 = a.getX(), x2 = b.getX(), y1 = a.getY(), y2 = b.getY();
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}