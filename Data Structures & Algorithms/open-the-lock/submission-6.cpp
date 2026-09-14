class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int moves = 0;
        set<string> visit(deadends.begin(), deadends.end());
        if (visit.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        visit.insert("0000");

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string current = q.front();
                q.pop();

                if (current == target) return moves;

                for (string next : getNexts(current)) {
                    if (visit.count(next)) continue;
                    visit.insert(next);
                    q.push(next);
                }
            }
            moves++;
        }

        return -1;
    }

private:
    vector<string> getNexts(string current) {
        vector<string> nexts;
        for (int i = 0; i < 4; i++) {
            string next = current;
            next[i] = (next[i] - '0' + 1) % 10 + '0';
            nexts.push_back(next);

            next = current;
            next[i] = (next[i] - '0' - 1 + 10) % 10 + '0';
            nexts.push_back(next);
        }

        return nexts;
    }
};