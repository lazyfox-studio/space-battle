#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "Global/ViewControl.h"
#include "Actor/Pawn/Character/Character.h"

//Уровень (управляет тем какие объекты есть на карте, какой фон и т.п.)
class Level
{
public:
	enum class Status
	{
		inactive,
		active,
		undefined
	};
protected:
    //Состояние уровня
    Status status;

    // Объекты уровня
    sf::RenderWindow* window;           // Окно, в котором рисуется уровень
    std::vector<ViewControl*> views;    // Все View на уровне
    std::vector<Actor*> actors;         // Все объекты (надо будет разбить с помощью введения поля "группа")
    std::vector<Pawn*> pawns;           // Все подвижные объекты
    std::vector<Character*> characters; // Все игроки
    
    // Функции
	std::vector<void(*)(Actor&, Actor&)> interactions; // Функции, обрабатывающие взаимодействия объектов
	std::vector<void(*)(Actor&)> modifications;        // Функции, преобразующие объекты

public:
    Level(sf::RenderWindow* window_, ViewControl* view, std::string path);
    ~Level();

    //Управление уровнем
    void pause();  //Пауза
    void resume();  //Запуск уровня
    void stop();   //Остановка уровня и закрытие
    void play();   //Проиграть уровень
};