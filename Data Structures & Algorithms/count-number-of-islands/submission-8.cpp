class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int re = 0;
        set<pair<int, int>> visit;

        auto iterate = [&grid, &visit, row, col](auto &self, int r, int c) {
            if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] != '1' || visit.count({r, c})) return;

            visit.insert({r, c});

            self(self, r + 1, c);
            self(self, r - 1, c);
            self(self, r, c + 1);
            self(self, r, c - 1);
        };

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == '1' && !visit.count({r, c})) {
                    iterate(iterate, r, c);
                    re++;
                }
            }
        }

        return re;
    }
};
