
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/*
  Given two strings text1 and text2, return the length of their longest common subsequence.
  If there is no common subsequence, return 0.
  A subsequence of a string is a new string generated from the original string with some characters (can be none)
  deleted without changing the relative order of the remaining characters.
  * For example, "ace" is a subsequence of "abcde".
  A common subsequence of two strings is a subsequence that is common to both strings.

*/


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
      return -1;
    }
};


int main() {

  Solution sol;
  vector<tuple<int, string, string>> problems = {
      {3, "abcde", "ace"},
      {3, "abc", "abd"},
      {0, "abc", "def"}
  };

  for (auto &[ans, t1, t2] : problems) {
    auto ret = sol.longestCommonSubsequence(t1, t2);
    if (ans == ret) {
      cout << "Passed\n";
    } else {
      cout << "Failed, " << ret << "\n";
    }
  }

  return 0;
}