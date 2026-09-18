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
    void solve(TreeNode* &root, int &k, int &val) {
        // base case
        if(root == nullptr)
            return;
        // recursive relation
        solve(root->left, k, val);
        k--;
        if(k == 0)
            val = root->val;
        solve(root->right, k, val);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int val = -1;
        solve(root, k, val);
        return val;
    }
};
