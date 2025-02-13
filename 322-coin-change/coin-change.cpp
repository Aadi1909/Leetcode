class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { 
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        function<int(int, int)> sol = [&](int i, int j) -> int {
            if (j == amount) return 0; 
            if (i >= n || j > amount) return 1e9;
            if (dp[i][j] != -1) return dp[i][j];
            int ans = sol(i + 1, j);
            if (j + coins[i] * 1LL <= amount) {
                ans = min(ans, 1 + sol(i, j + coins[i]));
            }
            return dp[i][j] = ans;
        };
        int ans = sol(0, 0);
        return (ans == 1e9) ? -1 : ans;
    }
};