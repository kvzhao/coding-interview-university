
#include <deque>
#include <vector>
#include <iostream>
#include <utility>

using std::vector;
using std::deque;
using std::pair;
using std::make_pair;
using std::cout;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int max_row = n - 1, max_col = m - 1;
        deque<pair<int, int>> queue;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> directions{
          {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int total_fresh_orange = 0;
        // init queue
        for(int i =0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
              queue.push_back(make_pair(i, j));
            } else if (grid[i][j] == 1) {
              total_fresh_orange ++;
            }
          }
        }

        if (total_fresh_orange == 0) {
          return 0;
        }

        int time_elapsed = -1;
        while (!queue.empty()) {
          time_elapsed++;
          int num_fresh = queue.size();

          while (num_fresh > 0) {
            num_fresh--;
            int row = queue.front().first;
            int col = queue.front().second;
            queue.pop_front();

            for (auto [dr, dc]: directions) {
              int new_row = row + dr;
              int new_col = col + dc;

              // skip invalid
              if (!(new_row >=0 and new_row <= max_row and new_col >= 0 and new_col <= max_col)) {
                continue;
              }

              if (grid[new_row][new_col] == 1 and !visited[new_row][new_col]) {
                queue.push_back(make_pair(new_row, new_col));
                visited[new_row][new_col] = true;
                total_fresh_orange--;
              }
            }
          }
        }

        if (total_fresh_orange == 0) {
          return time_elapsed;
        } 
        return -1;
    }
};

int main() {
  Solution sol;

  vector<vector<int>> grid{
    {2, 1, 1},
    {1, 1, 0},
    {0, 1, 1}
  };
  int ans = 4;

  auto res = sol.orangesRotting(grid);
  if (res == ans) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << res << "\n";
  }

  return 0;
}