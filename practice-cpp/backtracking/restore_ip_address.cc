
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;

        return ret;
    }
};



int main() {
    string s = "25525511135";
    // Output: ["255.255.11.135","255.255.111.35"]
    Solution sol;
    vector<string> ret = sol.restoreIpAddresses(s);

    return 0;
}