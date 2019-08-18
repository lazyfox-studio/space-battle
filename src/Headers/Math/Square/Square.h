#pragma once

class Square
{
public:
    //Координаты
    float x;
    float y;

    //Параметры
    float r; //половина стороны


    Square();
    Square(const Square& temp);
    Square(float x_, float y_, float r_);
    ~Square();

    Square& operator=(const Square& temp);

    void setPosition(float x_, float y_);
};