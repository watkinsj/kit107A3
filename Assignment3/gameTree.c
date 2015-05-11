/*
 *	GameTree ADT
 *	Author: <<YOUR STUDENT IDs AND NAMES HERE>>
 *	Version: May 2015
 *	
 *	This file holds the GameTree ADT which is a
 *	general game tree.  The GameTree is built using
 *	TNode ADTs.  A GameTree variable consists of a
 *	"root" field which refers to a TNode variable
 *	which has a "data" field and "child" and
 *	"sibling" references, and a "level" value.
 *	
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
*/


#include <stdbool.h>
#include "tNode.h"
#include "gameTree.h"
#include "assig_three115.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct gameTree_int
{
	tNode root;			// the node at the top of the tree
};

/*
	*	GameTree
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: if the parameter value (e) is true then the 
	*					GameTree variable's "root" field is set to NULL
	*					otherwise the GameTree variable's "root" field
	*					refers to a new TNode variable containing the
	*					parameter value (o) of level with parameter 
	*					value (l) with a NULL child, and a NULL sibling
	*	Informally: creates either an empty tree or a leaf node as
	*				required
*/
void init_gameTree(gameTree *tp,bool e,void *o,int l)
{
	trace("GameTree: initialiser starts");
	
    //allocate memory
    *tp = (gameTree)malloc(sizeof(struct gameTree_int));
    
    //check what verson of instanciator to use
    if (e)
    {
        //top of tree
        (*tp)->root = NULL;
    }
    else
    {
        //not top of tree
        init_TNode(&((*tp)->root), o, l);
    }

	trace("GameTree: initialiser ends");
}
	
	
/*
	*	isEmptyGT
	*	Emptiness test.
	*	Pre-condition: none
	*	Post-condition: true is returned if the GameTree variable is
	*					empty, false is returned otherwise
	*	Informally: indicate if the GameTree contains no nodes
	*
	*	return boolean whether or not the game tree is empty
*/
bool isEmptyGT(gameTree t)
{
//COMPLETE ME!                                                          //not sure why this needs editing???????????

	return (t->root == NULL);
}


/**
	*	getData
	*	Get function for "root" instance variable's data value.
	*	Pre-condition: none
	*	Post-condition: the value of the GameTree variable's data
	*					field is returned
	*	Informally: return the value within the root node
	*
	*	return void * the data item of the root node
*/
void *getData(gameTree t)
{
	trace("getData: getData starts");
		
	return getTNData(t->root);

	trace("getData: getData ends");
}
	
	
/*
	*	getLevel
	*	Get function for "root" instance variable's level value.
	*	Pre-condition: none
	*	Post-condition: the value of the GameTree variable's data
	*					field's level is returned
	*	Informally: return the level value within the root node
	*
	*	return int the level number of the root node
*/
int getLevel(gameTree t)
{
	trace("getLevel: getLevel starts");
		
	return getTNLevel(t->root);

	trace("getLevel: getLevel ends");
}	
	

/*
*	getParent
*	Get function for "root" instance variable's parent value.
*	Pre-condition: none
*	Post-condition: the value of the GameTree variable's parent
*					field is returned in a newly constructed
*					GameTree variable
*	Informally: return the GameTree variable's parent
*
*	return GameTree the parent of the current node
*/
gameTree getParent(gameTree t)
{
	gameTree p;

	trace("getParent: getParent starts");

	if (isEmptyGT(t))
	{
		fprintf(stderr, "getParent: empty game tree");
		exit(1);
	}

	init_gameTree(&p, true, NULL, -1);
	p->root = getTNParent(t->root);

	trace("getParent: getParent ends");
	return p;
}


/*
*	getChild
*	Get function for "root" instance variable's child value.
*	Pre - condition: none
*	Post - condition : the value of the GameTree variable's child
*					field is returned in a newly
*					constructed GameTree variable
*	Informally : return the GameTree variable's child
*
*	return GameTree the eldest child of the current node
*/
gameTree getChild(gameTree t)
{
	gameTree c;

	trace("getChild: getChild starts");

	if (isEmptyGT(t))
	{
		fprintf(stderr, "getChild: empty game tree");
		exit(1);
	}

	init_gameTree(&c, true, NULL, -1);
	c->root = getTNChild(t->root);

	trace("getChild: getChild ends");
	
	return c;
}


/*
	* 	getSibling
	*	Get function for "root" instance variable's sibling value.
	*	Pre-condition: none
	*	Post-condition: the value of the GameTree variable's sibling
	*					field is returned in a newly constructed 
	*					GameTree variable
	*	Informally: return the GameTree variable's sibling
	*
	*	return GameTree the next sibling of the current node
*/
gameTree getSibling(gameTree t) 
{
	gameTree s;
		
	trace("getSibling: getSibling starts");
		
	if (isEmptyGT(t))
	{
		fprintf(stderr, "getSibling: empty game tree");
		exit(1);
	}

	init_gameTree(&s, true, NULL, -1);
	s->root = getTNSibling(t->root);

	trace("getSibling: getSibling ends");

	return s;
}


/*
	*	setData
	*	Set function for "root" instance variable's data field.
	*	Pre-condition: none
	*	Post-condition: the TNode variable's data field is altered to
	*					hold the given (o) value
	*	Informally: store the given value in the root node of the
	*				GameTree variable
	*
	*	param o void * to install as data for root node
*/
void setData(gameTree t,void *o)
{
	trace("setData: setData starts");
		
	setTNData(t->root, o);

	trace("setData: setData ends");
}
		
	
/*
	*	setLevel
	*	Set function for "root" instance variable's level field.
	*	Pre-condition: none
	*	Post-condition: the TNode variable's level field is altered
	*					to hold the given (l) value
	*	Informally: assign the given value as the level of the
	*				GameTree variable
	*
	*	param l level number for root of current game tree
*/
void setLevel(gameTree t,int l)
{
	trace("setLevel: setLevel starts");
		
	setTNLevel((tNode)(t->root), l);

	trace("setLevel: setLevel ends");
}
	
	
/*
	*	setParent
	*	Set function for "root" instance variable's parent field.
	*	Pre-condition: none
	*	Post-condition: the TNode variable's parent field is altered
	*					to hold the given (p) value
	*	Informally: assign the given value as the parent of the
	*				GameTree variable
	*
	*	param p GameTree to be set as parent of current game tree
*/
void setParent(gameTree t, gameTree p)
{
	trace("setParent: setParent starts");

	setTNParent((tNode)(t->root), (tNode)(p->root));

	trace("setParent: setParent ends");
}


/*
	*	setChild
	*	Set function for "root" instance variable's child field.
	*	Pre-condition: none
	*	Post-condition: the TNode variable's child field is altered
	*					to hold the given (c) value
	*	Informally: assign the given value as the child of the
	*				GameTree variable
	*
	*	param c GameTree to be set as eldest child of current game tree
*/
void setChild(gameTree t, gameTree c)
{
	trace("setChild: setChild starts");

	setTNChild((tNode)(t->root), (tNode)(c->root));

	trace("setChild: setChild ends");
}


/*
	*	setSibling
	*	Set function for "root" instance variable's sibling field.
	*	Pre-condition: none
	*	Post-condition: the TNode variable's sibling field is altered
	*					to hold the given (s) value
	*	Informally: assign the given value as the sibling of the
	*				GameTree variable
	*
	*	param s GameTree to be set as next sibling of current game tree
*/
void setSibling(gameTree t,gameTree s)
{
	trace("setSibling: setSibling starts");
		
	setTNSibling((tNode)(t->root), (tNode)(s->root));

	trace("setSibling: setSibling ends");
}
	
	
/*
	*	generateLevelDF
	*	Generate the next level of the tree
	*	Pre-condition: the given tree is defined, the given stack
	*				   is defined, and the given players represent
	*				   the current and opposing players
	*	Post-condition: an additional level of possible moves has
	*					been added to the given game tree and each
	*					tree node of the new level also has been
	*					pushed onto the stack.
	*	Informally: generate the next level of the game tree
	*
	*	param k Stack of reachable but unexpanded game trees
*/
void generateLevelDF(gameTree t, stack k)
{
	const int HORIZ_MOVES[] = { -2, -1, +1, +2, +2, +1, -1, -2 };	// moves left/right
	const int VERT_MOVES[] =  { -1, -2, -2, -1, +1, +2, +2, +1 };	// moves up/down
	const int MOVE_COUNT = 8;										// number of potential moves

	int cur_r, cur_c;	//current row and current column
	int new_r, new_c;	//updated to new row and column possiblitites
	int test_move;

	trace("generateLevelDF: generateLevelDF starts");

	gameTree *current_gameTree;
	gameTree previous_gameTree;
	gameState parent_gameState, current_gameState;
	bool no_siblings = true;

	//parent_tNode = (tNode)getData(t);
	parent_gameState = (gameState)(getData(t));

	//update current row & col.
	cur_r = getRow(parent_gameState);
	cur_c = getColumn(parent_gameState);

	trace("generateLevelDF:showing parent_gameState:");
	//showGameState(parent_gameState);

	//generate possible moves
	for (test_move = 0; test_move < MOVE_COUNT; test_move++)
	{
		//update new location
		new_r = cur_r + VERT_MOVES[test_move];
		new_c = cur_c + HORIZ_MOVES[test_move];

		//test to see if new location is legal & valid

		if (valid(parent_gameState, new_r, new_c))
		{
			//play is on the board
			trace("gernateLevelDF: new location on board");
			if (!taken(parent_gameState, new_r, new_c))
			{
				//dirive the new game state
				current_gameState = derive(parent_gameState, new_r, new_c, getLevel(t)+1);
				
				//current_tNode = malloc(sizeof(tNode));
				//init_TNode(current_tNode, current_gameState, getLevel(t) + 1);

				//create a game tree containing the new gamestate
				current_gameTree = malloc(sizeof(gameTree));	//creates new space for pointer
				init_gameTree(current_gameTree, false, current_gameState, getLevel(t) + 1);

				//set parents siblings etc
				setParent(*current_gameTree,t);
				
				if (no_siblings)
				{
					//setTNChild(parent_tNode, *current_tNode);
					setChild(t, current_gameTree);
					no_siblings = false;
				}
				else
				{
					setSibling(previous_gameTree, current_gameTree);
				}

				//add game tree to stack
				push(k, *current_gameTree);
				previous_gameTree = *current_gameTree;
				trace("generateLevelDF:showing new_gameState:");
				//showGameState(current_gameState);
			}
		}
	}

	trace("generateLevelDF: generateLevelDF ends");
}


/*
	*	buildGameDF
	*	Generate the game tree in a depth-first manner
	*	Pre-condition: the given stack and game tree are defined, and
	*				   the given int value represents the desired depth
	*				   of the tree
	*	Post-condition: If the given tree isn't already deep enough, an
	*					additional level of possible moves is added to
	*					the given game tree and each tree node of the
	*					new level also is pushed onto the stack.
	*					Finally, the next tree is determined by removing
	*					the top of the stack and the process continues
	*					until the stack is empty
	*	Informally: generate the game tree from the current point
	*				in a depth-first manner until it is "d" levels
	*				deep
	*
	*	param k Stack of reachable but unexpanded game trees
	*	param d desired depth (length of tour) that game tree should be built to
	*	return	the game tree with the first found solution, or an empty game
	*			tree if there is no solution
*/
gameTree buildGameDF(gameTree t, stack k, int d)
{
	gameTree c;

	trace("buildGameDF: buildGameDF starts");

	init_gameTree(&c, true, NULL, -1);	//allocate enough memory for c to hold a game tree

	c = t;

	push(k, t);

	while ((!(isEmptyS(k))) && (getLevel(c)<TOUR_LENGTH))
	{
		pop(k);
		generateLevelDF(c, k);
		if (!(isEmptyS(k)))
		{
			c = (gameTree)(top(k));
		}
	} 

	if (getLevel(c) < TOUR_LENGTH)
	{
		//no solution found
		init_gameTree(&c, true, NULL, NULL);
	}
	
	return c;

	trace("buildGameDF: buildGameDF ends");
}


/*
	*	generateLevelBF
	*	Generate the next level of the tree
	*	Pre-condition: the given tree is defined, the given queue
	*				   is defined, and the given players represent
	*				   the current and opposing players
	*	Post-condition: an additional level of possible moves has
	*					been added to the given game tree and each
	*					tree node of the new level also has been
	*					added to the queue.
	*	Informally: generate the next level of the game tree
	*
	*	param q Queue of reachable but unexpanded game trees
*/
void generateLevelBF(gameTree t, queue q)
{
	const int HORIZ_MOVES[] = { -2, -1, +1, +2, +2, +1, -1, -2 };	// moves left/right
	const int VERT_MOVES[] = { -1, -2, -2, -1, +1, +2, +2, +1 };	// moves up/down
	const int MOVE_COUNT = 8;										// number of potential moves

	trace("generateLevelBF: generateLevelBF starts");

//COMPLETE ME!

	trace("generateLevelBF: generateLevelBF ends");
}


/*
	*	buildGameBF
	*	Generate the game tree in a depth-first manner
	*	Pre-condition: the given queue and game tree are defined, and
	*				   the given int value represents the desired depth
	*				   of the tree
	*	Post-condition: If the given tree isn't already deep enough, an
	*					additional level of possible moves is added to
	*					the given game tree and each tree node of the
	*					new level also is added to the queue.
	*					Finally, the next tree is determined by removing
	*					the front of the queue and the process continues
	*					until the queue is empty
	*	Informally: generate the game tree from the current point
	*				in a breadth-first manner until it is "d" levels
	*				deep
	*
	*	param q Queue of reachable but unexpanded game trees
	*	param d desired depth (length of tour) that game tree should be built to
	*	return	the game tree with the first found solution, or an empty game
	*			tree if there is no solution
*/
gameTree buildGameBF(gameTree t, queue q, int d)
{
	gameTree c;

	trace("buildGameBF: buildGameBF starts");

//COMPLETE ME!
		
	trace("buildGameBF: buildGameBF ends");
}


/*
	*	toStringGT
	*	String conversion for tree
	*	Pre-condition: none
	*	Post-condition: a string variable is returned consisting of the
	*				string representation of all items in the GameTree,
	*				from top to bottom in depth-first order, separated by
	*				" " and contained within "<" and ">"
	*	Informally: produce a string representation of the game tree
	*
	*	return (char *) printable contents of game tree
*/
char *toStringGT(gameTree t)
{
	gameTree c;
	char *s;

	trace("toStringGT: toStringGT starts");
		
	if (isEmptyGT(t))
	{
		trace("toStringGT: toStringGT ends");
		return "<>";
	}
	else
	{
		s=(char *)malloc(200*5*sizeof(char));

		sprintf(s,"%s (%d,%d) ",s,getRow(getData(t)),getColumn(getData(t)));
		c=getChild(t);
		if (! isEmptyGT(c))
		{
			sprintf(s,"%s %s ",s,toStringGT(c));
		}
		c=getSibling(t);
		if (! isEmptyGT(c))
		{
			sprintf(s,"%s %s ",s,toStringGT(c));
		}
	}

	trace("toStringGT: toStringGT ends");

	return s;
}

