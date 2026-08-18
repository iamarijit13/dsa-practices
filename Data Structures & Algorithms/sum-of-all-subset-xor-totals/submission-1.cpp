class Solution {
    int re = 0;
    vector<vector<int>> subsets;
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> cur;

        auto findSubsets = [this, &nums](auto &self, vector<int>& cur, int index) -> void {
            if (index == nums.size()) {
                subsets.push_back(cur);
                return;
            }

            cur.push_back(nums[index]);
            self(self, cur, index + 1);
            cur.pop_back();
            self(self, cur, index + 1);
        };

        findSubsets(findSubsets, cur, 0);

        for (auto &subset : subsets) {
            int xr = 0;
            for (auto &n : subset) {
                xr = xr ^ n;
            }
            re += xr;
        }

        return re;
    }
};


