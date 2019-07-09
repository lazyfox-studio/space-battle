#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "FontTableDictionary.h"
#include <array>
#include <string>

class FontTable
{
protected:
	static std::array<sf::Font, FontTableCount> font;
	static std::array<bool, FontTableCount> isLoaded;        // Загружен ли шрифт
	static std::array<std::string, FontTableCount> fontPath; // Пути к шрифтам

	friend class text;
	friend class Scoreboard;
	friend class Textarea;

	//Объекты не должны быть собраны
private:
	FontTable();
	FontTable(const FontTable& temp);
	~FontTable();

public:
	static void load(FontTableDictionary index);
	static void loadAll();
	static void unload(FontTableDictionary index);
	static void unloadAll();
};