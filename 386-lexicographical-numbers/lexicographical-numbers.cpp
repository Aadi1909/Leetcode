class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> answer;
        function<void(int)> dfs = [&](int curr) {
            if (curr > n) return ;
            answer.push_back(curr);
            for (int i = 0; i < 10; ++i) {
                int depth = curr * 10 + i;
                dfs(depth);
            }
        };
        for (int i = 1; i <= 9; ++i) {
            dfs(i);
        }
        return answer;
    }
};