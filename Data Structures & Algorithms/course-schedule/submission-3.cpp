class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
