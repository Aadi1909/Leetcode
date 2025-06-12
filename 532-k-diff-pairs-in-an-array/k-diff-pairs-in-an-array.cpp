class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> st;
        unordered_set<pair<int, int>, pair_hash> st2;
        // unordered_map<int, int> mp;
        int answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int m_diff = nums[i] - k;
            int p_diff = nums[i] + k;
            if (st.find(m_diff) != st.end()) {
                if (st2.find({nums[i], m_diff}) == st2.end() && st2.find({m_diff, nums[i]}) == st2.end()){
                    answer += 1;
                    st2.insert({nums[i], m_diff});
                }
            }
            if (st.find(p_diff) != st.end()) {
                if (st2.find({nums[i], p_diff}) == st2.end() && st2.find({p_diff, nums[i]}) == st2.end()){
                    answer += 1;
                    st2.insert({nums[i], p_diff});
                }
            }
            st.insert(nums[i]);
        }
        return answer;
    }
};

// 1 1 3 4 5

// abs() -> +
//       -> -

// 1 - 2 = -1
// 1 + 2 =  3
