class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major;
        int count = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++) {
            if(count == 0)
                major = nums[i];
            if(nums[i] == major)
                count++;
            else
                count--;
        }

        return major;
    }
};