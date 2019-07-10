#pragma once

#include "Interface/Widget/Icon/Icon.h"

Icon::Icon()
{
    current = nullptr;
    onFlipbook.assignTexture("Empty");
    offFlipbook.assignTexture("Empty");
}

Icon::Icon(const Icon& temp)
{
    current = temp.current;
    onFlipbook = temp.onFlipbook;
    offFlipbook = temp.offFlipbook;
}

Icon::Icon(bool* current_, TTD onTexture, TTD offTexture)
{
    current = current_;
    onFlipbook.assignTexture(onTexture);
    offFlipbook.assignTexture(offTexture);
}

Icon::~Icon()
{

}

void Icon::drawIn(sf::RenderWindow& window)
{
    if (*current)
    {
        onFlipbook.drawIn(window);
    }
    else
    {
        offFlipbook.drawIn(window);
    }
}