#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>

class Logger
{
protected:
    static std::ofstream logFile;

public:
    static void start(std::string path = "latest.log"); //Открытие .log файла
    static void end();                                  //Закрытие .log файла
    static void log(std::string messange, std::string event_type = "Global Event");              //Запись сообщения в .log файл
};