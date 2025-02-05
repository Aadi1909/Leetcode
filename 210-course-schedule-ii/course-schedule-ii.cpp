#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>> g(num);
        vector<int> deg(num, 0), topo_;
        for (const auto& p : pre) {
            int a = p[0], b = p[1];
            g[b].push_back(a);
            deg[a]++;
        }
        queue<int> q;
        for (int i = 0; i < num; ++i) {
            if (deg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo_.push_back(u);
            for (int v : g[u]) {
                if (--deg[v] == 0) q.push(v);
            }
        }
        return (topo_.size() == num) ? topo_ : vector<int>();
    }
};
