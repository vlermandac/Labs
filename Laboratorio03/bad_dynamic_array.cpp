#include "bad_dynamic_array.h"
#include <climits>

using namespace std;

bad_dynamic_array::bad_dynamic_array(int size){
  this->size = size;
  this->array = new int[size];
}

bad_dynamic_array::~bad_dynamic_array(){
  delete[] array;
}

// El uso de el 'this->' es opcional mientras no haya ambigüedad de nombre
// lo pongo para dar a entender a que nos referimos al ATRIBUTO array
void bad_dynamic_array::insert(int value){
  if((elements + 1) == size){
    int *temp = new int[size*2];
    for(int i=0;i<size;i++) temp[i] = this->array[i];
    delete[] this->array;
    this->array = temp;
  }
  for(int i = elements - 1; i > 0; i--)
    array[i + 1] = array[i]; 
  array[0] = value;
  elements++;
}

int bad_dynamic_array::remove(){
  if(elements <= 0) return INT_MIN;
  int front = array[0];
  for(int i = 0; i < elements - 1; i++)
    array[i] = array[i + 1]; 
  elements--;
  return front;
}

bool bad_dynamic_array::is_empty(){
  return (elements == 0);
}

int bad_dynamic_array::find(int value){
  for(int i = 0; i < elements; i++)
    if(array[i] == value) return i;
  return -1;
}
