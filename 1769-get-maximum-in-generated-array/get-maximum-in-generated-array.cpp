class Solution {
public:
    int getMaximumGenerated(int N) {
        if(N==0)return 0;
        if(N==1)return 1;
        vector<int>dp(N+1);
        dp[0]=0,dp[1]=1;
        int mx=-1e9;
        for(int i=2; i<=N; i++){
            if(i%2==0)dp[i]=dp[i/2];
            else dp[i]=dp[i/2]+dp[i/2+1];
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};