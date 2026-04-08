struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row, col;
        unordered_map<pair<int, int>, unordered_set<char>, pair_hash> squares;

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                char point = board[r][c];
                
                if (point == '.') {
                    continue;
                }

                pair<int, int> square = {r / 3, c / 3};

                if (row[r].count(point) || col[c].count(point) || squares[square].count(point)) {
                    return false;
                }

                row[r].insert(point);
                col[c].insert(point);
                squares[square].insert(point);
            }
        }
        return true;
    }
};
