class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
        }
        int req = nums.size() / 3;
        vector<int> answer;
        for (auto& m : mp) {
            if (m.second > req) answer.push_back(m.first);
        }
        return answer;
    }
};