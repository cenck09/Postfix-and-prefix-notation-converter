



#include "DLList.h"
#include "Stack.h"






int main(){

  int userinput = 0;
  Stack tri;


  while(userinput != -1){

    cin>> userinput;
    cout<<endl;
    switch(userinput){

    case 1: cin>>userinput; tri.push(userinput); cout<<endl; break;
    case 2: userinput = tri.pop(); cout<<userinput<<endl; break;

    }



  }

}
