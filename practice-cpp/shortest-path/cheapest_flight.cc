
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::pair;
using std::tuple;
using std::priority_queue;
using std::greater;
using std::cout;
using std::make_pair;
using std::make_tuple;
using std::max_element;

typedef pair<int, int> ipair;
typedef tuple<int, int, int> ituple;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      /*
      Some explanation.
        The key difference with the classic Dijkstra algo is, we don't maintain the global optimal distance to each node, i.e. ignore below optimization:
        alt ← dist{u} + length(u, v)
        if alt < dist[v]:
        Because there could be routes which their length is shorter but pass more stops, and those routes don't necessarily constitute the best route in the end. To deal with this, rather than maintain the optimal routes with 0..K stops for each node, the solution simply put all possible routes into the priority queue, so that all of them has a chance to be processed. IMO, this is the most brilliant part.
        And the solution simply returns the first qualified route, it's easy to prove this must be the best route.
      */

      vector<vector<ipair>> graph(n);

      // (source city, destiniation city, price)
      for (const auto& flight: flights) {
        graph[flight[0]].emplace_back(make_pair(flight[1], flight[2]));
      }

      // (current total price, current source city, max stops allowed)
      priority_queue<ituple, vector<ituple>, greater<ituple>> pq;
      pq.emplace(make_tuple(0, src, k + 1));

      int min_cost = INT_MAX;

      while (!pq.empty()) {
        auto [cost, u, stops] = pq.top();
        pq.pop();

        if (u == dst) {
          min_cost = std::min(cost, min_cost);
          continue;
        }

        if (stops == 0) {
          // stop explore
          continue;
        }

        for (auto [v, w] : graph[u]) {

          // some modifications of the Dijkstra algorithm, see explaination
          if (cost + w < min_cost) {
            pq.emplace(make_tuple(cost + w, v, stops -1));
          }
        }

      }

      return min_cost == INT_MAX ? -1 : min_cost;
    }
};


int main() {
  Solution sol;

  vector<vector<int>> flights{{0,1,100}, {1,2, 100}, {0,2,500}};
  int n = 3;
  int src = 0, dst = 2;

  int k1 = 1, k2 = 0;
  auto res1 = sol.findCheapestPrice(n, flights, src, dst, k1);
  auto res2 = sol.findCheapestPrice(n, flights, src, dst, k2);

  if (res1 == 200 and res2 == 500) {
    cout << "Pass\n";
  } else {
    cout << "Failed, " << res1 << ", " << res2 << "\n";
  }


  n = 13;
  flights = {{11,12,74},{1,8,91},{4,6,13},{7,6,39},{5,12,8},{0,12,54},{8,4,32},{0,11,4},{4,0,91},{11,7,64},{6,3,88},{8,5,80},{11,10,91},{10,0,60},{8,7,92},{12,6,78},{6,2,8},{4,3,54},{3,11,76},{3,12,23},{11,6,79},{6,12,36},{2,11,100},{2,5,49},{7,0,17},{5,8,95},{3,9,98},{8,10,61},{2,12,38},{5,7,58},{9,4,37},{8,6,79},{9,0,1},{2,3,12},{7,10,7},{12,10,52},{7,2,68},{12,2,100},{6,9,53},{7,4,90},{0,5,43},{11,2,52},{11,8,50},{12,4,38},{7,9,94},{2,7,38},{3,7,88},{9,12,20},{12,0,26},{10,5,38},{12,8,50},{0,2,77},{11,0,13},{9,10,76},{2,6,67},{5,6,34},{9,7,62},{5,3,67}};
  src = 10;
  dst = 1;
  int k = 10;
  res2 = sol.findCheapestPrice(n, flights, src, dst, k);

  return 0;
}