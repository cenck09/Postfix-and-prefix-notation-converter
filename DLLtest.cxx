#include <iostream>
#include "DLList.h"
#include <stdlib.h>


int main(){

  DLList test;
  char inputData = '0';
  bool quit = true;
  int userInput = 0;
  while(quit){
    
    cout<<"0 to fill"<<endl;
    cout<<"1 to add to tail"<<endl<<"2 to add to head"<<endl<<" 3 to deletehead"<<endl;
    cout<<"4 to delete tail"<<endl<<"5 to clear"<<endl<<" 6 to return first"<<endl;
    cout<<"t"<<endl<<"8 to print list"<<endl<<"9 to quit"<<endl;
    cin>>userInput;
    if (userInput==9){quit= false;}
    
    switch(userInput){
      
    case 0:
      for(int i =0; i<30; i++){
	if( (drand48()*9) <=4){inputData = '2';}
	if( (drand48() *9)>4){inputData = '8';}

	test.addToTail(inputData);
      } break;
    case 1: cin>>inputData; test.addToTail(inputData); break;
    case 2: cin>>inputData; test.addToHead(inputData); break;
    case 3: test.printDeleteHead();  break;
    case 4: test.printDeleteTail();  break;
    case 5: test.clear(); cout<<"is cleared!"<<endl; break;
    case 6: inputData= test.first(); break;
    case 8: test.print(); break;
    default: break;
    }
 
  }  
  return 0;
}

