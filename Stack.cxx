/*
Stack.cxx
Chris Enck
11/11/13
This program replaces the need for the given Stack.o 

 */


#include "DLList.h"
#include "Stack.h"
#include <cstdlib>

Stack::~Stack(){
list.clear();

}
//doesn't need to do anything
Stack::Stack(){
  

}

 // is this stack empty?
bool Stack::isEmpty(){
    return list.isEmpty();
  }
 
  // is this stack full?
bool Stack::isFull(){
    return false;
  } 
  
  //clears stack
void Stack::clear(){
    list.clear();
  }

  // DO NOT call this method on a full stack
  // adds an item on top of the stack
  void Stack::push(char data){
    list.addToHead(data);
  }

  // DO NOT call this method on an empty stack
  // removes an item on top of the stack
  //   and retuns the removed character
char Stack::pop(){
    if(list.isEmpty()!= true){
      return  list.deleteHead();
    }else{exit(0);}
 }

  // DO NOT call this method on an empty stack
  // returns the character on top of the stack
  //   without removing it from the stack
char Stack::top(){
  if(isEmpty()==false){
    return list.first();
  }else{ return '@';}

  }
