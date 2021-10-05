
#include <vector>
#include <deque>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();

    const vector<vector<int>> neighbors = {
      {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int num_islands = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          // start depth-first searching from here
          deque<pair<int, int>> q;
          q.push_back(make_pair(i, j));
          while(!q.empty()) {
            auto current = q.front();
            q.pop_front();
            int x = current.first, y = current.second;

            grid[x][y] = '0';

            for (auto next : neighbors) {
              int new_x = x + next[0];
              int new_y = y + next[1];
              if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == '1') {
                q.push_back(make_pair(new_x, new_y));
              }
            }
          }
          // Done search, #islands increment
          num_islands++;
        }
      }
    }

    return num_islands;
  }
};


int main() {

  /*
    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
    You may assume all four edges of the grid are all surrounded by water.

    constraints
      m == grid.length
      n == grid[i].length
      1 <= m, n <= 300
      grid[i][j] is '0' or '1'.
  */

  int ans = 0, ret = 0;
  vector<vector<char>> grid;
  Solution sol;

  grid = {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
  };
  ans = 1;

  ret = sol.numIslands(grid);
  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << ret << "\n";
  }

  grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
  };
  ans = 3;

  ret = sol.numIslands(grid);
  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << ret << "\n";
  }

  return 0;
}