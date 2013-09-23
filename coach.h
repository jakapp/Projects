#ifndef COACH_H
#define COACH_H

#include <string>

using namespace std;

class Coaches
{
public:

    Coaches();
    ~Coaches();

    void setCoachID(string id);
    void setSeason(int val);
    void setFirstName(string fname);
    void setLastName(string lname);
    void setSeasonWin(int val);
    void setSeasonLoss(int val);
    void setPlayoffWin(int val);
    void setPlayoffLoss(int val);
    void setTeam(string tm);
    void setYearOrder(int val);

    string getCoachID() const;
    int getSeason() const;
    string getFirstName() const;
    string getLastName() const;
    int getSeasonWin() const;
    int getSeasonLoss() const;
    int getPlayoffWin() const;
    int getPlayoffLoss() const;
    string getTeam() const;
    int getYearOrder() const;

private:
    string coach_ID;
    int season;
    string first_name;
    string last_name;
    int season_win;
    int season_loss;
    int playoff_win;
    int playoff_loss;
    string team;
    int yr_order;



};


#endif // COACH_H
