
#include <vector>
#include <deque>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
private:
  int m = 0, n = 0;

void eraseIsland(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';
    eraseIsland(grid, i + 1, j);
    eraseIsland(grid, i - 1, j);
    eraseIsland(grid, i, j + 1);
    eraseIsland(grid, i, j - 1);
}

public:
  int numIslands(vector<vector<char>>& grid) {
    m = grid.size();
    if (m == 0) return 0;
    n = grid[0].size();

    int num_islands = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
            eraseIsland(grid, i, j);
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