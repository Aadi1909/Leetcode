#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num] += num;
        }
        vector<int> values;
        for (auto& [num, points] : freq) {
            values.push_back(num);
        }
        int n = values.size();
        unordered_map<int, int> dp;
        function<int(int)> sol = [&](int index) {
            if (index >= n) return 0;
            if (dp.count(index)) return dp[index];
            int option1 = sol(index + 1);
            int option2 = freq[values[index]];
            if (index + 1 < n && values[index] + 1 == values[index + 1]) {
                option2 += sol(index + 2);
            } else {
                option2 += sol(index + 1);
            }
            return dp[index] = max(option1, option2);
        };
        return sol(0);
    }
};