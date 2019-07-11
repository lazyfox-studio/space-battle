#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "Global/ViewControl.h"
#include "Actor/Actor.h"
#include "Actor/Pawn/Pawn.h"
#include "Actor/Pawn/Character/Character.h"

//Уровень (управляет тем какие объекты есть на карте, какой фон и т.п.)
class Level
{
protected:
    //Состояние уровня
    unsigned status; //0 - на пазе 1 - работает

    //Объекты уровня
    sf::RenderWindow* window;           //Окно в котором рисуется уровень
    std::vector<ViewControl*> views;    //Все View'ы на уровне
    std::vector<Actor*> actors;         //Все объекты (надо будет разбить с помощью введения поля "группа"
    std::vector<Pawn&> pawns;           //Все подвижные объекты
    std::vector<Character*> characters; //Все игроки
    
    //Массивы функций
    void (**interactions) (Actor& a, Actor& b); //Функции обрабатывающие взаимодействия объектов
    unsigned interationsCount;
    void(**modifications) (Actor& a);           //Функции преобразующие объекты
    unsigned modificationsCount;

public:
    Level(sf::RenderWindow* window_, ViewControl* view, std::string path);
    ~Level();

    //Управление уровнем
    void pause();  //Пауза
    void resume();  //Запуск уровня
    void stop();   //Остановка уровня и закрытие
    void play();   //Проиграть уровень
};