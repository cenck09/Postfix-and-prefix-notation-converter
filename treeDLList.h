/*************************************************************************
 *  CMPSC 122                                                            *
 *  Christopher enck                                               *
 *  December 9, 2013                                                     *
 *  Sukmoon Chang                                                        *
 *  sukmoon@psu.edu                                                      *
 *            **treeDLList.h**                                           *
 *                                                                       *
 *  Description:                                                         *
 *                                                                       *
 *  This is a header file for a simplified doubly-linked list ADT        *
 *  Do not modify any codes in this file                                 *
 *                                                                       *
 *  Please report any bug to sukmoon@psu.edu                             *
 *************************************************************************/  
 

#ifndef _TREEDLLIST_H
#define _TREEDLLIST_H
#include "tree.h"
#include <cstddef>   // NULL is defined here
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <iostream>

using namespace std;


// ADT for the nodes in Doubly Linked List

class treeDLNode
{
private:
  TreeNode *data;
  treeDLNode *next, *prev;
  
public:
 treeDLNode() {
    next = prev = NULL;
  }

  treeDLNode(TreeNode *d, treeDLNode* p=NULL, treeDLNode* n=NULL) {
    data = d;
    prev = p;
    next = n;
 
  }
 TreeNode *returnData(){ return data;}
  
  friend class treeDLList;
};



// ADT for Doubly Linked List

class treeDLList
{
 private:
  treeDLNode *head, *tail;

 public:

  treeDLList();              // create an empty list
  ~treeDLList();             // destroy this list

  bool isEmpty();        // is this list empty?
  void addToHead(TreeNode *);  // add the given character to the head
  void addToTail(TreeNode *);  // add the given character to the tail

  TreeNode *deleteHead();     
  TreeNode *deleteTail();     
  TreeNode *first();

};


#endif
