class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> hash;
        return visit(s, 0, hash);
    }

    int visit(string s, int index, unordered_map<int, int>& hash) {
        if (hash.count(index)) {
            return hash[index];
        }

        if (index == s.size()) {
            return 1;
        }

        if (s[index] - '0' == 0) {
            return 0;
        }

        int re = visit(s, index + 1, hash);
        if (index < s.size() - 1) {
            if (s[index] == '1' || (s[index] == '2' && s[index + 1] - '0' <= 6)) {
                re += visit(s, index + 2, hash);
            }
        }

        return hash[index] = re;
    }
};
