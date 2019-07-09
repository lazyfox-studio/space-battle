#include "Tables/FontTable/FontTable.h"

std::array<sf::Font, FontTableCount> FontTable::font = std::array<sf::Font, FontTableCount>();
std::array<bool, FontTableCount> FontTable::isLoaded = std::array<bool, FontTableCount>();
std::array<std::string, FontTableCount> FontTable::fontPath = std::array<std::string, FontTableCount>();
