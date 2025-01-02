class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> psum(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            psum[i] = psum[i - 1] + nums[i - 1];
        }
        vector<int> left(N, 0), right(N, 0);
        int max_sum = 0, max_idx = 0;
        for (int i = k; i <= N; ++i) {
            int curr_sum = psum[i] - psum[i - k];
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                max_idx = i - k;
            }
            left[i - 1] = max_idx;
        }
        max_sum = 0;
        max_idx = N - k;
        for (int i = N - k; i >= 0; --i) {
            int curr_sum = psum[i + k] - psum[i];
            if (curr_sum >= max_sum) {
                max_sum = curr_sum;
                max_idx = i;
            }
            right[i] = max_idx;
        }
        vector<int> result(3, -1);
        int max_total_sum = 0;
        for (int j = k; j <= N - 2 * k; ++j) {
            int l = left[j - 1];
            int r = right[j + k];
            int total_sum = (psum[l + k] - psum[l]) + 
                            (psum[j + k] - psum[j]) + 
                            (psum[r + k] - psum[r]);

            if (total_sum > max_total_sum) {
                max_total_sum = total_sum;
                result = {l, j, r};
            }
        }
        return result;
    }
};