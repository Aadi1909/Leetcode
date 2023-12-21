class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low=0,hi=nums.size()-1;
        int cnt=0;
        while(low<hi){
            int sm=nums[low]+nums[hi];
            if(sm-k==0){
                cnt++;
                low++,hi--;
            }
            else if(sm-k>0){
                hi--;
            }
            else{
                low++;
            }
        }
        return cnt;
    }
};