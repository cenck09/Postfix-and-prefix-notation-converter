/*
treeDLList.cxx
Chris Enck
11/11/13
This code replaces the need for the precompiled DLList.o that was given

 */



#include <cstddef>   // NULL is defined here
#include "treeDLList.h"
#include "tree.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;




 // create an empty list
 treeDLList::treeDLList(){
   head=tail = NULL;

  }             
  //Destroys the list
  treeDLList::~treeDLList(){

  }            

     // is this list empty?
bool treeDLList::isEmpty(){
    return (head==NULL);
  }



// add the given character to the head
void treeDLList::addToHead(TreeNode *c){
    if(isEmpty()){
      head=tail= new treeDLNode( c );

    }else{
      treeDLNode *tempnode= head;
      head = tempnode->prev= new treeDLNode( c, NULL , tempnode);
    }

  } 

 // add the given character to the tail 
void treeDLList::addToTail(TreeNode *c){

    if(isEmpty()){
      head=tail= new treeDLNode( c );

    }else{
      treeDLNode *tempnode= tail;
      tail = tempnode->next= new treeDLNode( c,tempnode , NULL);
    }
  } 


TreeNode * treeDLList::deleteHead(){
    if(isEmpty()!=true){
      
      TreeNode *tempdata = head->data;
      treeDLNode *tempnode= head;
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

TreeNode * treeDLList::deleteTail(){

    if(isEmpty()!= true){

     TreeNode *tempdata = tail->data;  
      treeDLNode *tempnode = tail->prev;
    
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



TreeNode * treeDLList::first(){
    return head->data;
  }
