class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> a(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            a.push_back(nums[i]);
        }
        return a;
    }
};