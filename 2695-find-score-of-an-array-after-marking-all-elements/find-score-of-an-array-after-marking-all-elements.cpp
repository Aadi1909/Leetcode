class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long answer = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }
        set<int> st;
        while (!pq.empty()) {
            int value = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            if (st.find(index) != st.end()) {
                continue;
            }
            answer += value;
            st.insert(index);
            if (index - 1 >= 0) st.insert(index - 1);
            if (index + 1 < nums.size()) st.insert(index + 1);
        }
        return answer;
    }
};