// https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int depth, i, j, mx = 0, val;
        if (root == NULL) 
            return ans;
        
        queue<TreeNode*> q;
        vector< pair<int,int>> store;
        store.push_back({root->val, 0});
        
        root->val = 0;
        q.push(root);
        
        
        while (!q.empty()) {
            TreeNode* cur = q.front();
            depth = cur->val;
            mx = max(mx, depth);
            q.pop();
            
            if (cur->left != NULL) {
                store.push_back({cur->left->val, depth+1});
                cur->left->val = depth+1;
                q.push(cur->left);
            }
            if (cur->right != NULL) {
                store.push_back({cur->right->val, depth+1});
                cur->right->val = depth+1;
                q.push(cur->right);
            }
        }
        
        vector<vector<int>> ans1(depth+1);
        for (i = 0; i < store.size(); i++) 
        {
            depth = store[i].second;
            val = store[i].first;
            if (depth%2 == 1) 
                ans1[depth].push_back(val);
            else
                ans1[depth].push_back(val);
        }
        
        return ans1;
    }
};

