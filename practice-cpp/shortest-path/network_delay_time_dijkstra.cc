

#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::greater;
using std::cout;
using std::max_element;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      const int inf = 1e9;
      vector<vector<pair<int, int>>> graph(n + 1);
      vector<int> dist(n + 1, inf);
      // build graph
      for(const auto& t : times) {
        // from, to, cost
        graph[t[0]].emplace_back(make_pair(t[1], t[2]));
      }
      dist[k] = 0;
      
      priority_queue<pair<int, int>,
                     vector<pair<int, int>>,
                     greater<pair<int, int>>> pq;
      // (dist, node)
      pq.push(make_pair(0, k));

      while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int u = p.second;

        for (auto [v ,w] : graph[u]) {
          if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            pq.push(make_pair(dist[v], v));
          }
        }
      }

      int ans = *max_element(dist.begin() + 1, dist.end());

      return ans == inf ? -1 : ans;
        
      return -1;
    }
};


int main() {
  Solution sol;

  vector<vector<int>> times{{2,1,1}, {2,3,1}, {3,4,1}};
  int n = 4, k = 2;
  const int ans = 2;

  auto res = sol.networkDelayTime(times, n, k);

  if (res == ans) {
    cout << "Pass\n";
  } else {
    cout << "Failed, " << res << "\n";
  }

  return 0;
}