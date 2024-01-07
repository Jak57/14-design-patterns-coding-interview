# https://leetcode.com/problems/subsets-ii/
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        subsets = [[]]
        nums = sorted(nums)
        for i, n in enumerate(nums):
            tmp = []
            if i > 0 and nums[i] == nums[i-1]:
                #tmp = []
                for item in subsets:
                    if not(item + [n] in subsets):
                        tmp.append(item + [n])
            else:
                for item in subsets:
                    tmp.append(item + [n])
            subsets += tmp
        return subsets
                
        
