#include <string>
#include <vector>

using namespace std;

class HashTable {
private:
  int size; 
  vector<pair<string, int>> table; 
  int hash(const string& key) const{
      int hashVal = 0;
      for(char ch : key) hashVal += ch;
      return hashVal % size;
  }
public:
  HashTable(int size): size(size), table(size) {}

  void insert(const string& key, int value) {
    int i = hash(key);
    while(table[i].first != "" && table[i].first != key)
        i = (i + 1) % size;
    table[i] = {key, value};
  }

  int get(const string& key) const {
    int i = hash(key);
    while(table[i].first != "" && table[i].first != key)
        i = (i + 1) % size;
    if(table[i].first == key)
        return table[i].second;
    return -1; 
  }

  void remove(const string& key) {
    int i = hash(key);
    while(table[i].first != "" && table[i].first != key)
      i = (i + 1) % size;
    if(table[i].first == key) 
      table[i].first = ""; 
  }
};
