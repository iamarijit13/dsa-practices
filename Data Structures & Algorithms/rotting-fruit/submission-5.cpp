class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid.at(0).size(), time = 0, fresh = 0;
        set<pair<int, int>> visit;
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                    visit.insert({r, c});
                } else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : dir) {
                    int cr = r + dr, cc = c + dc;

                    if (cr < 0 || cr >= row || cc < 0 || cc >= col || visit.count({cr, cc})) continue;

                    if (grid[cr][cc] == 1) {
                        grid[cr][cc] = 2;
                        q.push({cr, cc});
                        visit.insert({cr, cc});
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
