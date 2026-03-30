class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftPrefix(n), rightPrefix(n);
        leftPrefix[0] = 1;
        rightPrefix[n-1] = 1;
        int prod = 1;
        for(int i=0;i<n-1;i++) {
            prod *= nums[i];
            leftPrefix[i+1] = prod;
        }
        prod = 1;
        for(int i=n-1;i>=1;i--) {
            prod *= nums[i];
            rightPrefix[i-1] = prod;
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            prod = leftPrefix[i] * rightPrefix[i];
            ans.push_back(prod);
        }
        return ans;
    }
};
