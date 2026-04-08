class Solution {
public:
    vector<vector<int>> re;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        dfs(nums, target, 0, cur);
        
        return re;
    }

    void dfs(vector<int>& nums, int target, int i, vector<int>& cur) {
        if (target == 0) {
            re.push_back(cur);
            return;
        }
        if (i >= nums.size() || target < 0) {
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, target - nums[i], i, cur);
        cur.pop_back();
        dfs(nums, target, i + 1, cur);
    }
};
