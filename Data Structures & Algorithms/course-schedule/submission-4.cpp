class Solution {
public:
    bool canFinishs(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> hash;
        unordered_set<int> visit;
        
        for (auto& pre : prerequisites) {
            if (!hash.count(pre[0])) {
                hash[pre[0]] = {pre[1]};
            } else {
                hash[pre[0]].push_back(pre[1]);
            }
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(hash, visit, c)) {
                return false;
            }
        }
        return true;
    }

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

    bool dfs(unordered_map<int, vector<int>>& hash, unordered_set<int>& visit, int course) {
        if (visit.count(course)) {
            return false;
        }

        if (hash[course].empty()) {
            return true;
        }
        visit.insert(course);

        for (auto& h : hash[course]) {
            if (!dfs(hash, visit, h)) {
                return false;
            }
        }
        hash[course].clear();
        visit.erase(course);
        return true;
    }
};
