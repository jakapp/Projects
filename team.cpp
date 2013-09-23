#include "team.h"

void Teams::setTeamID(string id)
{
    team_ID = id;
}

void Teams::setLocation(string loc)
{
    location = loc;
}

void Teams::setName(string ne)
{
    name = ne;
}

void Teams::setLeague(char ch)
{
   league = ch;
}

string Teams::getTeamID() const
{
    return team_ID;
}

string Teams::getLocation() const
{
    return location;
}

string Teams::getName() const
{
    return name;
}

char Teams::getLeague() const
{
    return league;
}
