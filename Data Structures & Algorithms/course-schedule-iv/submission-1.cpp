class Solution {
    unordered_map<int, vector<int>> preq;
    unordered_map<int, unordered_set<int>> preqMap;
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        for (const auto& pre : prerequisites) {
            preq[pre[0]].push_back(pre[1]);
        }
        vector<bool> re;
        // for (vector<int> q : queries) {
        //     if (dfs(q[0], q[1])) {
        //         re.push_back(true);
        //     } else {
        //         re.push_back(false);
        //     }
        // }

        for (int i = 0; i < numCourses; i++) {
            dfs(i);
        }
        for (vector<int> q : queries) {
            if (preqMap[q[0]].count(q[1])) {
                re.push_back(true);
            } else {
                re.push_back(false);
            }
        }
        return re;
    }

private:
    bool dfs(int source, int target) {
        if (source == target) {
            return true;
        }

        for (int c : preq[source]) {
            if (dfs(c, target)) return true;
        }
        return false;
    }

    unordered_set<int> dfs(int crs) {
        if (preqMap.count(crs)) return preqMap[crs];

        preqMap[crs] = unordered_set<int>();
        for (int c : preq[crs]) {
            unordered_set<int> cur = dfs(c);
            preqMap[crs].insert(cur.begin(), cur.end());
        }
        preqMap[crs].insert(crs);
        return preqMap[crs];
    }
};