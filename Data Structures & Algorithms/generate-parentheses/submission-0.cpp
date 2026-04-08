class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        backtrack(n, 0, 0, res, "");

        return res;
    }

    void backtrack(int n, int open, int close, vector<string>& res, string current) {
        if (open == close && open == n) {
            res.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(n, open + 1, close, res, current + "(");
        }

        if (close < open) {
            backtrack(n, open, close + 1, res, current + ")");
        }
    }
};
