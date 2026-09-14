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

class Solution {
private:
    vector<int> solve(TreeNode* &root) {
        // base case
        if(root == nullptr)
            return {1, 0};
        // recursive relation
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        bool isBalanced = (left[0] == 1 && right[0] == 1 && abs(left[1] - right[1]) <= 1);
        int height = 1 + max(left[1], right[1]);
        return {isBalanced ? 1 : 0, height};
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root)[0] == 1;
    }
};
