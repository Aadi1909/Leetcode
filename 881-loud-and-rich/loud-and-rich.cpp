class Solution {
public:
    vector<vector<int>> graph;
    vector<int> answer;
    vector<int> quiet;

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int N = quiet.size();
        graph.resize(N);
        answer = vector<int>(N, -1);
        this->quiet = quiet;

        for (const auto& edge : richer) {
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < N; ++i) {
            dfs(i);
        }

        return answer;
    }

    int dfs(int node) {
        if (answer[node] == -1) {
            answer[node] = node;
            for (int child : graph[node]) {
                int cand = dfs(child);
                if (quiet[cand] < quiet[answer[node]]) {
                    answer[node] = cand;
                }
            }
        }
        return answer[node];
    }
};
