class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int answer = 0;
        for(int i = 0; i < 24; ++i) {
            int count = 0;
            for(int j = 0; j < candidates.size(); ++j) {
                if (candidates[j] & (1 << i)) {
                    count++;
                }
            }
            answer = max(count, answer);
        }
        return answer;
    }
};
