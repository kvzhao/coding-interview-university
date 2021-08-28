
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::unordered_map;
using std::unordered_set;
using std::min;
using std::abs;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
      // x-coord: [ys coordindates]
      unordered_map<int, unordered_set<int>> hashmap;

      for (const auto& point : points) {
        hashmap[point[0]].insert(point[1]);
      }

      int min_area = INT_MAX;

      for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
          int x1 = points[i][0], y1 = points[i][1];
          int x2 = points[j][0], y2 = points[j][1];


          if (x1 != x2 && y1 != y2) {
            
            if (hashmap[x1].find(y2) != hashmap[x1].end() && 
                hashmap[x2].find(y1) != hashmap[x2].end()) {
                // form a rectangle
                min_area = min(min_area, abs((y1 - y2) * (x1 - x2)));
            }
          }
        }
      }

      return min_area == INT_MAX ? -1 : min_area; 
    }
};


int main() {

  vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3},{2,2}};

  Solution sol;
  auto ret = sol.minAreaRect(points);
  cout << ret << "\n";

  points = {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}};
  ret = sol.minAreaRect(points);
  cout << ret << "\n";

  return 0;
}