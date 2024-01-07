// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int i, j, n, val;
        map<int, int> mp;
        vector<int> ans;
        n = nums.size();
        
        for (i = 0; i < n; i++) {
            val = nums[i];
            if (mp.find(val) == mp.end()) 
                mp[val] = 1;
            else
                mp[val] += 1;
        }

        priority_queue< pair<int, int> > pq;
        for (auto i: mp) {
            pq.push(make_pair(i.second, i.first));
        }
        
        int cnt = k;
        while (!pq.empty() && cnt > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            cnt--;
        }
        
        return ans;
    }
};

