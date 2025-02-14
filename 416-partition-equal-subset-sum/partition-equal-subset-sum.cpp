class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        function<bool(int, int)> sol = [&](int i, int sof) {
            if(sof == target) return true;
            if(i >= nums.size() || sof > target) return false;
            if(dp[i][sof] != -1) return (bool)dp[i][sof];
            dp[i][sof] = sol(i + 1, sof) || sol(i + 1, sof + nums[i]);
            return (bool)dp[i][sof];
        };
        return sol(0, 0);
    }
};