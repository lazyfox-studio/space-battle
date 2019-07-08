#pragma once

#include <SFML/Graphics.hpp>
#include "Tables/TextureTable.h"

// Мультиспрайт (спрайт с покадровой анимацией)
class Flipbook
{
protected:
	typedef TextureTableDictionary TTD;
	TTD        index;         // Номер текстуры в таблице
    sf::Sprite sprite;        // Фрейм-контейнер
    unsigned   frameWidth;    // Ширина кадра
    unsigned   frameHeight;   // Высота кадра
    unsigned   frameCount;    // Количество кадров
    unsigned   frameCurrent;  // Текущий кадр
    bool       isVisible;     // Видим ли спрайт
    //Можно сделать поля для работы с эффектами

	// Перерасчет области текстуры
	void updateTextureRect();
public:
    //Конструкторы
    Flipbook();
    Flipbook(const Flipbook& temp);
    Flipbook(TTD index_);

    //Обновление текстуры
    void assignTexture(TTD index_);

    //Управление анимацией
    void nextFrame(); //Следущий кадр
    void previousFrame(); //Предыдущий кадр
    void firstFrame(); //Первый кадр
    
    //Рисование
    void drawIn(sf::RenderWindow& window);
    void makeVisible();
    void makeUnvisible();
};