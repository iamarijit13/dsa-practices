class Solution {
public:
    int openLocks(vector<string>& deadends, string target) {
        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.count("0000")) return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visit.insert("0000");

        while (!q.empty()) {
            auto [lock, turns] = q.front();
            q.pop();

            if (lock == target) return turns;
            for (string child : children(lock)) {
                if (!visit.count(child)) {
                    visit.insert(child);
                    q.push({child, turns + 1});
                }
            }
        }
        return -1;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.count("0000")) return -1;
        queue<string> q;
        q.push("0000");
        visit.insert("0000");
        int turns = 0;

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string lock = q.front();
                q.pop();
                
                if (lock == target) return turns;
                for (string child : children(lock)) {
                    if (!visit.count(child)) {
                        visit.insert(child);
                        q.push(child);
                    }
                }
            }
            turns++;
        }
        return -1;
    }

private:
    vector<string> children(string lock) {
        vector<string> re;
        for (int i = 0; i < 4; i++) {
            string next = lock;
            next[i] = (next[i] - '0' + 1) % 10 + '0';
            re.push_back(next);

            next = lock;
            next[i] = (next[i] - '0' - 1 + 10) % 10 + '0';
            re.push_back(next);
        }

        return re;
    }
};