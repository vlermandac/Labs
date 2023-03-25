#include <iostream>

using namespace std;

// Ni siquiera es dinamico :(
class bad_dynamic_array{
  private:
    int size;
    int elements;
    int *array;
  public:
    bad_dynamic_array(int size);
    ~bad_dynamic_array();
    void insert(int value);
    int remove();
    bool is_empty();
    int find(int value);
};
