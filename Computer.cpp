/*****************************************
** File:    Computer.cpp
** Project: CMSC 202 Project 4 - Battleship, Fall 2017
** Author:  Jeremy Dixon
** User:    Innocent Kironji
** Date:    11/16/17
** Section: 0107
** E-mail:  wambugu1@umbc.edu
**
**   This file contains the implementation of the Computer class 
**	 this class is a child of Player and  outlines what
**   a CPU or AI player can do in the game of battleship.
**
***********************************************/
#include "Computer.h"
#include <ctime>

const int GRID_SIZE = 10;
const bool HIDDEN = true;
const int MISS = 2;
const int HIT = 3;
const int TRIED = 4;
const int MAX_GUESS = 5;
const int MIN_GUESS = 1;
const int GRID_EDGE = 0;

// Used for initilizing Computer member variables that hold last move
const int NO_MOVE = 10;
const int NO_HITS = 10;
 
// Computer (Default Constructor)
// Creates computer player
Computer::Computer(){

  m_grid = new Grid();
  m_xLast = NO_MOVE;
  m_yLast = NO_MOVE;
  m_xCenter = NO_HITS;
  m_yCenter = NO_HITS;
}

// Computer (Overloaded Constructor)
// Creates computer player with file name
Computer::Computer(string file){

  m_grid = new Grid(file);
  m_xLast = NO_MOVE;
  m_yLast = NO_MOVE;
  m_xCenter = NO_HITS;
  m_yCenter = NO_HITS;
}

// makeMove()
// Makes an educated guess for next place to fire for computer
// **This function should be more thoughtful than just two random numbers**
void Computer::makeMove(Grid* grid){

  // To output attack results
  cout << "Computer ";
  int x = NO_MOVE;
  int y = NO_MOVE;

  // When the computer hasn't hit any ships
  if(m_xCenter == NO_HITS){

    // Validates that computer doesn't attack an already attack position
    do {
      srand( time(NULL) + rand() );
      x = rand() % GRID_SIZE;
      y = rand() % GRID_SIZE;

      // Validates computer doesn't go beyond edge of grid
      if (x < GRID_EDGE)
	x = -x;
      if (y < GRID_EDGE)
	y = -y;

    } while( grid->alreadyTried(x,y) );

   // Computer's attack hits
    if(grid->attack(x,y) == HIT){
      m_xCenter = x;
      m_yCenter = y;
    }
    
    // Computer's attack misses 
    else{
      m_xLast = x;
      m_yLast = y;
    }
  }

  // When the computer has previously hit a ship 
  else {
    srand( time(NULL) + rand() );

    // Attacks squares in proximity of hit
    x = (m_xLast + rand() % (MIN_GUESS + MIN_GUESS) - MIN_GUESS) % GRID_SIZE;
    y = (m_yLast + rand() % (MIN_GUESS + MIN_GUESS) - MIN_GUESS) % GRID_SIZE;
    
    // Validates for positive x & y
    if (x < GRID_EDGE)
      x = -x;
    if (y < GRID_EDGE)
      y = -y;

    int attackResult = grid->attack(x,y);
    
    // Attack misses
    if(attackResult == MISS){
      m_xLast = m_xCenter;
      m_yLast = m_yCenter;
    }
    
    // When attacks a position that already tried logic returns to normal
    if (attackResult == TRIED){
      m_xCenter = NO_HITS;
      m_yCenter = NO_HITS;
    }
    
    // Attack hits
    else{
      m_xLast = x;
      m_yLast = y;
    }
  }
  cout << "At x: " << x << " y: " << y << endl;
  cout << endl;
  return;
}

// printBoard
// Prints the computer's board
void Computer::printBoard(){

  cout << "******* COMPUTER *******" << endl;
  cout << m_grid->print(HIDDEN) << endl;
  cout << endl << endl;
  return;
}
