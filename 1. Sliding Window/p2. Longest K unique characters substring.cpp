// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int i, j, n, fast, slow, mx = -1;
    char ch, ch2;
    unordered_map<char, int> dic;
    n = s.size();
    
    slow = 0;
    fast = 0;
    while (fast < n) {
        ch = s[fast];
        if (dic.find(ch) == dic.end()) {
            dic[ch] = 1;
        } else {
            dic[ch] += 1;
        }
        
        if (dic.size() > k) {
            mx = max(mx, fast-slow);
            while (dic.size() > k) {
                ch2 = s[slow];
                dic[ch2]--;
                if (dic[ch2] == 0) {
                    dic.erase(ch2);
                }
                slow++;
            }
        }
        fast++;
    }
    
    if (dic.size() == k)
        mx = max(mx, fast-slow);
    return mx;
    
    }
};
