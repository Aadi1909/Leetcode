class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(dfs(board, word, vis, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& vis, int i, int j, int k) {
        if(k == word.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j] || board[i][j] != word[k]) {
            return false;
        }
        
        vis[i][j] = true;
        
        bool found = dfs(board, word, vis, i+1, j, k+1) ||
                     dfs(board, word, vis, i-1, j, k+1) ||
                     dfs(board, word, vis, i, j+1, k+1) ||
                     dfs(board, word, vis, i, j-1, k+1);
        
        vis[i][j] = false;
        return found;
    }
};
