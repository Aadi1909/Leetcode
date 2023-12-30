class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        int MAX=0;
        int N=A.size(),M=A[0].size();
        vector<vector<int>> dp(N, vector<int>(M));
        for(int i=0; i<M; i++){
            if(A[N-1][i]=='1')dp[N-1][i]=1;
            else dp[N-1][i]=0;
            MAX=max(MAX,dp[N-1][i]);
        }
        for(int i=0; i<N; i++){
            if(A[i][M-1]=='1')dp[i][M-1]=1;
            else dp[i][M-1]=0;
            MAX=max(MAX,dp[i][M-1]);
        }
        for(int i=A.size()-2; i>=0; i--){
            for(int j=A[0].size()-2; j>=0; j--){
                if(A[i][j]=='1'){
                    dp[i][j]=min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]})+1;
                    MAX=max(MAX,dp[i][j]);
                }
            }
        }
        return MAX*MAX;
    }
};