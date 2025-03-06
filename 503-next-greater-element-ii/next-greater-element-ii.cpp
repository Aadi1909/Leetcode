class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> a_s(n, -1);
        stack<int> s_t;
        for (int i = 2 * n - 1; i >= 0; --i) {
            while (!s_t.empty() && nums[s_t.top()] <= nums[i % n]) {
                s_t.pop();
            }
            if (!s_t.empty()) {
                a_s[i % n] = nums[s_t.top()];
            }
            s_t.push(i % n);
        }
        return a_s;
    }
};