class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int re = 0;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == '1') {
                    traverse(grid, row, col, r, c);
                    re++;
                }
            }
        }

        return re;
    }

    void traverse(vector<vector<char>>& grid, int row, int col, int r, int c) {
        if (r < 0 || c < 0 || r >= row || c >= col || grid[r][c] != '1') {
            return;
        }

        grid[r][c] = '0';

        traverse(grid, row, col, r + 1, c);
        traverse(grid, row, col, r, c + 1);
        traverse(grid, row, col, r - 1, c);
        traverse(grid, row, col, r, c - 1);
    }
};
