class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;

        for (auto x : s) {
            hash[x]++;
        }

        for (auto x : t) {
            hash[x]--;
        }

        for (auto h : hash) {
            if (h.second != 0) {
                return false;
            }
        }
        return true;
    }
};
