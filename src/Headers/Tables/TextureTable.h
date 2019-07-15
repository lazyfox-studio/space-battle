#pragma once

#include <SFML/Graphics.hpp>
#include "LuaScript/LuaScript.h"
#include <map>
#include <string>

namespace Game
{
	extern LuaEnv lua;
}

struct Texture
{
	sf::Texture texture;
	unsigned width = 0U;
	unsigned height = 0U;
	unsigned frames = 1U;
};

class TextureTable
{
	static std::map<std::string, Texture> textures;
	TextureTable();
	TextureTable(const TextureTable&);
	friend class Flipbook;
public:
	static void init();
	static const sf::Texture& getTexture(const std::string index); // хз
	static const Texture& get(const std::string index);
	static void load(const std::string index);
	static void loadAll();
	static void unload(const std::string index);
	static void unloadAll();
};

