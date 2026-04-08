class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        unordered_set<int> pac, atl;
        vector<vector<int>> re;

        for (int i = 0; i < row; i++) {
            dfs(i, 0, pac, heights[i][0], row, col, heights);
            dfs(i, col - 1, atl, heights[i][col - 1], row, col, heights);
        }

        for (int j = 0; j < col; j++) {
            dfs(0, j, pac, heights[0][j], row, col, heights);
            dfs(row - 1, j, atl, heights[row - 1][j], row, col, heights);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int cood = i * col + j;

                if (pac.count(cood) && atl.count(cood)) {
                    re.push_back({i, j});
                }
            }
        }

        return re;
    }

    void dfs(int r, int c, unordered_set<int>& visit, int preh, int row, int col, vector<vector<int>>& heights) {
        int cood = r * col + c;

        if (r < 0 || c >= col || c < 0 || r >= row || heights[r][c] < preh || visit.count(cood)) {
            return;
        }

        visit.insert(cood);

        dfs(r + 1, c, visit, heights[r][c], row, col, heights);
        dfs(r, c + 1, visit, heights[r][c], row, col, heights);
        dfs(r - 1, c, visit, heights[r][c], row, col, heights);
        dfs(r, c - 1, visit, heights[r][c], row, col, heights);
    }
};
