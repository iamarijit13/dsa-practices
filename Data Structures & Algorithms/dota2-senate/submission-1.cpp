class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r, d;

        for (int i = 0; i < n; i++) {
            char c = senate[i];
            if (c == 'R') r.push(i);
            else d.push(i);
        }

        while (!r.empty() && !d.empty()) {
            if (r.front() < d.front()) {
                d.pop();
                int c = r.front();
                r.pop();
                r.push(c + n - 1);
            } else {
                r.pop();
                int c = d.front();
                d.pop();
                d.push(c + n - 1);
            }
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};