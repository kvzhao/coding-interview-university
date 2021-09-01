
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
using std::abs;
using std::max;

// avoid using tuple
class Site {
public:
  Site(int x, int y, int diff) : x(x), y(y), diff(diff) {}
  int x = 0;
  int y = 0;
  int diff = 0;
};

struct Comparator {
  bool operator() (const Site& s1, const Site& s2) {
    return s1.diff > s2.diff;
  }
};

class Solution {
public:
    bool isValid(int x, int y, int row, int col) {
      if (x >= 0 and x < row and y >=0 and y < col)
        return true;
      return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
      const int inf = 1e9;
      vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      int row = heights.size(), col = heights[0].size();
      vector<vector<int>> diffMatrix(row, vector<int>(col, inf));
      vector<vector<bool>> visited(row, vector<bool>(col, false));

      priority_queue<Site, vector<Site>, Comparator> pq;
      pq.push(Site(0, 0, 0));
      diffMatrix[0][0] = 0;
      visited[0][0] = true;

      while (!pq.empty()) {

        Site current = pq.top();
        pq.pop();

        // traverse adjacent
        for (auto [dx, dy] : directions) {
          int nx = current.x + dx;
          int ny = current.y + dy;
          visited[current.x][current.y] = true;

          if (isValid(nx, ny, row, col) and !visited[nx][ny]) {

            int currentDiff = abs(heights[nx][ny] - heights[current.x][current.y]);
            int maxDiff = max(currentDiff, diffMatrix[current.x][current.y]);

            if (diffMatrix[nx][ny] > maxDiff) {
              diffMatrix[nx][ny] = maxDiff;
              pq.push(Site(nx, ny, maxDiff));
            }
          }
        }
      }
      return diffMatrix[row - 1][col - 1];
    }
};


int main() {

  Solution sol;

  vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
  int ans = 2;

  int ret = sol.minimumEffortPath(heights);
  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Faield, " << ret << "\n";
  }

  heights = {{1,2,3},{3,8,4},{5,3,5}};
  ans = 1;
  ret = sol.minimumEffortPath(heights);
  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Faield, " << ret << "\n";
  }
  heights = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
  ans = 0;
  ret = sol.minimumEffortPath(heights);
  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Faield, " << ret << "\n";
  }

  return 0;
}