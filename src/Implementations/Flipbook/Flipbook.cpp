#include "Flipbook/Flipbook.h"
#include "..\..\Headers\Flipbook\Flipbook.h"
void Flipbook::updateTextureRect()
{
	sprite.setTextureRect(sf::IntRect(frameWidth * frameCurrent, 0, frameWidth, frameHeight));
}

Flipbook::Flipbook()
{
	index = "Empty";
	frameWidth = frameHeight = 0U;
	frameCount = frameCurrent = 0U;
	isVisible = true;
	sprite.setTexture(TextureTable::getTexture(index));
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
	sprite.setTexture(TextureTable::getTexture(index));
	updateTextureRect();
}

Flipbook::Flipbook(std::string index_)
{
	const Texture& textureData = TextureTable::get(index);
	index = index_;
	frameWidth = textureData.width;
	frameHeight = textureData.height;
	frameCount = textureData.frames;
	frameCurrent = 0U;
	isVisible = true;
	sprite.setTexture(textureData.texture);
	updateTextureRect();
}

bool Flipbook::visible() const
{
	return isVisible;
}

float Flipbook::width() const
{
	return sprite.getOrigin().x;
}

float Flipbook::height() const
{
	return sprite.getOrigin().y;
}

sf::Vector2f Flipbook::getPosition() const
{
	return sprite.getPosition();
}

void Flipbook::assignTexture(std::string index_)
{
	const Texture& textureData = TextureTable::get(index_);
	index = index_;
	frameWidth = textureData.width;
	frameHeight = textureData.height;
	frameCount = textureData.frames;
	frameCurrent = 0U;
	sprite.setTexture(textureData.texture);
	updateTextureRect();
}

void Flipbook::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Flipbook::scale(float factor)
{
	sprite.setScale(sf::Vector2f(factor, factor));
}

void Flipbook::rotate(int angle)
{
	sprite.rotate(float(angle));
}

void Flipbook::setRotation(int angle)
{
	sprite.setRotation(float(angle));
}

void Flipbook::setTextureRect(sf::IntRect rect)
{
	sprite.setTextureRect(rect);
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

Flipbook& Flipbook::operator=(const Flipbook& temp)
{
	index = temp.index;
	frameWidth = temp.frameWidth;
	frameHeight = temp.frameHeight;
	frameCount = temp.frameCount;
	frameCurrent = temp.frameCurrent;
	isVisible = temp.isVisible;
	sprite.setTexture(TextureTable::getTexture(index));
	updateTextureRect();
	return *this;
}
