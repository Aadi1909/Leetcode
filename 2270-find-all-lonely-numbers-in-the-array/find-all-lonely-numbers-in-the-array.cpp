class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int>mp;
        unordered_set<int>st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
            mp[nums[i]]++;
        }
        vector<int>answer;
        for(int i=0; i<nums.size(); i++){
            if((st.find(nums[i]+1)==st.end()) && (st.find(nums[i]-1) == st.end()) && (mp[nums[i]] == 1)){
                answer.push_back(nums[i]);
            }
        }
        return answer;
    }
};