class Solution {
    private:
        void solve(vector<vector<int>> &res, vector<int> nums, vector<int> tmp){
            if(nums.size() == 0){
                res.push_back(tmp);
                return ;
            }
            int x = nums[0];
            nums.erase(nums.begin());
            solve(res, nums, tmp);
            tmp.push_back(x);
            solve(res, nums, tmp);
        }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        solve(res, nums, tmp);
        return res;
    }
};
