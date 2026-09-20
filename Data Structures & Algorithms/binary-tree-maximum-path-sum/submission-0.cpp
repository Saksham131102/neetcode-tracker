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
    int solve(TreeNode* &root, int &maxSum) {
        // base case
        if(root == nullptr)
            return 0;
        // recursive relation
        int leftSum = solve(root->left, maxSum);
        int rightSum = solve(root->right, maxSum);

        maxSum = max(maxSum, root->val + leftSum + rightSum);
        return max(0, root->val + max(leftSum, rightSum));
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};
