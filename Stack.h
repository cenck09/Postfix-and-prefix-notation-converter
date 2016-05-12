/*******************************************************
 *  CMPSC 122                                          *
 *   hacked by Chris Enck                            *
 *  december 9, 2013                                   *
 *  Sukmoon Chang                                      *
 *  sukmoon@psu.edu                                    *
 *                                                     *
 *                                                     *
 *  Description:                                       *
 *                                                     *
 *  This is a header file for a simplified stack ADT   *
 *  Do not modify any codes in this file               *
 *                                                     *
 *  Please report any bug to sukmoon@psu.edu           *
 *******************************************************/  


#ifndef _STACK_H
#define _STACK_H


#include "DLList.h"


// ADT for Stack using Doubly Linked Lis

class Stack
{
private:
  DLList list;

public:
  Stack();     // create an empty statk
  ~Stack();    // destroy this stack

  bool isEmpty();  // is this stack empty?
  bool isFull();   // is this stack full?

  void clear();    // remove every item in the stack

  // DO NOT call this method on a full stack
  // adds an item on top of the stack
  void push(char data);

  // DO NOT call this method on an empty stack
  // removes an item on top of the stack
  //   and retuns the removed character
  char pop();

  // DO NOT call this method on an empty stack
  // returns the character on top of the stack
  //   without removing it from the stack
  char top();

};

#endif
