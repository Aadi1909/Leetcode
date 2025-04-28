class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long answer = 0, sum = 0;
        // int low = 0;
        // for (int i = 0; i < nums.size(); ++i) {
        //   sum += nums[i];
        //   while (low <= i && sum * (i - low + 1) >= k) {
        //     sum -= nums[low];
        //     low++;
        //   }
        //   answer += (i - low + 1);
        // }
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        for (int r = 0; r < n; ++r) {
            int left = 0, right = r;
            int l_valid = r + 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                long long sum = prefix[r + 1] - prefix[mid];
                long long length = r - mid + 1;
                if (sum * length < k) {
                    l_valid = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            answer += (r - l_valid + 1);
        }
        return answer;
    }
};