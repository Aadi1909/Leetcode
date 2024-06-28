class Solution {
public:
    int maxRepeating(string s, string w) {
        int answer = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == w[0]) {
                int low = i, hi = 0;
                int count = 0, len = 0;
                while (s[low] == w[hi] and low < s.length() and hi < w.length()) {
                    low++, hi++;
                    count++;
                    if (count == w.length()) {
                        count = 0;
                        hi = 0;
                        len++;
                    }
                }
                answer = max(answer, len);
            }
        }
        return answer;
    }
};