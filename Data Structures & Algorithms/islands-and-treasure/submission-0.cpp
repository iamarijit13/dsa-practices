class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int dis = 0;
        queue<pair<int, int>> queue;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0) {
                    // bfs(grid, i, j, r, c, dis);
                    queue.push({i, j});
                }
            }
        }

        while (!queue.empty()) {
            int row = queue.front().first;
            int col = queue.front().second;
            queue.pop();

            for (int side = 0; side < 4; side++) {
                int x = dirs[side][0] + row;
                int y = dirs[side][1] + col;

                if (x < 0 || y >= c || x >= r || y < 0 || grid[x][y] != INT_MAX) {
                    continue;
                }
                grid[x][y] = grid[row][col] + 1;
                queue.push({x, y});
            } 
        } 
    }

    void bfs(vector<vector<int>>& grid, int i, int j, int r, int c, int& dis) {
        if (i < 0 || j >= c || i >=r || j < 0 || grid[i][j] != INT_MAX) {
            return;
        }

        dis++;
        cout << grid[i][j] << " " << endl;
        if (grid[i][j] != 0 && grid[i][j] != -1 && grid[i][j] > dis) {
            cout << dis << " " << endl;
            grid[i][j] = dis;
        }

        bfs(grid, i + 1, j, r, c, dis);
        bfs(grid, i, j + 1, r, c, dis);
        bfs(grid, i - 1, j, r, c, dis);
        bfs(grid, i, j - 1, r, c, dis);
    }
};
