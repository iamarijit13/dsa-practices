class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), re = 0;
        set<pair<int, int>> visit;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (visit.count({r, c})) {
                    continue;
                }
                if (grid[r][c] == '1') {
                    traverse(grid, visit, r, c);
                    re++;
                }
            }
        }

        return re;
    }

    void traverse(vector<vector<char>>& grid, set<pair<int, int>>& visit, int r, int c) {
        int row = grid.size(), col = grid[0].size();

        if (r < 0 || c < 0 || r >= row || c >= col || visit.count({r, c}) || grid[r][c] != '1') {
            return;
        }

        visit.insert({r, c});

        traverse(grid, visit, r + 1, c);
        traverse(grid, visit, r, c + 1);
        traverse(grid, visit, r - 1, c);
        traverse(grid, visit, r, c - 1);
    }
};
