class Solution {
    private:
   vector<vector<char>> rotateMatrixClockwise(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Create a new matrix with dimensions m x n
    vector<vector<char>> rotatedMatrix(m, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Assign the rotated values to the new matrix
            rotatedMatrix[j][n - 1 - i] = matrix[i][j];
        }
    }

    return rotatedMatrix;
}

public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for(int i = 0; i < box.size(); i++){
            int l = 0, r = 1;
            while(r < box[0].size()){
                if(box[i][l] == '#' && box[i][r] == '.'){
                    swap(box[i][l], box[i][r]);
                    l++, r++;
                }
                else if(box[i][l] == '#' && box[i][r] == '#'){
                    r++;
                }
                else if(box[i][l] == '*' || box[i][r] == '*'){
                    l = r, r++;
                }
                else{
                    l++, r++;
                }
            }
        }
        vector<vector<char>> res = rotateMatrixClockwise(box);
        return res;
    }
};