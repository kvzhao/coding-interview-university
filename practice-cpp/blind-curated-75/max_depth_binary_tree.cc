
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 #include <iostream>
 #include <vector>
 #include <deque>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {

    // recursive method
    int dfs(TreeNode* node) {

        // base case
        if (node == nullptr)
            return 1;

        int left = 0, right = 0;

        if (node->left != nullptr)
            left = dfs(node->left);
        if (node->right != nullptr)
            right = dfs(node->right);

        return 1 + max(left, right);

    }

public:
    int maxDepth(TreeNode* root) {

        if (root == nullptr)
            return 0;

        return dfs(root);
    }
};


int main() {

    //Input: root = [3,9,20,null,null,15,7]
    //Output: 3
    // Build the tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int ans = 3, ret = 0;
    Solution sol;

    ret = sol.maxDepth(root);
    if (ans != ret) cout << "failed" << ", " << ret << "\n";
    else cout << "passed\n";

    return 0;
}