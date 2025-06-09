class Solution {
public:
    struct CompareBySecond {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int MAX_S = 1e4 + 11;
        int neg[MAX_S] = {};
        int pos[MAX_S] = {};
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareBySecond> pq;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) neg[abs(nums[i])]++;
            else pos[nums[i]]++;
        }
        vector<int> answer;
        for (int i = 0; i < 1e4 + 11; ++i) {
            pq.push({i, pos[i]});
            pq.push({-i, neg[i]});
        }
        while (!pq.empty() && k > 0) {
            pair<int, int> top = pq.top(); pq.pop();
            answer.push_back(top.first);
            k -= 1;
        }
        return answer;
    }
};