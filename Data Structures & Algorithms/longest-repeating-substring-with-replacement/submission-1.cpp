class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        int re = 0, l = 0;

        for (int r = 0; r < s.size(); r++) {
            hash[s[r]] = 1 + (hash.count(s[r]) ? hash[s[r]] : 0);
            while ((r - l + 1) - mostfrequent(hash) > k) {
                hash[s[l]] -= 1;
                l += 1;
            }
            re = max(re, r - l + 1);
        }
        return re;
    }

private:
    int mostfrequent(unordered_map<char, int> &hash) {
        int frequent = 0;
        for (auto &h : hash) {
            frequent = max(frequent, h.second);
        }
        return frequent;
    }
};
