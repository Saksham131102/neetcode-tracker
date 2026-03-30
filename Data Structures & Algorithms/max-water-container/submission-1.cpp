class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int left = 0, right = n-1;
        while(left < right) {
            ans = max(ans, (right - left) * min(heights[right], heights[left]));
            if(heights[left] <= heights[right])
                left++;
            else if(heights[left] > heights[right])
                right--;
        }
        return ans;
    }
};
