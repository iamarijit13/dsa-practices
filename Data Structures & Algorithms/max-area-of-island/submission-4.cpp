class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid.at(0).size();
        int re = 0;
        set<pair<int, int>> visit;

        auto iterate = [&grid, &visit, row, col](auto &self, int r, int c, int &area) {
            if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] != 1 || visit.count({r, c})) return;

            visit.insert({r, c});
            area++;

            self(self, r + 1, c, area);
            self(self, r - 1, c, area);
            self(self, r, c + 1, area);
            self(self, r, c - 1, area);
        };

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 1 && !visit.count({r, c})) {
                    int area = 0;
                    iterate(iterate, r, c, area);
                    re = max(re, area);
                }
            }
        }
        
        return re;
    }
};
