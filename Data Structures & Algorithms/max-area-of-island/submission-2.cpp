class Solution {
public:
    
bool valid(int r, int c, int row, int col) {
    return (r >= 0 && c >= 0 && r < row && c < col);
}

void dfs(vector<vector<int>>& grid, int& res, int r, int c, set<pair<int, int>>& visit) {
    int row = grid.size();
    int col = grid[0].size();
    if (!valid(r, c, row, col) || grid[r][c] != 1 || visit.count({r, c})) {
        return;
    }

    visit.insert({r, c});
    res++;

    dfs(grid, res, r + 1, c, visit);
    dfs(grid, res, r, c - 1, visit);
    dfs(grid, res, r - 1, c, visit);
    dfs(grid, res, r, c + 1, visit);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    int res = 0;
    set<pair<int, int>> visit;

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (grid[r][c] == 1) {
                int area = 0;
                dfs(grid, area, r, c, visit);
                res = max(res, area);
            }
        }
    }
    return res;
}
};
