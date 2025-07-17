class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool> (n + 1, false));
        dp[n][0] = true;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= n; ++j) {
                bool ok = false;
                if (s[i] == '(') {
                    ok |= dp[i + 1][j + 1];
                } else if (s[i] == ')') {
                    if (j > 0 ) ok |= dp[i + 1][j - 1];
                } else {
                    ok |= dp[i + 1][j + 1];
                    if (j > 0) ok |= dp[i + 1][j - 1];
                    ok |= dp[i + 1][j];
                }
                dp[i][j] = ok;
            }
        }
        return dp[0][0];
    }
};
