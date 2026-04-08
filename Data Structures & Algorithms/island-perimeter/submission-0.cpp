class Solution {
private:
    set<pair<int, int>> visit;
    int traverse(vector<vector<int>>& grid, int row, int col, int r, int c) {
        if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 0) {
            return 1;
        }

        if (visit.count({r, c})) {
            return 0;
        }

        visit.insert({r, c});

        return traverse(grid, row, col, r + 1, c)
                + traverse(grid, row, col, r, c + 1)
                + traverse(grid, row, col, r - 1, c)
                + traverse(grid, row, col, r, c - 1);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 1) {
                    return traverse(grid, row, col, r, c);
                }
            }
        }
        return 0;
    }
};