class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int mx=0;
        int low=0,hi=k;
        int presum=0;
        for(int i=0; i<k; i++) presum+=nums[i];
        mx=presum;
        while(hi<nums.size()){
            presum+=nums[hi];
            presum-=nums[low];
            mx=max(mx,presum);
            low++,hi++;
        }
        return (double)mx/k;
    }
};