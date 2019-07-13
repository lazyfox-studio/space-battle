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

void MenuPage::addElement(size_t row, Widget*& element)
{
	// check row!
    elements.widgets[row].push_back(element);
}