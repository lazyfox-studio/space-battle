#include "Logger.h"

std::ofstream Logger::logFile;

void Logger::start(std::string path)
{
    logFile.open(path);
}

void Logger::end()
{
    logFile.close();
}

void Logger::log(std::string messange, std::string event_type)
{
    if (!logFile.is_open()) return;
    time_t current_time = time(NULL);
    std::tm *date = std::localtime(&current_time);

    logFile << "[";
    logFile << std::setfill('0') << std::setw(2) << date->tm_mday;
    logFile << ".";
    logFile << std::setfill('0') << std::setw(2) << date->tm_mon + 1;
    logFile << ".";
    logFile << date->tm_year + 1900 << "] ";
    logFile << "[";
    logFile << std::setfill('0') << std::setw(2) << date->tm_hour;
    logFile << ":";
    logFile << std::setfill('0') << std::setw(2) << date->tm_min;
    logFile << ":";
    logFile << std::setfill('0') << std::setw(2) << date->tm_sec;
    logFile << "] [" << event_type << "] " << messange << std::endl;
    //Как всё удобно! XD
}