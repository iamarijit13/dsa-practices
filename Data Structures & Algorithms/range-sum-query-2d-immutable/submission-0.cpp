class NumMatrix {
private:
    vector<vector<int>> sumMat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        sumMat = vector(row + 1, vector(col + 1, 0));

        for (int i = 0; i < row; i++) {
            int prefix = 0;
            for (int j = 0; j < col; j++) {
                prefix += matrix[i][j];
                int above = sumMat[i][j + 1];
                sumMat[i + 1][j + 1] = prefix + above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int r1 = row1 + 1, c1 = col1 + 1, r2 = row2 + 1, c2 = col2 + 1;

        int bottomRight = sumMat[r2][c2];
        int above = sumMat[r1 - 1][c2];
        int left = sumMat[r2][c1 - 1];
        int topleft = sumMat[r1 - 1][c1 - 1];

        return bottomRight - above - left + topleft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */