class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> hash;
        unordered_set<int> cache;

        for (const vector<int> &preq : prerequisites) {
            hash[preq[0]].push_back(preq[1]);
        }

        auto iterate = [&](auto &self, int index) {
            if (cache.count(index)) return false;

            cache.insert(index);
            for (const int &pr : hash[index]) {
                if (!self(self, pr)) return false;
            }
            hash[index].clear();
            cache.erase(index);
            return true;
        };
        
        for (int c = 0; c < numCourses; c++) {
            if (!iterate(iterate, c)) return false;
        }
        return true;
    }
};
