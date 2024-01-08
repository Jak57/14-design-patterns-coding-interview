// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> dic1, dic2;
        vector<int> ans;
        
        int i, j, n, m, slow, fast;
        char ch, ch_slow, ch_fast;
        n = s.size();
        m = p.size();
        
        if (m > n)
            return ans;
        
        for (i = 0; i < m; i++) {
            ch = s[i];
            if (dic1.find(ch) == dic1.end()) {
                dic1[ch] = 1;
            } else
                dic1[ch] += 1;
        }
        
        for (i = 0; i < m; i++) {
            ch = p[i];
            if (dic2.find(ch) == dic2.end()) {
                dic2[ch] = 1;
            } else
                dic2[ch] += 1;
        }
        
        for (slow = 0; slow <= n-m; slow++) {
            if (dic1 == dic2)
                ans.push_back(slow);
                
            fast = slow + m;
            if (fast == n)
                continue;
            
            ch_slow = s[slow];
            ch_fast = s[fast];
            
            dic1[ch_slow]--;
            if (dic1[ch_slow] == 0)
                dic1.erase(ch_slow);
            
            if (dic1.find(ch_fast) == dic1.end())
                dic1[ch_fast] = 1;
            else
                dic1[ch_fast]++;
        }
        
        return ans;
    }
};
