class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> re;
        unordered_set<int> cache, loop;
        unordered_map<int, vector<int>> hash;

        for (const vector<int> &preq : prerequisites) {
            hash[preq[0]].push_back(preq[1]);
        }

        auto iterate = [&](auto &self, int c) {
            if (loop.count(c)) return false;
            if (cache.count(c)) return true;

            loop.insert(c);
            for (const int &p : hash[c]) {
                if (!self(self, p)) return false;
            }
            cache.insert(c);
            loop.erase(c);
            re.push_back(c);
            return true;
        };

        for (int c = 0; c < numCourses; c++) {
            if (!iterate(iterate, c)) return {};
        }

        return re;
    }
};
