class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();

        int currSum = 0;
        int answer = 0;
        for (int i = 0; i < nums.length; ++i) {
            currSum += nums[i];
            if (currSum == k) answer += 1;
            if (map.containsKey(currSum - k)) {
                answer += map.get(currSum - k);
            }
            map.put(currSum, map.getOrDefault(currSum, 0) + 1);
        }
        return answer;
    }
}