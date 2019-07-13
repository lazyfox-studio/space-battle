#pragma once

#include "Interface/Widget/Button/Button.h"
#include "Interface/Grid/Grid.h"
#include <vector>

//Диалоговое окно
class DialogWindow
{
protected:
    //Координаты окна
    float x;
    float y;

    //Параметры окна
    unsigned height;
    unsigned width;

    //Элементы окна
	Grid elements;

public:
    DialogWindow();
    DialogWindow(const DialogWindow& temp);
    //DialogWindow() Куча параметров
    ~DialogWindow();

    void draw();
};