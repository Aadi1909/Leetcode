class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        function<int (int, int)> climb = [&](int i, int n){
            if(i == n) return 1;
            if(dp[i] != 0) return dp[i];
            int answer = climb(i + 1, n);
            if(i + 2 <= n) answer += climb(i + 2, n);
            dp[i] = answer;
            return dp[i];
        };
        return climb(0, n);
    }
};