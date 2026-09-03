class Solution {
private:
    bool isPossible(int rate, vector<int> &piles, int maxHrs) {
        int n = piles.size();
        int hrs = 0;
        for(int i=0;i<n;i++) {
            hrs += ((piles[i] + rate - 1) / rate);
        }
        return hrs <= maxHrs;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = INT_MAX;
        int ans = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(isPossible(mid, piles, h)) {
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
