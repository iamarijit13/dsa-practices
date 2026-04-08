class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O' && (i == 0 || j == 0 || i == r - 1 || j == c - 1)) {
                    capture(i, j, r, c, board);
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void capture(int r, int c, int row, int col, vector<vector<char>>& board) {
        if (r < 0 || c >= col || r >= row || c < 0 || board[r][c] != 'O') {
            return;
        }

        board[r][c] = 'T';

        capture(r + 1, c, row, col, board);
        capture(r, c + 1, row, col, board);
        capture(r - 1, c, row, col, board);
        capture(r, c - 1, row, col, board);
    }
};
