/*
*	GameTree
*	Author: J.R.Dermoudy
*	Version: May 2015
*
*	This file holds the specification of the GameTree.
*
*	This file is complete.
*/

#include "assig_three115.h"
#include <stdbool.h>
#include "stack.h"
#include "queue.h"

struct gameTree_int;
typedef struct gameTree_int *gameTree;

void init_gameTree(gameTree *gp,bool e,void *o,int l);
bool isEmptyGT(gameTree g);
void setData(gameTree g,void *o);
void *getData(gameTree g);
void setLevel(gameTree g,int l);
int getLevel(gameTree g);
void setChild(gameTree g,gameTree c);
gameTree getChild(gameTree g);
void setSibling(gameTree g, gameTree s);
gameTree getSibling(gameTree g);
void setParent(gameTree g, gameTree p);
gameTree getParent(gameTree g);
void generateLevelDF(gameTree g, stack s);
gameTree buildGameDF(gameTree g, stack s, int d);
void generateLevelBF(gameTree g, queue q);
gameTree buildGameBF(gameTree g, queue q, int d);
char *toStringGT(gameTree g);

