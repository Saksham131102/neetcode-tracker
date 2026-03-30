class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int trappedWater = 0;
        vector<int> prefixMax(n, 0), suffixMax(n, 0);
        int maxHeight = 0;
        for(int i=0;i<n-1;i++) {
            maxHeight = max(maxHeight, height[i]);
            prefixMax[i+1] = maxHeight;
        }
        maxHeight = 0;
        for(int i=n-1;i>=1;i--) {
            maxHeight = max(maxHeight, height[i]);
            suffixMax[i-1] = maxHeight;
        }
        for(int i=0;i<n;i++) {
            int minWall = min(prefixMax[i], suffixMax[i]);
            // no water can be trapped
            if(minWall <= height[i])
                continue;
            trappedWater += (minWall - height[i]);
        }
        return trappedWater;
    }
};
