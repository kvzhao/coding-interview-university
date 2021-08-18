#include <set>
#include <deque>
#include <vector>
#include <iostream>
#include <utility>

using std::vector;
using std::deque;
using std::pair;
using std::set;
using std::make_pair;
using std::cout;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

      if (grid[0][0] != 0) {
        return -1;
      }

      int n = grid.size();
      int max_row = n - 1, max_col = n - 1;
      // BFS: walk from upper-left to bottom-right

      deque<pair<int, int>> queue;
      vector<vector<bool>> visited(n, vector<bool>(n, false));
      vector<pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

      queue.push_back(make_pair(0, 0));
      visited[0][0] = true;

      int path_length = 0;
      while (!queue.empty()) {

        int num_neighbors = queue.size();
        path_length++;

        for (int i = 0; i < num_neighbors; i++) {
          auto site = queue.front();
          int row = site.first, col = site.second;
          queue.pop_front();

          if (row == max_row and col == max_col) {
            return path_length;
          }

          for (auto [dr, dc]: directions) {
            int new_row = row + dr;
            int new_col = col + dc;

            // skip invalid
            if (!(new_row >= 0 and new_row <= max_row and new_col >= 0 and new_col <= max_col)) continue;

            // add new neigobor sites
            if (grid[new_row][new_col] == 0 and !visited[new_row][new_col]) {
              queue.push_back(make_pair(new_row, new_col));
              visited[new_row][new_col] = true;
            }
          }
        }
      }
        
      return -1;
    }
};

int main() {
  Solution sol;

  vector<vector<int>> grid{
    vector<int>{0, 0, 0},
    vector<int>{1, 1, 0},
    vector<int>{1, 1, 0}
  };

  int ans = 4;

  int res = sol.shortestPathBinaryMatrix(grid);
  if (res == ans) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << res << "\n";
  }

  return 0;
}