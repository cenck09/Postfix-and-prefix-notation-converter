/*******************************************************
 *  CMPSC 122                                          *
 *  Christopher Enck                              *
 *  December 5, 2013                                   *
 *  Sukmoon Chang                                      *
 *  sukmoon@psu.edu                                    *
 *                                                     *
 *       **TreeStack.cxx**                                              *
 *  Description:                                       *
 *                                                     *
 *  This is a header file for a simplified stack ADT   *
 *  Do not modify any codes in this file               *
 *                                                     *
 *  Please report any bug to sukmoon@psu.edu           *
 *******************************************************/  

#include "TreeStack.h"
#include "treeDLList.h"

TreeStack::TreeStack(){

  }

TreeStack::~TreeStack(){

  }    

bool TreeStack::isEmpty(){
    return list.isEmpty();
  }
 

void TreeStack::push(TreeNode *data){
    list.addToHead(data);

  }

TreeNode *TreeStack::pop(){
    return list.deleteHead();
  }

TreeNode *TreeStack::top(){
    return list.first();
  }
