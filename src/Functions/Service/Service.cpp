#include "Service.h"

void Service::foreachActorPair(void* function(Actor&, Actor&), std::vector <Actor> actors)
{
    for (int i = 0; i < actors.size(); i++)
    {
        for (int j = i + 1; j < actors.size(); j++)
        {
            function(actors[i], actors[j]);
        }
    }
}