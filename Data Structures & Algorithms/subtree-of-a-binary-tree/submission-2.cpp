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
    bool sameTree(TreeNode* &p, TreeNode* &q) {
        // base case
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr && q != nullptr || p != nullptr && q == nullptr)
            return false;
        if(p->val != q->val)
            return false;
        bool leftSubTree = sameTree(p->left, q->left);
        bool rightSubTree = sameTree(p->right, q->right);
        return leftSubTree && rightSubTree;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base case
        if(root == nullptr)
            return false;
        // recursive relation
        if(root->val == subRoot->val && sameTree(root, subRoot))
            return true;
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left || right;
    }
};
