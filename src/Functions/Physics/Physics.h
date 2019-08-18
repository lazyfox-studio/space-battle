#pragma once

#include <cmath>
#include "Actor/Actor.h"
#include "Constants.h"

namespace Physics
{
    // Ньютоновское притяжение
    void gravitation(Actor& a, Actor& b);

    // Притяжение по произвольной оси с укорением g
    void acceleration(Actor& a, char axis = 'y', char direction = '+');

    // Проверка коллизий
    void collisionCheck(Actor& a, Actor& b);

	// Расстояние
	template<typename Type1, typename Type2>
	float distance(const Type1& a, const Type2& b);
}

template<typename Type1, typename Type2>
float Physics::distance(const Type1& a, const Type2& b)
{
	float x1 = a.getX(), x2 = b.getX(), y1 = a.getY(), y2 = b.getY();
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}