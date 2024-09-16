class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        multiset<int, greater<int>> mset;
        for (int i = 0; i < k; ++i) {
            mset.insert(nums[i]);
        }
        answer.push_back(*mset.begin());
        int lo = 0, hi = k;
        while (hi < nums.size()) {
            auto it = mset.lower_bound(nums[lo]);
            mset.erase(it);
            mset.insert(nums[hi]);
            answer.push_back(*mset.begin());
            lo++, hi++;
        }
        return answer;
    }
};