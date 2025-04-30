class Solution {
public:
  long long countSubarrays(vector<int>& nums, int k) {
    int maxVal = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;
        int left = 0;
        int freq = 0;
        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxVal) {
                freq++;
            }
            while (freq >= k) {
                count += n - right;
                if (nums[left] == maxVal) {
                    freq--;
                }
                left++;
            }
        }
      return count;
  }
};