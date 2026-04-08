class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, string> digitMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> res;
        dfs(digits, digitMap, 0, "", res);
        return res;
    }

    void dfs(string digits, unordered_map<char, string>& digitMap, int i, 
        string current, vector<string>& res) {
        if (current.size() == digits.size()) {
            res.push_back(current);
            return;
        }

        for (char c : digitMap[digits[i]]){
            dfs(digits, digitMap, i + 1, current + c, res);
        }
    }
};
