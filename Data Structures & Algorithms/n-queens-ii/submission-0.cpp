class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> col, positiveDiagonal, negativeDiagonal;
        int result = 0;

        auto backtrack = [n, &result, &col, &positiveDiagonal, &negativeDiagonal](auto &self, int row) {
            if (row == n) {
                result++;
                return;
            }

            for (int c = 1; c <= n; c++) {
                if (col.count(c) || positiveDiagonal.count(row + c) || negativeDiagonal.count(row - c)) continue;

                col.insert(c);
                positiveDiagonal.insert(row + c);
                negativeDiagonal.insert(row - c);
                self(self, row + 1);
                col.erase(c);
                positiveDiagonal.erase(row + c);
                negativeDiagonal.erase(row - c);
            }
        };
        backtrack(backtrack, 0);
        return result;
    }
};