class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> f(102, 0);
        for(int i = 0; i < nums.size(); ++i){
            ++f[nums[i]];
        }
        int pairs = 0;
        for(int i = 0; i <= 101; ++i){
            pairs += (f[i] * (f[i] - 1) / 2);
        }
        return pairs;
    }
};