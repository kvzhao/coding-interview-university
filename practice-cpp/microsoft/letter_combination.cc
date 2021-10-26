
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty()) {
            return ret;
        }

        // How to use BFS to solve this?
        vector<string> words{
            " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };


        return ret;
    }
};

int main() {

    string digits = "23";
    vector<string> results;
    Solution sol;
    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    results = sol.letterCombinations(digits);
    for (auto r : results) {
        cout << r << " ";
    }
    cout << "\n";

    return 0;
}