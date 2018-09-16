/*****************************************
** File:    Grid.cpp
** Project: CMSC 202 Project 4 - Battleship, Fall 2017
** Author:  Innocent Kironji
** Date:    11/16/17
** Section: 0107
** E-mail:  wambugu1@umbc.edu 
**
**   This file contains the implementation of the Grid class
**	 this class is resposible for keeping track of all
**   spaces on the board and their current state
**
***********************************************/

#include "Grid.h"

const string HEADER = "  0 1 2 3 4 5 6 7 8 9";
const char HIDDEN_CELL = '.';
const char SHIP_INDICATOR = '#';
const char MISSED_ATTACK = 'O';
const char HIT_ATTACK = 'X';
const char INVALID_CELL = '!';
const int TRIED = 4;

// Grid() Default Constructor for grid
Grid::Grid(){

  // Iterates through the grid
  for (int y = 0; y < SIZE; y++){
    for (int x = 0; x < SIZE; x++){

      // Makes an empty grid
      m_grid[y][x] = EMPTY;
    }
  }
}

// Grid (file name) - Overloaded Constructor
// Constructor to build grid with ship locations from file
Grid::Grid(string file){

  // Initializes the grid cells
  for (int y = 0; y < SIZE; y++){
    for (int x = 0; x < SIZE; x++){

      // Spaces initialized as being empty
      m_grid[y][x] = EMPTY;
    }
  }
  // Variables for reading/interpreting the file
  int shipSize, x, y = 0;
  char orientation = ' ';
  ifstream shipInfo( file.c_str() );

  // Verifies file opened properly
  if( shipInfo.is_open() ) {

    // Iterates through text file
    while (shipInfo >> shipSize){
      
      // Reads in needed information about ship
      shipInfo >> x;
      shipInfo >> y;
      shipInfo >> orientation;

      // When the ship is alligned vertically
      if (orientation == VERTICAL){
	for (int i = y; i < shipSize + y; i++){
	    
	  // Assigns cells to represent if a ship occupies that position
	  m_grid[i][x] = OCCUPIED;
	  }
      }
      // When the ship is alligned horizontally
      else if (orientation == HORIZONTAL){
	for (int j = x; j < shipSize + x; j++){
	  
	  // Assigns cells to represent if occupied by a ship
	  m_grid[y][j] = OCCUPIED;
	}
      }
      // When not given proper information
      else
	cout << "Incorrect orientation" << endl;
    }
  }else
    cout << endl << "[!!!!!]: File was unable to open" << endl << endl;

  shipInfo.close();
}

// alreadyTried(int, int)
// Returns true if location has already been checked (returned MISS)
bool Grid::alreadyTried(int x, int y){

  // Checks if that location has been previously targeted
  if (m_grid[y][x] == MISS)
    return true;
  else if (m_grid[y][x] == HIT)
    return true;

  // Only cells that have been hit or missed have been checked
  else
    return false;
}

// isMiss(int, int)
// Returns true if a location is not occupied
bool Grid::isMiss(int x, int y){

  if (m_grid[y][x] == OCCUPIED)
    return false;

  // Checks if missed because position was already attacked before
  else if( alreadyTried(x,y) )
    return true;

  // Miss if anything but being occupied
  else
    return true;
}

// attack(int, int)
// Returns integer based on result also checks if occupied
int Grid::attack(int x, int y){

  // Checks if attack missed and updates the grid
  if( isMiss(x,y) ){

    // If position has already been attacked nothing updates    
    if( alreadyTried(x,y) ){
      cout << "this position has already been checked." << endl;
      return TRIED;
    }

    // Position misses and has not been attacked then grid updates
    else{
      m_grid[y][x] = MISS;
      cout << "Missed..." << endl;
      return MISS;
    }
  }
  // When attack hits
  else{
    m_grid[y][x] = HIT;
    cout << "HIT!" << endl;
    return HIT;
  }
}

// noOccupiedLeft()
// Returns true if no cells in grid have a value of 1 (checks win)
bool Grid::noOccupiedLeft(){

  // Iterates through columns
  for (int y = 0; y < SIZE; y++){

    // Iterates through rows
    for (int x = 0; x < SIZE; x++){
      
      // Checks for occupied cells
      if (m_grid[y][x] == OCCUPIED)
	return false;
    }
  }
  // When nothing is left occupied
  return true;
}

// print(bool)
// Prints the grid - parameter toggles if ships are hidden or not
string Grid::print(bool hideShips){

  const string SPACE = " ";
  stringstream shipGrid;

  // When you don't want to show ship locations
  if (hideShips){
    shipGrid << HEADER << endl;

    // Iterates down grid columns
    for (int y = 0; y < SIZE; y++){
      shipGrid << y << SPACE;

      // Iterates along grid rows
      for (int x = 0; x < SIZE; x++){
	
	// Verifies what should be printed based on what that cell holds
	switch(m_grid[y][x])
	  {
	  case EMPTY:
	    shipGrid << HIDDEN_CELL << SPACE;
	    break;
	  case OCCUPIED:
	    // Ships must be hidden in this case
	    shipGrid << HIDDEN_CELL << SPACE;
	    break;
	  case MISS:
	    shipGrid << MISSED_ATTACK << SPACE;
	    break;
	  case HIT:
	    shipGrid << HIT_ATTACK << SPACE;
	    break;
	  default:
	    shipGrid << INVALID_CELL << SPACE;
	  }
      }
      // Prepares for next row
      shipGrid << endl;
    }
  }
  // When ship locations are revealed
  else{
    shipGrid << HEADER << endl;

    // Iterates down the columns of the grid
    for (int y = 0; y < SIZE; y++){
      shipGrid << y << SPACE;

      // Iterates along the rows of the grid
      for (int x = 0; x < SIZE; x++){

	// Prints out characters based on what value the cell holds
	switch(m_grid[y][x])
	  {
	  case EMPTY:
	    shipGrid << HIDDEN_CELL << SPACE;
	    break;
	  case OCCUPIED:
	    shipGrid << SHIP_INDICATOR << SPACE;
	    break;
	  case MISS:
	    shipGrid << MISSED_ATTACK << SPACE;
	    break;
	  case HIT:
	    shipGrid << HIT_ATTACK << SPACE;
	    break;
	  default:
	    shipGrid << INVALID_CELL << SPACE;
	  }
      }
      //Prepares for next row
      shipGrid << endl;
    }
  }
  shipGrid << "---- Grid Printed ----";
  return shipGrid.str();
}
