// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
struct Node {
    long sum;
    int x, y;
};

class cmp {
public:
    bool operator()(Node a, Node b) {
        return a.sum > b.sum;
    }
};

class Solution {
public:
    bool limit(int i, int j, int n, int m) {
        return ((i >= 0 && i < n) && (j >= 0 && j < m));
    }
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node, vector<Node>, cmp> pq;
        vector<vector<int>> ans;
        int i, j;
        int n, m;
        
        n = nums1.size();
        m = nums2.size();
        
        Node node;
        node.sum = long(nums1[0]) + long(nums2[0]);
        node.x = 0;
        node.y = 0;
        pq.push(node);
        
        set<pair<int, int>> s;
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        s.insert(p);
        
        while (!pq.empty() && k > 0) {
            Node tmp = pq.top();
            pq.pop();
            vector<int> idx;
            i = tmp.x;
            j = tmp.y;
            
            idx.push_back(nums1[tmp.x]);
            idx.push_back(nums2[tmp.y]);
            ans.push_back(idx);
            pair<int, int> p1;
            p1.first = i+1;
            p1.second = j;
            
            if (limit(i+1, j, n, m) && (s.find(p1) == s.end())) {
                Node temp2;
                temp2.sum = long(nums1[i+1]) + long(nums2[j]);
                temp2.x = i+1;
                temp2.y = j;
                pq.push(temp2);
                s.insert(p1);
            }
            
            pair<int, int> p2;
            p2.first = i;
            p2.second = j+1;
            
            if (limit(i, j+1, n, m) && (s.find(p2) == s.end())) {
                Node temp2;
                temp2.sum = long(nums1[i]) + long(nums2[j+1]);
                temp2.x = i;
                temp2.y = j+1;
                pq.push(temp2);
                s.insert(p2);
            }
            k--;
        }
        return ans;
        
    }
};
