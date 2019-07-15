#include "Tables/TextureTable.h"

std::map<std::string, Texture> TextureTable::textures = std::map<std::string, Texture>();

void TextureTable::init()
{
	LuaScript script(Game::lua);
	script.execute("config/Tables/Textures.lua");
}

const sf::Texture& TextureTable::getTexture(const std::string index)
{
	auto textureIter = textures.find(index);
	if (textureIter == textures.end())
	{
		load(index);
		return textures[index].texture;
	}
	return (*textureIter).second.texture;
}

const Texture& TextureTable::get(const std::string index)
{
	auto textureIter = textures.find(index);
	if (textureIter == textures.end())
	{
		load(index);
		return textures[index];
	}
	return (*textureIter).second;
}

void TextureTable::load(const std::string index)
{
	luabridge::LuaRef texturesData = Game::lua.getGlobal("textures");
	luabridge::LuaRef textureData = texturesData[index.c_str()];
	if (textureData.isNil())
		throw std::out_of_range("Texture with that index not found."); // noindex
	Texture texture;
	texture.texture.loadFromFile(textureData["path"].cast<std::string>().c_str());;
	texture.width = textureData["width"].cast<unsigned>();
	texture.height = textureData["height"].cast<unsigned>();
	texture.frames = textureData["frames"].cast<unsigned>();
	textures.insert(std::pair<std::string, Texture>(index, texture));
}

void TextureTable::unload(const std::string index)
{
	textures.erase(index);
}

void TextureTable::unloadAll()
{
	textures.clear();
}
