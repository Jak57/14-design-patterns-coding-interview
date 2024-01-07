// https://leetcode.com/problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n, i, j, pos = 0;
        n = nums.size();
        nums.push_back(-1);
        
        while (pos <= n) {
            if ((nums[pos] > 0 && nums[pos] <= n) && (nums[pos] <= n && nums[pos] != nums[nums[pos]])) {
                int tmp = nums[pos];
                nums[pos] = nums[tmp];
                nums[tmp] = tmp;
            } else
                pos++;
        }
        
        for (i = 1; i <= n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n+1;
    }
};
