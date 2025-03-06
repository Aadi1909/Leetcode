class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> a_s(n, -1);
        stack<int> s_t;
        for (int i = n - 1; i >= 0; --i) {
            s_t.push(nums[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!s_t.empty() && s_t.top() <= nums[i]) {
                s_t.pop();
            }
            if (!s_t.empty()) {
                a_s[i] = s_t.top();
            }
            s_t.push(nums[i]);
        }
        return a_s;
    }
};