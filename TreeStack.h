/*******************************************************
 *  CMPSC 122                                          *
 *  Christopher Enck                              *
 *  December 9, 2013                                   *
 *  Sukmoon Chang                                      *
 *  sukmoon@psu.edu                                    *
 *            **TreeStack.h                                         *
 *                                                     *
 *  Description:                                       *
 *                                                     *
 *  This is a header file for a simplified stack ADT   *
 *  Do not modify any codes in this file               *
 *                                                     *
 *  Please report any bug to sukmoon@psu.edu           *
 *******************************************************/  


#ifndef _TREESTACK_H
#define _TREESTACK_H


#include "treeDLList.h"
#include "tree.h"


// ADT for Stack using Doubly Linked Lis

class TreeStack
{
private:
 treeDLList list;

public:
  TreeStack();     // create an empty statk
  ~TreeStack();    // destroy this stack

  bool isEmpty();  // is this stack empty?
  bool isFull();   // is this stack full?

  void clear();    // remove every item in the stack

  // DO NOT call this method on a full stack
  // adds an item on top of the stack
  void push(TreeNode *data);

  // DO NOT call this method on an empty stack
  // removes an item on top of the stack
  //   and retuns the removed character
  TreeNode *pop();

  // DO NOT call this method on an empty stack
  // returns the character on top of the stack
  //   without removing it from the stack
  TreeNode *top();

};

#endif
