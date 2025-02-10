class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int len = nums.size();
        long long pairs = len * (len - 1LL) / 2;
        // count the good pairs
        unordered_map<int, int> mp;
        long long count = 0;
        for (int i = 0; i < len; ++i) {
            if (mp.find(nums[i] - i) != mp.end()) {
                count += mp[nums[i] - i];
            }
            mp[nums[i] - i]++;
        }
        long long answer = pairs - count;
        // return the pairs - good pairs
        return answer;
    }
};