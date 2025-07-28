class Solution {
    public int countHillValley(int[] nums) {
        int answer = 0;
        for (int i = 1; i + 1 < nums.length; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = nums[i - 1];
                continue;
            }
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                answer += 1;
            } else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                answer += 1;
            }
        }
        return answer;
    }
}