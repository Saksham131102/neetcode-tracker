class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int idx1 = i;
            int target = -nums[idx1];
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                if(nums[left] + nums[right] == target) {
                    ans.push_back({nums[idx1], nums[left], nums[right]});
                    while(left+1 < right && nums[left] == nums[left+1])
                        left++;
                    while(left < right - 1 && nums[right-1] == nums[right])
                        right--;
                    left++;
                    right--;
                }
                else if(nums[left] + nums[right] > target)
                    right--;
                else if(nums[left] + nums[right] < target)
                    left++;
            }
        }
        return ans;
    }
};
