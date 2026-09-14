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
    void solve(TreeNode* &root, int depth, int &maxDepth) {
        // base case
        if(root == nullptr)
            return;
        // recursive relation
        maxDepth = max(maxDepth, depth);
        solve(root->left, depth + 1, maxDepth);
        solve(root->right, depth + 1, maxDepth);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int maxDepth = 1;
        solve(root, 1, maxDepth);
        return maxDepth;
    }
};
