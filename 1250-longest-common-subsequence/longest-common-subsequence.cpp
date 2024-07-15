class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s, string &t, int i, int j){
        if(i >= (int) s.length() || j >= (int) t.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = solve(s, t, i + 1, j + 1) + 1;
        }
        else{
            return dp[i][j] = max(solve(s, t, i + 1, j) , solve(s, t, i, j + 1));
        }
    }
    int longestCommonSubsequence(string s, string t) {
        dp.resize(s.length() + 1, vector<int> (t.length() + 1, -1));
        return solve(s, t, 0, 0);
    }
};