class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxOr |= nums[i];
        }
        int count = 0;
        for (int i = 1; i < (1 << nums.size()); ++i) {
            int tmpOr = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (i & (1 << j)) {
                    tmpOr |= nums[j];
                }
            }
            if (tmpOr == maxOr) count++;
        }
        return count;
    }
};