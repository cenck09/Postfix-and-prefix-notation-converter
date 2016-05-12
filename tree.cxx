/*
tree.cxx
Chris Enck
11/11/13
This code replaces the need for the precompiled DLList.o that was given

 */



#include <cstddef>   // NULL is defined here
#include "tree.h"
#include "Stack.h"
#include "DLList.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;




 // create an empty list
Tree::Tree(){
   root=leaf = NULL;

  }             
  //Destroys the list

Tree::~Tree(){
 
  }

Tree::Tree(char data2, TreeNode *left2=NULL, TreeNode *right2=NULL, TreeNode *parent2=NULL){
  root=leaf= new TreeNode(data2, right2, left2, parent2);

}

void Tree::setRoot(TreeNode *r){
  root= r;

}

TreeNode *Tree::returnRoot(){
  return root;
}

bool Tree::isEmpty(){
  return root==NULL;
}

void Tree::addLeft(TreeNode *d){
    root->left = d; 
 }

void Tree::addRight(TreeNode *d){
    root->right = d; 
}
