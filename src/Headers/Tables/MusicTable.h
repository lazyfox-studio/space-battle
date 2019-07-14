#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "LuaScript/LuaScript.h"
#include <map>
#include <string>

struct Music
{
	sf::Music music;
};

class MusicTable
{
	static std::map<const std::string, Music> music;
	MusicTable();
	MusicTable(const MusicTable&);
	friend class Scoreboard;
	friend class text;
public:
	static const sf::Music& getMusic(const std::string index);
	static const Music& get(const std::string index);
	static void load(const std::string index);
	static void loadAll();
	static void unload(const std::string index);
	static void unloadAll();
};