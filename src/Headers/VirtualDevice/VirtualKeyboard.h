#pragma once

class VirtualKeyboard
{
protected:
    enum class Mode
    {
        local,
        network,
    };

    Mode mode; //Откуда читать управление, с клавиатуры или по сети
    //webStream stream Что-то связанное с сетью
    //static KeyMap keyboard; Структура ОСЕЙ! т.е Up, Down, Shoot и т.п.

    friend class InputControl;

public:
    VirtualKeyboard();
    explicit VirtualKeyboard(Mode mode_);
    VirtualKeyboard(VirtualKeyboard& temp);
    ~VirtualKeyboard();

    void update();
    //Запись в сеть
};