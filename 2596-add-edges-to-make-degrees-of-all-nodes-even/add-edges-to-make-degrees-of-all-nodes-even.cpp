class Solution {
public:
  bool isPossible(int n, vector<vector<int>>& edges) {
    vector<set<int>> g(n + 1);
    for (auto &edge : edges) {
        int node_u = edge[0], node_v = edge[1];
        g[node_u].insert(node_v);
        g[node_v].insert(node_u);
    }

    vector<int> odd_count;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() % 2 == 1) odd_count.push_back(i);
    }

    int odd = odd_count.size();
    if (!odd) return true;
    if (odd > 4) return false;
    if (odd == 2) {
        int u = odd_count[0], v = odd_count[1];
        if (!g[u].count(v)) {
          return true;
        } else {
            for (int x = 1; x <= n; ++x) {
                if (x != u && x != v && !g[u].count(x) && !g[v].count(x)) {
                  return true;
                }
            }
        }
    } else if (odd == 4) {
        int a = odd_count[0], b = odd_count[1], c = odd_count[2], d = odd_count[3];
        if (!g[a].count(b) && !g[c].count(d)) {
          return true;
        } else if (!g[a].count(c) && !g[b].count(d)) {
          return true;
        } else if (!g[a].count(d) && !g[b].count(c)) {
          return true;
        } else {
          return false;
        }
    }
    return false;
  }
};