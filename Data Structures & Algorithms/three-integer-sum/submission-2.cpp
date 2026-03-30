class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int idx = 0;
        while(idx < n-2) {
            int sum = nums[idx];
            int left = idx+1, right = n-1;
            while(left < right) {
                if(sum + nums[left] + nums[right] == 0) {
                    ans.push_back({nums[idx], nums[left], nums[right]});
                    int val = nums[left];
                    while(nums[left] == val)
                        left++;
                    val = nums[right];
                    while(nums[right] == val)
                        right--;
                }
                if(sum + nums[left] + nums[right] > 0)
                    right--;
                else if(sum + nums[left] + nums[right] < 0)
                    left++;
            }
            int val = nums[idx];
            while(nums[idx] == val)
                idx++;
        }
        return ans;
    }
};
