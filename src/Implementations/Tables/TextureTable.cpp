#include "Tables/TextureTable/TextureTable.h"

std::array<sf::Texture, TextureTableCount> TextureTable::texture = std::array<sf::Texture, TextureTableCount>();
std::array<bool, TextureTableCount> TextureTable::isLoaded = std::array<bool, TextureTableCount>();
std::array<unsigned, TextureTableCount> TextureTable::frameWidth = std::array<unsigned, TextureTableCount>();
std::array<unsigned, TextureTableCount> TextureTable::frameHeight = std::array<unsigned, TextureTableCount>();
std::array<unsigned, TextureTableCount> TextureTable::frameCount = std::array<unsigned, TextureTableCount>();