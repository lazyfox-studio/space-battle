#include "Math/Square/Square.h"

Square::Square()
{
    x = 0;
    y = 0;
    r = 0;
}

Square::Square(const Square& temp)
{
    x = temp.x;
    y = temp.y;
    r = temp.r;

}

Square::Square(float x_, float y_, float r_)
{
    x = x_;
    y = y_;
    r = r_;
}

Square::~Square()
{

}

Square& Square::operator=(const Square& temp)
{
    x = temp.x;
    y = temp.y;
    r = temp.r;
    return *this;
}

void Square::setPosition(float x_, float y_)
{
    x = x_;
    y = y_;
}