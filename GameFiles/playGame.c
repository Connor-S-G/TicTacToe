
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "playGame.h"
#include "endGame.h"

/*
 * Controls the game logic from start to end
 */

void playGame( Game *game ) {

  char symbols[2] = { 'X','O' };
  int col;
  int row;
  int gameWon = 0;
  int gameDrew = 0;

  // player 'X' plays first
  int player = 0;

  // starting board
  printf("New game starting\n");
  showGame( game );
  
  // Your game should be controlled by an outer loop
  // Each pass through the loop is one completed move by a player
  
  while (gameDrew == 0 && gameWon == 0){
   
    // Request a move from the next player and check it is valid (an unused square within the board)
    printf("Player %c: Enter your move as row column values:\n",symbols[player]); // use this to request the player move
    scanf("%d %d",&row,&col);

    // If the move is invalid you should repeat the request for the current player
    while (row<0 || row>game->boardSize-1 || col<0 || col>game->boardSize-1 || game->board[row][col]!='.'){
      printf("Move rejected. Please try again\n"); // use this message if move cannot be made. You must repeat the request for a move
      scanf("%d %d",&row,&col);
    }

    // If the move is valid update the board
    game->board[row][col]=symbols[player];
    game->turns += 1;
    
    // After each completed move display the board 
    showGame( game );

    // After each valid move you can test for win or draw using functions you implement in endGame.c
    int pos[2];
    pos[0] = row;
    pos[1] = col;

    // This has to be seperated to make sure the game cannot be a win and a draw simultaneously.
    if (winGame(game,pos)){
      gameWon = 1;
    } else if (drawGame(game)){
      gameDrew = 1;
    } else {
      player = game->turns % 2;
    }

  }

  if (gameWon){
    printf("Player %c has won\n",symbols[player]); // use to announce a winner - game is over
  } else {
    printf("Match is drawn\n"); // use to announce a draw - game is over
  }
  return;
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame( Game *game ) {

  printf("\n");
  printf("      0  1  2\n");
  printf("\n");
  printf(" 0    %c  %c  %c\n",game->board[0][0],game->board[0][1],game->board[0][2]);
  printf(" 1    %c  %c  %c\n",game->board[1][0],game->board[1][1],game->board[1][2]);
  printf(" 2    %c  %c  %c\n",game->board[2][0],game->board[2][1],game->board[2][2]);
  printf("\n");

  return;
}


int makeMove( Game *game, char symbol ){
  return 1;
}

