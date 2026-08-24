class Solution {
private:
    int solve(int idx, int isBuy, vector<int> &prices, int n, vector<vector<int>> &dp) {
        // base case
        if(idx >= n)
            return 0;
        // recursive relation
        if(dp[idx][isBuy] != -1)
            return dp[idx][isBuy];
        int profit = INT_MIN;
        if(isBuy) {
            int notBuy = 0 + solve(idx+1, 1, prices, n, dp);
            int buy = -prices[idx] + solve(idx+1, 0, prices, n, dp);
            profit = max(notBuy, buy);
        }
        else {
            int notSell = 0 + solve(idx+1, 0, prices, n, dp);
            int sell = prices[idx] + solve(idx+1, 1, prices, n, dp);
            profit = max(notSell, sell);
        }
        return dp[idx][isBuy] = profit;
    }
public:
    // 1: buy state | 0: sell state
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, INT_MIN));
        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int idx=n-1;idx>=0;idx--) {
            for(int isBuy = 0;isBuy<2;isBuy++) {
                int profit = INT_MIN;
                if(isBuy) {
                    int notBuy = 0 + dp[idx+1][1];
                    int buy = -prices[idx] + dp[idx+1][0];
                    profit = max(notBuy, buy);
                }
                else {
                    int notSell = 0 + dp[idx+1][0];
                    int sell = prices[idx] + dp[idx+1][1];
                    profit = max(notSell, sell);
                }
                dp[idx][isBuy] = profit;
            }
        }
        return dp[0][1];
    }
};