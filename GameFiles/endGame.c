#include <stdio.h>
#include "game.h"
#include "endGame.h"

/*
 * Functions in this module check for wins and draws
  I have implemented these functions in the same way that they will be used in Part 2 of the coursework.
 */

// Declaring these functions.
int winHorizontal(Game *game, int pos[]);
int winVertical(Game *game, int pos[]);
int winDiagL(Game *game, int pos[]);
int winDiagR(Game *game, int pos[]);

// test all possible ways the game can be won for one player
int winGame( Game *game, int pos[]) {

  if (winHorizontal(game,pos) || winVertical(game,pos) || winDiagL(game,pos) || winDiagR(game,pos)){
    return 1;
  }
  return 0;

  // return 1(true) if game is won, 0(false) otherwise

}

/*
  This function will count the number of consecutive symbols containing the one just placed.
  It then compares that to the amount needed in a line to win.
*/

int winHorizontal(Game *game, int pos[]) {
  int x = pos[0]; // Positions of where the X/O was placed.
  int y = pos[1];
  int n = 1; // Count of consecutive symbols to the left (including self)
  int m = 0; // Count of consecutive symbols to the right.
  char left; // Symbol to the left.
  char right; // Symbol to the right.
  int left_; // is 1 if the left symbol is the same.
  int right_; // is 1 if the right symbol is the same.

  // if there are any symbols to the left (not the edge of the board)
  if (y - n >= 0) { 
    left = game->board[x][y-n];
    left_ = 1;
  } else {
    left_ = 0;
  }

  // while the symbols to the left are the same, count them.
  while (left_==1){
    if (left != game->board[x][y]){
      left_ = 0;
    } else {
      n+=1;
      if (y-n >= 0) {
        left = game->board[x][y-n];
      } else {
        left_ = 0;
      }
    }
  }

  // if there are any symbols to the right (not the edge of the board)
  if (y+m+1 < game->boardSize) {
    right = game->board[x][y+m+1];
    right_ = 1;
  } else {
    right_ = 0;
  }

  // while the symbols to the right are the same, count them.
  while (right_==1) {
    if (right != game->board[x][y]){
      right_ = 0;
    } else {
      m += 1;
      if (y+m+1 < game->boardSize) {
        right = game->board[x][y+m+1];
      } else {
        right_ = 0;
      }
    }
  }
  // if the total of the same symbols in a row is the amount needed, then return 1.
  if (m+n >= game->winLength){
    return 1;
  } else {
    return 0;
  }
}

int winVertical(Game *game, int pos[]) {
  int x = pos[0]; // Positions of where the X/O was placed.
  int y = pos[1];
  int n = 1; // Count of consecutive symbols above (including self)
  int m = 0; // Count of consecutive symbols below.
  char up; // Symbol above.
  char down; // Symbol to the down.
  int up_; // is 1 if the above symbol is the same.
  int down_; // is 1 if the down symbol is the same.

  // if there are any symbols above (not the edge of the board)
  if (x - n >= 0) { 
    up = game->board[x-n][y];
    up_ = 1;
  } else {
    up_ = 0;
  }

  // while the symbols above are the same, count them.
  while (up_==1){
    if (up != game->board[x][y]){
      up_ = 0;
    } else {
      n+=1;
      if (x-n >= 0) {
        up = game->board[x-n][y];
      } else {
        up_ = 0;
      }
    }
  }

  // if there are any symbols down (not the edge of the board)
  if (x+m+1 < game->boardSize) {
    down = game->board[x+m+1][y];
    down_ = 1;
  } else {
    down_ = 0;
  }

  // while the symbols down are the same, count them.
  while (down_==1) {
    if (down != game->board[x][y]){
      down_ = 0;
    } else {
      m += 1;
      if (x+m+1 < game->boardSize) {
        down = game->board[x+m+1][y];
      } else {
        down_ = 0;
      }
    }
  }
  // if the total of the same symbols in a row is the amount needed, then return 1.
  if (m+n >= game->winLength){
    return 1;
  } else {
    return 0;
  }
}

// This counts the number of consecutive symbols from bottom right to top left to see if someone has won.
int winDiagL(Game *game, int pos[]) {
  int x = pos[0]; // Positions of where the X/O was placed.
  int y = pos[1];
  int n = 1; // Count of consecutive symbols above (including self)
  int m = 0; // Count of consecutive symbols below.
  char up; // Symbol above.
  char down; // Symbol down.
  int up_; // is 1 if the above symbol is the same.
  int down_; // is 1 if the down symbol is the same.

  // if there are any symbols above (not the edge of the board)
  if (x - n >= 0 && y - n >= 0) { 
    up = game->board[x-n][y-n];
    up_ = 1;
  } else {
    up_ = 0;
  }

  // while the symbols above are the same, count them.
  while (up_==1){
    if (up != game->board[x][y]){
      up_ = 0;
    } else {
      n+=1;
      if (x-n >= 0 && y-n >= 0) {
        up = game->board[x-n][y-n];
      } else {
        up_ = 0;
      }
    }
  }

  // if there are any symbols down (not the edge of the board)
  if (x+m+1 < game->boardSize && y+m+1 < game->boardSize) {
    down = game->board[x+m+1][y+m+1];
    down_ = 1;
  } else {
    down_ = 0;
  }

  // while the symbols down are the same, count them.
  while (down_==1) {
    if (down != game->board[x][y]){
      down_ = 0;
    } else {
      m += 1;
      if (x+m+1 < game->boardSize && y+m+1 < game->boardSize) {
        down = game->board[x+m+1][y+m+1];
      } else {
        down_ = 0;
      }
    }
  }
  // if the total of the same symbols in a row is the amount needed, then return 1.
  if (m+n >= game->winLength){
    return 1;
  } else {
    return 0;
  }
}

// This counts the number of consecutive symbols from bottom left to top right to see if someone has won.
int winDiagR(Game *game, int pos[]) {
  int x = pos[0]; // Positions of where the X/O was placed.
  int y = pos[1];
  int n = 1; // Count of consecutive symbols above (including self)
  int m = 0; // Count of consecutive symbols below.
  char up; // Symbol above.
  char down; // Symbol down.
  int up_; // is 1 if the above symbol is the same.
  int down_; // is 1 if the down symbol is the same.

  // if there are any symbols above (not the edge of the board)
  if (x - n >= 0 && y + n < game->boardSize) { 
    up = game->board[x-n][y+n];
    up_ = 1;
  } else {
    up_ = 0;
  }

  // while the symbols above are the same, count them.
  while (up_==1){
    if (up != game->board[x][y]){
      up_ = 0;
    } else {
      n+=1;
      if (x-n >= 0 && y + n < game->boardSize) {
        up = game->board[x-n][y+n];
      } else {
        up_ = 0;
      }
    }
  }

  // if there are any symbols down (not the edge of the board)
  if (x+m+1 < game->boardSize && y-m-1 >= 0) {
    down = game->board[x+m+1][y-m-1];
    down_ = 1;
  } else {
    down_ = 0;
  }

  // while the symbols down are the same, count them.
  while (down_==1) {
    if (down != game->board[x][y]){
      down_ = 0;
    } else {
      m += 1;
      if (x+m+1 < game->boardSize && y-m-1 >= 0) {
        down = game->board[x+m+1][y-m-1];
      } else {
        down_ = 0;
      }
    }
  }
  // if the total of the same symbols in a row is the amount needed, then return 1.
  if (m+n >= game->winLength){
    return 1;
  } else {
    return 0;
  }
}



// test for a draw
int drawGame( Game *game ) {

  if (game->turns >= game->maxTurns){
    return 1;
  }
  // return 1(true) if game is drawn, 0(false) otherwise
  return 0; // continue
}

