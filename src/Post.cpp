// T01_G12

#include "Post.h"

using namespace std;

/**
 * @brief Post default constructor
 */
Post::Post()
{
    this->row = 0;
    this->col = 0;
    this->type = '+';
}

/**
 * @brief Post constructor that creates a post with these attributes
 * @param row
 * @param col
 * @param type
 */
Post::Post(int row, int col, char type)
{
    this->row = row;
    this->col = col;
    this->type = type;
}

/**
 * @brief Checks post row
 * @return Row where the post is
 */
int Post::getRow() const
{
    return row;
}

/**
 * @brief Checks post column
 * @return Column where the post is
 */
int Post::getCol() const
{
    return col;
}

/**
 * @brief Checks post symbol
 * @return Symbol of the post 
 */
char Post::getSymbol() const
{
    return type;
}

/**
 * @brief Checks post eletricity
 * @return If the post is electrified
 */
bool Post::isElectrified() const
{
    if (type == '+')
    { //if non-eletrified
        return false;
    }
    else
    {
        return true;
    }
}