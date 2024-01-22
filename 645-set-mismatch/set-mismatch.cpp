class Solution {
    public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>answer(2);
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                answer[0]=nums[i];
                break;
            }
        }
        int sm=accumulate(nums.begin(),nums.end(),0);
        int res = n*(n+1)/2 - sm + answer[0];
        answer[1]=res;
        return answer;
    }
};