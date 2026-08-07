class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> re;
        vector<string> cur;
        int n = s.size();

        auto dfs = [this, &s, n, &cur, &re](auto& self, int index) -> void {
            if (index >= n) {
                re.push_back(cur);
                return;
            }

            for (int i = index; i < n; i++) {
                if (isPalindrome(s, index, i)) {
                    cur.push_back(s.substr(index, i - index + 1));
                    self(self, i + 1); // Recurse with i + 1
                    cur.pop_back();    // Backtrack
                }
            }
        };

        dfs(dfs, 0);
        
        return re;
    }

    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
};
