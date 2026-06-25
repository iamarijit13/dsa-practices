class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        set<pair<int, int>> visit;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    visit.insert({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < dir.size(); d++) {
                int nr = r + dir[d].first;
                int nc = c + dir[d].second;

                if (nr < 0 || nc < 0 || nr >= row || nc >= col || grid[nr][nc] == -1 || visit.count({nr, nc})) {
                    continue;
                }

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
                visit.insert({nr, nc});
            }
        }
    }
};
