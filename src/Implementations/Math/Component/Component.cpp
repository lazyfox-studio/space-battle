#pragma once

#include "Math/Component/Component.h"

Component::Component()
{
    x = 0;
    y = 0;
    angle = 0;
    r = 0;
    R = 0;
}

Component::Component(const Component& temp)
{
    x = temp.x;
    y = temp.y;
    angle = temp.angle;
    r = temp.r;
    R = temp.R;
}

Component::Component(float x_, float y_, int angle_, float r_, float R_)
{
    x = x_;
    y = y_;
    angle = angle_;
    r = r_;
    R = R_;
}
Component::~Component()
{

}

Component& Component::operator=(const Component& temp)
{
    x = temp.x;
    y = temp.y;
    angle = temp.angle;
    r = temp.r;
    R = temp.R;
    return *this;
}