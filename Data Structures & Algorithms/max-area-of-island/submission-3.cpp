class Solution {
public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), re = 0;
        set<pair<int, int>> visit;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (visit.count({r, c})) {
                    continue;
                }
                if (grid[r][c] == 1) {
                    int res = 0;
                    traverse(grid, visit, r, c, res);
                    re = max(re, res);
                }
            }
        }

        return re;
    }

    void traverse(vector<vector<int>>& grid, set<pair<int, int>>& visit, int r, int c, int& re) {
        int row = grid.size(), col = grid[0].size();

        if (r < 0 || c < 0 || r >= row || c >= col || visit.count({r, c}) || grid[r][c] != 1) {
            return;
        }

        re++;
        visit.insert({r, c});

        traverse(grid, visit, r + 1, c, re);
        traverse(grid, visit, r, c + 1, re);
        traverse(grid, visit, r - 1, c, re);
        traverse(grid, visit, r, c - 1, re);
    }
};
