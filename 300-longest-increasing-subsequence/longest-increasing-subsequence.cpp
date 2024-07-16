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
    int lengthOfLIS(vector<int>& nums) {
      vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
       return solve(nums,-1,0,dp);
    }
};