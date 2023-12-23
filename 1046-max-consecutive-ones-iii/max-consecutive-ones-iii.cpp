class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=-1;
        int zero=0;
        int maxlen=-1e9;
        while(i<nums.size()){
            if(nums[i]){
                i++;
            }
            else{
                zero++,i++;
            }
            if(zero>k){
                while(zero>k){
                    j++;
                    if(nums[j]==0){
                        zero--;
                    }
                }
            }
            maxlen=max(maxlen,i-1-j);
        }
        maxlen=max(maxlen,i-1-j);
        return maxlen;
    }
};