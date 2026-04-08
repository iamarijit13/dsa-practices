class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> m, n;

        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) != m.end()) {
                m[s[i]]++;
            } else {
                m.insert({s[i], 1});
            }

            if (n.find(t[i]) != n.end()) {
                n[t[i]]++;
            } else {
                n.insert({t[i], 1});
            }
        }

        if (m.size() != n.size()) {
            return false;
        }

        for (auto x : m) {
            if (n[x.first] != x.second) {
                return false;
            }
        }

        return true;
    }
};
