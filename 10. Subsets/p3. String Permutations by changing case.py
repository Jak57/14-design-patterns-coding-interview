# https://leetcode.com/problems/letter-case-permutation/

class Solution(object):
    def letterCasePermutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        subsets = [s]
        
        for i, ch in enumerate(s):
            tmp = []
            if ch.isalpha():
                for item in subsets:
                    tmp2 = list(item)
                    
                    if ch >= 'a' and ch <= 'z':
                        tmp2[i] = chr(ord(ch) - ord('a')+ord('A'))
                    elif ch >= 'A' and ch <= 'Z':
                        tmp2[i] = chr(ord(ch) - ord('A')+ord('a'))
                    tmp.append("".join(tmp2))
            subsets += tmp
        return subsets
