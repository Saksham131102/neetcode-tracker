class Solution {
    private:
        int solve(int idx, int isBuy, int cnt, vector<int> &prices, vector<vector<vector<int>>> &dp) {
                
            // base case
            if(cnt == 0) return 0;
            if (idx == prices.size()) return 0;

            if (dp[idx][isBuy][cnt] != -1) return dp[idx][isBuy][cnt];

            int ans = 0;

            if (isBuy) {
                int skip = solve(idx + 1, 1, cnt, prices, dp);
                int buy = -prices[idx] + solve(idx + 1, 0, cnt, prices, dp);
                ans = max(skip, buy);
            } else {
                int skip = solve(idx + 1, 0, cnt, prices, dp);
                int sell = prices[idx] + solve(idx + 1, 1, cnt-1, prices, dp);
                ans = max(skip, sell);
            }

            return dp[idx][isBuy][cnt] = ans;
        }
   
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
            return solve(0, 1, 1, prices, dp);
        }
};