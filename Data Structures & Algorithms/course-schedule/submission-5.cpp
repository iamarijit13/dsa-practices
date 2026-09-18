class Solution {
public:
    bool canFinish(int courses, vector<vector<int>>& preqs) {
        unordered_map<int, vector<int>> hash;
        unordered_set<int> visit;

        for (auto &pre : preqs) {
            hash[pre[0]].push_back(pre[1]);
        }

        auto iterate = [&preqs, &hash, &visit](auto &self, int c) {
            if (visit.count(c)) return false;
            visit.insert(c);

            for (auto &h : hash[c]) {
                if (!self(self, h)) return false;
            }
            hash[c].clear();
            visit.erase(c);
            return true;
        };

        for (int c = 0; c < courses; c++) {
            if (!iterate(iterate, c)) return false;
        }
        return true;
    }
};
