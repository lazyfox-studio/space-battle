#pragma once

#include "../Widget/Button/Button.h"
#include <vector>;

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
    std::vector<Button::base> buttons;
    //std::vector<TextSpace> Text;

public:
    DialogWindow();
    DialogWindow(const DialogWindow& temp);
    //DialogWindow() Куча параметров
    ~DialogWindow();

    void draw();
};