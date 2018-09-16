/*****************************************
** File:    User.cpp
** Project: CMSC 202 Project 4 - Battleship, Fall 2017
** Author:  Jeremy Dixon
** User:    Innocent Kironji
** Date:    11/16/17
** Section: 0107
** E-mail:  wambugu1@umbc.edu
**
**   This file contains the implementation of the User class 
**	 this class is a child of Player and  outlines what
**   a human user can do in the game of battleship.
**
***********************************************/
#include "User.h"

const int MAX_CELL = 9;
const int MIN_CELL = 0;
 
// User (Default Constructor)
User::User(){

  m_grid = new Grid();
}

// User (Overloaded Constructor)
User::User(string file){

  m_grid = new Grid(file);
}

// makeMove(grid)
// Checks if move (x,y) hits or misses (or if already checked)
void User::makeMove(Grid* grid){

  int x, y = 0;

  // Asking user for position to attack
  cout << "Enter square to attack (number): " << endl;

  // Verifies user inputs valid x
  do{
    cout << "Enter x (column): ";
    cin >> x;
  } while( (x > MAX_CELL) || (x < MIN_CELL) );

  // Verifies user inputs valid y
  do{
  cout << "Enter y (row): ";
  cin >> y;
  } while( (y > MAX_CELL) || (y < MIN_CELL) );

  // Attack results
  cout << "You ";

  //Updates the grid of the attacked computer
  grid->attack(x,y);

  cout << endl;
  return;
}

// printBoard
// Displays the users grid
void User::printBoard(){

  cout << "********* USER *********" << endl;
  Player::printBoard();
  cout << endl << endl;
  return;
}
