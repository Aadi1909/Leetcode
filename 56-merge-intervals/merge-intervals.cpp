class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int start = nums[0][0], end = nums[0][1];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i][0] <= end){
                end = max(end, nums[i][1]);
            }
            else{
                res.push_back({start, end});
                start = nums[i][0], end= nums[i][1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};