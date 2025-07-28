class Solution {
    public int countHillValley(int[] nums) {
        ArrayList<Integer> array = new ArrayList<>();
        array.add(nums[0]);
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] != nums[i - 1]) {
                array.add(nums[i]);
            }
        }
        int answer = 0;
        for (int i = 1; i + 1 < array.size(); ++i) {
            int e = array.get(i);
            if (e > array.get(i - 1) && e > array.get(i + 1)) {
                answer += 1;
            } else if (e < array.get(i - 1) && e < array.get(i + 1)) {
                answer += 1;
            }
        }
        return answer;
    }
}