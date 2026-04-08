class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> sequence(n + 1, -1);

        for (auto t : trust) {
            sequence[t[0]] = 0;
        }
        int potential = -1;
        for (int i = 1; i < sequence.size(); i++) {
            if (sequence[i] == -1) {
                potential = i;
            }
        }

        if (potential != -1) {
            for (auto t : trust) {
                if (t[1] != potential) {
                    return -1;
                }
            }
            return potential;
        }
        return -1;
    }
};