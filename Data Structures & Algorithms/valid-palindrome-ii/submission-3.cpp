class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() == 0) return true;

        int l = 0, r = s.size() - 1;

        while (l <= r) {
            if (s[l] == s[r]) l++, r--;
            else {
                return isPalindrome(s, l + 1, r)
                    || isPalindrome(s, l, r - 1);
            }
        }
        return true;
    }

private:
    bool isPalindrome(string s, int l, int r) {
        if (s.size() == 0 || s.size() == 1) return true;

        while (l <= r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;

            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
};