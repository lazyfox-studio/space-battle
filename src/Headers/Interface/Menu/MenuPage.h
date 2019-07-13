#pragma once

#include <vector>
#include "Interface/Grid/Grid.h"

//Страница меню
class MenuPage
{
protected:
    Grid elements;

public:
    MenuPage();
    MenuPage(const MenuPage& temp);
    MenuPage(Grid::GridElements elements_);
    ~MenuPage();

    void addElement(size_t row, Widget*& element);
};