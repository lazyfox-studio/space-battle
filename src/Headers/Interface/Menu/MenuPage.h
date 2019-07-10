#pragma once

#include <vector>
#include "Interface/Widget/Widget.h"

//Страница меню
class MenuPage
{
protected:
    std::vector<Widget*> elements;

public:
    MenuPage();
    MenuPage(const MenuPage& temp);
    MenuPage(std::vector<Widget*> element_);
    ~MenuPage();

    void addElement(Widget*& element);
};