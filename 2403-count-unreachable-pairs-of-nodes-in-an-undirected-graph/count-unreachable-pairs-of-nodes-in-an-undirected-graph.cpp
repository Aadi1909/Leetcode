class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long answer = 0;
        vector<long long> getCon;
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        function<int(int)> dfs = [&](int u) {
            vis[u] = true;
            int size = 1;
            for (auto& v : adj[u]) {
                if (!vis[v]) {
                    size += dfs(v);
                }
            }
            return size;
        };
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                getCon.push_back(dfs(i));
            }
        }
        if (getCon.size() == 1) return 0;
        long long totalNodes = n;
        for (auto size : getCon) {
            totalNodes -= size;
            answer += size * totalNodes;
        }

        return answer;
    }
};
