// T01_G12

#include "Game.h"
#include "Maze.h"
#include "Player.h"
#include "Post.h"
#include "Robot.h"
#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

string MENU_FILE = "menu.txt";
string RULES_FILE = "rules.txt";

int main()
{
    bool menu = true;
    bool rules = false;
    bool play = false;
    bool winners = false;
    bool resultado;
    string maze_file;

    time_t time_counter;
    bool reset_time = true;
    string finish_time;

    while (true)
    {
        if (menu)
        {
            if (!displayMenu(MENU_FILE, menu, rules, play, winners))
                return 0;
        }
        if (rules)
        {
            if (!displayRules(RULES_FILE, menu, rules))
                return 0;
        }
        if (play)
        {
            maze_file = chooseMaze();
            if (maze_file == "EXIT")
                return 0;
            else if (maze_file == "MENU")
            {
                menu = true;
                play = false;
                continue;
            }
            Game game(maze_file);
            time_t current_time = time(nullptr); //start timer
            if (reset_time)
            {
                time_counter = current_time; // resets the timer
                reset_time = false;
            }
            resultado = game.play(); //plays the game
            if (resultado)
            { //won
                finish_time = to_string(time(nullptr) - time_counter);
                cout << "You WON!!" << endl;
                cout << "It took you " << finish_time << "s." << endl;
                displayWinner(maze_file, finish_time);
                restartGame(play, menu, reset_time);
            }
            else
            { //lost
                cout << "YOU LOST!" << endl;
                restartGame(play, menu, reset_time);
            }
        }
        if (winners)
        {
            if (!displayWinners(menu, winners))
                return 0;
        }
    }

    return 0;
}