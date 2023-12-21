class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0,hi=height.size()-1;
        int mx=-1e9;
        while(low<hi){
            int left=height[low],right=height[hi];
            int cmp=min(left,right)*(hi-low);
            mx=max(mx,cmp);
            if(left<right){
                low++;
            }
            else{
                hi--;
            }
        }
        return mx;
    }
};