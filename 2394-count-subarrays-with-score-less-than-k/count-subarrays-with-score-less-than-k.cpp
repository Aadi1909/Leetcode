class Solution {
public:
  long long countSubarrays(vector<int>& nums, long long k) {
    long long answer = 0;
    int low = 0, size = 0;
    long long sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];answer += (size - 1) * size / 2;
      while (low <= i && sum * (i - low + 1) >= k) {
        sum -= nums[low];
        low++;
      }
      answer += (i - low + 1);
    }
    return answer; 
  }
};