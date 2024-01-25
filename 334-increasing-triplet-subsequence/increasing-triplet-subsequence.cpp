class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small=INT_MAX,medium=INT_MAX;
        if(nums.size()<3)return false;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=small){
                small=nums[i];
            }
            else if(nums[i]<=medium){
                medium=nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};