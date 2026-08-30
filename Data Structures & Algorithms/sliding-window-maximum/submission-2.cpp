class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = k;
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<k;i++) {
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        while(right < n) {
            while(!dq.empty() && nums[dq.back()] < nums[right])
                dq.pop_back();
            dq.push_back(right);
            right++;
            if(dq.front() == left)
                dq.pop_front();
            left++;
            ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};
