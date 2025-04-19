class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> graph(n); 
        for (auto& e : redEdges) graph[e[0]].push_back({e[1], 0});
        for (auto& e : blueEdges) graph[e[0]].push_back({e[1], 1});

        vector<vector<int>> dist(n, vector<int>(2, -1));
        queue<tuple<int, int, int>> q;

        q.push({0, 0, 0});
        q.push({0, 1, 0});
        dist[0][0] = dist[0][1] = 0;

        while (!q.empty()) {
            auto [node, color, length] = q.front();
            q.pop();
            for (auto& [nei, neiColor] : graph[node]) {
                if (neiColor != color && dist[nei][neiColor] == -1) {
                    dist[nei][neiColor] = length + 1;
                    q.push({nei, neiColor, length + 1});
                }
            }
        }
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            if (dist[i][0] == -1 || dist[i][1] == -1)
                result[i] = max(dist[i][0], dist[i][1]);
            else
                result[i] = min(dist[i][0], dist[i][1]);
        }
        return result;
    }
};
