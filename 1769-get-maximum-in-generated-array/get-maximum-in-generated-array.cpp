class Solution {
public:
    int getMaximumGenerated(int N) {
        if(N==0||N==1)return N;
        vector<int>dp(N+1);
        dp[0]=0,dp[1]=1;
        for(int i=1; i<=N; i++){
            if(2*i<=N)dp[2*i]=dp[i];
            if(2*i+1<=N)dp[2*i+1]=dp[i]+dp[i+1];
        }
        int res=*max_element(dp.begin(),dp.end());
        return res;
    }
};