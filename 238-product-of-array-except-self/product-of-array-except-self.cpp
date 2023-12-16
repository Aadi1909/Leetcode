class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        int prod = 1;
        int cnt_zeros = 0;
        int zero_prod = 1;
        for(int i = 0; i < n; i++){
            prod *= nums[i];
            if(nums[i] == 0){
                cnt_zeros++;
            }
            else{
                zero_prod *= nums[i];
            }
        }
        vector<int> answer(n);
        if(cnt_zeros == 0){
            for(int i = 0; i < n; i++){
                answer[i] = prod / nums[i];
            }
        }
        else if(cnt_zeros == 1){
            for(int i = 0; i < n; i++){
                if(nums[i] == 0){
                    answer[i] = zero_prod;
                }
            }
        }
        return answer;
    }
};