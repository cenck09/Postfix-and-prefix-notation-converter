// BuildTree.cxx
// Chris Enck
// Cmpsc122


#include "rpn.cxx"
#include "tree.h"
#include "DLList.h"
#include "Stack.h"
#include "TreeStack.h"
#include "treeDLList.h"

//main helper functions
TreeNode *fillTree( );
string convertInput();


int main(){

  // menu stored in string
  string menu = "\n 1 = enter expression \n 2 = evaluate \n 3 = VLR \n 4 = LVR postfix RPN \n 5 = quit \n";
  string tempChar="n";
  string postfix="";
  string prefix = "";

  // stacks/ flags and other pointers used for tree and traversal
  Tree *root= new Tree;
  Stack opp;
  Stack opp2;
  TreeStack opp3;

  TreeNode *temp = NULL;
  TreeNode *temp2 =NULL;
  TreeNode *loopEnd= new TreeNode;
  bool flag = true;
  int userinput = 0;
  double tempvalueF = 0.0;
  DLList evaluate;
  DLNode *DLPointer;
  DLNode *helperPointer;
 while(flag){

    cout<<menu;
    cin>>userinput; 

    switch(userinput){

    case 1: // prompts user for input and generates an expression tree
      temp=fillTree();
      evaluate.clear();
      prefix="";
      postfix="";
      //sets roots and pointers for tree traversal
      root->setRoot(temp); 
      loopEnd->left=root->returnRoot();
      temp->parent=loopEnd;
      temp=root->returnRoot();
      break;

    case 2:// eval(root);
      DLPointer = evaluate.head;
      cout<<DLPointer->value<<endl;
      break;

    case 3:// prints prefix notation
      cout<<prefix<<endl;
      break;

    case 4: //printPostfix(root);
      cout<<postfix<<endl;
      break;

    case 5://quit flag 
      flag = false;
      break;
    } //end of switch 




    //start of tree traversals when given new input
    if(userinput==1){

      // This chunck calculates RPN Notation********************

      while(loopEnd!=temp){
	//checks for leafs
	if(temp->left==NULL&&temp->right==NULL){
	  temp->evalFlag= false; 
	  opp.push(temp->data);
	  temp= temp->parent;
	}    
	if(temp->left->evalFlag==false && temp->right->evalFlag==false){
	  temp->evalFlag= false;
	  opp.push(temp->data);
	  temp= temp->parent;
	}// prints if both children =false
	if(temp->left!=NULL && temp->left->evalFlag==true){
	  temp= temp->left;

	}else if(temp->right!=NULL && temp->right->evalFlag==true){
	  temp = temp->right;
	}
      }//end of root whileloop
      

      while(opp.isEmpty()==false){
	opp2.push(opp.pop());
      }
    
      userinput= 0;
      while(opp2.isEmpty()==false){
	tempChar = opp2.pop();
	postfix.insert(userinput,tempChar);
	userinput++;
      }
      //  userinput++;
      // postfix.insert(";", userinput);

      //End of RPN while loops
      //***************************************
   

   
      // Start of Preorder Notation
      
      temp = temp2 = root->returnRoot();
      opp3.push(temp);
      while(opp3.isEmpty()==false){
	temp2=opp3.pop();
	opp.push(temp2->data);
	  if(temp2->right!=NULL){
	    opp3.push(temp2->right);
	  }
	if(temp2->left!=NULL){
	  opp3.push(temp2->left);
	}
      }

   while(opp.isEmpty()==false){
	opp2.push(opp.pop());
      }
    
      userinput= 0;
      while(opp2.isEmpty()==false){
	tempChar = opp2.pop();
	prefix.insert(userinput,tempChar);
	userinput++;
      }
      //end of preorder traversal part
   

   //Deletes the tree
      // This part cleans up all the dynamic memory used by the tree
      while(loopEnd!=temp){
	//checks for leafs
	if(temp->left==NULL&&temp->right==NULL){
	  temp=temp->parent;
	  if(temp->right!=NULL){
	    delete temp->right;
	    temp->right=NULL;
	  }else if(temp->left!=NULL){
	    delete temp->left;
	    temp->left=NULL;
	  }
	}else{
	  if(temp->left!=NULL){temp=temp->left;
	  }else if(temp->right!=NULL){
	    temp=temp->right;
	  }
	}
      }
      //start of eval calulations
      //************************************
      /*




operators char
isOperator bool
values float

evaluate 
DLPointer
      */
      
      userinput=0;
      while(postfix[userinput]){
	
	//loops through parting the operators from the operands 
	if(postfix[userinput]=='+'){
	  evaluate.addToTail('+');

	}else if(postfix[userinput]=='-'){
	  evaluate.addToTail('-');
	
	}else if(postfix[userinput]=='*'){
	  evaluate.addToTail('*');
	
	}else if(postfix[userinput]=='/'){
	  evaluate.addToTail('/');
	
	}else{
	  tempvalueF = 1.0;
	  switch(postfix[userinput]){
	  case '0': evaluate.addToTail(tempvalueF*0.0); break;
	  case '1': evaluate.addToTail(tempvalueF*1.0); break;
  	  case '2': evaluate.addToTail(tempvalueF*2.0); break;
  	  case '3': evaluate.addToTail(tempvalueF*3.0); break;
  	  case '4': evaluate.addToTail(tempvalueF*4.0); break;
	  case '5': evaluate.addToTail(tempvalueF*5.0); break;
	  case '6': evaluate.addToTail(tempvalueF*6.0); break;
  	  case '7': evaluate.addToTail(tempvalueF*7.0); break;
 	  case '8': evaluate.addToTail(tempvalueF*8.0); break;
  	  case '9': evaluate.addToTail(tempvalueF*9.0); break;
  		  
	  }
	  
	}

	userinput++;
      }

      evaluate.addToTail('@');
      helperPointer=evaluate.head;

      while(helperPointer->next!=NULL){
	helperPointer= helperPointer->next;
      }

      helperPointer->endFlag=true;
      
      DLPointer = evaluate.head; 
      // while loop goes through list removing 2 nodes and replacing the value after calculations
      while(DLPointer->endFlag== false){

	if(DLPointer->flag==true){
	  helperPointer= DLPointer->prev->prev;

	  if(DLPointer->data=='+'){
	    helperPointer->value= ((helperPointer->value)+ (helperPointer->next->value));
	    helperPointer->removeNextNodes(helperPointer);
	    
	  }else if(DLPointer->data=='-'){
	    helperPointer->value= ((helperPointer->value)- (helperPointer->next->value));
	    helperPointer->removeNextNodes(helperPointer);
	    

	   
	  }else if(DLPointer->data=='*'){
	    helperPointer->value= ((helperPointer->value)* (helperPointer->next->value));
	    helperPointer->removeNextNodes(helperPointer);
	    

	   
	  }else if(DLPointer->data=='/'){
	    helperPointer->value= ((helperPointer->value)/ (helperPointer->next->value));
	    helperPointer->removeNextNodes(helperPointer);
	    
	    }
	 
	  DLPointer = helperPointer;

	}
	DLPointer=DLPointer->next;
      } 

    }//end if if userInput==1
  
 }// end of program
 delete root;
  delete loopEnd;
  return 0;
}




TreeNode *fillTree(){

  TreeNode *root= new TreeNode;
  int count=0;
  string rpnExp = convertInput();
  TreeStack trees;
  TreeNode *temp=NULL;
 

  while(rpnExp[count]!= ';'){
    

    if(precedence(rpnExp[count])>0 && precedence(rpnExp[count]<3)){
      temp = new TreeNode(rpnExp[count], trees.pop(), trees.pop());
      temp->left->parent=temp;
      temp->right->parent=temp;
	trees.push(temp);

      }else if(precedence(rpnExp[count])==-9999){
	trees.push( new TreeNode(rpnExp[count]));
      }
    count++;
  }
  root=trees.pop();
  return root;
}


string convertInput(){

 string beginPar = "(";
  string endPar = ");";
  string expr;
  string semi = ";";

  cout<<"enter an infix expression"<<endl;
  cin>>expr;
  cin.ignore();
  int length = expr.length();

  expr.insert(length,endPar);
  expr.insert(0, beginPar);
  string rpnExp = convert(expr);
  length= rpnExp.length();

  rpnExp.insert(length, semi);

 return rpnExp;
}
