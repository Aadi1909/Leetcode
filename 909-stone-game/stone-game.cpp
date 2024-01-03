class Solution {
public:
    bool stoneGame(vector<int>& A) {
        int N=A.size();
        vector<vector<int>>dp(N,vector<int>(N,0));
        for(int i=0; i<N; i++){
            for(int j=0,k=i; k<N; k++){
            if(i==0){
                dp[j][k]=A[j];
            }
            else if(i==1){
                dp[j][k]=max(A[j],A[k]);
            }
            else{
                int v1=A[j]+min(dp[j+2][k],dp[j+1][k-1]);
                int v2=A[k]+min(dp[j+1][k-1],dp[j][k-2]);
                dp[j][k]=max(v1,v2);
            }
            }
        }
        return dp[0][N-1];
    }
};