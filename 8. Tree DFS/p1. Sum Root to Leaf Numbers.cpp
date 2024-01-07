// https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    int sumNumbers(TreeNode* root) {
        int val, sum = 0;
        
        if (root->left == NULL && root->right == NULL)
            return root->val;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            
            if (cur->left == NULL && cur->right == NULL) {
                sum += cur->val;
            }
            
            val = cur->val;
            if (cur->right != NULL) {
                cur->right->val = val*10 + cur->right->val;
                st.push(cur->right);
            }
            
            if (cur->left != NULL) {
                cur->left->val = val*10 + cur->left->val;
                st.push(cur->left);
            }
        }
        return sum;
    }
};
