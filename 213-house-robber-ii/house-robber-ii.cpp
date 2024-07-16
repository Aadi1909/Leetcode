class Solution {
public:
    int rob(vector<int>& a) {
      int n=a.size();
      if(a.size()==1)return a[0];
      int dp1[n+2],dp2[n+2];
      memset(dp1,0,sizeof(dp1));
      memset(dp2,0,sizeof(dp2));
      for(int i=n-1; i>=0; i--){
        if(i<n-1){
          dp2[i]=max(dp2[i],dp2[i+1]);
          dp2[i]=max(dp2[i],dp2[i+2]+a[i]);
        }
        if(i>0){
          dp1[i]=max(dp1[i],dp1[i+1]);
          dp1[i]=max(dp1[i],dp1[i+2]+a[i]);
        }
      }
      return max(dp1[1],dp2[0]);
    }
};