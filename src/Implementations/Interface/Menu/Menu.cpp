#pragma once

#include "Interface/Menu/Menu.h"

Menu::Menu()
{

}

Menu::Menu(const Menu& temp)
{
    pages = pages;
}

Menu::~Menu()
{

}

void Menu::addPage(MenuPage& page)
{
    pages.push_back(page);
}