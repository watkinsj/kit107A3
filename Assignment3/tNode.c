/*
 *	Tree Node ADT
 *	Author: <<YOUR STUDENT IDs AND NAMES HERE>>
 *	Version: May 2015
 *	
 *	This file holds the Tree Node ADT which represents
 *	the nodes in a doubly-linked general tree.  Tree
 *	nodes consist of a "data" field, a level number
 *	("level"), and two references to other nodes
 *	(these being the child node ("child") and the
 *	eldest sibling node	("sibling").
 *	
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
 */

//include statements
#include <stdbool.h>
#include "assig_three115.h"
#include "tNode.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * tNode_int struct
 * 
 * internal structure for tNode 
 * tNode pointer points to this struct. Data types as below:
 * 
 */

struct tNode_int
{
	void *data;		// the value stored in the node
	int level;		// the level of the current node
	tNode parent;	// the parent node of the current node
	tNode child;	// the eldest child node of the current node
	tNode sibling;	// the next eldest node of the current node
};

/*
	*	TNode
	*	Initialiser function
	*	Pre-condition: none
	*	Post-condition: the TNode variable holds the parameter value
	*					(o) within its "data" field, the parameter
	*					value (l) within its "level" field, and its
	*					"child", "sibling", and "parent" fields are
	*					null
	*	Informally: intialises the fields of the newly
	*				created TNode variable to hold the given parameters
	*				and to terminate the "child", "sibling", and
	*				"parent" fields
	*
	*	param o the value to store in the data field of the node
	*	param l the level number of the created node
*/
void init_TNode(tNode *tp, void *o, int l)
{
    trace("TNode: Initialiser starts");	//for debug purposes only. function in assig_three115.c

	//allocate memory
	*tp = (tNode)malloc(sizeof(struct tNode_int));

	//store values in data fields
	(*tp)->data = o;
	(*tp)->level = l;

	//refrences to other neighbours in tree
	//set to NULL initially and then can be set to tNodes later
	(*tp)->parent = NULL;
	(*tp)->child = NULL;
	(*tp)->sibling = NULL;

    trace("TNode: Initialiser ends"); //for debug purposes only. function in assig_three115.c
}


/*
	*	setTNData
	*	Set function for "data" field.
	*	Pre-condition: none
	*	Post-condition: the TNode varable's data field is altered to
	*					hold the given (o) value
	*	Informally: assign the value of the parameter to the TNode
	*				variable's "data" field
	*
	*	param o the variable to store in the data field of the node
*/
void setTNData(tNode t,void *o)
{
    trace("setTNData: setTNData starts");	//for debug purposes only. function in assig_three115.c

	//update data field
	t->data = o;

    trace("setTNData: setTNData ends");	//for debug purposes only. function in assig_three115.c
}
	
	
/*
	*	setTNLevel
	*	Set function for "level" field.
	*	Pre-condition: none
	*	Post-condition: the TNode variable's level field is altered to
	*					hold the given (l) value
	*	Informally: assign the value of the parameter to the TNode
	*				variable's "level" field
	*
	*	param l the level number of the node
*/
void setTNLevel(tNode t,int l)
{
    trace("setTNLevel: setTNLevel starts");	//for debug purposes only. function in assig_three115.c

	//update data field
	t->level = l;

    trace("setTNLevel: setTNLevel ends");	//for debug purposes only. function in assig_three115.c
}
	
	
/*
	*	setTNChild
	*	Set function for "child" field.
	*	Pre-condition: none
	*	Post-condition: the TNode variable's child field is altered
	*					to hold the given (n) value
	*	Informally: assign the value of the parameter to the TNode
	*				variable's "child" field
	*
	*	param n the node to set as the child of the current node
*/
void setTNChild(tNode t,tNode n)
{
    trace("setTNChild: setTNChild starts");	//for debug purposes only. function in assig_three115.c

	//update data field
	t->child = n;

    trace("setTNChild: setTNChild ends");	//for debug purposes only. function in assig_three115.c
}
	
	
/*
*	setTNSibling
*	Set function for "sibling" field.
*	Pre-condition: none
*	Post-condition: the TNode variable's sibling field is altered
*					to hold the given (n) value
*	Informally: assign the value of the parameter to the TNode
*				variable's "sibling" field
*
*	param n the node to set as the sibling of the current node
*/
void setTNSibling(tNode t, tNode n)
{
	trace("setTNSibling: setTNSibling starts");	//for debug purposes only. function in assig_three115.c

	//update data field
	t->sibling = n;

	trace("setTNSibling: setTNSibling ends");	//for debug purposes only. function in assig_three115.c
}


/*
*	setTNParent
*	Set function for "parent" field.
*	Pre-condition: none
*	Post-condition: the TNode variable's parent field is altered
*					to hold the given (n) value
*	Informally: assign the value of the parameter to the TNode
*				variable's "parent" field
*
*	param n the node to set as the parent of the current node
*/
void setTNParent(tNode t, tNode n)
{
	trace("setTNParent: setTNParent starts");	//for debug purposes only. function in assig_three115.c

	//update data field
	t->parent = n;

	trace("setTNParent: setTNParent ends");	//for debug purposes only. function in assig_three115.c
}


/*
	*	getTNData
	*	Get function for "data" field.
	*	Pre-condition: none
	*	Post-condition: the TNode variable's data field is returned
	*	Informally: examine the TNode variable's "data" instance
	*				variable returning its value
	*
	*	return variable the item in the node
*/
void *getTNData(tNode t)
{
    trace("getTNData: getTNData starts and ends"); //for debug purposes only. function in assig_three115.c

	//fetch and return pointer to data
	return (t->data);
}
	
	
/*
	*	getTNLevel
	*	Get function for "level" field.
	*	Pre-condition: none
	*	Post-condition: the TNode variable's level field is
	*				returned
	*	Informally: examine the TNode variable's "level" instance
	*				variable returning its value
	*
	*	return int the level number of the current node
*/
int getTNLevel(tNode t)
{
    trace("getTNLevel: getTNLevel starts and ends"); //for debug purposes only. function in assig_three115.c

	//fetch and return level data field
	return (t->level);
}
	
	
/*
	*	getTNChild
	*	Get function for "child" field.
	*	Pre-condition: none
	*	Post-condition: the TNode variable's child field is
	*					returned
	*	Informally: examine the TNode variable's "child"
	*				field returning its value
	*
	*	return TNode the child of the current node
*/
tNode getTNChild(tNode t)
{
    trace("getTNChild: getTNChild starts and ends"); //for debug purposes only. function in assig_three115.c

	//fetch and return child data field
	return (t->child);
}
	
	
/*
*	getTNSibling
*	Get function for "sibling" field.
*	Pre-condition: none
*	Post-condition: the TNode variable's sibling field is
*					returned
*	Informally: examine the TNode variable's "sibling"
*				field returning its value
*
*	return TNode the sibling of the current node
*/
tNode getTNSibling(tNode t)
{
	trace("getTNSibling: getTNSibling starts and ends");	//for debug purposes only. function in assig_three115.c

	//fetch and return sibling data field
	return (t->sibling);
}


/*
*	getTNParent
*	Get function for "parent" field.
*	Pre-condition: none
*	Post-condition: the TNode variable's parent field is
*					returned
*	Informally: examine the TNode variable's "parent"
*				field returning its value
*
*	return TNode the parent of the current node
*/
tNode getTNParent(tNode t)
{
	trace("getTNParent: getTNParent starts and ends");	//for debug purposes only. function in assig_three115.c

	//fetch and return parent data field
	return (t->parent);
}
