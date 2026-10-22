class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1) return true;

        int i = 0, j = s.size() - 1;

        while (i <= j) {
            cout << s[i] << " " << s[j] << endl;
            while ((i < j) && !isalnum(s[i])) i++; 
            while((i < j) && !isalnum(s[j])) j--;
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++, j--;
        }
        return true;
    }
};
