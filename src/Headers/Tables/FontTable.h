#pragma once

#include <SFML/Graphics.hpp>
#include "LuaScript/LuaScript.h"
#include <map>
#include <string>

struct Font
{
	sf::Font font;
};

class FontTable
{
	static std::map<std::string, Font> fonts;
	FontTable();
	FontTable(const FontTable&);
	friend class Scoreboard;
	friend class text;
public:
	static const sf::Font& getFont(const std::string index); // õç
	static const Font& get(const std::string index);
	static void load(const std::string index);
	static void loadAll();
	static void unload(const std::string index);
	static void unloadAll();
};

