#ifndef TEAM_H
#define TEAM_H

#include <string>

using namespace std;

class Teams
{
public:
    void setTeamID(string id);
    void setLocation(string loc);
    void setName(string ne);
    void setLeague(char ch);

    string getTeamID() const;
    string getLocation() const;
    string getName() const;
    char getLeague() const;

private:
    string team_ID;
    string location;
    string name;
    char league;
};

#endif // TEAM_H
