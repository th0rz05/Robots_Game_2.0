// T01_G12

#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>

class Robot
{
public:
   Robot();
   Robot(int row, int col);
   int getID() const;
   char getSymbol() const;
   int getRow() const;
   int getCol() const;
   bool isAlive() const;
   void move(int x, int y);
   void setAsDead();

private:
   static int robotCounter; //used to attribute automatically the id to the robots
   int id;
   int row, col;
   bool alive;
};

#endif
