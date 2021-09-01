
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::pair;
using std::make_pair;
using std::cout;
using std::priority_queue;
using std::greater;
using std::abs;


class Solution {
private:

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      int n = points.size();

      // pair: (n-th point, distance)
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      vector<bool> visited(n, false);

      for (int i = 1; i < n; ++i) {
        int dist = abs(points[i][0] - points[0][0]) + abs(points[i][1] - points[0][1]);
        pq.push(make_pair(dist, i));
      }
      visited[0] = true;
    
      int min_cost = 0;

      while (!pq.empty()) {
        int current = pq.top().second;

        // Kinda BFS nature, so skip visited first
        if (visited[current]) {
          pq.pop();
          continue;
        }

        int cost = pq.top().first;
        min_cost += cost;
        pq.pop();
        visited[current] = true;

        for (int i = 0; i < n; ++i) {
          if (!visited[i]) {
            int dist = abs(points[i][0] - points[current][0]) + abs(points[i][1] - points[current][1]);
            pq.push(make_pair(dist, i));
          }
        }
      }

      return min_cost;
    }
};


int main() {

  vector<vector<int>> points {
    {0,0},{2,2},{3,10},{5,2},{7,0}};
  int ans = 20;

  Solution sol;
  int res = sol.minCostConnectPoints(points);

  if (res == ans) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << res << "\n";
  }

  return 0;

}