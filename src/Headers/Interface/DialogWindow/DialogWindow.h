#pragma once

#include "../Widget/Button/Button.h"
#include <vector>;

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
    std::vector<Button::base> buttons;
    //std::vector<TextSpace> Text;

public:
    DialogWindow();
    DialogWindow(const DialogWindow& temp);
    //DialogWindow() ���� ����������
    ~DialogWindow();

    void draw();
};