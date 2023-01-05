// T01_G12

#include "Maze.h"
#include "Post.h"

using namespace std;

/**
 * @brief Maze default constructor
 */
Maze::Maze()
{
    this->numRows = 10;
    this->numCols = 10;
}

/**
 * @brief Maze constructor that stores the size of the maze
 * @param numRows
 * @param numCols
 */
Maze::Maze(int numRows, int numCols)
{
    this->numRows = numRows;
    this->numCols = numCols;
}

/**
 * @brief Adds an object Post with these atributes in the vector posts
 * @param row
 * @param col
 * @param type
 */
void Maze::addPost(int row, int col, char type)
{
    posts.push_back(Post(row, col, type));
}

/**
 * @brief Checks if exists a post in a certain position
 * @param row
 * @param col
 * @return Character ('+','*',' ')
 */
char Maze::charPost(int row, int col) const
{
    for (size_t i = 0; i < posts.size(); i++) //iterate through the posts
    {
        if (posts.at(i).getCol() == col && posts.at(i).getRow() == row) //if in the position
        {
            return posts.at(i).getSymbol();
        }
    }
    return ' '; //no post found
}

/**
 * @brief Checks maze columns
 * @return Checks maze columns
 */
int Maze::getnumCols() const
{
    return numCols;
}

/**
 * @brief Checks maze rows
 * @return Checks maze rows
 */
int Maze::getnumRows() const
{
    return numRows;
}

/**
 * @brief Changes number of columns of the maze
 * @param numCols
 */
void Maze::setnumCols(int numCols)
{
    this->numCols = numCols;
}

/**
 * @brief Changes number of rows of the maze
 * @param numRows
 */
void Maze::setnumRows(int numRows)
{
    this->numRows = numRows;
}
