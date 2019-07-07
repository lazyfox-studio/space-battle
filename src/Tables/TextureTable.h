#pragma once

#include <SFML/Graphics.hpp>
#include "../Constants.h"
#include "TextureTableDictionary.h"
#include "Flipbook/Flipbook.h"

//Таблица текстур
class TextureTable
{
protected:
    static sf::Texture texture[TextureTableCount][1];
    static bool isLoaded[TextureTableCount][1]; //Загружена ли текстура
    static unsigned frameWidth[TextureTableCount][1]; //Ширина кадра
    static unsigned frameHeight[TextureTableCount][1]; //Высота кадра
    static unsigned frameCount[TextureTableCount][1]; //Число кадров

    friend class Flipbook;

    //Объекты не должны быть собраны
private:
    TextureTable();
    TextureTable(const TextureTable& temp);
    ~TextureTable();

public:
    static void load(TextureTableDictionary index);
    static void loadAll();
    static void unload(TextureTableDictionary index);
    static void unloadAll();
};