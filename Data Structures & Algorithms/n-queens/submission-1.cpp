class Solution {
    vector<string> grid;
    unordered_set<int> cols;
    unordered_set<int> dig1;
    unordered_set<int> dig2;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> re;
        
        grid.resize(n, string(n, '.'));
        backtrack(0, n, re);

        return re;
    }

private:
    void backtrack(int row, int n, vector<vector<string>>& re) {
        if (row == n) {
            re.push_back(grid);
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col;
            int d2 = row + col;

            if (cols.count(col) || dig1.count(d1) || dig2.count(d2)) continue;

            grid[row][col] = 'Q';
            cols.insert(col);
            dig1.insert(d1);
            dig2.insert(d2);
            backtrack(row + 1, n, re);
            
            grid[row][col] = '.';
            cols.erase(col);
            dig1.erase(d1);
            dig2.erase(d2);
        }
    }
};
