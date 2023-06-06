#include <iostream>
#include <vector>

using namespace std;

class hanoi_tower {
private:
  int disks;
  vector<int> rods[3]; 

  void move(int n, int src, int dest, int aux) {
    if(n == 1){ // Base case
      rods[dest].push_back(rods[src].back());
      rods[src].pop_back();
      display_move(src, dest);
      display_state();
    } 
    else{
      move(n - 1, src, aux, dest); //H(n-1) from A to B
      move(1, src, dest, aux); // 1
      move(n - 1, aux, dest, src); // H(n-1) from B to C
    }
  }

  void display_move(int src, int dest) {
    cout<<"Moving disk from "<<char('A' + src)<<" to "<<char('A' + dest)<<endl;
  }

  void display_state() {
    for(int i = disks; i > 0; i--){
      for(auto rod : rods){
        if(i <= rod.size()) 
          for(int k = 0; k < rod[i - 1]; ++k) cout << "-";
        cout << "\t";
      }
      cout << endl;
    }
    cout << "A\tB\tC" << endl << endl;
    cout << "---------------------------\n";
  }
public:
  hanoi_tower(int disks){
    this->disks = disks;
    for (int i = disks; i > 0; i--) 
        rods[0].push_back(i);
  }

  void solve() {
      display_state();
      move(disks, 0, 2, 1);
  }
};

int main() {
  int disks = 3;
  hanoi_tower tower(disks);
  tower.solve();
  return 0;
}
