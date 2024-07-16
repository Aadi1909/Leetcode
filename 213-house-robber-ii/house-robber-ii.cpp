class Solution {
public:
    int rob(vector<int>& a) {
      int n=a.size();
      if(a.size()==1)return a[0];
      int dp[n+1];
      memset(dp,-1,sizeof(dp));
      function<int(int,int)>sol = [&](int i,int x){
        //base case
        if(i>=x)return 0;
        int answer=0;
        if(dp[i]!=-1)return dp[i];
        //function call 1
        answer=max(answer,sol(i+2,x)+a[i]);
        //function call 2
        answer=max(answer,sol(i+1,x));
        return dp[i] = answer;
      };
      int p=sol(0,n-1);
      memset(dp,-1,sizeof(dp));
      int q=sol(1,n);
      return max(p,q);
    }
};