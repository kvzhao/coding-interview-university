
#include <vector>
#include <iostream>
using namespace std;


// Given an m x n matrix, return all elements of the matrix in spiral order.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        return {};
    }
};


int main() {

    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = {1,2,3,6,9,8,7,4,5};
    auto ret = sol.spiralOrder(matrix);

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