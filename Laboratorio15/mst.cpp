#include <iostream>
#include "union_find.hpp"

using namespace std;

typedef tuple<int, int, int> iii;

int main(){
   // Kruskal's algorithm
  int V, E; scanf("%d %d", &V, &E);
  vector<iii> EL(E);
  for (int i = 0; i < E; ++i) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);  // read as (u, v, w)
    EL[i] = {w, u, v};                           // reorder as (w, u, v)
  }
  sort(EL.begin(), EL.end());                    // sort by w, O(E log E)
  // note: std::tuple has built-in comparison function

  int mst_cost = 0, num_taken = 0;               // no edge has been taken
  UnionFind UF(V);                               // all V are disjoint sets
  // note: the runtime cost of UFDS is very light
  for (int i = 0; i < E; ++i) {                  // up to O(E)
    auto [w, u, v] = EL[i];                      // C++17 style
    if (UF.isSameSet(u, v)) continue;            // already in the same CC
    mst_cost += w;                               // add w of this edge
    UF.unionSet(u, v);                           // link them
    ++num_taken;                                 // 1 more edge is taken
    if (num_taken == V-1) break;                 // optimization
  }
  // note: the number of disjoint sets must eventually be 1 for a valid MST
  printf("MST cost = %d (Kruskal's)\n", mst_cost);
  return 0;
}
