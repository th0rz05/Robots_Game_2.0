// T01_G12

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Game.h"

/**
    Reads an integer and tests if it is valid.
    @param input Integer read passed by reference.
    @return Returns 1 if the input was valid and 0 otherwise.
*/
bool readInteger(int &input);

/**
    Reads and prints a text file.
    @param file_name The name of the file.
*/
void displayFile(std::string file_name);

/**
    Prints the menu from a file and executes the menu logic.
    @param file_name The name of the file.
    @param menu True if the menu should be displayed.
    @param rules True if the rules should be displayed.
    @param play True if the game should be displayed.
    @param winners True if the winners should be displayed.
    @return Returns 0 if the game should close 1 otherwise.
*/
bool displayMenu(std::string file_name, bool &menu, bool &rules, bool &play, bool &winners);

/**
    Prints the rules from a file and executes the rules logic.
    @param file_name The name of the file.
    @param menu True if the menu should be displayed.
    @param rules True if the rules should be displayed.
    @return Returns 0 if the game should close 1 otherwise.
*/
bool displayRules(std::string file_name, bool &menu, bool &rules);

/**
    Prints the winners from a maze chosen by input.
    @param menu True if the menu should be displayed.
    @param winners True if the winners should be displayed.
    @return Returns 0 if the game should close 1 otherwise.
*/
bool displayWinners(bool &menu, bool &winners);

/**
    Asks for a maze number until a valid one is given.
    @return Returns the chosen maze's file name.
*/
std::string chooseMaze();

/**
    Sorts all the entries on the scoreboard so it can be written.
    @param scoreboard vector<string> with all the winners
*/
void sortScoreboard(std::vector<std::string> &scoreboard);

/**
    Asks for a name and writes it on the scoreboard file.
    @param maze_file Played maze file's name.
    @param finish_time Player's score.
*/
void displayWinner(std::string maze_file, std::string finish_time);

/**
    Resets all parameters to their default value.
    @param play Stores the current display state.
    @param menu Stores the current display state.
    @param reset_time Stores the current reset time state.
*/
void restartGame(bool &play, bool &menu, bool &reset_time);

#endif