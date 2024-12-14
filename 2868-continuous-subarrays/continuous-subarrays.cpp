class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long answer = 0;
        int lo = 0;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
            int Max = mp.rbegin() != mp.rend() ? mp.rbegin()->first : 0;
            int Min = mp.begin() != mp.end() ? mp.begin()->first : 0;
            while (lo < nums.size() && Max - Min > 2) {
                mp[nums[lo]]--;
                if (mp[nums[lo]] == 0) mp.erase(nums[lo]);
                lo++;
                Max = mp.rbegin() != mp.rend() ? mp.rbegin()->first : 0;
                Min = mp.begin() != mp.end() ? mp.begin()->first : 0;
            }
            answer += i - lo + 1;
        }

        return answer;
    }
};
