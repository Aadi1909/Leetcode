class Solution {
public:
    int countPaths=0;
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        int N=A.size(),M=A[0].size();

        if(A[0][0]==1)return 0;
        vector<vector<long long>>dp(N,vector<long long>(M,0));
        dp[0][0]=1;
        for(int i=1; i<N; i++){
            if(A[i][0]!=1)dp[i][0]=dp[i-1][0];
        }
        for(int j=1; j<M; j++){
            if(A[0][j]!=1)dp[0][j]=dp[0][j-1];
        }
        for(int i=1; i<N; i++){
            for(int j=1; j<M; j++){
                if(A[i][j]!=1) dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[N-1][M-1];
    }
};