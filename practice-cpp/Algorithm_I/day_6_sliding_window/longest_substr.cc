#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

// Given a string s, find the length of the longest substring without repeating characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int max_length = 0;
        int window_start = 0, window_end = 0;
        int n = s.length();

        while (window_end < n && window_start < n) {
            if (set.find(s[window_end]) != set.end()) {
                // found
                set.erase(s[window_start++]);
            } else {
                set.insert(s[window_end++]);
                max_length = max(max_length, window_end - window_start);
            }
        }
        
        return max_length;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    int ans = 3;
    int ret;
    ret = sol.lengthOfLongestSubstring(s);

    if (ret == ans) {
        cout << "pass\n";
    } else {
        cout << "failed, " << ret << "\n";
    }
    return 0;
}

