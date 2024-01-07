// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int i, j, n = nums.size(), val;
        for (i = 0; i < k; i++)
            pq.push(-nums[i]);
        
        for (i = k; i < n; i++) {
            val = nums[i];
            if (val > -pq.top()) {
                pq.pop();
                pq.push(-val);
            }
        }
        return -pq.top();
    }
};
