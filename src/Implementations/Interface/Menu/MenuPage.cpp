#pragma once

#include "Interface/Menu/MenuPage.h"

MenuPage::MenuPage()
{

}

MenuPage::MenuPage(const MenuPage& temp)
{
    elements = elements;
}

MenuPage::~MenuPage()
{

}

void MenuPage::addElement(Widget*& element)
{
    elements.push_back(element);
}