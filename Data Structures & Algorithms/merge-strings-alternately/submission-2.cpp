class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (m == 0) return word2;
        if (n == 0) return word1;

        string word = "";
        int l = 0, r = 0;
        while (l < m && r < n) {
            word.push_back(word1[l]);
            word.push_back(word2[r]);
            l++, r++;
        }
        if (l < m) word += word1.substr(l, m - l);
        if (r < n) word += word2.substr(r, n - r);

        return word;
    }
};