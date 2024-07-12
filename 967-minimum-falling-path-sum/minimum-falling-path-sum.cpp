class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int dp[n + 1][m + 1];
        for(int i=0; i<=n; ++i){
          for(int j=0; j<=m; ++j){
            dp[i][j]=1e9;
          }
        }
        for (int i = 0; i <= m; ++i) {
            dp[n][i] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j] + a[i][j];
                dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + a[i][j]);
                if (j - 1 >= 0)
                  dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + a[i][j]);
            }
        }
        int result = 1e9;
        for (int i = 0; i <= m; ++i) {
            result = min(result, dp[0][i]);
        }
        return result;
    }
};