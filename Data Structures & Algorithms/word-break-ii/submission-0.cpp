class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> bank(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> cache;

        auto backtrack = [&bank, &cache, s](auto &self, int i) -> vector<string> {
            if (i == s.size()) return {""};
            if (cache.count(i)) return cache[i];

            vector<string> re;
            for (int j = i; j < s.size(); j++) {
                string w = s.substr(i, j - i + 1);
                if (!bank.count(w)) continue;

                vector<string> strings = self(self, j + 1);
                for (const string &st : strings) {
                    string sentence = w;
                    if (!st.empty()) sentence += " " + st;
                    re.push_back(sentence);
                }
            }
            return cache[i] = re;
        };

        return backtrack(backtrack, 0);
    }
};