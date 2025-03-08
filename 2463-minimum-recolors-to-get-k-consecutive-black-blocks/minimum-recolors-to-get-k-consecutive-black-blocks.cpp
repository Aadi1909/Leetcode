class Solution {
public:
    int minimumRecolors(string block, int k) {
        int answer = 1e9;
        int black = 0;
        for (int i = 0; i < k; ++i) {
            if (block[i] == 'B') black++;
        }
        answer = min(answer, k - black);
        for (int i = k; i < block.length(); ++i) {
            if (block[i - k] == 'B') black--;
            if (block[i] == 'B') black++;
            answer = min(answer, k - black);
        }
        return answer;
    }
};