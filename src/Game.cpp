// T01_G12

#include "Game.h"
#include "Maze.h"
#include "Player.h"
#include "Post.h"
#include "Robot.h"

using namespace std;

/**
 * @brief Constructor for class Game that reads the maze from the file and initiates the game
 * @param file_name file with name of maze
 */
Game::Game(const std::string &file_name)
{
    char column; //stores the column being read´

    ifstream maze_file;
    maze_file.open(file_name); //opens the file

    int width, height; //maze dimensions

    maze_file >> height;

    maze_file.get(column);
    while (column < '0' || column > '9') //ignores the non-digit characters
        maze_file.get(column);
    maze_file.unget();

    maze_file >> width;

    maze.setnumRows(height); //sets the height and width of maze
    maze.setnumCols(width);

    maze_file.get(column); //reads '\n' so it can be ignored

    for (int i = 0; i < height; i++) //iterates the lines
    {
        for (int j = 0; j < width; j++) //iterates the columns
        {
            maze_file.get(column); //reads a character
            if (column == '+' || column == '*' || column == 'O')
            {
                maze.addPost(i, j, column); //creates object Post and adds it to vector posts
            }
            else if (column == 'r' || column == 'R')
            {
                robots.push_back(Robot(i, j)); // creates object Robot and adds it to vector robots
            }
            else if (column == 'H')
            {
                player.setPos(i, j); // Updates player position
            }
        }
        maze_file.get(column); //reads '\n' so it can be ignored
    }
    maze_file.close();
}

/**
 * @brief Displays on the screen the current state of the game
 */
void Game::showGameDisplay() const
{
    for (int row = 0; row < maze.getnumRows(); row++)
    {
        for (int col = 0; col < maze.getnumCols(); col++)
        {
            if (!player.drawPlayer(row, col) && !drawRobot(row, col)) //if there isn't a player or a robot
                cout << maze.charPost(row, col);                      //prints '+','*' or ' '
        }
        cout << '\n'; //design purposes
    }
}

/**
 * @brief Check if a robot is in a certain spot and draw its symbol on the screen.
 * @param row
 * @param col
 * @return boolean representing if the robot was found or not.
 */
bool Game::drawRobot(int row, int col) const
{
    for (size_t i = 0; i < robots.size(); i++)
    {
        if (robots.at(i).getCol() == col && robots.at(i).getRow() == row) //if robot is in that spot
        {
            cout << robots.at(i).getSymbol(); //prints 'r' or 'R'
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Checks if the player has won the game by getting to the exit.
 * @return boolean for representing if it has won or not.
 */
bool Game::hasWon()
{
    if (maze.charPost(player.getRow(), player.getCol()) == 'O') //if player has found the exit
        return 1;
    return 0;
}

/**
 * @brief Move all the robots closer to the player 
 */
void Game::moveRobots()
{
    for (size_t i = 0; i < robots.size(); i++)
    {
        char post;
        Robot temp = robots.at(i); //temporary robot if its need to rewind the position

        robots.at(i).move(player.getCol(), player.getRow()); // move robot

        post = maze.charPost(robots.at(i).getRow(), robots.at(i).getCol()); // store the new position characther
                                                                            // ('*','+',' ')

        if (post == '+')
        {
            robots.at(i).setAsDead(); //collide with non-eletrified post
        }
        if (post == '*')
        {
            robots.at(i) = temp;      // don't move robot
            robots.at(i).setAsDead(); //collide with eletrified post
        }
        collide(robots.at(i)); //check if has collided with another robot
    }
}

/**
 * @brief Checks if robot has collided with any other robot
 * @param robot
 */
void Game::collide(Robot &robot)
{
    for (size_t i = 0; i < robots.size(); i++)
    {
        if (robot.getCol() == robots.at(i).getCol() &&
            robot.getRow() == robots.at(i).getRow() &&
            robot.getID() != robots.at(i).getID()) //if same position and diferent robots
        {
            robot.setAsDead();
            robots.at(i).setAsDead(); //set both of them as dead
        }
    }
}

/**
 * @brief Checks if robot has collided with the player 
 * @param robot
 * @param player
 * @return boolean representing if it has or not collided
 */
bool Game::collide(Robot &robot, Player &player)
{
    return (robot.getCol() == player.getCol() && robot.getRow() == player.getRow()); //if in the same position
}

/**
 * @brief Plays the game 
 * @return boolean representing if the user won or lost
 */
bool Game::play()
{
    char move;
    string game_state;

    while (1) //while
    {
        showGameDisplay();           //display maze
        Player temp_player = player; //temporary player for using if movement is not valid
        char post;
        do
        {
            cout << "\nPerform a movement: ";
            cin >> move; //ask for a move
            cout << endl;
            cin.ignore(100000, '\n');
            if (cin.fail() && cin.eof()) //check if ctrl + z was pressed
            {
                cout << "EXIT"; //end game
                return 0;
            }
        } while (!player.move(move));
        post = maze.charPost(player.getRow(), player.getCol()); //see if new spot is a post
        if (post == '+')
        {
            player = temp_player; //don't move player
            cout << "Invalid movement!\n";
            continue; //new move
        }
        if (post == '*')
        {
            game_state = "lost";
        }

        bool valid_move = true;

        for (size_t i = 0; i < robots.size(); i++) //check if player and stuck robot collide
        {   
            if (collide(robots.at(i), player)&& !robots.at(i).isAlive()) //same position and robot dead/stuck
            {
                valid_move = false;
                break;
            }
        }
        
        if (!valid_move){
            player = temp_player; //don't move player
            cout << "Invalid movement!\n";
            continue; //next move
        }

        moveRobots(); //move all robots

        for (size_t i = 0; i < robots.size(); i++)
        { //check if player and robot collide
            if (collide(robots.at(i), player))
            {
                game_state = "lost";
            }
        }

        if (hasWon())
        {
            showGameDisplay(); //show final state of maze
            return 1;
        }

        if (game_state == "lost")
        {
            game_state = "lost";
            player.setAsDead(); //kill player
            showGameDisplay();  //show final state of maze
            return 0;
        }
    }
}