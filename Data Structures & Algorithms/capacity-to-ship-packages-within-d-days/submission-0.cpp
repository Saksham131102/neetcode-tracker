class Solution {
private:
    bool isPossible(int capacity, vector<int> &weights, int d) {
        int n = weights.size();
        int wt = 0;
        int days = 0;
        for(int i=0;i<n;i++) {
            if(weights[i] > capacity)
                return false;
            if(wt + weights[i] > capacity) {
                days++;
                wt = weights[i];
            }
            else {
                wt += weights[i];
            }
        }
        days++;
        return days <= d;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 1, right = INT_MAX;
        int ans;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(isPossible(mid, weights, days)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};