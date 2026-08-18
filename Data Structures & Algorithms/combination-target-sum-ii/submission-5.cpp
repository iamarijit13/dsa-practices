class Solution {
    vector<vector<int>> combinations;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());

        auto findUnique = [this, &candidates](auto& self, vector<int>& cur, int index, int target) {
            if (target == 0) {combinations.push_back(cur); return;}

            if (index >= candidates.size() || target < 0) return;

            cur.push_back(candidates[index]);
            self(self, cur, index + 1, target - candidates[index]);
            cur.pop_back();
            while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) index++;
            self(self, cur, index + 1, target);
        };

        findUnique(findUnique, cur, 0, target);

        return combinations;
    }
};
