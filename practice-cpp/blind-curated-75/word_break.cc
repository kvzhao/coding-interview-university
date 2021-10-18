
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Given a string s and a dictionary of strings wordDict,
// return true if s can be segmented into a space-separated sequence of one or more dictionary words.


// BF method O(2^n): https://leetcode.com/problems/word-break/discuss/169383/The-Time-Complexity-of-The-Brute-Force-Method-Should-Be-O(2n)-and-Prove-It-Below

class Solution {
private:

    bool wordBreakBFS(string s, vector<string>& wordDict) {
        // BFS solution
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        // search for substr (start, end) which found in set
        // starting index
        queue<int> q;
        vector<bool> visited(s.length(), false);
        q.push(0);

        while (!q.empty()) {

            int start = q.front();
            q.pop();

            if (visited[start]) continue;

            // (start, end) are index pair, end-start => length
            for (int end = start + 1; end <= s.length(); ++end) {
                if (wordSet.find(s.substr(start, end - start)) != wordSet.end()) {
                    q.push(end);
                    if (end == s.length()) {
                        return true;
                    }
                }
            }
            visited[start] = true;
        }
        return false;
    }

    bool wordBreakDP(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);

        dp[0] = true;
        for (int end = 1; end <= s.length(); ++end) {
            for (int start = 0; start < end; ++start) {
                if (dp[start] and 
                    wordSet.find(s.substr(start, end - start)) != wordSet.end()) {
                        dp[end] = true;
                        break;
                    }
            }
        }

        //for ( int i =0; i < dp.size(); ++i) {
        //    cout << dp[i] << " ";
        //}
        //cout << "\n";

        return dp[s.length()];
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreakDP(s, wordDict);
    }
};



int main() {

    string s;
    vector<string> wordDict;
    bool ret;
    Solution sol;

    // Input: s = "applepenapple", wordDict = ["apple","pen"]
    // Output: true
    s = "applepenapple";
    wordDict = {"apple", "pen"};
    ret = sol.wordBreak(s, wordDict);
    if (!ret) cout << "failed\n";
    else cout <<"passed\n";

    //Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    // Output: false
    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    ret = sol.wordBreak(s, wordDict);
    if (ret) cout << "failed\n";
    else cout <<"passed\n";

    return 0;
}