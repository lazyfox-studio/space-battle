#pragma once

#include <SFML/Graphics.hpp>
#include "LuaScript/LuaScript.h"
#include <map>
#include <string>

struct DTexture
{
	sf::Texture texture;
	unsigned width = 0U;
	unsigned height = 0U;
	unsigned frames = 1U;
};

class DTextureTable
{
	static std::map<std::string, DTexture> textures;
	DTextureTable();
	DTextureTable(const DTextureTable&);
	friend class Flipbook;
public:
	static const sf::Texture& get(const std::string index); // хз
	static void load(const std::string index);
	static void loadAll();
	static void unload(const std::string index);
	static void unloadAll();
};

