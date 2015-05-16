/*
*	GameState ADT Implementation
*	Author: <<YOUR STUDENT IDs AND NAMES HERE>>
*	Version: May 2015
*
*	This file holds the GameState ADT.  It comprises
*	the coordinate of the knight's current position
*	(as "row" and "column"), and the board (as a
*	two-dimensional array called "board").
*
*	YOU NEED TO MAKE CHANGES TO THIS FILE!
*/

//include statements
#include <stdbool.h>
#include "assig_three115.h"
#include <stdio.h>
#include <stdlib.h>
#include "gameState.h"

/*
 * gameState_int struct
 * internal structure for gameState.
 * data fields as per comments below
 */
struct gameState_int {
	int row;							// knight's current row position
	int column;							// knight's current column
	int board[DIMENSION][DIMENSION];	// board of move numbers as 2d matrix
};


/*
	*	GameState
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: a gameState variable is created and pointed
	*					to by the first parameter.  Its row field
	*					is set to r, its column field is set to c,
	*					and each element in the board table is set
	*					to 0, except that given by (r,c) which is
	*					set to 1
	*	Informally: creates either an empty tree or a leaf node as
	*				required
	*
	*	Param r int intended row number for knight
	*	Param c int intended column number for knight
*/
void init_gameState(gameState *sp, int r, int c)
{
	const int SPACE_EMPTY = 0;	//represents a location on board[][] that has not been visited
	const int START_OF_ARRAY = 0;	//represents the lowest possible location in an array

	int x, y;   //used in for loop to traverse across board

	trace("init_gameState: init_gameState starts");	//for debug purposes only. function in assig_three115.c
    
	//allocate memory
    *sp = (gameState)malloc(sizeof(struct gameState_int));
    
    //loops through x & y setting entire board matrix to empty
    for (x = START_OF_ARRAY; x<DIMENSION; x++)
    {
        for (y= START_OF_ARRAY; y<DIMENSION; y++)
        {
            (*sp)->board[x][y] = SPACE_EMPTY;
        }
    }
    
    //update location of knight
    (*sp)->board[r-1][c-1] = 1;
    
    //update row and column datafields to represent those passed in.
    (*sp)->row = r;
    (*sp)->column = c;

	trace("init_gameState: init_gameState ends");	//for debug purposes only. function in assig_three115.c
}


/*
	* 	getRow
	*	Get function for row field.
	*	Pre-condition: none
	*	Post-condition: the value of the GameState variable's row
	*					field is returned
	*	Informally: return the GameState variable's row
	*
	*	return int the current row number of the knight
*/
int getRow(gameState s)
{
	trace("getRow: getRow starts and finishes");	//for debug purposes only. function in assig_three115.c

	//fetch and return row data field
    return (s->row);
}


/*
	* 	getColumn
	*	Get function for column field.
	*	Pre-condition: none
	*	Post-condition: the value of the GameState variable's column
	*					field is returned
	*	Informally: return the GameState variable's column
	*
	*	return int the current column number of the knight
*/
int getColumn(gameState s)
{
	trace("getColumn: getColumn starts and finishes");	//for debug purposes only. function in assig_three115.c

	//fetch and return column data field
    return (s->column);
}


/*
	* 	setRow
	*	Set function for row field.
	*	Pre-condition: the given gameState is defined and the given row
	*					is within the bounds of that gameState variable's
	*					board
	*	Post-condition: the value of the GameState variable's row
	*					field is updated to the given int value
	*	Informally: update the GameState variable's row
	*
	* Param r int value to be placed into the gameState's row field
*/
void setRow(gameState s, int r)
{
	trace("setRow: setRow starts");	//for debug purposes only. function in assig_three115.c

	//update row data field
	s->row = r;

	trace("setRow: setRow ends");	//for debug purposes only. function in assig_three115.c
}


/*
	* 	setColumn
	*	Set function for column field.
	*	Pre-condition: the given gameState is defined and the given column
	*					is within the bounds of that gameState variable's
	*					board
	*	Post-condition: the value of the GameState variable's column
	*					field is updated to the given int value
	*	Informally: update the GameState variable's column
	*
	*	Param c int value to be placed into the gameState's column field
*/
void setColumn(gameState s, int c)
{
	trace("setColumn: setColumn starts");	//for debug purposes only. function in assig_three115.c

	//update column data field
	s->column = c;

	trace("setColumn: setColumn ends");	//for debug purposes only. function in assig_three115.c
}


/*
	* 	valid
	*	Check whether a square is on the board
	*	Pre-condition: the given gameState is defined 
	*	Post-condition: true is returned if (r,c) is within the bounds
	*					of the given gameState variable's board field,
	*					and false is returned otherwise
	*	Informally: Return whether or not a square is on the board
	*
	*	Param r int row value to check
	*	Param c int column value to check
*/
bool valid(gameState s, int r, int c)
{
	trace("valid: valid starts and finishes");		//for debug purposes only. function in assig_three115.c
	
	const int ZERO = 0;	//must use a number that is within bounds of array to get size (zero always works)
						//0 is also lower than all row and column values (i.e 1,1 is top left corner)

	int x, y;	//will contain the width and hight of array respectivly

	//set x and y to the dimentions of the array board (= size of board).
		//takes into consideration that board may not be square
	x = sizeof(s->board) / sizeof(s->board[ZERO]);
	y = sizeof(s->board[ZERO]) / sizeof(s->board[ZERO][ZERO]);

	//compare r,c to board dimentions (taking into consideration that r,c could be 0 or below)
	if ((r <= y) && (r>ZERO) && (c <= x) && (c>ZERO))
	{
		//c,r is on the board
		return true;
	}
	else
	{
		//off the board
		return false;
	}
}


/*
	* 	taken
	*	Check whether a square on the board has already been visited
	*	Pre-condition: the given gameState is defined and (r,c) is
	*					within the bounds of the given gameState
	*					variable's board field
	*	Post-condition: true is returned if (r,c) has been visited (i.e.
	*					is non-zero, and false is returned otherwise
	*	Informally: Return whether or not a square has been taken
	*
	*	Param r int row value to check
	*	Param c int column value to check
*/
bool taken(gameState s, int r, int c)
{
	const int SPACE_EMPTY = 0;	//represents a location on board[][] that has not been visited
	const int DIFFERENCE_ARRAY_VS_RC = 1;	//difference between row & column values vs positions in board array 

	trace("taken: taken starts and finishes");	//for debug purposes only. function in assig_three115.c

	//fetch location on board and reurn true if space is not empty
	return (s->board[r-DIFFERENCE_ARRAY_VS_RC][c-DIFFERENCE_ARRAY_VS_RC]!= SPACE_EMPTY);
}


/*
	* 	derive
	*	Create a new board based on an old one
	*	Pre-condition: the given gameState is defined and (r,c) is
	*					within the bounds of the given gameState
	*					variable's board field
	*	Post-condition: a copy of the given gameState variable is
	*					returned which has been updated by placing
	*					move number m at (r,c) and r as its row
	*					and c as its column
	*	Informally: Copy an existing gameState and update the knight
	*				position
	*
	*	Param r int row value for the new move
	*	Param c int column value for the new move
	*	Param m int the move number for the new move
*/
gameState derive(gameState s, int r, int c, int m)
{
	const int SPACE_EMPTY = 0;	//represents a location on board[][] that has not been visited
	const int DIFFERENCE_ARRAY_VS_RC = 1;	//difference between row & column values vs positions in board array 
	const int START_OF_ARRAY = 0;	//represents the lowest possible location in an array

	gameState n;	//new game state to be updates and then returned
	int x, y;	//used in for loop to traverse across board

	trace("derive: derive starts");	//for debug purposes only. function in assig_three115.c

	// instanciate a new gameState state given inputs
	init_gameState(&n, r, c);

	// add the new move
	n->board[r-DIFFERENCE_ARRAY_VS_RC][c-DIFFERENCE_ARRAY_VS_RC] = m;

	// duplicate the existing moves
	for (x = START_OF_ARRAY; x < DIMENSION; x++)
	{
		for (y = START_OF_ARRAY; y < DIMENSION; y++)
		{
			//determine if the space has been played on previously
			if (s->board[x][y] != SPACE_EMPTY)
			{
				//update the current location on board to previous move location
				n->board[x][y] = s->board[x][y];
			}
		}
	}

	trace("derive: derive ends");	//for debug purposes only. function in assig_three115.c

	//return new board
	return n;
}


/*
	* 	showGameState
	*	Display a game state
	*	Pre-condition: the given gameState is defined
	*	Post-condition: the given gameState has been displayed on
	*					the standard output stream
	*	Informally: Print the board
*/
void showGameState(gameState s)
{
	//given in solution so not updated

	int x, y;

	trace("showGameState: showGameState starts");

	// for all rows
	for (x = 1; x <= DIMENSION; x++)
	{
		// print row separator
		printf("+");
		for (y = 1; y <= DIMENSION * 3 - 1; y++)
		{
			printf("-");
		}
		printf("+\n");

		// print all columns
		printf("|");
		for (y = 1; y <= DIMENSION; y++)
		{
			if (taken(s,x,y))	// knight is/has been there
			{
				if ((x == getRow(s))  && (y == getColumn(s)))	// knight is there
				{
					printf(" K|");
				}
				else	// knight was there
				{
					printf("%2d|", s->board[x-1][y-1]);
				}
			}
			else	// empty
			{
				printf("  |");
			}
		}
		printf("\n");
	}
	
	// print row separator
	printf("+");
	for (y = 1; y <= DIMENSION * 3 - 1; y++)
	{
		printf("-");
	}
	printf("+\n");

	trace("showGameState: showGameState ends");
}