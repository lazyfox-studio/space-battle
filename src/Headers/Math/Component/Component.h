#pragma once

// Класс компоненты (используется для коллизий)
class Component
{
protected:
    // Координаты
    float x;
    float y;
    
    // Параметры осей
    float height; //Высота компоненты
    float width;  //Ширина компоненты

    friend class Actor;

public:
    Component();
    Component(const Component& temp);
    Component(float x_, float y_, float height_, float width_);
    ~Component();

    Component& operator=(const Component& temp);
};