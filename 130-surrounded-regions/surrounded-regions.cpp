class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int n = board.size(), m = board[0].size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O') {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newY >= 0 && newX < n && newY < m && board[newX][newY] == 'O' && !vis[newX][newY]) {
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};