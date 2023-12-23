class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=-1,maxlen=-1e9;
        int cntzero=0;
        while(i<nums.size()){
            if(nums[i]){
                i++;
            }
            else {
                cntzero++;
                i++;
            }
            while(cntzero>1){
                j++;
                if(nums[j]==0){
                    cntzero--;
                }
            }
            maxlen=max(maxlen,i-j-1);
        }
        maxlen=max(maxlen,i-j-1);
        return maxlen-1;
    }
};