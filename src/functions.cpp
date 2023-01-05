// T01_G12

#include "functions.h"

using namespace std;

bool readInteger(int &input)
{
    while (1)
    {
        cin >> input;

        if (cin.fail()) // if fail
        {
            if (cin.eof()) // if ctrl-Z is pressed
            {
                cout << "EXIT";
                return 0; //exit
            }
            else // not integer
            {
                cin.clear();
                cin.ignore(100000, '\n');
                cout << "Invalid Input! Try again!\n\n";
            }
        }
        else
            return 1; //input successful
    }
}

void displayFile(string file_name)
{
    ifstream file(file_name); 
    cout << endl;
    cout << file.rdbuf(); //reads and displays the file
}

bool displayMenu(string file_name, bool &menu, bool &rules, bool &play, bool &winners)
{
    int menu_option;
    displayFile(file_name); //displays the menu
    do
    {
        cout << "Option: ";
        if (!readInteger(menu_option) || menu_option == 0)
        {
            return 0;
        }
    } while (menu_option > 3 || menu_option < 0); //get a valid option
    if (menu_option == 1) //rules
    {
        menu = false;
        rules = true;
    }
    if (menu_option == 2) //play
    {
        menu = false;
        play = true;
    }
    if (menu_option == 3) //winners
    {
        menu = false;
        winners = true;
    }
    return 1;
}

bool displayRules(string file_name, bool &menu, bool &rules)
{
    int option;
    displayFile(file_name); //displays rules
    do
    {
        cout << "Option: ";
        if (!readInteger(option))
            return 0;
    } while (option != 0); //waits for a valid input
    menu = true;
    rules = false;
    return 1;
}

bool displayWinners(bool &menu, bool &winners)
{
    int option;
    string file_name;
    file_name = chooseMaze(); //gets a valid maze
    if (file_name == "EXIT")
        return 0;
    else if (file_name == "MENU") //return to menu
    {
        menu = true;
        winners = false;
        return 1;
    }
    else
        file_name.insert(7, "_WINNERS"); //create winners .txt
    cout << endl;
    displayFile(file_name); //display winners
    cout << "\n\t\t\t\t0) Menu" << endl;
    do
    {
        cout << "Option: ";
        if (!readInteger(option))
            return 0;
    } while (option != 0); //waits for a valid input
    menu = true;
    winners = false;
    return 1;
}

string chooseMaze()
{
    int maze_number;

    while (1) //main loop
    {
        cout << "\nChoose a maze (input 0 to return to main menu) :  ";

        if (!readInteger(maze_number)) //ctrl+z 
            return "EXIT";

        string file_name;
        if (maze_number == 0)
        {
            cout << endl;  //design purposes
            return "MENU"; // return to menu
        }
        else if (maze_number < 10)
        {
            file_name = "MAZE_0" + to_string(maze_number) + ".txt"; //formats the fileName string
        }
        else
        {
            file_name = "MAZE_" + to_string(maze_number) + ".txt"; //formats the fileName string
        }

        ifstream file(file_name); //tries to open an existing file
        if (file.is_open())       //checks if the file exists
            return file_name;
        else
        {
            cout << "That maze does not exist.\n";
        }
    }
}

void sortScoreboard(vector<string>& scoreboard)
{
    for (size_t i = 0; i < scoreboard.size();i++){                 // reorder the scoreboard by time      
        for (size_t j = i + 1; j < scoreboard.size();j++){
            
            string substr1,substr2;
            int time1,time2;

            time1 = stoi(scoreboard.at(i).substr(18));       // change to integer
            time2 = stoi(scoreboard.at(j).substr(18));

            if(time2 < time1){                                  // swap if time2 less than time 1
                string temp ;
                temp = scoreboard.at(i);
                scoreboard.at(i) = scoreboard.at(j);
                scoreboard.at(j) = temp;
            } 
        }
    } 
}

void displayWinner(string maze_file, string finish_time)
{
    string winner;
    do 
    {
        cout << "Insert your name (max 15 characters): ";
        getline(cin,winner);
    } while (winner.size() > 15);
    winner.insert(winner.size(), 15 - winner.size(), ' '); //fill with ' '
    cout << endl;

    maze_file.insert(7, "_WINNERS");

    ofstream writing;  
    ifstream reading;

    reading.open(maze_file);
    string line;
    vector<string> scoreboard; //list of all the previous winners
    while (getline(reading, line))
    {
        if (line != "----------------------" && line != "Player         - Time")
            scoreboard.push_back(line);
    }
    reading.close();
    scoreboard.push_back(winner + "-  " + finish_time); //add the winner to the list

    sortScoreboard(scoreboard); //sort the scoreboard

    writing.open(maze_file);
    writing << "Player         - Time\n" << "----------------------\n";
    cout << "Player         - Time\n" << "----------------------\n";
    for (size_t i = 0; i < scoreboard.size(); i++)
    {
        writing << scoreboard[i] << endl;
        cout << scoreboard[i] << endl;
    }
    cout << endl;
    writing.close();
}

void restartGame(bool &play, bool &menu, bool &reset_time)
{
    play = false;
    menu = true; //return to the menu
    reset_time = true; // resets the timer
}