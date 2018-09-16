/*****************************************
** File:    Player.cpp
** Project: CMSC 202 Project 4 - Battleship, Fall 2017
** Author:  Innocent Kironji
** Date:    11/16/17
** Section: 0107
** E-mail:  wambugu1@umbc.edu
**
**   This file contains the implementation of the Player class 
**	 this class outlines the basics of what a player in
**   a game of battleship can do.
**
***********************************************/

#include "Player.h"

const bool NOT_HIDDEN = false;
const int MAX_CELL = 9;
const int MIN_CELL = 0;

// Player (Default Constructor)
// Constructor that builds a new grid
// Implementation is not necessary because player class is abstract
Player::Player(){}

// Player (Overloaded Constructor)
// Constructor that builds a new grid based on a file
// Implementation is not necessary because player class is abstract
Player::Player(string file){}

// ~Player (Destructor)
// Deletes dynamically allocated player
// Used for deleting User and Computer objects as well
Player::~Player(){

  delete m_grid;
  m_grid = NULL;
}

// hasLost()
// Checks to see if there are any "occupied" spaces left in grid
bool Player::hasLost(){

  return m_grid->noOccupiedLeft();
}

// getGrid()
// Returns a Grid pointer
Grid* Player::getGrid(){

  return m_grid;
}

// printBoard() {virutal}
// Prints current grid with ships not hidden
void Player::printBoard(){

  cout << m_grid->print(NOT_HIDDEN) << endl;
  return;
}
