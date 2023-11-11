#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "initGame.h"

/*
 * Intialise game data for a new game
 */

Game *initGame( int boardSize, int winLength ) {

  Game *game;

  // for incorrect boardSize or winLength you should return a NULL pointer

  if ((boardSize < 3) || (boardSize > 8)){
    printf("Incorrect parameter values for board size or win length. Exiting\n");
    return NULL;
  }

  // allocate the Game data structure

  game = malloc(sizeof(Game));

  // intialise the Game data structure values 

  game->boardSize = boardSize;
  game->winLength = winLength;
  game->maxTurns = boardSize*boardSize;
  game->turns = 0;

  // board values should be set to '.' (unused location)

  for (int i=0; i<boardSize; i++){
    for (int j=0; j<boardSize; j++){
      game->board[i][j] = '.';
    }
  }

  return game;
}


