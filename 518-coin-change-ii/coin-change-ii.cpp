class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int k = amount;
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        dp[n][k] = 1;
        for(int i = 0; i < k; ++i){
            dp[n][i] = 0;
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = k; j >= 0; j--){
                dp[i][j] = dp[i + 1][j];
                if(j + coins[i] <= k){
                    dp[i][j] += dp[i][j + coins[i]];
                }
            }
        }
        return dp[0][0];
    }
};