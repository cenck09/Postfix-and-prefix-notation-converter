/*
DLList.cxx
Chris Enck
11/11/13
This code replaces the need for the precompiled DLList.o that was given

 */



#include <cstddef>   // NULL is defined here
#include "DLList.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;




 // create an empty list
  DLList::DLList(){
   head=tail = NULL;

  }             
  //Destroys the list
  DLList::~DLList(){

  }            

     // is this list empty?
bool DLList::isEmpty(){
    return (head==NULL||tail==NULL);
  }


// add the given character to the head
void DLList::addToHead(char c){
    if(isEmpty()){
      head=tail= new DLNode( c );

    }else{
      DLNode *tempnode= head;
      head = tempnode->prev= new DLNode( c, NULL , tempnode);
    }

  } 

 // add the given character to the tail 
void DLList::addToTail(char c){

    if(isEmpty()){
      head=tail= new DLNode( c );

    }else{
      DLNode *tempnode= tail;
      tail = tempnode->next= new DLNode( c,tempnode , NULL);
    }
  } 
void DLList::addToTail(double c){

    if(isEmpty()){
      head=tail= new DLNode( c );

    }else{
      DLNode *tempnode= tail;
      tail = tempnode->next= new DLNode( c,tempnode , NULL);
    }
  } 


  // DO NOT call this method on empty list
  // remove from the head and return the removed character
char DLList::deleteHead(){
    if(isEmpty()!=true){
      
      char tempdata = head->data;
      DLNode *tempnode= head;
      if (head==tail){ delete head; head=tail=NULL; return tempdata;
      }else{
	head=tempnode->next;
	tempnode->prev=NULL;
	delete tempnode;
	return tempdata;
      }
    }else{exit(0);}
  }


  // DO NOT call this method on empty list
  // remove from the tail and return the removed character

char DLList::deleteTail(){

    if(isEmpty()!= true){

     char tempdata = tail->data;  
      DLNode *tempnode = tail->prev;
    
      if (head==tail){ 
	delete head;
	head=tail=NULL;
	return tempdata;

      }else{
	tempnode->next=NULL;
	delete tail;
	tail= tempnode;
	return tempdata;
      }
    }else{ exit(0);}
 }     



  // remove every element from this list

void DLList::clear(){
    while(isEmpty()!= true)
      {	deleteHead(); }
  }  



char DLList::first(){
    return head->data;
  }
