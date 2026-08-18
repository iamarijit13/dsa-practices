class Solution {
    vector<vector<int>> combinations;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;

        auto findCombinations = [this, &nums](auto& self, vector<int>& cur, int index, int target) {
            if (index >= nums.size() || target < 0) return;
            if (target == 0) {
                combinations.push_back(cur);
                return;
            }

            cur.push_back(nums[index]);
            self(self, cur, index, target - nums[index]);
            cur.pop_back();
            self(self, cur, index + 1, target);
        };

        findCombinations(findCombinations, cur, 0, target);

        return combinations;
    }
};
