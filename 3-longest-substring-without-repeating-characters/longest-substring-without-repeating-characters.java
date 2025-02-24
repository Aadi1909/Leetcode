import java.util.HashMap;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        HashMap<Character, Integer> map = new HashMap<>();
        int answer = 0;
        int low = 0;

        for (int i = 0; i < len; ++i) {
            char currentChar = s.charAt(i);
            if (map.containsKey(currentChar)) {
                low = Math.max(low, map.get(currentChar) + 1);
            }
            answer = Math.max(answer, i - low + 1);
            map.put(currentChar, i);
        }

        return answer;
    }
}