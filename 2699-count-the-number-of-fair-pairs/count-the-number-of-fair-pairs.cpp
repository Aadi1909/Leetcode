class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int lo = i + 1, hi = nums.size() - 1;
            int lowerIdx = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (nums[i] + nums[mid] >= lower) {
                    lowerIdx = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            lo = i + 1, hi = nums.size() - 1;
            int upperIdx = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (nums[i] + nums[mid] <= upper) {
                    upperIdx = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if (lowerIdx != -1 && upperIdx != -1 && lowerIdx <= upperIdx) {
                answer += (upperIdx - lowerIdx + 1);
            }
        }

        return answer;
    }
};
