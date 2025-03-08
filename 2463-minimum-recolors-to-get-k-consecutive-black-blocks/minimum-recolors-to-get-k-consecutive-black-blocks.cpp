class Solution {
public:
    int minimumRecolors(string block, int k) {
        int answer = 1e9;
        int black = 0;
        for (int i = 0; i < block.length(); ++i) {
            if (i < k) {
                if (block[i] == 'B') black++;
                continue;
            }
            answer = min(answer, k - black);
            if (block[i - k] == 'B') black--;
            if (block[i] == 'B') black++;
        }
        answer = min(answer, k - black);
        return answer;
    }
};