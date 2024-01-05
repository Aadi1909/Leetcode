class Solution {
public:
    int minFallingPathSum(vector<vector<int>>&A) {
        int N=A.size(),M=A[0].size();
        vector<vector<int>>dp(N,vector<int>(M,0));
        for(int i=0; i<M; i++){
            dp[0][i]=A[0][i];
        }
        for(int i=1; i<N; i++){
            for(int j=M-1; j>=0; j--){
                if(j==M-1){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+A[i][j];        
                }
                else if(j==0){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+A[i][j];
                }
                else{
                    dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]})+A[i][j];
                }
            }
        }
        int res=1e9;
        for(int j=0; j<M; j++){
            res=min(res,dp[N-1][j]);
        }
        return res;
    }
};