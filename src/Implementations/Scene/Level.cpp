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
    delete[] interactions;
    delete[] modifications;
}

void Level::resume()
{
    status = 1;
}

void Level::pause()
{
    status = 0;
}

void Level::stop()
{
    status = 0;
    //���, ��� ����� ��� ���������
}

void Level::play()
{
    if (status == 1)
    {

    }
}
