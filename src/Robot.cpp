// T01_G12

#include "Robot.h"

using namespace std;

int Robot::robotCounter = 0; // initialize variable

/**
 * @brief Robot default constructor
 */
Robot::Robot()
{
}

/**
 * @brief Robot constructor in this position
 * @param row
 * @param col
 */
Robot::Robot(int row, int col)
{
    this->row = row;
    this->col = col;
    this->id = robotCounter; //use static variable for attributing id
    robotCounter++;          //update
    this->alive = true;
}

/**
 * @brief Checks robot id
 * @return Id of the robot
 */
int Robot::getID() const
{
    return id;
}

/**
 * @brief Checks robot row
 * @return Row where the robot is
 */
int Robot::getRow() const
{
    return row;
}

/**
 * @brief Checks robot column
 * @return Column where the robot is
 */
int Robot::getCol() const
{
    return col;
}

/**
 * @brief Checks robot symbol
 * @return Symbol of the robot
 */
char Robot::getSymbol() const
{
    if (alive)
    {
        return 'R';
    }
    else
    {
        return 'r'; //if it's dead
    }
}

/**
 * @brief Checks robot attributes
 * @return if robot is alive
 */
bool Robot::isAlive() const
{
    return alive;
}

/**
 * @brief Moves the robot closer to the players position
 * @param x of player
 * @param y of player
 */
void Robot::move(int x, int y)
{
    if (alive) //move only if alive
    {
        if (col < x)
        {
            col++;
        }
        else if (col > x)
        {
            col--;
        }
        if (row < y)
        {
            row++;
        }
        else if (row > y)
        {
            row--;
        }
    }
}

/**
 * @brief Sets robot as dead
 */
void Robot::setAsDead()
{
    alive = false;
}
