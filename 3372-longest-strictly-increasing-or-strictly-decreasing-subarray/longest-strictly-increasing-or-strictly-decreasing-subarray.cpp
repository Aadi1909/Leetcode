class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int answer = 0;
        int curr = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) curr++;
            else {
                answer = max(answer, curr);
                curr = 1;
            } 
        }
        answer = max(answer, curr);
        curr = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) curr++;
            else {
                answer = max(answer, curr);
                curr = 1;
            }
        }
        answer = max(answer, curr);
        return answer;
    }
};