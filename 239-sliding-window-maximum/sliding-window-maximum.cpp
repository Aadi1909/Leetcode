class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mset;
        for(int i = 0; i < k; ++i){
            mset.insert(nums[i]);
        }
        vector<int> answer;
        answer.push_back(*(mset.rbegin()));
        for(int i = k; i < nums.size(); ++i){
            auto it = mset.lower_bound(nums[i-k]);
            mset.erase(it);
            mset.insert(nums[i]);
            answer.push_back(*(mset.rbegin()));
        }
        return answer;
    }
};