#include "database_controller.h"

bool DatabaseController::loadFile()
{
    bool success;

    ifstream coachFile ("coaches_season.txt");
    if(!coachFile.is_open()){
        cout << "****** FAILED TO LOAD COACH DATABASE FILE. ABORTING ******" << endl;
        return false;
    }

    success = parseCoachFile(coachFile);
    if(!success){
        cout << "***** COACH DATABASE PARSING FAILED ******" << endl;
        return false;
    }

    ifstream teamFile ("teams.txt");
    if(!teamFile.is_open()){
        cout << "****** FAILED TO LOAD TEAM DATABASE FILE. ABORTING ******" << endl;
        return false;
    }

    success = parseTeamFile(teamFile);
    if(!success){
        cout << "***** COACH DATABASE PARSING FAILED ******" << endl;
        return false;
    }

    return true;
}

bool DatabaseController::loadFileCoaches(string path)
{
    bool success;

    ifstream coachFile(path.c_str());
    if(!coachFile.is_open()){
        cout << "****** FAILED TO LOAD COACH DATABASE FILE. ABORTING ******" << endl;
        return false;
    }

    success = parseCoachFile(coachFile);
    if(!success){
        cout << "***** COACH DATABASE PARSING FAILED ******" << endl;
        return false;
    }

    return true;
}

bool DatabaseController::loadFileTeams(string path)
{
    bool success;

    ifstream teamFile(path.c_str());
    if(!teamFile.is_open()){
        cout << "****** FAILED TO LOAD TEAM DATABASE FILE. ABORTING ******" << endl;
        return false;
    }

    success = parseTeamFile(teamFile);
    if(!success){
        cout << "***** COACH DATABASE PARSING FAILED ******" << endl;
        return false;
    }

    return true;
}

bool DatabaseController::parseCoachFile(ifstream &coachFile)
{
    int buffer;
    string token;
    string test;
    string comma = ",";
    Coaches *chPtr = NULL;

    getline(coachFile,test);
    while(!coachFile.eof())
    {
        chPtr = new Coaches;

        if(!chPtr){
            cout << "****** FAILED TO ALLOCATE MEMORY TO chPtr ******" << endl;
            return false;
        }

         getline(coachFile,test);
        for(int i = 0; i < 10; i++){
            token = test.substr(0,test.find(comma));
            test.erase(0, test.find(comma) + comma.length());

            if(i == 0)
                chPtr->setCoachID(token);
            else if(i == 3)
                chPtr->setFirstName(token);
            else if(i == 4)
                chPtr->setLastName(token);
            else if(i == 9)
                chPtr->setTeam(token);


            if(i == 1 || i == 2 || i == 5 || i == 6 || i ==7 || i== 8){
                buffer = atoi(token.c_str());

                if(i == 1)
                    chPtr->setSeason(buffer);
                else if(i == 2)
                    chPtr->setYearOrder(buffer);
                else if(i == 5)
                    chPtr->setSeasonWin(buffer);
                else if(i == 6)
                    chPtr->setSeasonLoss(buffer);
                else if(i == 7)
                    chPtr->setPlayoffWin(buffer);
                else if(i == 8)
                    chPtr->setPlayoffLoss(buffer);
            }
        }
        coachData.push_back(chPtr);
        chPtr = NULL;
    }

    coachData.pop_back();

    cout << "Coach parsing complete!" << endl;
    return true;
}

bool DatabaseController::parseTeamFile(ifstream &teamFile)
{
    string token;
    string token2;
    string token3;
    char token4;
    string test;
    string comma = ",";
    Teams *tmPtr = NULL;

    getline(teamFile,test);
    while(!teamFile.eof())
    {
        tmPtr = new Teams;

        if(!tmPtr){
            cout << "****** FAILED TO ALLOCATE MEMORY TO tmPtr ******" << endl;
            return false;
        }

        getline(teamFile,test);

        token = test.substr(0,test.find(comma));
        test.erase(0, test.find(comma) + comma.length());
        token2 = test.substr(0,test.find(comma));
        test.erase(0, test.find(comma) + comma.length());
        token3 = test.substr(0,test.find(comma));
        test.erase(0, test.find(comma) + comma.length());
        token4 = *((char*)(test.substr(0,test.find(comma))).c_str());
        test.erase(0, test.find(comma) + comma.length());

        tmPtr->setTeamID(token);
        tmPtr->setLocation(token2);
        tmPtr->setName(token3);
        tmPtr->setLeague(token4);

        teamData.push_back(tmPtr);
    }

    tmPtr = NULL;

    teamData.pop_back();

    cout << "Team parsing complete!" << endl;
    return true;
}

void DatabaseController::printCoachesCommand()
{
    Coaches *chPtr = NULL;

    for(unsigned int i = 0; i < coachData.size(); i++)
    {
        chPtr = coachData[i];
        cout << i+1 << ":     "
        << setw(10) << chPtr->getCoachID()
        << setw(10) << chPtr->getSeason()
        << setw(10) << chPtr->getFirstName()
        << setw(15) << chPtr->getLastName()
        << setw(10) << chPtr->getSeasonWin()
        << setw(10) << chPtr->getSeasonLoss()
        << setw(10) << chPtr->getPlayoffWin()
        << setw(10) << chPtr->getPlayoffLoss()
        << setw(10) << chPtr->getTeam() << endl;
    }

}

void DatabaseController::printTeamsCommand()
{
    Teams *tmPtr = NULL;

    cout << "#" << setw(10) << "team_id" << setw(15) << "location" << setw(20) << "name" << setw(15) << "league" << endl;

    for(unsigned int i = 0; i < teamData.size(); i++)
    {
        tmPtr = teamData[i];
        cout << i+1
        << setw(10) << tmPtr->getTeamID()
        << setw(15) << tmPtr->getLocation()
        << setw(20) << tmPtr->getName()
        << setw(15) << tmPtr->getLeague() << endl;

    }
}

void DatabaseController::printCoachesByName(string name)
{
    Coaches *chPtr = NULL;
    int cnt = 1;

//    cout << "#" << setw(10) << "coach_ID" << setw(10) << "season" << setw(10) << "first_name" << setw(15) << "last_name" << setw(10) << "season_win"
//         << setw(10) << "season_loss" << setw(10) << "playoff_win" << setw(10) << "playoff_loss" << setw(10) << "team" << endl;

    for(unsigned int i = 0; i < coachData.size(); i++){
        chPtr = coachData[i];
        if(name.compare(chPtr->getLastName()) == 0){
            cout << cnt << ":    "
            << setw(10) << chPtr->getCoachID()
            << setw(10) << chPtr->getSeason()
            << setw(10) << chPtr->getFirstName()
            << setw(15) << chPtr->getLastName()
            << setw(10) << chPtr->getSeasonWin()
            << setw(10) << chPtr->getSeasonLoss()
            << setw(10) << chPtr->getPlayoffWin()
            << setw(10) << chPtr->getPlayoffLoss()
            << setw(10) << chPtr->getTeam() << endl;
            cnt++;
        }
    }
}

void DatabaseController::printTeamsByCity(string name)
{
    Teams *tmPtr = NULL;
    int cnt = 1;

    cout << "#" << setw(10) << "team_id" << setw(15) << "location" << setw(20) << "name" << setw(15) << "league" << endl;

    for(unsigned int i = 0; i < teamData.size(); i++){
        tmPtr = teamData[i];
        if(name.compare(tmPtr->getLocation()) == 0){
            cout << cnt
            << setw(10) << tmPtr->getTeamID()
            << setw(15) << tmPtr->getLocation()
            << setw(20) << tmPtr->getName()
            << setw(15) << tmPtr->getLeague() << endl;
            cnt++;
        }
    }
}

void DatabaseController::printBestCoach(string year)
{
    Coaches *chPtr = NULL;
    int index = 0;
    int bestTotal = 0;
    int totalTemp = 0;
    int yr = atoi(year.c_str());

    for(unsigned int i = 0; i < coachData.size(); i++){
        chPtr = coachData[i];
        if(yr == chPtr->getSeason()){
            totalTemp = (chPtr->getSeasonWin() - chPtr->getSeasonLoss()) + (chPtr->getPlayoffWin() - chPtr->getPlayoffLoss());
            if(totalTemp > bestTotal){
                bestTotal = totalTemp;
                index = i;
            }
        }
    }

    chPtr = coachData[index];
    cout << index << ":    "
    << setw(10) << chPtr->getCoachID()
    << setw(10) << chPtr->getSeason()
    << setw(10) << chPtr->getFirstName()
    << setw(15) << chPtr->getLastName()
    << setw(10) << chPtr->getSeasonWin()
    << setw(10) << chPtr->getSeasonLoss()
    << setw(10) << chPtr->getPlayoffWin()
    << setw(10) << chPtr->getPlayoffLoss()
    << setw(10) << chPtr->getTeam() << endl;
}

void DatabaseController::addCoach(string coachid, string season, string fname, string lname, string swin, string sloss, string pwin, string ploss, string tm)
{
    Coaches *chPtr = new Coaches;

    chPtr->setCoachID(coachid);
    chPtr->setSeason(atoi(season.c_str()));
    chPtr->setFirstName(fname);
    chPtr->setLastName(lname);
    chPtr->setSeasonWin(atoi(swin.c_str()));
    chPtr->setSeasonLoss(atoi(sloss.c_str()));
    chPtr->setPlayoffWin(atoi(pwin.c_str()));
    chPtr->setPlayoffLoss(atoi(ploss.c_str()));
    chPtr->setTeam(tm);

    coachData.push_back(chPtr);

    chPtr = NULL;
}

void DatabaseController::addTeam(string teamid, string loc, string nm, char lge)
{
    Teams *tmPtr = new Teams;

    tmPtr->setTeamID(teamid);
    tmPtr->setLocation(loc);
    tmPtr->setName(nm);
    tmPtr->setLeague(lge);

    teamData.push_back(tmPtr);

    tmPtr = NULL;
}
