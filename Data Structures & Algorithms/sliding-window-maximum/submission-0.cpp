class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        int left = 0, right = 0;
        for(;right<k;right++) {
            while(!dq.empty() && nums[dq.back()] < nums[right])
                dq.pop_back();
            dq.push_back(right);
        }
        ans.push_back(nums[dq.front()]);
        while(right < n) {
            if(left == dq.front()) {
                dq.pop_front();
            }
            left++;
            while(!dq.empty() && nums[dq.back()] < nums[right])
                dq.pop_back();
            dq.push_back(right);
            ans.push_back(nums[dq.front()]);
            right++;
        }
        return ans;
    }
};
