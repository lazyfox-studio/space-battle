#include "Service.h"

void Service::foreach(void* function(Actor&, Actor&), std::vector <Actor> actors)
{
    for (int i = 0; i < actors.size(); i++)
    {
        for (int j = i; j < actors.size(); j++)
        {
            function(actors[i], actors[j]);
        }
    }
}