class Solution {
public:
    vector<int> findOrder(int cours, vector<vector<int>>& preqs) {
        unordered_map<int, vector<int>> preq;
        for (const auto& pre : preqs) {
            preq[pre[0]].push_back(pre[1]);
        }

        unordered_set<int> visit;
        unordered_set<int> loop;
        vector<int> re;

        auto iterate = [&preqs, &preq, &visit, &loop, &re](auto &self, int cur) {
            if (loop.count(cur)) return false;

            if (visit.count(cur)) return true;

            loop.insert(cur);
            if (!preq[cur].empty()) {
                for (int c : preq[cur]) {
                    if (!self(self, c)) return false;
                }
            }
            visit.insert(cur);
            loop.erase(cur);
            re.push_back(cur);
            return true;
        };

        for (int course = 0; course < cours; course++) {
            if (!iterate(iterate, course)) {
                return {};
            }
        }
        return re;
    }
};
