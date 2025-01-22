class Solution {
public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        std::vector<std::vector<int>> answer(n, std::vector<int>(m, -1));
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j] == 1) {
                    answer[i][j] = 0;
                    vis[i][j] = true;
                    q.push({i, j});  
                }
            }
        }
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    answer[nx][ny] = answer[x][y] + 1;
                    vis[nx][ny] = true;            
                    q.push({nx, ny});               
                }
            }
        }

        return answer;
    }
};
