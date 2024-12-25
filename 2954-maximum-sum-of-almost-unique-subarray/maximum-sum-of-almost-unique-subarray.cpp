class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> mp;
        long long answer = 0;
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k && mp.size() >= m) {
                answer = max(answer, sum);
            }
            if (i < k) {
                sum += nums[i];
                mp[nums[i]]++;
                continue;
            }
            else {
                sum += nums[i];
                sum -= nums[i - k];
                mp[nums[i - k]]--;
                if (!mp[nums[i - k]]) mp.erase(nums[i - k]);
                mp[nums[i]]++;
            }
        }
        if (mp.size() >= m) {
            answer = max(answer, sum);
        }
        return answer;
    }
};