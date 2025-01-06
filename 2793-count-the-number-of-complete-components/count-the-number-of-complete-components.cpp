class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        auto dfs = [&](int node, int& nodeCount, int& edgeCount, auto& dfs) -> void {
            visited[node] = true;
            nodeCount++;
            edgeCount += graph[node].size();
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, nodeCount, edgeCount, dfs);
                }
            }
        };
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int nodeCount = 0, edgeCount = 0;
                dfs(i, nodeCount, edgeCount, dfs);
                if (edgeCount == nodeCount * (nodeCount - 1)) {
                    answer++;
                }
            }
        }
        return answer;
    }
};
