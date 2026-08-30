class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(char ch : t)
            mp[ch]++;
        int start = 0, end = 0;
        int minLength = INT_MAX;
        int begin = 0;
        int required = t.size();
        while(end < n) {
            if(mp[s[end]] > 0)
                required--;
            mp[s[end]]--;
            while(required == 0) {
                if(end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    begin = start;
                }
                mp[s[start]]++;
                if(mp[s[start]] > 0)
                    required++;
                start++;
            }
            end++;
        }
        return minLength == INT_MAX ? "" : s.substr(begin, minLength);
    }
};
