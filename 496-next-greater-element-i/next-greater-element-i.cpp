class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m_p;
        stack<int> s_t;
        s_t.push(0);
        for(int  i = 1; i < nums2.size(); ++i) {
            while (!s_t.empty() && nums2[s_t.top()] < nums2[i]) {
                m_p[nums2[s_t.top()]] = nums2[i];
                s_t.pop();
            }
            s_t.push(i);
        }
        while (!s_t.empty()) {
            m_p[nums2[s_t.top()]] = -1;
            s_t.pop();
        }
        vector<int> a_s(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i) {
            a_s[i] = m_p[nums1[i]];
        }
        return a_s;
    }
};