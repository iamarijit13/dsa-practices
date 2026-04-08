class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> hash;
        unordered_set<int> visit;

        for (auto& prerequisite : prerequisites) {
            if (!hash.count(prerequisite[0])) {
                hash[prerequisite[0]] = {prerequisite[1]};
            } else {
                hash[prerequisite[0]].push_back(prerequisite[1]);
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

        if (!hash.count(course)) {
            return true;
        }

        visit.insert(course);
        for (int pre : hash[course]) {
            if (!dfs(hash, visit, pre)) {
                return false;
            }
        }
        visit.erase(course);
        return true;
    }
};
