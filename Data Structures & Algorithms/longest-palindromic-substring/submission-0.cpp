class Solution {
public:
    string longestPalindrome(string s) {
        string re = "";
        int rel = 0, red = 0;

        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if ((r - l + 1) > rel) {
                    re = s.substr(l, r + 1);
                    red = l;
                    rel = r - l + 1;
                }
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if ((r - l + 1) > rel) {
                    re = s.substr(l, r + 1);
                    red = l;
                    rel = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(red, rel);
    }
};
