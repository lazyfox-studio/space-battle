#pragma once

#include "Math/Component/Component.h"

Component::Component()
{
    x = 0;
    y = 0;
    height = 0;
    width = 0;
}

Component::Component(const Component& temp)
{
    x = temp.x;
    y = temp.y;
    height = temp.height;
    width = temp.width;
}

Component::Component(float x_, float y_, float height_, float width_)
{
    x = x_;
    y = y_;
    height = height_;
    width = width_;
}
Component::~Component()
{

}

Component& Component::operator=(const Component& temp)
{
    x = temp.x;
    y = temp.y;
    height = temp.height;
    width = temp.width;
    return *this;
}