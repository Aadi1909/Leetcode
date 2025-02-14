class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
        dp[0][0] = true;
        for(int i = 0; i <= nums.size(); ++i) dp[i][0] = true;
        for(int i = 1; i <= nums.size(); ++i){
            for(int j = 1; j <= target; ++j){
                if(j >= nums[i-1])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                dp[i][j] |= dp[i - 1][j];
            }
        }
        return dp[nums.size()][target];
    }
};
        // function<int(int, int)> sol = [&](int i, int sof) {
        //     if(sof == target) return 1;
        //     if(i >= nums.size() || sof > target) return 0;
        //     if(dp[i][sof] != -1) return dp[i][sof];
        //     dp[i][sof] = sol(i + 1, sof) || sol(i + 1, sof + nums[i]);
        //     return dp[i][sof];
        // };
        // return sol(0, 0);