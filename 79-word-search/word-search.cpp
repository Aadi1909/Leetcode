class Solution {
public:
bool solve(int i, int j, vector<vector<bool>>&vis, vector<vector<char>>&board, string&word, int n, int m, int k){

    if(k == word.size()){
        return true;
    }
      if(i >= n || j >= m || i < 0 || j < 0 || vis[i][j] || board[i][j] != word[k]){
        return false;
    }
    vis[i][j]=true;
    bool res = solve(i+1, j, vis, board, word, n, m, k+1) || 
               solve(i, j+1, vis, board, word, n, m, k+1) || 
               solve(i-1, j, vis, board, word, n, m, k+1) || 
               solve(i, j-1, vis, board, word, n, m, k+1);
    vis[i][j]=false;
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    int n=board.size();
    int m=board[0].size();
    string str="";
    bool ok = false;
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool re = solve(i, j, vis,board,word, n, m, 0);
            if(re)return true;
        }
    }
        return false;
    }
};