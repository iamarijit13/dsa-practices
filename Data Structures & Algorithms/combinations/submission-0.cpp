class Solution {
    vector<vector<int>> combinations;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;

        auto findCombinations = [this, n, k](auto& self, vector<int>& cur, int index) {
            if (cur.size() == k) {
                combinations.push_back(cur);
                return;
            }

            if (cur.size() > k) return;

            for (int i = index; i <= n; i++) {
                cur.push_back(i);
                self(self, cur, i + 1);
                cur.pop_back();
            }
        };

        findCombinations(findCombinations, cur, 1);

        return combinations;
    }
};