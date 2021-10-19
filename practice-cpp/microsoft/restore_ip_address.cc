
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    string valid_ip;
    vector<string> result;

    bool is_valid(string s, int start, int end) {
        if (s[start] == '0' && start != end) {
            return false;
        }
        string tmp = s.substr(start, end - start + 1);
        int ip = stoi(tmp);
        if (ip >= 0 && ip <= 255) {
            return true;
        }
        return false;
    }

    // Need understand more about backtracking algorithm
    void backtracking(string s, int start, int segment) {
        // cout << "current ip: " << valid_ip << " start " << start << ", segment "<< segment << "\n";

        if (start == s.size() && segment == 4) {
            // cout << "valid found\n";
            result.emplace_back(valid_ip);
            return; 
        }

        for (int end = start; end < s.size(); ++end) {
            if (segment < 4 && end - start < 3 && is_valid(s, start, end)) {

                valid_ip += s.substr(start, end - start + 1);

                ++segment;
                if (segment < 4) valid_ip.push_back('.');

                backtracking(s, end + 1, segment);

                if (segment < 4) valid_ip.pop_back();
                --segment;

                for (int j = 0; j < end - start + 1; ++j) {
                    valid_ip.pop_back();
                }
            }
        }

    }

public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return result;
    }
};



int main() {
    string s = "25525511135";
    // Output: ["255.255.11.135","255.255.111.35"]
    Solution sol;
    vector<string> ret = sol.restoreIpAddresses(s);
    for (auto s : ret) {
        cout << s << "\n";
    }

    return 0;
}