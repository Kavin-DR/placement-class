//Geeks for Geeks Coin Change

class Solution {
public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        int INF = 1000000;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INF));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (coins[i - 1] <= j) {
                    dp[i][j] = min(dp[i][j],
                                   1 + dp[i][j - coins[i - 1]]);
                }
            }
        }

        if (dp[n][sum] == INF)
            return -1;

        return dp[n][sum];
    }
};
