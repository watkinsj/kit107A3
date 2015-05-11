/*
*	GameState
*	Author: J.R.Dermoudy
*	Version: May 2015
*
*	This file holds the specification of the GameState.
*
*	This file is complete.
*/
#include <stdbool.h>

struct gameState_int;
typedef struct gameState_int *gameState;

void init_gameState(gameState *sp,int r,int c);
void setRow(gameState s,int r);
void setColumn(gameState s,int c);
int getRow(gameState s);
int getColumn(gameState s);
bool valid(gameState s, int r, int c);
bool taken(gameState s, int r, int c);
gameState derive(gameState s, int r, int c, int m);
void showGameState(gameState s);
