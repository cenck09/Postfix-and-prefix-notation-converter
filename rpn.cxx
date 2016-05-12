/**************************************************/
/*                                                */
// rpn.cxx
// Chris Enck
// 12/9/13
// This program inputs math expressions from the input file
// and outputs the RPN converted version to the output file
/*                                                */
/**************************************************/

#include "DLList.h"
#include "Stack.h"
#include <iostream>
#include <cstdlib>    // exit() is defined here, if you need it.
#include <cstring>
#include <string>

using namespace std;
// This Code works 

/*                                         */
/* If you've used any additional functions */
/* Add forward declarations HERE           */
/*                                         */

string convert(const string& expr);
int precedence(const char c);




// main function repeats the following:
// - reads a line containing an infix expression from cin
// - convert the expression to rpn
// - outputs the following
//    - the given infix expression with title to cerr
//    - the converted rpn expression with title to cerr
//    - the converted rpn expression to cout

/*int main()
{
  string expr;

  cerr << "Enter an expression ===> ";
  while (getline(cin, expr)) {
    string rpn = convert(expr);
    cerr << "   Given: " << expr << endl;
    cerr << "     RPN: " << rpn << endl;
    cout << rpn << endl;
    cerr << "Enter an expression ===> ";
  }
  cerr << endl;
  return 0;
}

*/

// This function 
// - converts a given expression to equivalent rpn
// - returns the rpn expression
//
// You must implement the algorithm using a stack 
//   as discussed in the lecture



string convert(const string& expr)
{
  int count =0;
  int length = expr.length();
  DLList output;
  int par = 0;
  Stack opperator;
  char *temphold;
  
  
  while(precedence(expr[count])!=100){

      if(expr[count]==')'){par++;}
      if(expr[count]=='('){par++;}

      count++;    
	}

    length = length-par;
    temphold= new char[length];
    count=0;

  while(precedence(expr[count])!=100) {

   //checks if the token is not an opperator, pushes to output
    if(precedence(expr[count])== -9999 && count!=0)
      {	output.addToTail(expr[count]); }

    if(count==0){//checks first spot if its a ( or number
      if(expr[count]=='('){opperator.push('(');}
      else{ output.addToHead(expr[0]);}

    }else{// this handels all cases after first one


      if(expr[count]=='('){opperator.push('(');}
      
      if(expr[count]==')'){ 

	while(opperator.top() != '('){ 
	  output.addToTail( opperator.pop() );
	}

	opperator.pop();
      }



      // checks for minus, makes sure its empty
      if(expr[count]=='-'){
	if( opperator.isEmpty() != true){
	 
	  if(precedence(opperator.top())==2){
	    output.addToTail(opperator.pop());
	  }

	  if(precedence(opperator.top())==1){
 	    output.addToTail(opperator.pop());
	    opperator.push('-');
	  }else if(opperator.top()== '('){
	    opperator.push('-');
	  }    
	    
	}else{// if the opperator stack is already empty
	  opperator.push('-');
	}
      }// end of minus function
    


  // checks for plus, makes sure its empty
      if(expr[count]=='+'){
	if( opperator.isEmpty() != true){
	
	  if(precedence(opperator.top())==2){
	    output.addToTail(opperator.pop());
	  }

	  if(precedence(opperator.top())==1){
 	    output.addToTail(opperator.pop());
	    opperator.push('+');
	  }else if(opperator.top()== '('){
	    opperator.push('+');
	  }    
	    
	}else{// if the opperator stack is already empty
	  opperator.push('+');
	}
      }// end of plus function
    



      // checks for multiplication, makes sure its empty
      if(expr[count]=='*'){
	if( opperator.isEmpty() != true){
	  if(precedence(opperator.top())==2){
	    output.addToTail(opperator.pop());
	    opperator.push('*');
	  }else if(opperator.top()== '('){ opperator.push('*');
	  }else{ opperator.push('*');}	    
	  
	}else{// if the opperator stack is already empty
	  opperator.push('*');
	}
      }// end of mult function




     // checks for division, makes sure its empty
      if(expr[count]=='/')
	{ 
	if( opperator.isEmpty() != true){
	  if(precedence(opperator.top())==2){
	    output.addToTail(opperator.pop());
	    opperator.push('/');
	  }else if(opperator.top()== '('){
	      opperator.push('/');
	  }else{
	      opperator.push('/');
	    }
	    
	}else
	  {// if the opperator stack is already empty
	  opperator.push('/');
	  }
      }// end of div function
  
    }//end of else loop
    count++;
  } //end of while


  // This copies over a char array to a string to return
  while(opperator.top()!= '@')
	{
	  output.addToTail(opperator.pop()); 
	}
  
      count=0;
      while(output.isEmpty()!= true){ temphold[count]=output.deleteHead();count++;}
      string newvar= temphold;
  return newvar;
}


// This function returns the precedence of a given operator.
// The precedence of operators are:
//   ( or ) : 0
//   + or - : 1
//   * or / : 2
int precedence(const char c)
{
   
  if( c == ')') { return 0;}
  if( c == '(') { return 0;}
  if( c == '+') { return 1;}
  if( c == '-') { return 1;}
  if( c == '*') { return 2;}
  if( c == '/') { return 2;}
  if( c == ';') { return 100;}
  else { return -9999;}
}



/*                                            */
/* If you are using any additional functions, */
/* add them HERE                              */
/*                                            */
