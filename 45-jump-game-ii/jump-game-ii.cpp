class Solution {
public:
    int jump(vector<int>& A) {
        int N=A.size();
        vector<int>dp(N,-1);
        dp[N-1]=0;
        for(int i=N-2; i>=0; i--){
            int mn=1e9;
            for(int j=1; j<=A[i]&&i+j<N; j++){
                if(dp[i+j]!=-1&&dp[i+j]<mn){
                    mn=dp[i+j];
                }
            }
            if(mn==1e9){
                dp[i]=-1;
            }
            else{
                dp[i]=mn+1;
            }
        }
        return dp[0];
    }
};