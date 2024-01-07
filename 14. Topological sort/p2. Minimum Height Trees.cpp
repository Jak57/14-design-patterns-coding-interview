// https://leetcode.com/problems/minimum-height-trees/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int i, j, u, v, size, front_, child;
        vector<int> adj[20005];
        int degree[20005];
        vector<int> ans;
        memset(degree, 0, sizeof(degree));
        
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        
        for (i = 0; i < n-1; i++) {
            u = edges[i][0];
            v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            degree[u]++;
            degree[v]++;
        }
        
        queue<int> q;
        for (i = 0; i < n; i++) {
            if (degree[i] == 1) 
                q.push(i);
        }
        
        while (n > 2) {
            size = q.size();
            n -= size;
            
            while (size) {
                front_ = q.front();
                q.pop();
                for (j = 0; j < adj[front_].size(); j++) {
                    child = adj[front_][j];
                    degree[child] -= 1;
                    if (degree[child] == 1) {
                        q.push(child);
                    }
                }
                size--;
            }
        }
        
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};
