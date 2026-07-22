class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preq;
        for (const auto& pre : prerequisites) {
            preq[pre[0]].push_back(pre[1]);
        }

        unordered_set<int> visit;
        unordered_set<int> loop;
        vector<int> re;

        for (int course = 0; course < numCourses; course++) {
            if (!dfs(preq, course, visit, loop, re)) {
                return {};
            }
        }
        return re;
    }
private:
    bool dfs(unordered_map<int, vector<int>>& preq, int cur, unordered_set<int>& visit, unordered_set<int>& loop, vector<int>& re) {
        if (loop.count(cur)) {
            return false;
        }

        if (visit.count(cur)) {
            return true;
        }

        // if (preq[cur].empty()) {
        //     return true;
        // }

        loop.insert(cur);
        if (!preq[cur].empty()) {
            for (int c : preq[cur]) {
                if (!dfs(preq, c, visit, loop, re)) {
                    return false;
                }
            }
        }
        visit.insert(cur);
        loop.erase(cur);
        re.push_back(cur);
        return true;
    }
};
