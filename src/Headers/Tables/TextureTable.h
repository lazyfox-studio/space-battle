#pragma once

#include <SFML/Graphics.hpp>
#include "../Constants.h"
#include "TextureTableDictionary.h"
#include <array>

//Таблица текстур
class TextureTable
{
protected:
    static std::array<sf::Texture, TextureTableCount> texture;
	static std::array<bool, TextureTableCount> isLoaded;        // Загружена ли текстура
	static std::array<unsigned, TextureTableCount> frameWidth;  // Ширина кадра
	static std::array<unsigned, TextureTableCount> frameHeight; // Высота кадра
	static std::array<unsigned, TextureTableCount> frameCount;  // Количество кадров

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