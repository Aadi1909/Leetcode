class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, odd = 0;
        int l = 0, m = 0;
        for(int r = 0; r < nums.size(); ++r){
            if(nums[r] & 1) odd++;
            while(odd > k){
                if(nums[l] & 1)odd--;
                l += 1;
                m = l;
            }
            if(odd == k){
                while(!(nums[m] % 2)){
                    m += 1;
                }
                res += (m - l) + 1;
            }
        }
        return res;
    }
};