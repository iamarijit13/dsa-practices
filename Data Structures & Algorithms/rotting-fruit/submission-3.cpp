class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> q;
        set<pair<int, int>> visit;
        int time = 0, fresh = 0;
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
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < dir.size(); d++) {
                    int nr = r + dir[d].first, nc = c + dir[d].second;

                    if (nr < 0 || nc < 0 || nr >= row || nc >= col || grid[nr][nc] == 0 || visit.count({nr, nc})) {
                        continue;
                    }

                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    visit.insert({nr, nc});
                    fresh--;
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
