#include "Tables/FontTable.h"

std::map<std::string, Font> FontTable::fonts = std::map<std::string, Font>();

const sf::Font& FontTable::getFont(const std::string index)
{
	auto fontIter = fonts.find(index);
	if (fontIter == fonts.end())
	{
		load(index);
		return fonts[index].font;
	}
	return (*fontIter).second.font;
}

const Font& FontTable::get(const std::string index)
{
	auto fontIter = fonts.find(index);
	if (fontIter == fonts.end())
	{
		load(index);
		return fonts[index];
	}
	return (*fontIter).second;
}

void FontTable::load(const std::string index)
{
	LuaScript script;
	script.execute("config/Tables/Fonts.lua");
	luabridge::LuaRef fontsData = script.getGlobal("fonts");
	luabridge::LuaRef fontData = fontsData[index.c_str()];
	if (fontData.isNil())
		throw std::out_of_range("Font with that index not found."); // noindex
	Font font;
	font.font.loadFromFile(fontData["path"].cast<std::string>().c_str());;
	fonts.insert(std::pair<std::string, Font>(index, font));
}

void FontTable::unload(const std::string index)
{
	fonts.erase(index);
}

void FontTable::unloadAll()
{
	fonts.clear();
}
