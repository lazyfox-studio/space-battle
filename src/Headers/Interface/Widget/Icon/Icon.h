#pragma once

#include "Interface/Widget/Widget.h"
#include "Flipbook/Flipbook.h"

//»конка отображающа€ значение булеана
class Icon : Widget
{
protected:
    typedef TextureTableDictionary TTD;
    bool* current;
    Flipbook onFlipbook, offFlipbook;

public:
    Icon();
    Icon(const Icon& temp);
    Icon(bool* current_, TTD onTexture, TTD offTexture);
    ~Icon();

    void drawIn(sf::RenderWindow& window);
};