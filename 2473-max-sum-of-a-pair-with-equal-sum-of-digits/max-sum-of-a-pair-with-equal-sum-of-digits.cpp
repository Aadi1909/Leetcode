class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int len = nums.size();
        vector<pair<int, int>> a(len);
        for (int i = 0; i < len; ++i) {
            int dig = nums[i];
            int sum = 0;
            while (dig) {
                sum += dig % 10;
                dig /= 10;
            }
            a[i].first = nums[i];
            a[i].second = sum;
        }
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (int i = 0; i < len; ++i) {
            if (mp.find(a[i].second) == mp.end() or mp[a[i].second].size() < 2) {
                mp[a[i].second].push(a[i].first);
            } else {
                if (mp[a[i].second].top() < a[i].first) {
                    mp[a[i].second].pop();
                    mp[a[i].second].push(a[i].first);
                }
            }
        }
        int answer = -1;
        for (auto & m : mp) {
            if (m.second.size() == 2) {
                int f = m.second.top(); m.second.pop();
                int s = m.second.top();
                answer = max(answer, f + s);
            }
        }
        return answer;
    }
};