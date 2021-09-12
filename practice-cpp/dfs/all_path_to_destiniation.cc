

#include <vector>
#include <utility>
#include <iostream>

using std::vector;
using std::cout;

class Solution {
public:
    // all path from source lead to destiniation
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {

        return true;
    }
};


int main() {

  Solution sol;

  int n = 3;
  vector<vector<int>> edges = {{0,1},{0,2}};
  int source = 0, destination = 2;
  bool ans = false;
  bool ret = sol.leadsToDestination(n, edges, source, destination);
  if (ans == ret)
    cout << "Passed\n";
  else
    cout << "Failed\n";

  n = 4, edges = {{0,1},{0,3},{1,2},{2,1}}, source = 0, destination = 3, ans = false;
  ret = sol.leadsToDestination(n, edges, source, destination);
  if (ans == ret)
    cout << "Passed\n";
  else
    cout << "Failed\n";
  n = 4, edges = {{0,1},{0,2},{1,3},{2,3}}, source = 0, destination = 3, ans = true;
  ret = sol.leadsToDestination(n, edges, source, destination);
  if (ans == ret)
    cout << "Passed\n";
  else
    cout << "Failed\n";
  n = 3, edges = {{0,1},{1,1},{1,2}}, source = 0, destination = 2, ans = false;
  ret = sol.leadsToDestination(n, edges, source, destination);
  if (ans == ret)
    cout << "Passed\n";
  else
    cout << "Failed\n";
  n = 2, edges = {{0,1},{1,1}}, source = 0, destination = 1, ans = false;
  ret = sol.leadsToDestination(n, edges, source, destination);
  if (ans == ret)
    cout << "Passed\n";
  else
    cout << "Failed\n";

  return 0;
}