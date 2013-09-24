#include <iostream>
#include <string>
#include <database_controller.h>


using namespace std;

void displayHelp(void);

int main()
{
    string token;
    string token2;
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
        cout << "Command: ";
        getline(cin, inputStr);
        token = inputStr.substr(0,inputStr.find(space));
        inputStr.erase(0, inputStr.find(space) + space.length());
        token2 = inputStr;
        cout << endl;

        if(token.compare("help") == 0)
            displayHelp();
        else if(token.compare("add_coach") == 0)
            cout << "correct" << endl;
        else if(token.compare("add_team") == 0)
            cout << "correct" << endl;
            else if(token.compare("print_coaches") == 0)
                controller.printCoachesCommand();
            else if(token.compare("print_teams") == 0)
                controller.printTeamsCommand();
            else if(token.compare("coaches_by_name") == 0)
                cout << "correct" << endl;
            else if(token.compare("teams_by_city") == 0)
                cout << "correct" << endl;
            else if(token.compare("load_coaches") == 0){
               controller.loadFileCoaches(token2);
        }
        else if(token.compare("load_team") == 0)
            controller.loadFileTeams(token2);
            else if(token.compare("best_coach") == 0)
                cout << "correct" << endl;
            else if(token.compare("search_coaches") == 0)
                cout << "correct" << endl;
            else if(token.compare("delete_coaches") == 0)
                cout << "correct" << endl;
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
    cout << "search_coaches field=VALUE - print the name of the coach satisfying the specified conditions" << endl;
    cout << "delete_coaches field=VALUE - delete the coach satisfying the specified conditions" << endl;
    cout << "exit - quit the program" << endl;
}
