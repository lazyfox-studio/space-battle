#pragma once

// Анимация
class Flipbook
{
protected:
    //TextureTableIndex index; Номер текстуры в таблице
    sf::Sprite frame;
    unsigned frameWidth; //Ширина кадра
    unsigned frameHeight; //Высота кадра
    unsigned frameCount; //Количество кадров
    unsigned frameCurrent; //Текущий кадр
    bool isVisible; //Видим ли спрайт
    //Можно сделать поля для работы с эффектами

public:
    //Конструкторы
    Flipbook();
    Flipbook(const Flipbook& temp);
    //Flipbook(TextureTableIndex index_);

    //Обновление текстуры
    //void assign(TextureTableIndex index_);

    //Управление анимацией
    void frameNext(); //Следущий кадр
    void framePrevious(); //Предыдущий кадр
    void frameFirst(); //Первый кадр
    
    //Рисование
    void draw();
    void makeVisible();
    void makeUnvisible();
};