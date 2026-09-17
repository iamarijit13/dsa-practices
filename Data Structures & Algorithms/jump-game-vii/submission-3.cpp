class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        queue<int> q;
        int farthest = 0;
        q.push(0);

        while (!q.empty()) {
            int index = q.front();
            q.pop();
            int start = max(index + minJump, farthest + 1);
            // int end = min((index + maxJump + 1), (int)s.size());
            int end = index + maxJump + 1;
            for (int i = start; i < end; i++) {
                if (i >= s.size()) break;
                if (s[i] == '0') q.push(i);
                if (i == s.size() - 1) return true;
            }
            farthest = index + maxJump;
        }
        return false;
    }
};