class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            int curr = 1;
            int val = nums[i];
            while(mp.find(val-1) != mp.end()) {
                curr++;
                val--;
            }
            val = nums[i];
            while(mp.find(val+1) != mp.end()) {
                curr++;
                val++;
            }
            ans = max(ans, curr);
            mp[nums[i]]++;
        }
        return ans;
    }
};
