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
    status = Status::active;
}

void Level::pause()
{
	status = Status::inactive;
}

void Level::stop()
{
	status = Status::inactive;
	//���, ��� ����� ��� ���������
}

void Level::play()
{
    if (status == Status::active)
    {

    }
}
