class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights.at(0).size();
        set<pair<int, int>> pac, atl;
        vector<vector<int>> re;

        auto iterate = [&heights, row, col](auto &self, set<pair<int, int>> &sea, int rp, int cp, int r, int c) {
            if (r < 0 || r >= row || c < 0 || c >= col || heights[rp][cp] > heights[r][c] || sea.count({r, c})) return;

            sea.insert({r, c});

            self(self, sea, r, c, r + 1, c);
            self(self, sea, r, c, r - 1, c);
            self(self, sea, r, c, r, c + 1);
            self(self, sea, r, c, r, c - 1);
        };

        for (int r = 0; r < row; r++) {
            iterate(iterate, pac, r, 0, r, 0);
            iterate(iterate, atl, r, col - 1, r, col - 1);
        }


        for (int c = 0; c < col; c++) {
            iterate(iterate, pac, 0, c, 0, c);
            iterate(iterate, atl, row - 1, c, row - 1, c);
        }

        for (auto cell : pac) {
            if (atl.count(cell)) {
                re.push_back({cell.first, cell.second});
            }
        }

        return re;
    }
};
