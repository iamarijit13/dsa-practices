class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> charSet(s.begin(), s.end());
        int re = 0;

        for (auto& c : charSet) {
            int l = 0, count = 0;

            for (int r = 0; r < s.size(); r++) {
                if (c == s[r]) {
                    count++;
                }

                while ((r - l + 1) - count > k) {
                    if (s[l] == c) {
                        count--;
                    }
                    l++;
                }

                re = max(re, (r - l + 1));
            }
        }
        return re;
    }
};
