/*************************************************************************
 *  CMPSC 122                                                            *
 *  DLList.h
// Hacked by Chris Enck                                               *
 *  december 9, 2013                                                     *
 *  Sukmoon Chang                                                        *
 *  sukmoon@psu.edu                                                      *
 *                                                                       *
 *                                                                       *
 *  Description:                                                         *
 *                                                                       *
 *  This is a header file for a simplified doubly-linked list ADT        *
 *  Do not modify any codes in this file                                 *
 *                                                                       *
 *  Please report any bug to sukmoon@psu.edu                             *
 *************************************************************************/  
 

#ifndef _DLLIST_H
#define _DLLIST_H


#include <cstddef>   // NULL is defined here
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <iostream>

using namespace std;


// ADT for the nodes in Doubly Linked List

class DLNode{
 public:
  char data;
  DLNode *next, *prev;
  double value;
  bool flag;
  bool endFlag;
  // all public methods
  DLNode(){    next = prev = NULL;  }
  DLNode(char d, DLNode *p=NULL, DLNode *n=NULL){
    data = d;
    prev = p;
    next = n;
    value = 0.0;
    flag = true;
    endFlag = false;
  }
  DLNode(double d, DLNode *p=NULL, DLNode *n=NULL){
    value = d;
    data = '@';
    prev = p;
    next = n;
    flag = false;
    endFlag = false;
  }
  //function used in evaluation
  void removeNextNodes(DLNode *tempnode){
    DLNode *deleteNode;
    for(int i =0; i<2; i++){
      if(tempnode->next!=NULL){
      deleteNode= tempnode->next;
      tempnode->next= deleteNode->next;
      tempnode->next->prev= deleteNode->prev;
      delete deleteNode;
      }
    }
  }
  friend class DLList;
};



// ADT for Doubly Linked List

class DLList{

 public:
  DLNode *head, *tail;

  DLList();              // create an empty list
  ~DLList();             // destroy this list
  
  bool isEmpty();        // is this list empty?
  void addToHead(char);  // add the given character to the head
  void addToTail(char);  // add the given character to the tail
  void addToTail(double);

  // DO NOT call this method on empty list
  // remove from the head and return the removed character
  char deleteHead();     
  char deleteTail();     
  void clear();  
  char first();

};


#endif
