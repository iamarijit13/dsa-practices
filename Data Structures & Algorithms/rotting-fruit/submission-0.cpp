class Solution {
public:
    int orangesRottings(vector<vector<int>>& grid) {
        int re = 0;
        int row = grid.size();
        int col = grid[0].size();
        set<pair<int, int>> visit;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 2) {
                    dfs(grid, visit, re, r, c);
                }
            }
        }

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 1) {
                    return -1;
                }
            }
        }

        return re;
    }

    bool isInBound(int r, int c, int row, int col) {
        return r >= 0 && c >= 0 && r < row && c < col;
    }

    void dfs(vector<vector<int>>& grid, set<pair<int, int>>& visit, 
    int re, int r, int c) {
        int row = grid.size();
        int col = grid[0].size();

        if (!isInBound(r, c, row, col) || grid[r][c] == 0 || visit.count({r, c})) {
            return;
        }

        grid[r][c] = 2;
        visit.insert({r, c});
        re++;

        dfs(grid, visit, re, r + 1, c);
        dfs(grid, visit, re, r - 1, c);
        dfs(grid, visit, re, r, c + 1);
        dfs(grid, visit, re, r, c - 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        
        // Step 1: Count fresh oranges and add all rotten oranges to queue
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // Step 2: BFS to rot adjacent fresh oranges
        while (!q.empty() && fresh > 0) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [r, c] = q.front(); q.pop();
                for (auto [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nc >= 0 && nr < row && nc < col && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
