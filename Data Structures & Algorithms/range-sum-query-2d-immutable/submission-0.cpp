class NumMatrix {
private:
    vector<vector<int>> Prefix2D;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        Prefix2D.resize(n, vector<int> (m));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                Prefix2D[i][j] = matrix[i][j] + (i-1 >= 0 ? Prefix2D[i-1][j] : 0) + (j-1 >= 0 ? Prefix2D[i][j-1] : 0) - (i-1 >= 0 && j-1 >= 0 ? Prefix2D[i-1][j-1] : 0);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return Prefix2D[row2][col2] - (row1-1 >= 0 ? Prefix2D[row1-1][col2] : 0) - (col1-1 >= 0 ? Prefix2D[row2][col1-1] : 0) + (row1-1 >= 0 && col1-1 >= 0 ? Prefix2D[row1-1][col1-1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */