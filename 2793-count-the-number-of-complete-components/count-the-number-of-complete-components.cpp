class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (int i = 0; i < edges.size(); ++i) {
            int x = edges[i][0];
            int y = edges[i][1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int count = 0;
        set<int> st;
        vector<bool> vis(n, false);
        function<void(int, int&)> dfs = [&](int u, int& cnt) {
            st.insert(g[u].size());
            cnt++;
            vis[u] = true;
            for (int v : g[u]) {
                if (!vis[v]) {
                    dfs(v, cnt);
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int k = 0;
                dfs(i, k);
                if (st.size() == 1 && *st.begin() == (k - 1)) count++;
                st.clear();
            }
        }
        return count;
    }
};
