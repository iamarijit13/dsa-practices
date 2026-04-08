class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> re;
        vector<int> subset;
        sort(nums.begin(), nums.end());
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
        dfs(nums, index + 1, subset, re, target - nums[index]);
        subset.pop_back();
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) index++;
        dfs(nums, index + 1, subset, re, target);
    }
};
