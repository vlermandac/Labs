#include "linked_list.h"
#include <iostream>

using namespace std;

int main(){
  linked_list list;
  string operation;
  int value;
  while(cin>>operation){
    if(operation == "push_back"){
        cin>>value;
        list.push_back(value);
    }
    if(operation == "push_front"){
        cin>>value;
        list.push_front(value);
    }
    if(operation == "pop_front")
        list.pop_front();
    if(operation == "pop_back")
        list.pop_back();
  }
  list.print();
  return 0;
}
