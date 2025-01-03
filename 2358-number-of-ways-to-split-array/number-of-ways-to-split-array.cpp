class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int N = nums.size();
        std::vector<int64_t> pref(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            pref[i] = pref[i - 1] + nums[i - 1];
        }
        int answer = 0;
        for (int i = 0; i < N - 1; ++i) {
            int64_t first = pref[i + 1];
            int64_t last = pref[N] - pref[i + 1];
            if (first >= last) answer++;
        }
        return answer;
    }
};