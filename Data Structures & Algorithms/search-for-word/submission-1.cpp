class Solution {
public:
    set<pair<int, int>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (board[r][c] == word[0]) {
                    bool re = dfs(board, 0, r, c, word);
                    if (re) return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int r, int c, string word) {
        if (i == word.size()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= board.size() 
            || c >= board[0].size() || visited.count({r, c})
            || board[r][c] != word[i]) {
            return false;
        }

        visited.insert({r, c});
        bool res = dfs(board, i + 1, r + 1, c, word)
        || dfs(board, i + 1, r - 1, c, word)
        || dfs(board, i + 1, r, c + 1, word)
        || dfs(board, i + 1, r, c - 1, word);
        visited.erase({r, c});
        return res;
    }
};
