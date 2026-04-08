class Solution {
public:
    string minWindowx(string s, string t) {
        if (t.empty()) {
            return "";
        }

        pair<int, int> re = {-1, -1};
        int have = 0, need = t.size(), resL = INT_MAX, l = 0;
        unordered_map<char, int> window, countT;

        for (char e : t) {
            countT[e]++;
        }

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;
            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resL) {
                    resL = r - l + 1;
                    re = {l, r};
                }
                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resL != INT_MAX ? s.substr(re.first, resL) : "";  
    }

    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
