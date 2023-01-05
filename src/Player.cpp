// T01_G12

#include "Player.h"

using namespace std;

/**
 * @brief Player default constructor
 */
Player::Player()
{
    this->row = 0;
    this->col = 0;
    this->symbol = 'H';
    alive = true;
}

/**
 * @brief Player constructor that creates a player in a certain position
 * @param row
 * @param col
 * @param symbol
 */
Player::Player(int row, int col, char symbol)
{
    this->row = row;
    this->col = col;
    this->symbol = symbol;
    alive = true;
}

/**
 * @brief Checks row of player
 * @return Row where the player is
 */
int Player::getRow() const
{
    return row;
}

/**
 * @brief Checks column of player
 * @return Column where the player is
 */
int Player::getCol() const
{
    return col;
}

/**
 * @brief Checks symbol of player
 * @return Symbol of the player 
 */
char Player::getSymbol() const
{
    return symbol;
}

/**
 * @brief Checks player status 
 * @return if player is alive
 */
bool Player::isAlive() const
{
    return alive;
}

/**
 * @brief Sets the player as dead
 */
void Player::setAsDead()
{
    alive = false;
    symbol = 'h';
}

/**
 * @brief Changes player position
 * @param row
 * @param col
 */
void Player::setPos(int row, int col)
{
    this->row = row;
    this->col = col;
}

/**
 * @brief Moves the player
 * @param movement
 * @return if input for movement was valid
 */
bool Player::move(char movement)
{
    switch (tolower(movement)) //switch to lowercase
    {
    case 'q': //apply movement rules
        col--, row--;
        break;
    case 'w':
        row--;
        break;
    case 'e':
        col++, row--;
        break;
    case 'a':
        col--;
        break;
    case 's':
        break;
    case 'd':
        col++;
        break;
    case 'z':
        col--, row++;
        break;
    case 'x':
        row++;
        break;
    case 'c':
        col++, row++;
        break;
    default:
        cout << "Invalid movement!" << endl
             << endl;
        return 0;
    }
    return 1;
}

/**
 * @brief Draws the player on the screen
 * @param row
 * @param col
 * @return if player was found in that position
 */
bool Player::drawPlayer(int row, int col) const
{
    if (this->row == row && this->col == col) //if player in this position
    {
        cout << symbol;
        return 1;
    }
    return 0;
}