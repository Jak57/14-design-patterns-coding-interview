# https://leetcode.com/problems/subsets/
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        subsets = [[]]
        for num in nums:
            subsets = (subsets + [item + [num] for item in subsets])
        return subsets
