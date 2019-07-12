#pragma once

#include "Scene/Level.h"

Level::Level(sf::RenderWindow* window_, ViewControl* view, std::string path)
{
    window = window_;
    views.push_back(view);
    //������ ������ �� �����
}

Level::~Level()
{
}

void Level::resume()
{
    isActive = 1;
}

void Level::pause()
{
	isActive = 0;
}

void Level::stop()
{
	isActive = 0;
    //���, ��� ����� ��� ���������
}

void Level::play()
{
    if (isActive)
    {

    }
}
