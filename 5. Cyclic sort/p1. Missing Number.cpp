// https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n, i, j, pos = 0, val, tmp;
        n = nums.size();
        
        while (pos < n) {
            val = nums[pos];
            if (nums[pos] < n && nums[pos] != nums[nums[pos]]) {
                tmp = nums[pos];
                nums[pos] = nums[val];
                nums[val] = tmp;
            } else
                pos++;
        }
        
        for (i = 0; i < n; i++) {
            if (nums[i] != i)
                return i;
        }
        return n;
    }
};
