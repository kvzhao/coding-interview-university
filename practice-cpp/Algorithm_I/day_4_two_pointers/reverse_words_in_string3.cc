
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string reverseWords(string s) {

        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] != ' ') {
                size_t j = i + 1;
                // find next space
                for (; j < s.length() && s[j] != ' '; ++j) {}

                reverse(s.begin() + i, s.begin() + j);

                // jump
                i = j;
            }
        }

        return s;
    }
};

int main() {

    Solution sol;
    string  s = "Let's take LeetCode contest";
    string ans = "s'teL ekat edoCteeL tsetnoc";
    string ret = sol.reverseWords(s);

    if (ret == ans) {
        cout << "pass\n";
    } else {
        cout << "failed, " << ret << "\n";
    }

    return 0;
}