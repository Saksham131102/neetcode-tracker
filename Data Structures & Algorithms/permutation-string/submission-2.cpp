class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Fixed Sliding Window Problem
        unordered_map<char, int> mp1, mp2;
        for(char ch : s1)
            mp1[ch]++;
        int n = s1.size();
        int left = 0, right = 0;
        while(right < s2.size()) {
            mp2[s2[right]]++;
            if(right - left + 1 > n) {
                mp2[s2[left]]--;
                if(mp2[s2[left]] == 0)
                    mp2.erase(s2[left]);
                left++;
            }
            if(mp1 == mp2)
                return true;
            right++;
        }
        return false;
    }
};
