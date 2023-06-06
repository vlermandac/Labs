#include "linked_list.h"

void linked_list::push_back(int value) {
  node* newNode = new node(value);
  if(tail) tail->next = newNode;
  else head = newNode;
  tail = newNode;
}

void linked_list::push_front(int value) {
  node* newNode = new node(value);
  newNode->next = head;
  head = newNode;
  if(!tail) tail = head;
}

void linked_list::pop_front() {
  if(head == nullptr) return;
  node* temp = head;
  head = head->next;
  delete temp;
  if(!head) tail = nullptr;
}

void linked_list::print(){
  node* current = head;
  while(current->next != nullptr){
    // current->val
    current = current->next;
  }
}

void linked_list::pop_back() {
  if(head == nullptr) return;
  if(head->next == nullptr){
    delete head;
    head = nullptr;
    tail = nullptr;
    return;
  }
  node* current = head;
  while(current->next->next)
      current = current->next;
  delete current->next;
  current->next = nullptr;
  tail = current;
}
