#include "Tables/MusicTable.h"

std::map<const std::string, Music> MusicTable::music = std::map<const std::string, Music>();

void MusicTable::init()
{
	LuaScript script(Game::lua);
	script.execute("config/Tables/Textures.lua");
}

const sf::Music& MusicTable::getMusic(const std::string index)
{
	auto musicIter = music.find(index);
	if (musicIter == music.end())
	{
		load(index);
		return music[index].music;
	}
	return (*musicIter).second.music;
}

const Music& MusicTable::get(const std::string index)
{
	auto musicIter = music.find(index);
	if (musicIter == music.end())
	{
		load(index);
		return music[index];
	}
	return (*musicIter).second;
}

void MusicTable::load(const std::string index)
{
	luabridge::LuaRef musicData = Game::lua.getGlobal("music");
	luabridge::LuaRef musicFileData = musicData[index.c_str()];
	if (musicFileData.isNil())
		throw std::out_of_range("Music with that index not found."); // noindex
	Music musicFile;
	musicFile.music.openFromFile(musicFileData["path"].cast<std::string>().c_str());
	//music.insert(std::pair<const std::string, Music>(index, musicFile)); ???!!
}

void MusicTable::unload(const std::string index)
{
	music.erase(index);
}

void MusicTable::unloadAll()
{
	music.clear();
}
