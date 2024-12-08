class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N, 1e9);
        bool isBipartite = true;

        for (int i = 0; i < N; i++) {
            if (color[i] == 1e9) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty() && isBipartite) {
                    int u = q.front(); q.pop();
                    for (auto& v : graph[u]) {
                        if (color[v] == 1e9) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            isBipartite = false;
                            break;
                        }
                    }
                }
            }
        }

        return isBipartite;
    }
};
