#pragma once

#include <vector>
#include "Interface/Menu/MenuPage.h"

//Μενώ
class Menu
{
    std::vector<MenuPage> pages;

    Menu();
    Menu(const Menu& temp);
    ~Menu();

    void addPage(MenuPage& page);
};