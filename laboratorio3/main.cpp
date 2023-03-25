#include <iostream>
#include <string>
#include "bad_dynamic_array.h"

using namespace std;

int main (int argc, char *argv[]){
  string command;
  int size;
  cout<< "Insert initial size: \n"; // probar con tamaño 1 para verificar que realmente es dinámico
  cin>>size;
  bad_dynamic_array *bda = new bad_dynamic_array(size); 
  bda->insert(5);
  bda->insert(5);
  bda->insert(5);
  if(!bda->is_empty()) cout<<"No vacío"<<endl;
  bda->remove();
  bda->remove();
  bda->remove();
  if(bda->is_empty()) cout<<"vacío"<<endl;

  return 0;
}
