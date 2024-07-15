class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(string &s, string &t, int i, int j){
    //     if(i >= (int) s.length() || j >= (int) t.length()) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == t[j]){
    //         return dp[i][j] = solve(s, t, i + 1, j + 1) + 1;
    //     }
    //     else{
    //         return dp[i][j] = max(solve(s, t, i + 1, j) , solve(s, t, i, j + 1));
    //     }
    // }
    int longestCommonSubsequence(string s, string t) {
        vector<vector<int>> dp(s.length() + 1, vector<int> (t.length() + 1, 0));
        int n = s.length(), m = t.length();
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
            if(s[i] == t[j]){
                dp[i][j] = dp[i+1][j+1] + 1;
            }
            else{
                dp[i][j] = max(dp[i + 1][j], dp[i][j+1]);
            }
            }
        }
        return dp[0][0];
    }
};