/*****************************************
 ** File:    main.cpp
 ** Project: CMSC 202 Project 4 - Battleship, Fall 2017
 ** Author:  Innocent Kironji
 ** Date:    11/16/17
 ** Section: 0107
 ** E-mail:  wambugu1@umbc.edu
 **
 **  This file runs and manages the game.
 **
 ***********************************************/
#include "Grid.h"
#include "Player.h"
#include "User.h"
#include "Computer.h"
#include <vector>

const int PLAYER_1 = 0;
const int COMP = 1;

int main(int argc, char* argv[]){

  cout << "Welcome to UMBC Battleship" << endl;

  // Passes the file name in using "command line argument"
  if( (argv[1] > 0) && (argv[2] > 0) ){
    cout << "---------------------------" << endl;
    cout << "Battleship Positions Loaded" << endl;
    cout << "---------------------------" << endl;
  } else{
    cout << "-----------------------------------" << endl;
    cout << "No text files loaded - try make run1" << endl;
    cout << "-----------------------------------" << endl;
    return 0;
  }

  Player *p1 = new Computer(argv[1]);
  Player *p2 = new Computer(argv[2]);

  //
  int numTurns = 1;
  //

  // Preparing container for player
  vector <Player*> players;
  players.push_back(p1);
  players.push_back(p2);
  
  players.at(PLAYER_1)->printBoard();
  players.at(COMP)->printBoard();


  // Game runs until one of the players meets the conditions for winning
  while( !(players.at(PLAYER_1)->hasLost()) && !(players.at(COMP)->hasLost()) ){

    // Computer Attacks
    players.at(COMP)->makeMove( players.at(PLAYER_1)->getGrid() );
    players.at(PLAYER_1)->printBoard();

    // Player retaliates
    players.at(PLAYER_1)->makeMove( players.at(COMP)->getGrid() );
    players.at(COMP)->printBoard();

    //
    numTurns++;
    //  
  }
  
  // Checks who won
  if( players.at(COMP)->hasLost() )
    cout << "You Win!" << endl;
  else if( players.at(PLAYER_1)->hasLost() )
    cout << "You Lose!" << endl;

  //
  cout << "This game took " << numTurns/2 << " turns to complete" << endl;
  //

  // Cleaning up memory for dynamic objects
  players.clear();
  delete p1;
  p1 = NULL;
  delete p2;
  p2 = NULL;

  return 0;
}
