// T01_G12

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include "Post.h"
#include <vector>

class Maze
{
public:
   Maze();
   Maze(int numRows, int numCols);
   void addPost(int row, int col, char type);
   char charPost(int row, int col) const;
   int getnumCols() const;
   int getnumRows() const;
   void setnumCols(int numCols);
   void setnumRows(int numRows);

private:
   int numRows, numCols;
   std::vector<Post> posts;
};

#endif