/*************************************************************************
 *  CMPSC 122                                                            *
 *  Christopher Enck                                             *
 *  December 9, 2013                                                     *
 *  Sukmoon Chang                                                        *
 *  sukmoon@psu.edu                                                      *
 *                                                                       *
 *            tree.h**                                                           *
 *  Description:                                                         *
 *                                                                       *
 *  This is a header file for a simplified doubly-linked list ADT        *
 *  Do not modify any codes in this file                                 *
 *                                                                       *
 *  Please report any bug to sukmoon@psu.edu                             *
 *************************************************************************/  
 

#ifndef _TREE_H
#define _TREE_H


#include <cstddef>   // NULL is defined here
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <iostream>

using namespace std;


// ADT for the nodes in Tree
class TreeNode
{

 
public:

 char data;
 TreeNode *left, *right, *parent;
 bool evalFlag;
 bool postfixFlag;
 bool prefixFlag;

  TreeNode() {
    right = left = parent = NULL;
    evalFlag = postfixFlag = prefixFlag = true;
  }

 

 TreeNode(char d, TreeNode *r=NULL, TreeNode *l=NULL, TreeNode *par=NULL) {
    data = d;
    left = l;
    right = r;
    parent= par;
    evalFlag = postfixFlag = prefixFlag = true;

  }
  char returnData(){ return data;}
  
  friend class Tree;
};


// ADT for Tree
class Tree{

 private:
  TreeNode *root, *leaf;
 
 public:

  bool postfixFlagF(){return root->postfixFlag;}
  bool prefixFlagF(){return root->prefixFlag;}
  bool evalFlag(){return root->evalFlag;}

  void setRoot(TreeNode *);
  TreeNode *returnRoot();
  Tree();              // create an empty list
  ~Tree();           
  Tree(char,TreeNode *, TreeNode *, TreeNode*);// destroy this list 
  bool isEmpty();        // is this list empty?
  void addLeft(TreeNode *);
  void addRight(TreeNode *);

};


#endif
