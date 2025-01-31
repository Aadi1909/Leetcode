class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int N = grid.size();
        if (N == 0) return -1;
        int M = grid[0].size();
        queue<pair<int, int>> que;
        vector<vector<int>> dis(N, vector<int>(M, -1));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxDis = 0;
        while (!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for (auto &dir : directions) {
                int p = x + dir.first;
                int q = y + dir.second;
                if (p >= 0 && p < N && q >= 0 && q < M && grid[p][q] == 1) {
                    grid[p][q] = 2;
                    dis[p][q] = dis[x][y] + 1;
                    maxDis = max(maxDis, dis[p][q]);
                    que.push({p, q});
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return maxDis;
    }
};