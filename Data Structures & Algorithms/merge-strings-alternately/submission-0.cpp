class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        int l = 0, r = 0;
        string re = "";

        while (l < m && r < n) {
            re += word1[l];
            re += word2[r];
            l++, r++;
        }

        if (l < m) {
            re += word1.substr(l, m - l + 1);
        }

        if (l < n) {
            re += word2.substr(r, n - r + 1);
        }

        return re;
    }
};