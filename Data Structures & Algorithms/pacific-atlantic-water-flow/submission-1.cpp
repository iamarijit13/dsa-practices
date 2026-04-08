class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> re;
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));

        for (int c = 0; c < col; c++) {
            dfs(heights, pacific, 0, c);
            dfs(heights, atlantic, row - 1, c);
        }
        for (int r = 0; r < row; r++) {
            dfs(heights, pacific, r, 0);
            dfs(heights, atlantic, r, col - 1);
        }

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    re.push_back({r, c});
                }
            }
        }

        return re;
    }

    void dfs(vector<vector<int>>& heights,
    vector<vector<bool>>& ocean, 
    int r, int c) {
        int row = heights.size();
        int col = heights[0].size();

        ocean[r][c] = true;

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto d : dir) {
            int dr = d.first, dc = d.second;
            int nr = r + dr, nc = c + dc;
            if (!isOutOfBound(nr, nc, row, col) 
            && !ocean[nr][nc]
            && heights[r][c] <= heights[nr][nc]) {
                dfs(heights, ocean, nr, nc);
            }
        }
    }

    bool isOutOfBound(int r, int c, int row, int col) {
        return r < 0 || r >= row || c < 0 || c >= col;
    }
};
