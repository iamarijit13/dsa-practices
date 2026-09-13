class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid.at(0).size(), dis = 0;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<tuple<int, int, int>> q;
        set<pair<int, int>> visit;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c, 0});
                    visit.insert({r, c});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c, d] = q.front();
            q.pop();
            d = d + 1;
            
            for (auto [dr, dc] : dir) {
                int cr = r + dr, cc = c + dc;
                if (cr < 0 || cr >= row || cc < 0 || cc >= col || visit.count({cr, cc})) continue;

                if (grid[cr][cc] != -1 && grid[cr][cc] != 0) {
                    grid[cr][cc] = d;
                    q.push({cr, cc, d});
                    visit.insert({cr, cc});
                }
            }
        }
    }
};
