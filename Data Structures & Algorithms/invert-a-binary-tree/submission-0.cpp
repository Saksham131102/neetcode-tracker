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
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == nullptr)
            return nullptr;
        q.push(root);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            TreeNode* nodeLeft = node->left;
            TreeNode* nodeRight = node->right;
            node->left = nodeRight;
            node->right = nodeLeft;
            if(nodeLeft)
                q.push(nodeLeft);
            if(nodeRight)
                q.push(nodeRight);
        }
        return root;
    }
};
