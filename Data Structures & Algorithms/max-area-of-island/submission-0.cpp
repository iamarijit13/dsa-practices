class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int re = 0, count = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                dfs(grid, i, j, r, c, count);
                cout << max(re, count) << endl;
                re = max(re, count);
                count = 0;
            }
        }

        return re;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int r, int c, int& count) {
        if (i < 0 || j >= c || i >= r || c < 0 || grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;
        count++;

        dfs(grid, i + 1, j, r, c, count);
        dfs(grid, i, j + 1, r, c, count);
        dfs(grid, i - 1, j, r, c, count);
        dfs(grid, i, j - 1, r, c, count);
    }
};
