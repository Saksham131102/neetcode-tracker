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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* t = root;

        while(t != nullptr) {
            st.push(t);
            t = t->left;
        }
        
        while(!st.empty()) {
            auto node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right) {
                node = node->right;
                while(node != nullptr) {
                    st.push(node);
                    node = node->left;
                }  
            }
        }
        
        return ans;
    }
};