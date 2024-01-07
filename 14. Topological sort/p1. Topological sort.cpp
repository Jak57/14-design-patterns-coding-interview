// https://www.geeksforgeeks.org/problems/topological-sort/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    int i, j, n, m, node;
	    n = adj[0].size();
	    m = adj[0].size();
	    
	    int indegree[10005];
	    memset(indegree, 0, sizeof(indegree));
	    
	    for (i = 0; i < V; i++) {
	        for (j = 0; j < adj[i].size(); j++) {
	            node = adj[i][j];
	            indegree[node]++;
	        }
	    }

	   queue<int> q;
        for (i = 0; i < V; i++) {
          if (indegree[i] == 0) 
          {
              q.push(i);
          }
        }
        
        while (!q.empty()) {
            node = q.front();
            q.pop();
            ans.push_back(node);
            
            for (i = 0; i < adj[node].size(); i++) {
                int child = adj[node][i];
                if (--indegree[child] == 0)
                    q.push(child);
            }
        }
	    
	    return ans;
	}
};
