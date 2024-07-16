class Solution {
public:
    int solve(vector<int>&a,int i,int j,vector<vector<int>>&dp){
      if(j==a.size()) return 0;
      int answer=0;
      if(dp[j][i+1]!=-1)return dp[j][i+1];
      answer=max(answer,solve(a,i,j+1,dp));
      if(i==-1||a[j]>a[i]){
        answer=max(answer,solve(a,j,j+1,dp)+1);
      }
      return dp[j][i+1]=answer;
    }
    int lengthOfLIS(vector<int>& a) {
      int n=a.size();
      vector<vector<int>> dp(n+1,vector<int>(n+1,0));
      //iterative code
      int answer = 0;
      for (int j = n - 1; j >= 0; --j) {
        for (int i = j - 1; i >= -1; --i) {
            dp[j][i + 1] = dp[j + 1][i + 1];
            if (i == -1 || a[j] > a[i]) {
                dp[j][i + 1] = max(dp[j][i + 1], dp[j + 1][j + 1] + 1);
            }
            answer = max(answer, dp[j][i + 1]);
        }
    }
      return answer;
    }
};