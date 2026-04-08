class Solution {
public:

    string isAnagram(string s) {
        unordered_map<char, int> m;
        string t = "";

        for (char c = 'a'; c <= 'z'; ++c) {
            m[c] = 0;
        }

        for (auto x : s) {
            if (m.find(x) != m.end()) {
                m[x]++;
            } else {
                m.insert({x, 1});
            }
        }

        for (auto x : m) {
            t += to_string(x.first) + to_string(x.second);
        }

        return t;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> re;
        unordered_map<string, vector<string>> m; 

        for (auto x : strs) {
            string s = isAnagram(x);

            if (m.find(s) != m.end()) {
                m[s].push_back(x);
            } else {
                vector<string> c = {x};
                m.insert({s, c});
            }
        }

        for (auto x : m) {
            re.push_back(x.second);
        }

        return re;
    }
};
