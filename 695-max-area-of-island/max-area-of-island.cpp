class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        vector<vector<int>> vis(n, vector<int> (m, false));
        function<void(int, int, int&)> bfs = [&](int r, int c, int& area) {
            if (r >= n or c >= m or c < 0 or r < 0 or vis[r][c] or !grid[r][c]) return ;
            vis[r][c] = true;
            queue<pair<int, int>> q;
            q.push({r, c});
            while (!q.empty()) {
                pair<int, int> curr = q.front(); q.pop();
                int x = curr.first, y = curr.second;
                if (grid[x][y]) area += 1;
                for (int i = 0; i < 4; ++i) {
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    bfs(newX, newY, area);
                }
            }
        };
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] && !vis[i][j]) {
                    int area = 0;
                    bfs(i, j, area);
                    answer = max(answer, area);
                }
            }
        }
        return answer;
    }
};