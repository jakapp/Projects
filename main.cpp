#include <iostream>
#include <string>
#include <database_controller.h>


using namespace std;

void displayHelp(void);

int main()
{
    string token;
    string token2;
    string token3;
    string token4;
    string token5;
    string token6;
    string token7;
    string token8;
    string token9;
    string token10;
    string space = " ";
    string inputStr;
    bool success;
    DatabaseController controller;

   // if(!controller.loadFile())
   //     return 0;

    cout << "The mini-DB of NBA coaches and teams" << endl;
    cout << "Please enter a command.  Enter 'help' for a list of commands." << endl;
    cout << endl;

    while(1)
    {
        cout << endl;
        cout << "Command: ";
        getline(cin, inputStr);
        token = inputStr.substr(0,inputStr.find(space));
        inputStr.erase(0, inputStr.find(space) + space.length());
        token2 = inputStr.substr(0,inputStr.find(space));
        inputStr.erase(0, inputStr.find(space) + space.length());
        token3 = inputStr.substr(0,inputStr.find(space));
        inputStr.erase(0, inputStr.find(space) + space.length());
        token4 = inputStr.substr(0,inputStr.find(space));
        inputStr.erase(0, inputStr.find(space) + space.length());
        token5 = inputStr.substr(0,inputStr.find(space));
        inputStr.erase(0, inputStr.find(space) + space.length());
        token6 = inputStr.substr(0,inputStr.find(space));
        inputStr.erase(0, inputStr.find(space) + space.length());
        token7 = inputStr.substr(0,inputStr.find(space));
        inputStr.erase(0, inputStr.find(space) + space.length());
        token8 = inputStr.substr(0,inputStr.find(space));
        inputStr.erase(0, inputStr.find(space) + space.length());
        token9 = inputStr.substr(0,inputStr.find(space));
        inputStr.erase(0, inputStr.find(space) + space.length());
        token10 = inputStr.substr(0,inputStr.find(space));
        inputStr.erase(0, inputStr.find(space) + space.length());
        cout << endl;

        if(token.compare("help") == 0)
            displayHelp();
        else if(token.compare("add_coach") == 0)
           controller.addCoach(token2, token3, token4, token5, token6, token7, token8, token9, token10);
        else if(token.compare("add_team") == 0)
            controller.addTeam(token2, token3, token4, *((char*)token5.c_str()));
        else if(token.compare("print_coaches") == 0)
            controller.printCoachesCommand();
        else if(token.compare("print_teams") == 0)
            controller.printTeamsCommand();
        else if(token.compare("coaches_by_name") == 0)
            controller.printCoachesByName(token2);
        else if(token.compare("teams_by_city") == 0)
            controller.printTeamsByCity(token2);
        else if(token.compare("load_coaches") == 0)
            controller.loadFileCoaches(token2);
        else if(token.compare("load_team") == 0)
            controller.loadFileTeams(token2);
        else if(token.compare("best_coach") == 0)
            controller.printBestCoach();
        else if(token.compare("exit") == 0){
            cout << "Leaving the database, goodbye!" << endl;
            break;
        }
        else
            cout << "Invalid Command, try again!" << endl;
    }


    return 0;
}

void displayHelp(void)
{
    cout << "add_coach ID SEASON FIRST_NAME LAST_NAME SEASON_WIN SEASON_LOSS PLAYOFF_WIN PLAYOFF_LOSS TEAM - add new coach data" << endl;
    cout << "add_team ID LOCATION NAME LEAGUE - add a new team" << endl;
    cout << "print_coaches - print a listing of all coaches" << endl;
    cout << "print_teams - print a listing of all teams" << endl;
    cout << "coaches_by_name NAME - list info of coaches with the specified name" << endl;
    cout << "teams_by_city CITY - list the teams in the specified city" << endl;
    cout << "load_coach FILENAME - bulk load of coach info from a file" << endl;
    cout << "load_team FILENAME - bulk load of team info from a file" << endl;
    cout << "best_coach SEASON - print the name of the coach with the most netwins in a specified season" << endl;
    cout << "exit - quit the program" << endl;
}
