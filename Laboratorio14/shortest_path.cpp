#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> graph;
vector<int> dist;
vector<int> parent;

void dijsktra(int s){
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push({0, s});
  parent[s] = s;

  while(!pq.empty()){                    // main loop
    auto [d, u] = pq.top(); pq.pop();    // shortest unvisited u
    if(d > dist[u]) continue;            // a very important check
    for(auto &[v, w] : graph[u]){        // all edges from u
      if(dist[u]+w >= dist[v]) continue; // not improving, skip
      dist[v] = dist[u] + w;             // relax operation
      parent[v] = u;
      pq.push({dist[v], v});             // enqueue better pair
    }
  }
}

void print_path(int u){
  if(u == parent[u]) 
    cout << u << " ";
  else{
    print_path(parent[u]);
    cout << u << " ";
  }
}

int main(){
  /*
    completar
  */
  dist.assign(graph.size(), INT_MAX);
  parent.assign(graph.size(), -1);
  int concepcion, santiago;
  dijsktra(concepcion);
  print_path(santiago);
  return 0;
}
