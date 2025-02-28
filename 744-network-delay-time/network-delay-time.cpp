#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto& time : times) {
            g[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dis[u]) continue;
            for (auto& [v, w] : g[u]) {
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        int answer = *max_element(dis.begin() + 1, dis.end());
        return (answer == INT_MAX) ? -1 : answer;
    }
};
