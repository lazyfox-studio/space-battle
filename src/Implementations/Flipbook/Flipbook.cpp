#include "Flipbook/Flipbook.h"

void Flipbook::updateTextureRect()
{
	sprite.setTextureRect(sf::IntRect(frameWidth * frameCurrent, 0, frameWidth, frameHeight));
}

Flipbook::Flipbook()
{
	index = TTD::TextureEmpty;
	frameWidth = frameHeight = 0U;
	frameCount = frameCurrent = 0U;
	isVisible = true;
	sprite.setTexture(TextureTable::texture[index]);
	updateTextureRect();
}

Flipbook::Flipbook(const Flipbook& temp)
{
	index = temp.index;
	frameWidth = temp.frameWidth;
	frameHeight = temp.frameHeight;
	frameCount = temp.frameCount;
	frameCurrent = temp.frameCurrent;
	isVisible = temp.isVisible;
	sprite.setTexture(TextureTable::texture[index]);
	updateTextureRect();
}

Flipbook::Flipbook(TTD index_)
{
	index = index_;
	frameWidth = TextureTable::frameWidth[index];
	frameHeight = TextureTable::frameHeight[index];
	frameCount = TextureTable::frameCount[index];
	frameCurrent = 0U;
	isVisible = true;
	sprite.setTexture(TextureTable::texture[index]);
	updateTextureRect();
}

void Flipbook::assignTexture(TTD index_)
{
	index = index_;
	frameWidth = TextureTable::frameWidth[index];
	frameHeight = TextureTable::frameHeight[index];
	frameCount = TextureTable::frameCount[index];
	frameCurrent = 0U;
	sprite.setTexture(TextureTable::texture[index]);
	updateTextureRect();
}

void Flipbook::nextFrame()
{
	frameCurrent = frameCurrent < frameCount - 1 ? frameCurrent + 1 : 0U;
	updateTextureRect();
}

void Flipbook::previousFrame()
{
	frameCurrent = frameCurrent > 0 ? frameCurrent - 1 : frameCount - 1;
	updateTextureRect();
}

void Flipbook::firstFrame()
{
	frameCurrent = 0U;
	updateTextureRect();
}

void Flipbook::drawIn(sf::RenderWindow& window)
{
	if(isVisible)
		window.draw(sprite);
}

void Flipbook::makeVisible()
{
	isVisible = true;
}

void Flipbook::makeUnvisible()
{
	isVisible = false;
}
