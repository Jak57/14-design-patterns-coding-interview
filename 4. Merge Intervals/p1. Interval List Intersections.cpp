// https://leetcode.com/problems/interval-list-intersections/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n, m, a1, a2, b1, b2, i, j, mx;
        vector<vector<int>> ans;
        n = firstList.size();
        m = secondList.size();
        
        if (n == 0 || m == 0) 
            return ans;

        i = 0;
        j = 0;
        while (i < n && j < m) {
            a1 = firstList[i][0];
            a2 = firstList[i][1];
            b1 = secondList[j][0];
            b2 = secondList[j][1];
            
            mx = max(a2, b2);
            if (a2 < b1 || b2 < a1) {
                if (a2 == mx) 
                    j++;
                else 
                    i++;
                continue;
            }
            
            vector<int> tmp = {max(a1, b1), min(a2, b2)};
            ans.push_back(tmp);
            if (a2 == mx)
                j++;
            else
                i++;
        }
        
        return ans;
    }
};
