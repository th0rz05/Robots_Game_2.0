// T01_G12

#ifndef POST_H
#define POST_H

#include <iostream>

class Post
{
public:
   Post();
   Post(int row, int col, char type);
   int getRow() const;
   int getCol() const;
   char getSymbol() const;
   bool isElectrified() const;

private:
   int row, col;
   char type;
};

#endif