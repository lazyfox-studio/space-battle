#pragma once

#include "Interface/Widget/Widget.h"
#include "Flipbook/Flipbook.h"

//»конка отображающа€ значение булеана
class Icon : Widget
{
protected:
     
    bool* current;
    Flipbook onFlipbook, offFlipbook;

public:
    Icon();
    Icon(const Icon& temp);
    Icon(bool* current_, std::string onTexture, std::string offTexture);
    ~Icon();

    void drawIn(sf::RenderWindow& window);
};