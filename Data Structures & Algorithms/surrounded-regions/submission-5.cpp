class Solutions {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int row = board.size(), col = board.at(0).size();
        set<pair<int, int>> visit;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if ((r == 0 || r == row - 1 || c == 0 || c == col - 1) && board[r][c] == 'O') {
                    q.push({r, c});
                    visit.insert({r, c});
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : dir) {
                    int cr = r + dr, cc = c + dc;

                    if (cr < 0 || cr >= row || cc < 0 || cc >= col || board[cr][cc] != 'O' || visit.count({cr, cc})) continue;

                    q.push({cr, cc});
                    visit.insert({cr, cc});
                }
            }
        }

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (!visit.count({r, c})) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};

class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            int row = board.size(), col = board[0].size();
            queue<pair<int, int>> q;
            vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

            // 1. Mark boundary 'O's as safe ('#') and add to queue
            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    if ((r == 0 || r == row - 1 || c == 0 || c == col - 1) && board[r][c] == 'O') {
                        q.push({r, c});
                        board[r][c] = '#';
                    }
                }
            }

            // 2. Traversal: expand to all connected interior 'O's
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : dir) {
                    int cr = r + dr, cc = c + dc;
                    if (cr >= 0 && cr < row && cc >= 0 && cc < col && board[cr][cc] == 'O') {
                        board[cr][cc] = '#';
                        q.push({cr, cc});
                    }
                }
            }

            // 3. Final cleanup pass
            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    if (board[r][c] == 'O') board[r][c] = 'X';
                    else if (board[r][c] == '#') board[r][c] = 'O';
                }
            }
        }
    };
