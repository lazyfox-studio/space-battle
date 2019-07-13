#pragma once

#include "Interface/Widget/Button/Button.h"
#include "Interface/Grid/Grid.h"
#include <vector>

//���������� ����
class DialogWindow
{
protected:
    //���������� ����
    float x;
    float y;

    //��������� ����
    unsigned height;
    unsigned width;

    //�������� ����
	Grid elements;

public:
    DialogWindow();
    DialogWindow(const DialogWindow& temp);
    //DialogWindow() ���� ����������
    ~DialogWindow();

    void draw();
};