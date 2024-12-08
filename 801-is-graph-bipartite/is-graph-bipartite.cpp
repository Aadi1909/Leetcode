class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N, 1e9);
        bool isBipartite = true;
        for (int i = 0; i < N; i++) {
            if (color[i] == 1e9) {
                stack<int> st;
                st.push(i);
                color[i] = 0;
                while (!st.empty() && isBipartite) {
                    int u = st.top();
                    st.pop();
                    for (auto& v : graph[u]) {
                        if (color[v] == 1e9) {
                            color[v] = 1 - color[u];
                            st.push(v);
                        }
                        else if (color[v] == color[u]) {
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
