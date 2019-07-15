#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "LuaScript/LuaScript.h"
#include <map>
#include <string>

namespace Game
{
	extern LuaEnv lua;
}

struct Music
{
	sf::Music music;
};

class MusicTable
{
	static std::map<const std::string, Music> music;
	MusicTable();
	MusicTable(const MusicTable&);
public:
	static void init();
	static const sf::Music& getMusic(const std::string index);
	static const Music& get(const std::string index);
	static void load(const std::string index);
	static void loadAll();
	static void unload(const std::string index);
	static void unloadAll();
};