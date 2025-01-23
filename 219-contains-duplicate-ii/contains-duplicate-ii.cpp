class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i){
            auto it = map.find(nums[i]);
            if(it != map.end() && (i - (it->second)) <= k){
                return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};