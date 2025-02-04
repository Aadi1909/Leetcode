class Solution {
public:
    vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
        vector<int> inDegree(V, 0), topoOrder;
        queue<int> q;

        for (int u = 0; u < V; u++)
            for (int v : adj[u])
                inDegree[v]++;

        for (int i = 0; i < V; i++)
            if (inDegree[i] == 0) q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            topoOrder.push_back(u);

            for (int v : adj[u]) {
                if (--inDegree[v] == 0) q.push(v);
            }
        }
        return topoOrder;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> g(num);
        for (int i = 0; i < pre.size(); ++i) {
            int x = pre[i][0];
            int y = pre[i][1];
            g[x].push_back(y);
        }
        vector<int> res = topologicalSort(num, g);
        return res.size() == num;
    }
};
