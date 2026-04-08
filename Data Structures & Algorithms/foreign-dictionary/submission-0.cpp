class Solution {
    unordered_map<char, set<char>> adj;
    unordered_map<char, bool> visit;
    string re;
public:
    string foreignDictionary(vector<string>& words) {
        for (const auto& word : words) {
            for (const auto& c : word) {
                adj[c];
            }
        }

        for (size_t i = 0; i < words.size() - 1; i++) {
            int minLen = min(words[i].size(), words[i + 1].size());
            if (words[i].size() > words[i + 1].size() 
                && words[i].substr(0, minLen) == words[i + 1].substr(0, minLen)) return "";

            for (int j = 0; j < minLen; j++) {
                if (words[i][j] != words[i + 1][j]) {
                    adj[words[i][j]].insert(words[i + 1][j]);
                    break;
                }
            }
        }

        for (const auto& pair : adj) {
            if (dfs(pair.first)) return "";
        }

        reverse(re.begin(), re.end());
        return re;
    }

    bool dfs(char c) {
        if (visit.count(c)) {
            return visit[c];
        }

        visit[c] = true;

        for (auto next : adj[c]) {
            if (dfs(next)) return true;
        }

        visit[c] = false;
        re.push_back(c);
        return false;
    }
};
