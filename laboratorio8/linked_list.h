#include<string>

struct node{
  int value;
  node* next;
  node(int value) : value(value), next(nullptr) {}
};

class linked_list{
private:
  node* head;
  node* tail;
public:
  linked_list() : head(nullptr), tail(nullptr) {}
  void push_back(int data);
  void push_front(int data);
  void pop_front();
  void pop_back(); 
  void print();
};
