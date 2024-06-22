class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, answer = 0;
        unordered_map<int, int> pref;
        pref[sum]++;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(pref.count(sum - k)){
                answer += pref[sum - k];
            }
            pref[sum]++;
        }
        return answer;
    }
};