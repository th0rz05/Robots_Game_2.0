// T01_G12

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
public:
   Player();
   Player(int row, int col, char symbol);
   int getRow() const;
   int getCol() const;
   char getSymbol() const;
   bool isAlive() const;
   void setAsDead();
   void setPos(int row, int col);
   bool move(char movement);
   bool drawPlayer(int row, int col) const;

private:
   int row, col;
   bool alive;
   char symbol;
};

#endif