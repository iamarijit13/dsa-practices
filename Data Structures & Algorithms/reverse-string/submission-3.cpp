class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty() || s.size() == 1) return;

        int i = 0, j = s.size() - 1;
        
        while (i < j) {
            swap(s, i, j);
            i++, j--;
        }
    }
private:
    void swap(vector<char>& s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
};