class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, subset, res, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& subset, vector<vector<int>>& subsets, int i) {
        if (i >= nums.size()) {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, subset, subsets, i + 1);
        subset.pop_back();
        dfs(nums, subset, subsets, i + 1);

    }
};
