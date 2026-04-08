class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>> res;
        dfs(nums, target, 0, cur, res);
        return res;
    }

    void dfs(vector<int>& nums, 
        int target, 
        int i, 
        vector<int>& cur,
        vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        if (i >= nums.size() || target < 0) {
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, target - nums[i], i, cur, res);
        cur.pop_back();
        dfs(nums, target, i + 1, cur, res);
    }
};
