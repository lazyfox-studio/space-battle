#pragma once

#include "VirtualDevice/VirtualKeyboard.h"

VirtualKeyboard::VirtualKeyboard()
{
    mode = Mode::local;
}

explicit VirtualKeyboard::VirtualKeyboard(Mode mode_)
{
    mode = mode_;
}

VirtualKeyboard::VirtualKeyboard(VirtualKeyboard& temp)
{
    mode = temp.mode;
}

VirtualKeyboard::~VirtualKeyboard()
{

}

void VirtualKeyboard::update()
{
    if (mode == Mode::local)
    {
        //Сверка с таблицей, если нажатая клавиша есть в таблице то изменяет значения в структуре
    }
    else
    {
        //Чтение значений структуры из веб потока
    }
}