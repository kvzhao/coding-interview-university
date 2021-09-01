
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::pair;
using std::unordered_map;
using std::make_pair;
using std::priority_queue;
using std::greater;
using std::cout;
using std::max_element;


int dijkstra(int n, const vector<vector<int>>& edges, int src) {

  // weighted graph: adj list => vertex: [(v, weight)]
  const int inf = 1e9;
  vector<vector<pair<int, int>>> graph(n);
  vector<int> distTo(n, inf);
  vector<int> edgeTo(n, -1);

  for (const auto& e : edges) {
    graph[e[0]].emplace_back(make_pair(e[1], e[2]));
  }

  // pair: (w, vertex)
  priority_queue<pair<int, int>,
                 vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, src));
  distTo[src] = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto [v, w] : graph[u]) {
      if (distTo[u] + w < distTo[v]) {
        distTo[v] = distTo[u] + w;
        edgeTo[v] = u;
        pq.push(make_pair(distTo[v], v));
      }
    }
  }

  cout << "v\tdistTo[]\tedgeTo[]\n";
  for (int v = 0; v < n; ++v) {
    cout << v << "\t" << distTo[v] << "\t\t" << edgeTo[v] << "\n";
  }
  int min_cost = *max_element(distTo.begin(), distTo.end());
  return min_cost == inf ? -1 : min_cost;
}



int main() {

  int n = 8;
  int src = 0;
  vector<vector<int>> edges {
    {0, 1, 5},
    {0, 4, 9},
    {0, 7, 8},
    {1, 7, 4},
    {1, 7, 4},
    {1, 3, 15},
    {1, 2, 12},
    {7, 2, 7},
    {7, 5, 6},
    {4, 5, 4},
    {4, 6, 20},
    {5, 6, 13},
    {5, 2, 1},
    {2, 3, 3},
    {3, 6, 9},
    {2, 6, 11},
    {5, 6, 13},
  };

  int cost = dijkstra(n, edges, src);
  cout << cost << "\n";


  return 0;
}