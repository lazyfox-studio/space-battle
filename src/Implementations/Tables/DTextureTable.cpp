#include "Tables/DTextureTable.h"

std::map<std::string, DTexture> DTextureTable::textures = std::map<std::string, DTexture>();

const sf::Texture& DTextureTable::getTexture(const std::string index)
{
	auto textureIter = textures.find(index);
	if (textureIter == textures.end())
		throw std::out_of_range("Texture with that index not loaded."); // noindex
	return (*textureIter).second.texture;
}

const DTexture& DTextureTable::get(const std::string index)
{
	auto textureIter = textures.find(index);
	if (textureIter == textures.end())
		throw std::out_of_range("Texture with that index not loaded."); // noindex
	return (*textureIter).second;
}

void DTextureTable::load(const std::string index)
{
	LuaScript script;
	script.execute("config/Tables/Textures.lua");
	luabridge::LuaRef texturesData = script.getGlobal("textures");
	luabridge::LuaRef textureData = texturesData[index.c_str()];
	if (textureData.isNil())
		throw std::out_of_range("Texture with that index not found."); // noindex
	DTexture texture;
	texture.texture.loadFromFile(textureData["path"].cast<std::string>().c_str());;
	texture.width = textureData["width"].cast<unsigned>();
	texture.height = textureData["height"].cast<unsigned>();
	texture.frames = textureData["frames"].cast<unsigned>();
	textures.insert(std::pair<std::string, DTexture>(index, texture));
}

void DTextureTable::unload(const std::string index)
{
	textures.erase(index);
}

void DTextureTable::unloadAll()
{
	textures.clear();
}
