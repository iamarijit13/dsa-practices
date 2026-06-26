class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        set<pair<int, int>> pac, atl;
        vector<vector<int>> res;

        for (int r = 0; r < row; r++) {
            dfs(heights, r, 0, row, col, pac, heights[r][0]);
            dfs(heights, r, col - 1, row, col, atl, heights[r][col - 1]);
        }

        for (int c = 0; c < col; c++) {
            dfs(heights, 0, c, row, col, pac, heights[0][c]);
            dfs(heights, row - 1, c, row, col, atl, heights[row - 1][c]);
        }

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (atl.count({r, c}) && pac.count({r, c})) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& heights, int r, int c, int row, int col, set<pair<int, int>>& visit, int prev) {
        if (r < 0 || c < 0 || r >= row || c >= col || visit.count({r, c}) || heights[r][c] < prev) {
            return;
        }

        visit.insert({r, c});
        dfs(heights, r + 1, c, row, col, visit, heights[r][c]);
        dfs(heights, r - 1, c, row, col, visit, heights[r][c]);
        dfs(heights, r, c + 1, row, col, visit, heights[r][c]);
        dfs(heights, r, c - 1, row, col, visit, heights[r][c]);
    }
};
