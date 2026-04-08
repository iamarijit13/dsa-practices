class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> check;
        int i = 0, re = 0;

        for (int j = 0; j < s.size(); j++) {
            while (check.count(s[j])) {
                check.erase(s[i]);
                i++;
            }
            check.insert(s[j]);
            re = max(re, j - i + 1);
        }
        return re;

        // unordered_set<char> charSet;
        // int l = 0;
        // int res = 0;

        // for (int r = 0; r < s.size(); r++) {
        //     while (charSet.find(s[r]) != charSet.end()) {
        //         charSet.erase(s[l]);
        //         l++;
        //     }
        //     charSet.insert(s[r]);
        //     res = max(res, r - l + 1);
        // }
        // return res;
    }
};
