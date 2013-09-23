#ifndef DATABASE_CONTROLLER_H
#define DATABASE_CONTROLLER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "coach.h"
#include "team.h"

using namespace std;

class DatabaseController
{
public:
    bool loadFile();
    bool parseCoachFile(ifstream &coachFile);
    bool parseTeamFile(ifstream &teamFile);

private:
    vector<Coaches*> coachData;
    vector<Teams*> teamData;

};


#endif // DATABASE_CONTROLLER_H
