#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      string ret = "";
        
      return ret;
    }
};


int main() {
  string s, ans, ret;
  vector<vector<int>> pairs;
  Solution sol;

  s = "dcab", pairs = {{0,3},{1,2}};
  ans = "bacd";
  ret = sol.smallestStringWithSwaps(s, pairs);
  if (ans != ret)
    cout << "Failed " << ret << "\n";
  else
    cout << "Passed\n";

  s = "dcab", pairs = {{0,3},{1,2},{0,2}};
  ans = "abcd";
  ret = sol.smallestStringWithSwaps(s, pairs);
  if (ans != ret)
    cout << "Failed " << ret << "\n";
  else
    cout << "Passed\n";

  s = "dcab", pairs = {{0,3},{1,2},{0,2}};
  ans = "abc";
  ret = sol.smallestStringWithSwaps(s, pairs);
  if (ans != ret)
    cout << "Failed " << ret << "\n";
  else
    cout << "Passed\n";

  return 0;
}