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

    cout << "Coach parsing complete!" << endl;
    return true;
}

bool DatabaseController::parseTeamFile(ifstream &teamFile)
{
    string token;
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
        for(int i = 0; i < 3; i++){
            token = test.substr(0,test.find(comma));
            test.erase(0, test.find(comma) + comma.length());

            if(i == 0)
                tmPtr->setTeamID(token);
            else if(i == 1)
                tmPtr->setLocation(token);
            else if(i == 2)
                tmPtr->setName(token);
            else if(i == 3)
                tmPtr->setLeague(*((char*)(token.c_str())));
            }
    }
        teamData.push_back(tmPtr);
        tmPtr = NULL;

    cout << "Team parsing complete!" << endl;
    return true;
}
