class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int m = amount;
        if(amount == 0) return 1;
        int dp[n][m];
        memset(dp, -1, sizeof(dp));
        function<int(int, int)> sol = [&](int currentAmount, int index){
            if(index >= coins.size() or currentAmount > amount) return 0;
            if(currentAmount == amount) return 1;
            int answer = 0;
            if(dp[index][currentAmount] != -1) return dp[index][currentAmount];
            if((coins[index] + currentAmount) <= amount) 
                answer += sol(currentAmount + coins[index], index);
                answer += sol(currentAmount, index + 1);
            return dp[index][currentAmount] = answer;
        };
        return sol(0,0);
    }
};