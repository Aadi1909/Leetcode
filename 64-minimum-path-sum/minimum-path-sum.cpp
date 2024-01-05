class Solution {
public:
    int minPathSum(vector<vector<int>>& A) {
        int N=A.size(),M=A[0].size();
        vector<vector<int>>dp(N,vector<int>(M,0));
        dp[0][0]=A[0][0];
        for(int j=1; j<M; j++){
            dp[0][j]=A[0][j]+dp[0][j-1];
        }
        for(int i=1; i<N; i++){
            dp[i][0]=A[i][0]+dp[i-1][0];
        }
        for(int i=1; i<N; i++){
            for(int j=1; j<M; j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+A[i][j];
            }
        }
        return dp[N-1][M-1];
    }
};