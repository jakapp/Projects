#include "coach.h"

Coaches::Coaches()
{

}

Coaches::~Coaches()
{

}

void Coaches::setCoachID(string id)
{
    coach_ID = id;
}

void Coaches::setSeason(int val)
{
    season = val;
}

void Coaches::setFirstName(string fname)
{
    first_name = fname;
}

void Coaches::setLastName(string lname)
{
    last_name = lname;
}

void Coaches::setSeasonWin(int val)
{
    season_win = val;
}

void Coaches::setSeasonLoss(int val)
{
    season_loss = val;
}

void Coaches::setPlayoffWin(int val)
{
    playoff_win = val;
}

void Coaches::setPlayoffLoss(int val)
{
    playoff_loss = val;
}

void Coaches::setTeam(string tm)
{
    team = tm;
}

void Coaches::setYearOrder(int val)
{
    yr_order = val;
}

string Coaches::getCoachID() const
{
    return coach_ID;
}
int Coaches::getSeason() const
{
    return season;
}
string Coaches::getFirstName() const
{
    return first_name;
}
string Coaches::getLastName() const
{
    return last_name;
}
int Coaches::getSeasonWin() const
{
    return season_win;
}
int Coaches::getSeasonLoss() const
{
    return season_loss;
}
int Coaches::getPlayoffWin() const
{
    return playoff_win;
}
int Coaches::getPlayoffLoss() const
{
    return playoff_loss;
}
string Coaches::getTeam() const
{
    return team;
}

int Coaches::getYearOrder() const
{
    return yr_order;
}
