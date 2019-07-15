#pragma once

// Класс компоненты (используется для коллизий)
class Component
{
protected:
    // Координаты
    float x;
    float y;
    int angle;  //Угол
    
    // Параметры осей
    float r; //Малая полуось
    float R; //Большая полуось

    friend class Actor;

public:
    Component();
    Component(const Component& temp);
    Component(float x_, float y_, int angle_, float height_, float width_);
    ~Component();

    Component& operator=(const Component& temp);
};