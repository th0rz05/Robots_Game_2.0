// T01_G12


#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include "Robot.h"
#include "Post.h"
#include "Player.h"
#include "Maze.h"
#include <fstream>

class Game
{
public:
   Game(const std::string &file_name);
   bool play();
   bool isValid();
   int cols();

private:
   void showGameDisplay() const;
   bool drawRobot(int row, int col) const;
   void moveRobots();
   bool hasWon();
   void collide(Robot &robot);
   bool collide(Robot &robot, Player &player);

private:
   Maze maze;
   Player player;
   std::vector<Robot> robots;
};

#endif