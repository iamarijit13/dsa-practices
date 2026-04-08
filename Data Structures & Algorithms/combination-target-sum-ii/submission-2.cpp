class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, res);
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
        dfs(nums, target - nums[i], i + 1, cur, res);
        cur.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        dfs(nums, target, i + 1, cur, res);
    }
};
