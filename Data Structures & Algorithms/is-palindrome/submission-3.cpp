class Solution {
public:
    bool isPalindrome(string s) {
        s = removeSpace(s);

        cout << s << " " << endl;

        for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
            if (tolower(s[i]) != tolower(s[j])) {
                cout << i << ": " << s[i] << " -> " << j << ": " << s[j] << endl;
                return false;
            }
        }

        return true;
    }

    string removeSpace(string s) {
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (!isalnum(s[i])) {
                continue;
            }

            t += s[i];
        }

        return t;
    }
};
