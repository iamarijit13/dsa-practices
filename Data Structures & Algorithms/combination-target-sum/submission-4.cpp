class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
      vector<vector<int>> re;
        vector<int> subset;
        dfs(nums, 0, subset, re, target);
        return re;
    }

    void dfs(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& re, int target) {
        if (target == 0) {
            re.push_back(subset);
            return;
        }

        if (index >= nums.size() || target < 0) {
            return;
        }

        subset.push_back(nums[index]);
        dfs(nums, index, subset, re, target - nums[index]);
        subset.pop_back();
        dfs(nums, index + 1, subset, re, target);
    }
};
