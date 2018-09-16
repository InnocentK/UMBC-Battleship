/*****************************************
** File:    Player.h
** Project: CMSC 202 Project 4 - Battleship, Fall 2017
** Author:  Jeremy Dixon
** User:    Innocent Kironji
** Date:    11/16/17
** Section: 0107
** E-mail:  wambugu1@umbc.edu
**
**   This file contains the header file of the Player class 
**	 this class outlines the basics of what a player in
**   a game of battleship can do.
**
**   This file has not been modified aside from these comments
***********************************************/

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Grid.h"
 
class Player {
 public:
  // Name: Player (Default Constructor)
  // Preconditions - None
  // Postconditions - Constructor that builds a new grid
  Player();
  // Name: Player (Overloaded Constructor)
  // Preconditions - File exists
  // Postconditions - Constructor that builds a new grid based on a file
  Player(string file);
  // Name: ~Player (Destructor)
  // Preconditions - Player was dynamically allocated
  // Postconditions - Deletes dynamically allocated player 
  ~Player();
  // Name: makeMove (purely virtual)
  // Preconditions - Grid exists
  // Postconditions - Virtual function for child classes
  virtual void makeMove(Grid* grid) = 0;
  // Name: hasLost()
  // Preconditions - Grid is populated
  // Postconditions - Checks to see if there are any "occupied" spaces left in grid
  bool hasLost();
  // Name: getGrid()
  // Preconditions - Grid exists
  // Postconditions - Returns a Grid pointer
  Grid* getGrid();
  // Name: printBoard()
  // Preconditions - Grid exists
  // Postconditions - Prints current grid with ships not hidden
  virtual void printBoard();
protected:
  Grid* m_grid;
};

#endif
