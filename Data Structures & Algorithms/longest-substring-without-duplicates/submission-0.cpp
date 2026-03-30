class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> mp;
        int left = 0, right = 0;
        while(right < n) {
            mp[s[right]]++;
            while(mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
