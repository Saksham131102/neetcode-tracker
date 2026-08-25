class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i] < 0)
                nums[i] = 0;
        }
        for(int i=0;i<n;i++) {
            int idx = abs(nums[i]);
            if(idx <= 0 || idx > n)
                continue;
            if(nums[idx - 1] > 0)
                nums[idx - 1] = -nums[idx - 1];
            else if(nums[idx - 1] == 0)
                nums[idx - 1] = -1;
        }
        for(int i=0;i<n;i++)
            cout << nums[i] << " ";
        for(int idx=0;idx<n;idx++) {
            if(nums[idx] >= 0)
                return idx + 1;
        }
        return n + 1;
    }
};