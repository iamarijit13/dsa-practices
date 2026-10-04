class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int length = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (length % 4 != 0) return false;
        length /= 4;
        vector<int> sides(4, 0);

        sort(matchsticks.rbegin(), matchsticks.rend());
        
        auto backtrack = [&matchsticks, &sides, &length](auto &self, int index) {
            if (index == matchsticks.size()) return true;

            for (int side = 0; side < 4; side++) {
                if (sides[side] + matchsticks[index] <= length) {
                    sides[side] += matchsticks[index];
                    if (self(self, index + 1)) return true;
                    sides[side] -= matchsticks[index];
                }
                // if (sides[index] == 0) break;
            }
            return false;
        };
        return backtrack(backtrack, 0);
    }
};