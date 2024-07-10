class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        // function<int (int, int)> climb = [&](int i, int n){
        //     if(i == n) return 1;
        //     if(dp[i] != 0) return dp[i];
        //     int answer = climb(i + 1, n);
        //     if(i + 2 <= n) answer += climb(i + 2, n);
        //     dp[i] = answer;
        //     return dp[i];
        // };
        dp[n] = 1;
        for(int i = n-1; i >= 0; i--){
            dp[i] = dp[i + 1] + (i + 2 <= n ? dp[i + 2] : 0);
        }
        return dp[0];
    }
};