#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
};

int main() {

    vector<char> ret = {'h','e','l','l','o'};
    vector<char> ans = {'o', 'l', 'l', 'e', 'h'};

    Solution sol;
    sol.reverseString(ret);

    if (ret.size() != ans.size()) {
        cout << "failed\n";

    } else {
        bool passed = true;
        for (size_t i = 0; i < ans.size(); ++i) {
            if (ret[i] != ans[i]) {
                passed = false;
                break;
            }
        }
        if (passed) {
            cout << "passed\n";
        } else {
            cout << "failed, ";
            for (size_t i = 0; i < ret.size(); ++i) cout << ret[i] << " ";
            cout << "\n";
        }
    }

    return 0;
}