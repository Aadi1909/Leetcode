class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> sequence(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        function<bool(int)> backtrack = [&](int index) -> bool {
            if (index == sequence.size()) {
                return true;
            }
            if (sequence[index] != 0) {
                return backtrack(index + 1);
            }
            for (int num = n; num >= 1; --num) {
                if (used[num]) continue;
                if (num == 1) {
                    sequence[index] = 1;
                    used[1] = true;
                    if (backtrack(index + 1)) return true;
                    used[1] = false;
                    sequence[index] = 0;
                } else {
                    if (index + num >= sequence.size() || sequence[index + num] != 0) continue;
                    sequence[index] = num;
                    sequence[index + num] = num;
                    used[num] = true;
                    if (backtrack(index + 1)) return true;
                    used[num] = false;
                    sequence[index] = 0;
                    sequence[index + num] = 0;
                }
            }
            return false;
        };

        backtrack(0);
        return sequence;
    }
};