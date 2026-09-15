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


// Tree is a BST (Binary Search Tree)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            swap(p, q);
        
        while(root != nullptr) {
            if(p->val <= root->val && root->val <= q->val)
                return root;
            if(q->val < root->val)
                root = root->left;
            else if(p->val > root->val)
                root = root->right;
        }

        return nullptr;
    }
};
