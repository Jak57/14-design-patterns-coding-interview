// https://leetcode.com/problems/path-sum-ii/
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
    vector<vector<int>> ans;
    
    void dfs(TreeNode* root, vector<int> path, int target) {
        if (root == NULL)
            return;
        
        path.push_back(root->val);
        target -= root->val;
        
        if (root->left == NULL && root->right == NULL) {
            if (target == 0)
                ans.push_back(path);
        }
        
        if (root->left != NULL)
            dfs(root->left, path, target);
        
        if (root->right != NULL)
            dfs(root->right, path, target);
        
        path.pop_back();
            
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int n, i, j;
        vector<int> path;
        dfs(root, path, targetSum);
        
        return ans;
    }
};
