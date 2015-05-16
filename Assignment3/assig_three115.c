/*
	*	Harness File
	*	Author: J.R.Dermoudy
	*	Version: May 2015
	*	
	*	This file drives the solution.  
	*
	*	The file is complete but you will need to toggle between DF
	*		and BF solutions in main().
*/

#include <stdbool.h>
#include "assig_three115.h"
#include "gameTree.h"
#include "gameState.h"
#include "stack.h"
#include <stdio.h>


/*
	*	trace
	*	Provide trace output.
	*	Pre-condition: none
	*	Post-condition: if trace output is desired then the given String
	*					parameter is shown on the console
	*	Informally: show the given message for tracing purposes
	*
	*	param s the String to be displayed as the trace message
*/
void trace(char *s)
{
	if (TRACING)
	{
		printf("%s\n",s);
	}
}


/*
*	intro
*	Provide introductory output.
*	Pre-condition: none
*	Post-condition: an introduction to the progrm has been displayed
*	Informally: give the user some information about the program
*/
void intro()
{
	printf("Knight's Tour\n");
	printf("=============\n");
	printf("Welcome to the Knight's Tour.  This is played on a(n) %d x %d board.  The\n",DIMENSION,DIMENSION);
	printf("knight must move %d times without landing on the same square twice.\n",TOUR_LENGTH);
	printf("\n");
}


/*
*	main
*	Program entry point.
*	Pre-condition: none
*	Post-condition: the solution to the Knight's Tour will be found
*					and displayed
*	Informally: solve the Knight's Tour
*/
int main(int argc, char *argv[])
{
	gameTree g,a;	// whole game tree and solution game tree
	gameState s;	// initial game state
	stack k,r;		// stack for intermediate DF use and for tracing solution
	queue q;		// queue for intermediate BF use

	// give introduction
	intro();

	// initialise data structures
	init_stack(&k);
	init_queue(&q);
	init_gameState(&s, 1, 1);	// start at top left-hand corner: (1,1)

	// show initial board
	printf("\nStarting board:\n");
	showGameState(s);
	printf("\n");
	
	// solve
	init_gameTree(&g, false, s, 1);
	a = buildGameDF(g, k, TOUR_LENGTH);		// Depth-first
	//a = buildGameBF(g, q, TOUR_LENGTH);	// Breadth-first

	// show results
	if (isEmptyGT(a))
	{
		printf("No solution!\n");
	}
	else
	{
		// re-trace solution from leaf to root
		init_stack(&r);
		do
		{
			push(r, a);
			a = getParent(a);
		} while (!isEmptyGT(a));

		// display move list
		while (!isEmptyS(r))
		{
			a = (gameTree)top(r);
			s = (gameState)getData(a);
			printf("Move %d: (%d,%d)\n", getLevel(a), getRow(s), getColumn(s));
			pop(r);
		}

		// display final path
		printf("\nFinal board:\n");
		showGameState(s);
	}
}
