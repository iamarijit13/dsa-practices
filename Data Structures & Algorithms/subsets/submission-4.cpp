class Solution {
    vector<vector<int>> subset;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;

        auto findSubsets = [this, &nums](auto& self, vector<int>& cur, int index) {
            if (index == nums.size()) {
                subset.push_back(cur);
                return;
            }

            cur.push_back(nums[index]);
            self(self, cur, index + 1);
            cur.pop_back();
            self(self, cur, index + 1);
        };

        findSubsets(findSubsets, cur, 0);
        return this -> subset;
    }
};
