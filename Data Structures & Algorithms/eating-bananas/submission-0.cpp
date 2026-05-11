class Solution {
private:
    bool isValid(int mid, int totalHours, vector<int> &piles, int n) {
        int h = 0;
        for(int i=0;i<n;i++) {
            h += (piles[i] + mid - 1) / mid;
        }
        return h <= totalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = -1;
        int l = 1, r = INT_MAX;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(isValid(mid, h, piles, n)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
