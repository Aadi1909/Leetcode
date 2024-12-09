class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        vector<int> violations(N, 0);
        for (int i = 0; i < N - 1; ++i) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                violations[i] = 1;
            }
        }
        vector<int> prefixSum(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            prefixSum[i + 1] = prefixSum[i] + violations[i];
        }
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int fromi = queries[i][0];
            int toi = queries[i][1];
            res[i] = (prefixSum[toi] - prefixSum[fromi] == 0);
        }
        return res;
    }
};
