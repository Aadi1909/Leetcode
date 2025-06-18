class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int answer = 0;
        int curr = 0;
        for (int i = 0; i < nums.length; ++i) {
            curr += nums[i] == 1 ? 1 : -1;
            if (map.containsKey(curr)) {
                answer = Math.max(answer, i - map.get(curr));
            }
            else map.put(curr, i);
        }
        return answer;
    }
}