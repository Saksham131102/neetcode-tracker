class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        vector<vector<int>> topK;
        for(auto it : mp) {
            int val = it.first;
            int freq = it.second;
            topK.push_back({freq, val});
        }
        sort(topK.begin(), topK.end(), greater<vector<int>>());
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(topK[i][1]);
        return ans;
    }
};
