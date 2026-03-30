class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        for(int i=0;i<n;i++) {
            int val = nums[i];
            int curr = 0;
            while(mp.find(val) != mp.end()) {
                curr++;
                val++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
