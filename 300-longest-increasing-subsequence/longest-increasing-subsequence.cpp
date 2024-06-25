class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i){
            int maxlen = 0;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    if(dp[j] > maxlen) maxlen = max(maxlen, dp[j]);
                }
            }
            dp[i] = maxlen + 1;
        }
        int answer = 0;
        for(int i = 0; i < nums.size(); ++i){
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};